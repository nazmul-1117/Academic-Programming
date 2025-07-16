#!/bin/bash

echo "Enter numbers separated by space:"
read -a numbers

even_sum=0
odd_sum=0

for num in "${numbers[@]}"; do
    if (( num % 2 == 0 )); then
        ((even_sum += num))
    else
        ((odd_sum += num))
    fi
done

echo "Sum of Even Numbers: $even_sum"
echo "Sum of Odd Numbers: $odd_sum"
