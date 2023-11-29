#!/bin/bash

#Write a program to find given number of terms in the Fibonacci series.

echo "Enter Number: "
read num
i=0
t1=0
t2=1
t3=`expr t1 + t2`

echo "Fibonacci Series: "
for _ in $(seq 1 $num)
do
	echo "$t3"
        echo "$t1=$t2"
	echo "$t2=t3"
done	
