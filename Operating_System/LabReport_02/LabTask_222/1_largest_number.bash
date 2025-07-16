#!/bin/bash

find_largest() {
    if [ $1 -gt $2 ]; then
        echo "$1 is the largest number."
    elif [ $2 -gt $1 ]; then
        echo "$2 is the largest number."
    else
        echo "Both numbers are equal."
    fi
}

echo -n "Enter first number: "
read num1
echo -n "Enter second number: "
read num2

find_largest $num1 $num2
