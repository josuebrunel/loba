#!/bin/bash
###########################
###########################

for line in $(cat file.txt)
do
   echo $line
   git add $line
   git commit -m "added $line"
   sleep 1
done
