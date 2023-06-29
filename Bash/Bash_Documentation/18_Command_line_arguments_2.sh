#!/bin/bash

# Get the script name without the path
script_name=$(basename "$0")

# Check if two arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Invalid number of arguments."
    echo "Usage: $script_name [name] [age]"
    exit 1
fi

# Store the arguments in variables
name=$1
age=$2

# Print the formatted string
echo "Hello, my name is $name and I am $age years old."

<<'MULTI_LINE_COMMENT'
Note:
--> $0 represents the relative or absolute path to the script file,
    depending on how it's executed.
--> If you want to display just the script name
    without the path, you can use $(basename "$0") instead of $0.
MULTI_LINE_COMMENT
