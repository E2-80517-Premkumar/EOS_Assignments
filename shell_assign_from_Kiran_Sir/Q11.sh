#!/vin/bash

#Write a program to calculate gross salary if the DA is 40%, HRA is 20% of basic salary.
#Accept basic salary form user and display gross salary (Result can be floating point value).


echo "enter salary: "
read salary
DA=0.4
HRA=0.2
Gross_salary=`expr $salary + ($salary + DA) + ($salary + HRA)` | bc

echo "Gross Salary: $Gross_salary"
