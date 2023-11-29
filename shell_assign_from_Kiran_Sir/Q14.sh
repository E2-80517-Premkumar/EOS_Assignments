#!/bin/bash

#Write a shell script to display only executable files of current directory.

if [ -f *.out ]
then
	echo "All Executable files in current directory: "
	ls *.out
else
	echo "Not present!"
fi

