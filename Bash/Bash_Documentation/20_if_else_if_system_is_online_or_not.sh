#!/bin/bash

# Get the current hour of the day
current_hour=$(date +"%H")

# Check the hour and perform different actions based on the time
if [ $current_hour -lt 12 ]; then
    echo "Good morning! It's still early."
elif [ $current_hour -lt 18 ]; then
    echo "Good afternoon! Enjoy the rest of your day."
else
    echo "Good evening! It's getting late."
fi

# Check if the script is running as root
if [ $EUID -eq 0 ]; then
    echo "You are running the script as root."
else
    echo "You are not running the script as root."
fi

# Check if the system is online or offline
ping_result=$(ping -c 1 google.com)
if [ $? -eq 0 ]; then
    echo "The system is online."
else
    echo "The system is offline."
fi
