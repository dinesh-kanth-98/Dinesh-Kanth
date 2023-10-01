**<div align="center" >Enabling Tab Completion for Script Options in Bash</div>**

### Table of Contents
- [Enabling Tab Completion for Script Options in Bash](#enabling-tab-completion-for-script-options-in-bash)
  - [Method 1: Using the `complete` Command](#method-1-using-the-complete-command)
    - [Basic Usage](#basic-usage)
    - [Example](#example)
  - [Method 2: Using a Completion Function](#method-2-using-a-completion-function)
    - [Define the Completion Function](#define-the-completion-function)
    - [Enable the Completion Function](#enable-the-completion-function)
  - [Final Steps](#final-steps)


# Enabling Tab Completion for Script Options in Bash

Tab completion is a helpful feature that allows users to quickly select from a predefined list of options or arguments when they press the Tab key twice (double tab) after entering part of an option or argument in a shell. This functionality enhances the user experience and ensures that users provide valid inputs to your scripts. This guide explains how to enable tab completion for script options in Bash.

## Method 1: Using the `complete` Command

### Basic Usage

The `complete` command is a straightforward way to enable double-tab completion for a script's options or arguments. Here's how it works:

```bash
complete -W "option1 option2 option3" your_script.sh
```

- `complete`: This is the command used to configure tab completion.
- `-W`: Specifies that you are providing a list of words to complete from.
- `"option1 option2 option3"`: Replace this with the actual list of options or arguments that your script accepts.
- `your_script.sh`: Replace this with the name of your script.

### Example

Let's say you have a script called `my_script.sh` that accepts the options `-h`, `--help`, `-v`, and `--version`. You can enable tab completion for these options like this:

```bash
complete -W "-h --help -v --version" my_script.sh
```

Now, when you run `my_script.sh` and type `-` followed by Tab twice, it will display `-h` and `--help` as completion options.

**Usage After Sourcing:**

1. Source your script:

   ```bash
   source my_script.sh
   ```

2. Run your script:

   ```bash
   my_script.sh -<Tab><Tab>
   ```

   After sourcing your script, you can use tab completion as described above.

## Method 2: Using a Completion Function

For more complex cases or when you need dynamic completion, you can define a completion function in your script. Here's how:

### Define the Completion Function

In your script (e.g., `your_script.sh`), define a completion function that generates completion candidates based on the user's input:

```bash
your_script() {
   echo "script code"
}
_your_script_completion() {
   local options="option1 option2 option3"
   COMPREPLY=($(compgen -W "$options" -- "${COMP_WORDS[COMP_CWORD]}"))
}
```

- `_your_script_completion`: This is the name of your completion function.
- `local options`: Define a variable to hold the list of valid options or arguments.
- `COMPREPLY`: An array that stores the completion candidates.
- `compgen -W "$options" -- "${COMP_WORDS[COMP_CWORD]}"`: This command generates the completion candidates based on the user's input and the list of options.

### Enable the Completion Function

Use the `complete` command to associate the completion function with your script:

```bash
complete -F _your_script_completion your_script
```

- `-F _your_script_completion`: Specifies that you want to use the `_your_script_completion` function for completion.
- `your_script`: Replace this with the name of your script. 

<br>

> **`NOTE`**:
>  - As observed, when using the `complete` command, it is essential to provide a function name as the third argument. Without specifying a function name and body(**may be dummy function**), auto-completion won't work as expected.


**Usage After Sourcing:**

1. Source your script:

   ```bash
   source your_script.sh
   ```

2. Run your script:

   ```bash
   your_script.sh -<Tab><Tab>
   ```

   After sourcing your script, you can use tab completion as described above.

## Final Steps

By using either of these methods, you can enhance the usability of your scripts by providing users with tab-completion support for script options and arguments, making it easier for them to interact with your command-line tools.