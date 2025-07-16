#!/bin/bash

echo -n "Enter a number: "
read num

temp=$num
sum=0
n=${#num}

while [ $temp -gt 0 ]; do
    digit=$((temp % 10))
    power=1

    # Calculate digit^n
    for (( i=0; i<n; i++ )); do
        power=$((power * digit))
    done

    sum=$((sum + power))
    temp=$((temp / 10))
done

if [ $sum -eq $num ]; then
    echo "$num is an Armstrong number."
else
    echo "$num is not an Armstrong number."
fi
