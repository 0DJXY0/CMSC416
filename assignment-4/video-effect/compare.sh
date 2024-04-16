#!/bin/bash

# Check if exactly two arguments are passed
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 file1.txt file2.txt"
    exit 1
fi

file1=$1
file2=$2

# Check if the files exist
if [ ! -f "$file1" ]; then
    echo "File $file1 does not exist."
    exit 1
fi

if [ ! -f "$file2" ]; then
    echo "File $file2 does not exist."
    exit 1
fi

# Use diff to compare the files
output=$(diff -y --suppress-common-lines "$file1" "$file2")

if [ $? -eq 0 ]; then
    echo "The content of the two files are identical."
else
    echo "The files are different."
    echo "Differences:"
    echo "$output"
fi
