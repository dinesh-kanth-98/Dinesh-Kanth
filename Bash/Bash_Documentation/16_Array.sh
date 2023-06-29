#!/bin/bash

# Define an array of names in title case
NAME=("Dinesh" "Tharun" "Veeresh" "Manoj" "Sunil")

# Define an array of corresponding phone numbers
NUMBER=("11111" "22222" "33333" "44444" "55555")

# Loop through the elements of the arrays
for i in {0..4}; do
    # Print the name and phone number for each index
    echo "Name: ${NAME[i]}  Phone No: ${NUMBER[i]}"
done

# Loop through the indices of the NAME array
# ${!NAME[@]} returns the array indices
for index in "${!NAME[@]}"; do
    # Print the index and corresponding name
    echo "Index: ${index}  Name: ${NAME[${index}]}"
done
