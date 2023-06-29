#!/bin/bash

# Example values
file=""
directory="data"


# Read the file name from the user
read -p "Enter the file name: " file

# Check if the file exists
[[ -f $file ]] && echo "$file exists." || echo "$file does not exist."

# Check if the directory exists
[[ -d $directory ]] && echo "$directory is a directory." || echo "$directory is not a directory."

# Check if the file exists and is readable
[[ -f $file ]] && [[ -r $file ]] && echo "$file is readable." || echo "$file is not readable."

# Check if the file is not writable
[[ -w $file ]] || echo "$file is not writable."

# Check if the file is executable and if it is not empty
[[ -x $file ]] && echo "$file is executable."
[[ -s $file ]] && echo "$file is not empty."


<<'MULTI_LINE_COMMENT'
The [[ ]] syntax is generally recommended for Bash scripts due to its enhanced capabilities,
such as pattern matching, logical operators, and better handling of variables.

However, if you're writing a script that needs to be POSIX-compatible and portable across different shells,
you may choose to use the [ ] syntax instead.

In summary, both [ -f $file ] and [[ -f $file ]] can be used, but the [[ ]] syntax offers more features
and convenience for Bash scripts.
MULTI_LINE_COMMENT
