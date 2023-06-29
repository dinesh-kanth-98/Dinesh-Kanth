#!/bin/bash

validate_email() {
    local email=$1
    local pattern="^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
    if [[ $email =~ $pattern ]]; then
        echo "Valid email: $email"
    else
        echo "Invalid email: $email"
    fi
}

# Test email addresses
validate_email "test@example.com"
validate_email "invalid_email"

<<'MULTI_LINE_COMMENT'
Explanation of the regular expression pattern (`^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$`):

- `^` asserts the start of the string.

- `[a-zA-Z0-9._%+-]+` matches one or more occurrences of alphanumeric characters, dots, underscores,
    percentage signs, plus signs, or hyphens. This represents the local part of the email address
    before the `@` symbol.
    
- `@` matches the literal `@` symbol.

- `[a-zA-Z0-9.-]+` matches one or more occurrences of alphanumeric characters, dots, or hyphens.
    This represents the domain name part of the email address.
    
- `\.` matches the literal dot `.` character. It needs to be escaped with a backslash 
    since `.` has a special meaning in regular expressions.\

- `[a-zA-Z]{2,}` matches two or more occurrences of alphabetic characters.
    This represents the top-level domain (TLD) of the email address.
    
- `$` asserts the end of the string.

MULTI_LINE_COMMENT
