#!/bin/bash

echo -n "Enter a number: "
read num

digits=()

while [ $num -gt 0 ]; do
    digit=$((num % 10))
    digits+=($digit)
    num=$((num / 10))
done

# Remove duplicates and sort in reverse
unique_digits=($(printf "%s\n" "${digits[@]}" | sort -nr | uniq))

if [ ${#unique_digits[@]} -lt 2 ]; then
    echo "Second largest digit does not exist."
else
    echo "Second largest digit is: ${unique_digits[1]}"
fi
