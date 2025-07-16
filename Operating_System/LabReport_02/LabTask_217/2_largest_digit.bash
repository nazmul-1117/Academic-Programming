#!/bin/bash

echo -n "Enter a number: "
read num

max=0

while [ $num -gt 0 ]; do
    digit=$((num % 10))
    if (( digit > max )); then
        max=$digit
    fi
    num=$((num / 10))
done

echo "Largest digit is: $max"
