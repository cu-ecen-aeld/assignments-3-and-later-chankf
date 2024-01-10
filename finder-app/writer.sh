#!/bin/bash
# finder-app/writer.sh
# Assignment 1 / Question 10
# 2023-12-27
#
writefile=$1
writestr=$2

if [ $# -lt 2 ] 
then
    echo "Must specify filename with full path and string to write to file.!"
    exit 1

fi

echo $writestr > $writefile
exit 0

