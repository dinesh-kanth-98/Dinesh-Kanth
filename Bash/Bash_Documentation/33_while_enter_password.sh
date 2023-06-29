#!/bin/bash

# Set the correct password
correct_password="password123"

# Prompt the user for a password until the correct password is entered
while true; do
    # Read the password from the user
    read -p "Enter password: " password

    # Check if the entered password is correct
    if [ "$password" = "$correct_password" ]; then
        echo "Correct password entered. Access granted."
        break  # Exit the loop
    else
        echo "Incorrect password. Please try again."
    fi
done
