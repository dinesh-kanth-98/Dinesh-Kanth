#!/bin/bash

# Function to perform addition
perform_addition() {
    read -p "Enter the first number: " num1
    read -p "Enter the second number: " num2
    result=$(echo "$num1 + $num2" | bc)
    echo "Result: $result"
}

# Function to perform subtraction
perform_subtraction() {
    read -p "Enter the first number: " num1
    read -p "Enter the second number: " num2
    result=$(echo "$num1 - $num2" | bc)
    echo "Result: $result"
}

# Function to perform multiplication
perform_multiplication() {
    read -p "Enter the first number: " num1
    read -p "Enter the second number: " num2
    result=$(echo "$num1 * $num2" | bc)
    echo "Result: $result"
}

# Function to perform division
perform_division() {
    read -p "Enter the dividend: " dividend
    read -p "Enter the divisor: " divisor
    result=$(echo "scale=2; $dividend / $divisor" | bc)
    echo "Result: $result"
}

# Main script logic
while true; do
    PS3="Please select an operation: "
    options=("Addition" "Subtraction" "Multiplication" "Division" "Exit")
    echo "----- Calculator -----"
    select option in "${options[@]}"; do
        case $REPLY in
            1)
                perform_addition
                break
                ;;
            2)
                perform_subtraction
                break
                ;;
            3)
                perform_multiplication
                break
                ;;
            4)
                perform_division
                break
                ;;
            5)
                echo "Exiting..."
                exit 0
                ;;
            *)
                echo "Invalid choice. Please enter a number from 1 to 5."
                ;;
        esac
    done
done

<<'MULTI_LINE_COMMENT'

REPLY:
--> In Bash, the REPLY variable is an environment variable that is automatically set by the select statement.
--> It stores the user's input or selection when using the select statement. 
--> The value of REPLY corresponds to the number or index of the selected option in the select menu.

PS3:
--> In the context of the select statement in Bash, PS3 is an environment variable that defines the prompt
    string displayed to the user when presenting the menu options.

--> By default, the PS3 variable is set to #?, indicating the default prompt. 
    However, you can customize it by assigning a new value to the PS3 variable.

MULTI_LINE_COMMENT
