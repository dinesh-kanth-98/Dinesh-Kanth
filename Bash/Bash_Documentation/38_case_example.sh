#!/bin/bash

# Prompt the user for input
read -p "Enter a choice (a, b, c, d): " choice

# Perform actions based on the user's choice using case statements
case $choice in
    a)
        echo "You chose option A."
        ;;
    b | B)
        echo "You chose option B."
        ;;
    [c-dC-D])
        echo "You chose option C or D."
        ;;
    [[:digit:]])
        echo "You entered a digit."
        ;;
    *)
        echo "Invalid choice."
        ;;
esac
