#!/bin/bash

echo "Enter array elements separated by space:"
read -a arr

largest=${arr[0]}

for num in "${arr[@]}"; do
    if (( num > largest )); then
        largest=$num
    fi
done

echo "Largest element is: $largest"
