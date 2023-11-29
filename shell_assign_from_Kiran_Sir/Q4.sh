#!/bin/bash

#Write a shell script to determine whether a given number is prime or not


echo -n "Enter the Number: "
read num

i=2
flag=0

while [ $i -le $num ]
do
	if [ `expr $num % $i` -eq 0 ]
	then
		flag=1
		echo "$num is not prime number..."
		break
	fi
	i=`expr $i + 1`
done
if [ $flag -eq 0 ]
then
	echo "$num is prime number..."
fi
