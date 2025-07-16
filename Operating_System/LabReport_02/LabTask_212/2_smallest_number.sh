#!/bin/bash

echo "Enter numbers separated by space:"
read -a numbers

smallest=${numbers[0]}

for num in "${numbers[@]}"; do
    if (( num < smallest )); then
        smallest=$num
    fi
done

echo "Smallest number is: $smallest"
