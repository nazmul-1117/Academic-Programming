#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int nBlocks, nProcesses;
    int blockSize[MAX], blockAllocated[MAX] = {0};
    int processSize[MAX];
    int allocatedBlock[MAX];
    int internalFrag[MAX] = {0};

    cout << "\tEnter the number of Blocks: ";
    cin >> nBlocks;
    for(int i = 0; i < nBlocks; i++) {
        cout << "\tBlock " << i + 1 << " size: ";
        cin >> blockSize[i];
    }

    cout << "\tEnter the number of processes: ";
    cin >> nProcesses;
    for(int i = 0; i < nProcesses; i++) {
        cout << "\tEnter memory required for process " << i + 1 << ": ";
        cin >> processSize[i];
        allocatedBlock[i] = -1;
    }

    for(int i = 0; i < nProcesses; i++) {
        for(int j = 0; j < nBlocks; j++) {
            if(!blockAllocated[j] && (blockSize[j] >= processSize[i])) {
                allocatedBlock[i] = j; 
                internalFrag[i] = blockSize[j] - processSize[i];
                blockAllocated[j] = 1;
                break; 
            }
        }
    }

    cout << "\n\t---------------------------------------------------------------------------\n";
    cout << "\t| Processes | Process Size | Blocks | Block Size | Allocated | Int. Frag. |\n";
    cout << "\t---------------------------------------------------------------------------\n";
    for(int i = 0; i < nProcesses; i++) {
        cout << "\t|    " << i + 1 << "\t    |\t" << processSize[i] << "\t   |  ";
        if(allocatedBlock[i] != -1) {
            int blockIdx = allocatedBlock[i];
            cout << blockIdx + 1 << "\t    |    " << blockSize[blockIdx] << "\t |    YES    |\t" << internalFrag[i] << "\t  |\n";
        } else {
            cout << "--    |    --\t |    NO     |\t--\t  |\n";
        }
    }
    cout << "\t---------------------------------------------------------------------------\n";

    return 0;
}