#!/bin/bash

# Type 1
let a=5+2
echo $a

# Type 2
let a++
echo $a

# Type 3
let "b = 11 + 6"
echo $b

# Type 4
let "c = 11 * 6"
echo $c

# Type 5
let "d = $1 + 30"
echo $d

echo $1


