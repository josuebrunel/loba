#!/bin/bash

for line in $(cat file.txt)
do
   echo $line
   git rm $line
   git commit -m "deleted $line"
   sleep 1
done
