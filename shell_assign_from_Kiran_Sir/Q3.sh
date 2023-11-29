#!/bin/bash

#Write a shell script to accept the name from the user and check whether user entered
#name is file or directory. If name is file display its size and if it is directory display its
#contents.

echo -n "Enter name: "
read name

if [ -e "$name" ]
then
	if [ -d "$name"  ]
	then
		cd $name
		echo "...Directory..."
	        ls
	else
		echo "...File..."
		res=`stat -c %s $name`
		echo "Size=$res"
	fi
else
	echo "Name is not a file or Directory"
fi
