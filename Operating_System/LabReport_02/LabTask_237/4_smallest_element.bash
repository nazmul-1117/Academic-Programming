#!/bin/bash

echo "Enter array elements separated by space:"
read -a arr

smallest=${arr[0]}

for num in "${arr[@]}"; do
    if (( num < smallest )); then
        smallest=$num
    fi
done

echo "Smallest element is: $smallest"
