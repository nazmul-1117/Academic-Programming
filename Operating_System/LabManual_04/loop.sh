#!/bin/bash

for i in 1 2 3 
do
	#echo "$i"
	break;
done

for i in {1..5}
do
	 #echo "$i"
	 break;
done

for i in {1..10..2}
do
	#echo "$i"
	break;
done

for ((i=0; i<5; i++))
do
	#echo "$i"
	break;
done


# While loop
i=1
echo -n "While Loop1: "
while  [[ $i -le 5 ]]
do
	echo -n "$i "
	((i++))
done

dox="bye"
while [[ $dox == "bye" ]]
do
	# echo -n "Do you want to continue? "
	# read dox
	break
done
echo ""

# Array
echo "Array: "
arr=(hello world, i am md nazmul hossain)

echo "Print specific index elements"
echo "${arr[0]}"
echo "${arr[3]}"
echo "${arr[*]}"
echo ""

#Slicing
echo "Print Slicing elements"
echo "${arr[@]:2}"
echo "${arr[@]:2:3}"
echo ""

echo "Print all elements"
echo "${#arr[*]}"
echo ""

# Search in an array
echo "Search elements"
echo "${arr[@]/*[aA]*/}"

#Replace an array
echo "Replace elements"
echo "${arr[@]//a//A}"

echo ""
echo -n "New Array While: "
n=(1 2 3 4 5)
i=0
while [[ $i -lt "${#n[@]}" ]]
do
	echo -n "${n[$i]} "
	((i++))
done
echo ""

echo -n "New Array For: "
for i in "${n[@]}"
do
	echo -n "$i "
done

