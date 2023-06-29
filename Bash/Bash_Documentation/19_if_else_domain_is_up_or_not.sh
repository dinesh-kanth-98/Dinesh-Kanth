#!/bin/bash

# Read the domain from the user
read -p "Enter the domain to check: " domain

# Ping the domain and capture the result
ping_result=$(ping -c 1 $domain)

# Check the exit status of the ping command
if [ $? -eq 0 ]; then
    echo "Domain $domain is up."
else
    echo "Domain $domain is down."
fi
