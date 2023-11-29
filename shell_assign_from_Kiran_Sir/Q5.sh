#!/bin/bash

#Write a Program to find the greatest of three numbers


echo "Enter three numbers: "
read num1
read num2
read num3

if [ $num1 -gt $num2 -a $num1 -gt $num3 ]
then
	echo "$num1 is greater..."

elif [ $num2 -gt $num1 -a $num2 -gt $num3 ]
then
	echo "$num2 is greater..."

else
	echo "$num3 is greater..."
fi
