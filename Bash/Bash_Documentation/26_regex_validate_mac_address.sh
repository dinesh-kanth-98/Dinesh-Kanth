```bash
#!/bin/bash

validate_mac_address() {
    local mac_address=$1
    local pattern="^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$"
    if [[ $mac_address =~ $pattern ]]; then
        echo "Valid MAC address: $mac_address"
    else
        echo "Invalid MAC address: $mac_address"
    fi
}

# Test MAC addresses
validate_mac_address "00:1B:44:11:3A:B7"
validate_mac_address "00-1B-44-11-3A-B7"
validate_mac_address "001B44113AB7"
validate_mac_address "00:1B:44:11:3A:B7:00" # Invalid - has more than 6 pairs


<<'MULTI_LINE_COMMENT'
Explanation of the regular expression pattern (`^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$`):

- `^` asserts the start of the string.

- `([0-9A-Fa-f]{2}[:-]){5}` matches a group of five occurrences of two hexadecimal
    characters (`0-9A-Fa-f`) followed by a colon `:` or hyphen `-`. This represents the
    first five pairs of the MAC address.
    
- `([0-9A-Fa-f]{2})` matches the final pair of two hexadecimal characters.
    This represents the last pair of the MAC address.
    
- `$` asserts the end of the string.

MULTI_LINE_COMMENT
