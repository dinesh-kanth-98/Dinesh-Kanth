#!/bin/bash

# Check if at least one argument is provided
if [ $# -lt 1 ]; then
    echo "Error: No arguments provided."
    echo "Usage: bash 17_Command_line_arguments.sh [arg1] [arg2] ..."
    exit 1
fi

# Print the total number of arguments
echo "Total number of arguments: $#"

# Print each argument passed in
echo "Arguments:"
for arg in "$@"; do
    echo "$arg"
done
