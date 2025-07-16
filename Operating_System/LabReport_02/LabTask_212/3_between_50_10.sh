#!/bin/bash

sum=0

for (( i=50; i<=100; i++ )); do
    if (( i % 3 == 0 && i % 5 != 0 )); then
        ((sum += i))
    fi
done

echo "Sum of numbers between 50 and 100 divisible by 3 and not by 5: $sum"
