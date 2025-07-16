#!/bin/bash

echo "Enter numbers separated by space:"
read -a numbers

sum=0
count=${#numbers[@]}

for num in "${numbers[@]}"; do
    sum=$((sum + num))
done

average=$(echo "scale=2; $sum / $count" | bc)

echo "Average: $average"
