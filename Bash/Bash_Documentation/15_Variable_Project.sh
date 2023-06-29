#!/bin/bash

# Store the start time in seconds since the Unix epoch
START=$(date +%s)
echo "start time: ${START}"

# Print the current working directory
pwd

# Pause the script execution for 2 seconds
sleep 2

# Store the end time in seconds since the Unix epoch
END=$(date +%s)
echo "end time: ${END}"

# Calculate the time taken by subtracting the start time from the end time
TIME_TAKEN=$((END - START))

# Print the time taken to execute the script
echo "time taken to execute the script: ${TIME_TAKEN} seconds"
