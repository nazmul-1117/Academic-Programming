#!/bin/bash

declare -a blockSize
declare -a blockAllocated
declare -a processSize
declare -a allocatedBlock
declare -a internalFrag

read -p "Enter the number of Blocks: " nBlocks
for ((i=0; i<nBlocks; i++)); do
    read -p "Block $((i+1)) size: " blockSize[i]
    blockAllocated[i]=0
done

read -p "Enter the number of processes: " nProcesses
for ((i=0; i<nProcesses; i++)); do
    read -p "Enter memory required for process $((i+1)): " processSize[i]
    allocatedBlock[i]=-1
    internalFrag[i]=0
done

for ((i=0; i<nProcesses; i++)); do
    for ((j=0; j<nBlocks; j++)); do
        if [ ${blockAllocated[j]} -eq 0 ] && [ ${blockSize[j]} -ge ${processSize[i]} ]; then
            allocatedBlock[i]=$j
            internalFrag[i]=$((blockSize[j] - processSize[i]))
            blockAllocated[j]=1
            break
        fi
    done
done

echo
echo "---------------------------------------------------------------------------"
echo "| Processes | Process Size | Blocks | Block Size | Allocated | Int. Frag. |"
echo "---------------------------------------------------------------------------"
for ((i=0; i<nProcesses; i++)); do
    printf "|    %d\t    |\t%d\t   |  " $((i+1)) ${processSize[i]}
    if [ ${allocatedBlock[i]} -ne -1 ]; then
        blockIdx=${allocatedBlock[i]}
        printf "%d\t    |    %d\t |    YES    |\t%d\t  |\n" $((blockIdx+1)) ${blockSize[blockIdx]} ${internalFrag[i]}
    else
        printf "%-5s |    %-5s |    %-7s |\t%-5s |\n" "--" "--" "NO" "--"
    fi
done
echo "---------------------------------------------------------------------------"