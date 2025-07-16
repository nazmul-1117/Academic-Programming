#!/bin/bash

sum_numbers() {
    sum=0
    for num in "$@"; do
        sum=$((sum + num))
    done
    echo "Sum of numbers: $sum"
}

echo "Enter numbers separated by space:"
read -a numbers

sum_numbers "${numbers[@]}"
