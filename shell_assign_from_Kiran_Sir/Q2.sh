#!/bin/bash

#Write a shell script to display menu like “1. Date, 2. Cal, 3. Ls, 4. Pwd, 5. Exit” and execute the commands depending on user choice.

echo  "1.Date"
echo  "2.Calendar"
echo  "3.Ls"
echo  "4.Pwd"
echo  "5.Exit"

echo -e -n "Enter your choice: "
read choice

case $choice in
     1)echo -n "Date: "
	     date
	     ;;

     2)echo -n "Calendar: "
	     cal
	     ;;
     3)echo -n "Ls: "
	     ls
	     ;;
     4)echo -n "pwd: "
	     pwd
	     ;;
     *)echo -n "Exit: "

esac

