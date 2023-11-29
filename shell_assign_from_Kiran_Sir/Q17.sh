#!/bin/bash

#Print the following pattern.
#*
#* *
#* * *
#* * * *
#* * * * *

echo -n "Enter len  : "
read len

i=1

while [ $i -le $len ]
 do


    b=`expr $len - $i`
    while [ $b -gt 0 ]
        do
          
        b=`expr $b - 1`
    done

    num=1
    while [ $num -le $i ]
    do
        echo -n "* "
        num=`expr $num + 1`
    done

    i=`expr $i + 1 `
    echo " "
 done
