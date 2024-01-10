#!/bin/bash
# Asignment 1: finder-app/finder.sh
# chankf
# 1st argument: (filesdir) a path to a directory on the filesystem
# 2nd argument: (searchstr) a text string which will be searched within these files
# exits with return value 1 error and print statements if any of the parameters above were not specified
# exits with return value 1 error and print statements if filesdir does not represent a directory on the filesystem
# prints a message "The number of files are X and the number of matching lines are Y" 
#   where X is the number of files in the directory and all subdirectories and 
#   Y is the number of matching lines found in respective files, 
#   where a matching line refers to a line which contains searchstr (and may also contain additional content).
# Example invocation:
#   finder.sh /tmp/aesd/assignment1 linux
#

filesdir=/tmp
searchstr=CHANKf

if [ $# -lt 2 ] 
then
    echo "Insufficient parameters!"
    exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d "$filesdir" ]
then
    echo "No such directory!"
    exit 1
fi

X=`grep -R -c "${searchstr}" ${filesdir} | wc -l`
Y=`grep -R "${searchstr}" ${filesdir} | wc -l`

echo "The number of files are ${X} and the number of matching lines are ${Y}."
exit 0
