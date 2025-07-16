#!/bin/bash

echo -n "Enter a number: "
read num

odd_sum=0
even_sum=0

while [ $num -gt 0 ]; do
    digit=$((num % 10))
    if (( digit % 2 == 0 )); then
        even_sum=$((even_sum + digit))
    else
        odd_sum=$((odd_sum + digit))
    fi
    num=$((num / 10))
done

echo "Sum of Even Digits: $even_sum"
echo "Sum of Odd Digits: $odd_sum"
