#!/bin/bash

# Read IP addresses from a file (one IP address per line)
filename="32_random_ip_addresses.txt"

while IFS= read -r ip; do
    echo "Checking $ip..."

    # Ping the IP address
    if ping -c 1 "$ip" >/dev/null 2>&1; then
        echo "$ip is up."
    else
        echo "$ip is down."
    fi

    echo
done < "$filename"
