#!/bin/bash

echo "Enter numbers separated by space:"
read -a numbers

odd_sum=0
even_sum=0

for num in "${numbers[@]}"; do
    if (( num % 2 == 0 )); then
        even_sum=$((even_sum + num))
    else
        odd_sum=$((odd_sum + num))
    fi
done

echo "Sum of Even numbers: $even_sum"
echo "Sum of Odd numbers: $odd_sum"
