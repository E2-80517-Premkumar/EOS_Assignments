#!/bin/bash

#Write a Program to find whether a given number is positive or negative

echo -n "Enter Number: "
read num

if [ $num -gt 0 ]
then
	echo "$num is Positive Number !!"
elif [ $num -lt 0 ]
then
	echo "$num is negative number!!"
else
	echo "$num is neither positive nor negative!!"
fi

