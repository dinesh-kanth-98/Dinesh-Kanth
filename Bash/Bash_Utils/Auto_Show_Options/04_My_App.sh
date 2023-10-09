# Define the completion function for the 'myapp' command.
function _myapp()
{
    # Define an associative array to map subcommands to their completion options.
    declare -A COMMAND_MAPPING=(
        ["create"]="--name --file"
        ["delete"]="--force --quiet"
        ["list"]="--all --details"
        # Add more subcommands and their completion options here if needed.
    )

    # Define a list of available subcommands.
    local AVAILABLE_COMMANDS="create delete list"
    
    # Get the current word being typed by the user.
    local CURRENT_WORD=${COMP_WORDS[COMP_CWORD]}
    
    # Get the word immediately following 'myapp' (e.g., 'create' or 'delete').
    local WORD_AFTER_MYAPP=${COMP_WORDS[1]}

    # Initialize the completion reply array.
    COMPREPLY=()

    # If the current word is the first word after 'myapp'.
    if [ "$COMP_CWORD" -eq 1 ]; then
        # Provide completion options for subcommands.
        COMPREPLY=($(compgen -W "$AVAILABLE_COMMANDS" -- "$CURRENT_WORD"))
    # If the current word is after a recognized subcommand.
    elif [[ -n "${COMMAND_MAPPING[$WORD_AFTER_MYAPP]}" ]]; then
        # Provide completion options for the specific subcommand.
        COMPREPLY=($(compgen -W "${COMMAND_MAPPING[$WORD_AFTER_MYAPP]}" -- "$CURRENT_WORD"))
    # If the current word is not a recognized subcommand.
    else
        # Provide generic file-based completion options (e.g., files in the current directory).
        COMPREPLY=($(compgen -W "$(ls)" -- "$CURRENT_WORD"))
    fi 
}

function myapp()
{
    echo "hello"
}

# Register the completion function for the 'myapp' command.
complete -F _myapp myapp
