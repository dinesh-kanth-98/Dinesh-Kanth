**<div align="center" >Auto_Complete_Script_commands_Example</div>**

### Table of Contents
- [Example:](#example)
- [Explanation:](#explanation)

# Example:

```bash
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
```

# Explanation:

1. The script is a Bash shell script that defines a command-line tool called `mugger`. You should replace the `mugger` function with your actual command logic.

2. The `_runtime` function is defined to handle tab-completion for the `mugger` command. It provides suggestions for subcommands and options as the user types.

3. An associative array `COMMAND_MAPPING` is used to map subcommands to their associated completion options. In this example, the `commit` subcommand has associated options `--amed` and `--no-edit`.

4. The `AVAILABLE_COMMANDS` variable lists the available subcommands for the `mugger` command. You can customize this list with your specific subcommands.

5. The completion function checks the current word being typed by the user, the word following `mugger`, and provides completion suggestions accordingly.

6. If the current word is the first word after `mugger`, it suggests available subcommands. If it's after a recognized subcommand, it suggests completion options. If it's neither, it suggests generic file-based completion options.

7. The completion function is registered using the `complete` command, associating `_runtime` with the `mugger` command. This enables tab-completion for the `mugger` command when the script is sourced or executed.

8. Finally, comments throughout the script provide explanations of each section and guide you on how to customize it for your specific use case.