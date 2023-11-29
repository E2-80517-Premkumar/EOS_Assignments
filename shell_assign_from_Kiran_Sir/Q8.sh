#!/bin/bash

#Write a program to print the table of a given number.

echo -n "Enter number: "
read num
echo "Table of $num : "
for i in 1 2 3 4 5 6 7 8 9 10
do
	res=`expr $num \* $i`
	echo "$res"
	i=`expr $num  + 1`
done

