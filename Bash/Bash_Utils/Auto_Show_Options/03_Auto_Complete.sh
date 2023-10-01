#!/bin/bash

# Define the 'mugger' function. Replace this with your actual command implementation.
function mugger()
{
    echo "mugger function (replace with your command logic)"
}

# Define the completion function for the 'mugger' command.
function _runtime()
{
    # Define an associative array to map subcommands to their completion options.
    declare -A COMMAND_MAPPING=(
        ["commit"]="--amed --no-edit"
        # Add more subcommands and their completion options here if needed.
    )

    # Define a list of available subcommands.
    local AVAILABLE_COMMANDS="add commit"
    
    # Get the current word being typed by the user.
    local CURRENT_WORD=${COMP_WORDS[COMP_CWORD]}
    
    # Get the word immediately following 'mugger' (e.g., 'add' or 'commit').
    local WORD_AFTER_MUGGER=${COMP_WORDS[1]}

    # Initialize the completion reply array.
    COMPREPLY=()

    # If the current word is the first word after 'mugger'.
    if [ "$COMP_CWORD" -eq 1 ]; then
        # Provide completion options for subcommands.
        COMPREPLY=($(compgen -W "$AVAILABLE_COMMANDS" -- "$CURRENT_WORD"))
    # If the current word is after a recognized subcommand.
    elif [[ -n "${COMMAND_MAPPING[$WORD_AFTER_MUGGER]}" ]]; then
        # Provide completion options for the specific subcommand.
        COMPREPLY=($(compgen -W "${COMMAND_MAPPING[$WORD_AFTER_MUGGER]}" -- "$CURRENT_WORD"))
    # If the current word is not a recognized subcommand.
    else
        # Provide generic file-based completion options (e.g., files in the current directory).
        COMPREPLY=($(compgen -W "$(ls)" -- "$CURRENT_WORD"))
    fi 
}

# Register the completion function for the 'mugger' command.
complete -F _runtime mugger

# The script above defines a completion function for the 'mugger' command. 
# The completion function provides tab-completion suggestions for subcommands and options.
# Customize the 'mugger' function and add more subcommands/options as needed.
# With the Same Name Of second Argumrnt Functionn needed
