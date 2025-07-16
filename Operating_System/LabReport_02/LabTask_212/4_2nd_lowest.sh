#!/bin/bash

echo "Enter numbers separated by space:"
read -a numbers

sorted=($(for i in "${numbers[@]}"; do echo $i; done | sort -nr))

echo "Second highest number is: ${sorted[1]}"
