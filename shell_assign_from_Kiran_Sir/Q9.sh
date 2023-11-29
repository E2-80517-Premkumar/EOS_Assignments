#!/bin/bash

#Write a program to find the factorial of given number.


echo "Enter Number: "
read num
i=0
factorial=1
for i in $(seq 1 $num)
do
	factorial=`expr $factorial \* $i`
done

echo "Factorial: $factorial"
