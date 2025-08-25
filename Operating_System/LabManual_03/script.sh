#!/bin/bash

# Using Let
echo "Let Commands"
echo "------------------------------"

let a=8+9
let b=++a
let "a2 = a + b "
#echo "Let Result1 ${b}"
echo "Let a2 ${a2}"

let c=$(( 8+9 ))
#echo "Let Result2 ${c}"

(( d = 8 + 9 ))
echo "Another Result: ${d}"
echo " "

# Expr Command
echo "Expr Commands"
echo "------------------------------"

let "xd1 = $( expr 9 + 6 )"
echo "Let xd1 Result: ${xd1}"

let xd2=$( expr 9 + 6 )
echo "Let xd2 Result: ${xd2}"

echo -e "\nExpr arithmatic operation of 9 and 6 (9+6, 9-6, 9*6, 9/6, 9%6)"
a=9
b=6
expr $a + $b
expr $a - $b
expr $a \* $b
expr $a / $b
expr $a % $b
echo "--------------------------"

#  Double  Parenthesis 
echo "Double Parenthesis"
echo "------------------------------"

a=$(( 8 + 9 ))
echo "Double Parenthesis Result a: ${a}"
b=$((a+ 3 ))
echo "Double Parenthesis Result b: ${b}"
echo " "

# Floating point
echo "Floating point"
echo "------------------------------"
a=$(echo "scale=2; 10.01254565455654" | bc)
echo "Floating point Result a: ${a}"
echo " "


# Variable Length
echo "Variable Length"
echo "------------------------------"
a='Hello World'
echo "Variable Length Result a: ${#a}"
b=897
echo "Variable Length Result b: ${#b}"
echo " "

# Basic String Operations
echo "Basic String Operations"
echo "------------------------------"
str="Hello World"
substr="ello"
substrmatch=$(expr index "$str" "$substr")
echo "Basic String Operations substrmatch: ${substrmatch}"

str="Hello World"
st=6
length=5
substr=${str:st:length}
echo "Basic String Operations Slicing: ${substr}"


# If else
echo "If else"
echo "------------------------------"
echo " "
a=790
if [[ $a -ge 80 ]]
then
	echo "A+"
elif [[ $a -ge 75 && $a -lt 80 ]]
then
	echo "A"
elif [[ $a -ge 70 && $a -lt 75 ]]
then
    echo "A-"
elif [[ $a -ge 65 && $a -lt 70 ]]
then
	echo "B+"
fi

# Switch Case
echo "Switch Case"
echo "------------------------------"
c="xd"
case $c in
	"audi") echo "AX" ;;
	"bmw") echo "BX" ;;
	*) echo "Wrong" ;;
esac

# String Manipulation
echo -e "\nString Manipulation"
echo "------------------------------"

echo -n "String Match ---> "
str="i am nazmul"
if [[ $str == *"am"* ]]
then
	echo "Matched"
else
    echo "Not Matched"
fi

echo -n "Empty String --> "
str="valid string"
if [[ -z $str ]]; then
	echo "Empty String"
else
    echo "Not Empty String"
fi
