**<div align="center" >Linux Administrator Documentation</div>**

## Table of content
- [echo](#echo)
  - [echo options](#echo-options)
  - [echo escape sequences](#echo-escape-sequences)
- [Brace expansion](#brace-expansion)
  - [Basic Syntax:](#basic-syntax)
  - [Number Sequences:](#number-sequences)
  - [Character Sequences:](#character-sequences)
  - [Incrementing Values:](#incrementing-values)
  - [Multiple Patterns:](#multiple-patterns)
  - [Nested Brace Expansion:](#nested-brace-expansion)
  - [Command Substitution with Brace Expansion:](#command-substitution-with-brace-expansion)
- [xargs](#xargs)
  - [Key Features and Usage:](#key-features-and-usage)
  - [Basic Examples:](#basic-examples)
    - [Delimiters and Input Parsing:](#delimiters-and-input-parsing)
    - [Echoing Arguments:](#echoing-arguments)
    - [Reading Input from a File and Passing Arguments to a Command:](#reading-input-from-a-file-and-passing-arguments-to-a-command)
    - [Reading File Names from Stdin and Deleting Them:](#reading-file-names-from-stdin-and-deleting-them)
  - [Advance Examples:](#advance-examples)
    - [Parallel Execution:](#parallel-execution)
    - [Simple Interactive Mode and Confirmation:](#simple-interactive-mode-and-confirmation)
    - [Advanced Interactive Mode and Confirmation:](#advanced-interactive-mode-and-confirmation)
    - [Running a Command with Multiple Arguments:](#running-a-command-with-multiple-arguments)
    - [Batching and Argument Limits:](#batching-and-argument-limits)
- [find](#find)
  - [Options:](#options)
  - [Tests:](#tests)
  - [Actions:](#actions)
  - [Examples](#examples)
- [tr](#tr)
  - [common use cases and examples](#common-use-cases-and-examples)
  - [Examples](#examples-1)
- [grep](#grep)
  - [options](#options-1)
  - [Examples](#examples-2)

# echo

The `echo` command in Linux is a built-in command that is used to display text or variables on the terminal or in a script. It takes the input string as an argument and outputs it as text. The `echo` command is commonly used for printing messages, displaying variable values, or generating output within shell scripts.

The basic syntax of the `echo` command is:
```bash
echo [OPTIONS] [STRING]
```

Here, `[OPTIONS]` represents optional flags that modify the behavior of the `echo` command, and `[STRING]` is the text or variable you want to display.

By default, the `echo` command adds a newline character at the end of the output, which means that each `echo` command starts on a new line.

Example usages of the `echo` command:

1. Printing a message:
   ```bash
   echo "Hello, world!"
   ```
   Output:
   ```
   Hello, world!
   ```

2. Displaying the value of a variable:
   ```bash
   name="John"
   echo "My name is $name"
   ```
   Output:
   ```
   My name is John
   ```
---
## echo options

The available options for the `echo` command are `-n` and `-e`. <br>
Here are examples demonstrating the usage of the `-n` and `-e` options:

1. **Using the `-n` option**:
   ```bash
   echo -n "Hello, "
   echo "World!"
   ```
   Output:
   ```
   Hello, World!
   ```
   **Explanation**: The `-n` option suppresses the trailing newline character, allowing multiple `echo` statements to appear on the same line. In this example, the first `echo` statement prints "Hello, " without a newline, and the second `echo` statement continues on the same line, printing "World!".

2. **Using the `-e` option**:
   ```bash
   echo -e "This is a\ttabbed\tline."
   ```
   Output:
   ```
   This is a    tabbed   line.
   ```

   **Explanation**: The `-e` option enables the interpretation of backslash escapes in the input string. In this example, the `\t` escape sequence is used to insert horizontal tabs between the words, resulting in a tabbed line.

## echo escape sequences

The `echo` command in Linux supports a few escape sequences that allow you to include special characters in the output. Here are the available escape sequences for the `echo` command:

- `\n`: Inserts a newline character.
- `\t`: Inserts a horizontal tab character.
- `\r`: Inserts a carriage return character.
- `\\`: Inserts a backslash character.
- `\"`: Inserts a double quote character.
- `\'`: Inserts a single quote character.
- `\b`: Moves the cursor back one position (backspace).
- `\f`: Inserts a form feed character.
- `\v`: Inserts a vertical tab character.

Here are some examples demonstrating the usage of escape sequences with the `echo` command:

1. **Newline and tab**:
   ```bash
   echo -e "Line 1\nLine 2\tTabbed"
   ```
   Output:
   ```
   Line 1
   Line 2    Tabbed
   ```

2. **Backslash and double quote**:
   ```bash
   echo -e "This is a backslash: \\ and this is a double quote: \""
   ```
   Output:
   ```
   This is a backslash: \ and this is a double quote: "
   ```

3. **Vertical Tab (`\v`)**:
   ```bash
   echo -e "Line 1\vLine 2"
   ```
   Output:
   ```
   Line 1
           Line 2
   ```

   **Explanation**:<br> 
   The `\v` escape sequence inserts a vertical tab character, which causes subsequent text to be displayed vertically shifted. In this example, "Line 2" is displayed below "Line 1" but shifted to the right.

4. **Carriage Return (`\r`)**:
   ```bash
   echo -e "Hello\rWorld"
   ```
   Output:
   ```
   World
   ```

   **Explanation**: The `\r` escape sequence moves the cursor to the beginning of the line, causing the subsequent text ("World") to overwrite the previous text ("Hello").

5. **Backspace (`\b`)**:
   ```bash
   echo -e "Counting: 1\b0\b0\b2"
   ```
   Output:
   ```
   Counting: 102
   ```

   **Explanation**:<br> The `\b` escape sequence moves the cursor back one position, allowing you to overwrite characters. In this example, it first backspaces from "1" to "0" and then backspaces again to replace the "0" with "2".

6. **Form Feed (`\f`)**:
   ```bash
   echo -e "Page 1\fPage 2"
   ```
   Output:
   ```
   Page 2
   ```

   **Explanation**:<br>
   The `\f` escape sequence inserts a form feed character, which is often used to indicate a page break. In this example, the output is displayed as if the text "Page 2" is on a new page.

These are some commonly used escape sequences with the `echo` command. They allow you to include special characters, control characters, and format your output in a desired way.

> Remember to use the `-e` option with `echo` to enable the interpretation of backslash escapes.

>  The `echo` command is a versatile tool that allows you to display text and generate output within shell scripts and command-line operations. It is commonly used for various purposes such as printing messages, displaying variable values, generating formatted output, and more.

# Brace expansion

Brace expansion is a powerful feature in shell scripting that allows you to generate a series of strings or numbers based on a specified pattern inside curly braces `{}`. The shell expands this pattern into the corresponding sequence, providing a concise and convenient way to generate multiple values.

Here are the key details about brace expansion:

## Basic Syntax:

   ```vbnet
   {START..END}
   ```

   The pattern consists of a starting value (`START`), an optional increment, and an ending value (`END`).

## Number Sequences:

   ```bash
   echo {1..5}
   ```
   Output:
   ```
   1 2 3 4 5
   ```
   This example generates a sequence of numbers from 1 to 5.

## Character Sequences:

   ```bash
   echo {A..E}
   ```
   Output:
   ```
   A B C D E
   ```
   This example generates a sequence of characters from A to E.

## Incrementing Values:

   - **First Example**:
      ```bash
      echo {10..20..2}
      ```
      Output:
      ```
      10 12 14 16 18 20
      ```
   -  **Second Example**:
      ```bash
      echo {A..Z..3}
      ```
      Output:
      ```
      A D G J M P S V Y
      ```
   By specifying an increment value (`2` in this example), you can generate a sequence with a specific step between the values.

## Multiple Patterns:

   ```bash
   echo {apples,bananas,cherries}
   ```
   Output:
   ```
   apples bananas cherries
   ```
   This example generates a list of strings based on the provided patterns, separated by spaces.

## Nested Brace Expansion:

   - **First Example**:
      ```bash
      echo {a,b{1..3},c}
      ```
      Output:
      ```
      a b1 b2 b3 c
      ```
   -  **Second Example**:
      ```bash
      echo {X,Y,z}{1..3}
      ```
      Output:
      ```
      X1 X2 X3 Y1 Y2 Y3 z1 z2 z3
      ```

   - **Third Example**:
       ```bash
      echo {A..C}{1..3}
      ```
      Output:
      ```
      A1 A2 A3 B1 B2 B3 C1 C2 C3
      ```
   - **Fourth Example**:
      ```bash
      mkdir {src,inc,tests}/{dir1,dir2,dir3}
      ```
      This command creates the directories `src/dir1`, `src/dir2`, `src/dir3`, `inc/dir1`, `inc/dir2`, `inc/dir3`, `tests/dir1`, `tests/dir2`, and `tests/dir3`.

   > Brace expansion can be nested, allowing for more complex patterns and combinations.

## Command Substitution with Brace Expansion:
   ```bash
   echo {$(ls)}
   ```
   Output:
   ```
   file1.txt file2.txt file3.txt
   ```
   Brace expansion can also include command substitution, where the output of a command is used as part of the expansion.

> It's important to note that brace expansion is performed by the shell before any other expansions or evaluations. Therefore, it operates purely on the provided pattern and does not interpret any variables or special characters within the braces.


# xargs
The `xargs` command is a powerful utility in Unix-like operating systems that reads items from standard input (stdin) or another input source and executes a specified command with those items as arguments. It allows you to handle and process input data that is too large or complex to be handled directly by a single command.

**Basic Syntax**:
```bash
xargs [options] [command]
```

## Key Features and Usage:

1. **Handling Input Arguments:**
   - By default, `xargs` takes input from stdin and treats each line or item as a separate argument for the command it executes.
   - Alternatively, you can specify the input source using the `-a` option, followed by the file name.
   - You can also provide input arguments directly after the command, and `xargs` will use them as input.

2. **Command Execution:**
   - `xargs` executes the specified command for each input item received.
   - By default, it appends the input items as arguments to the command.
   - The placeholder `{}` is used within the command to represent the input items.
   - If the command expects input from stdin, you can use the `-I` option to specify a custom placeholder instead of `{}`.
3. **Batching and Argument Limits:**
   - `xargs` allows you to control the number of arguments passed to each command invocation using the `-n` option.
   - You can specify a maximum number of arguments per command, such as `-n 5`, to process items in batches.
   - Similarly, you can use the `-s` option to limit the size (in bytes) of the arguments passed.

4. **Delimiters and Input Parsing:**
   - By default, `xargs` treats spaces, tabs, and newline characters as delimiters between input items.
   - You can modify the delimiter character(s) using the `-d` option, followed by the desired delimiter.
   - This is useful when dealing with input that contains spaces or special characters.

5. **Other Useful Options:**
   - `-p`: Interactive mode. Asks for confirmation before executing each command.
   - `-r`: Prevents running the command if there are no input items.
   - `-t`: Prints the command to be executed before running it.
   - `-I`: Specifies a custom placeholder for the input items in the command.

## Basic Examples:
Here are basic examples covering various aspects of the `xargs` command:

### Delimiters and Input Parsing:
```bash
echo "apple,banana,orange" | xargs -d ',' echo
```
This example sets the delimiter to a comma (`-d ','`) and passes the input string `"apple,banana,orange"` to `xargs`. The `echo` command is executed with each item (`apple`, `banana`, `orange`) as separate arguments.

### Echoing Arguments:
```bash
echo "Hello World" | xargs echo
```
In this example, the input string `"Hello World"` is passed to `xargs`, which then executes the `echo` command with the input as arguments. The output will be `Hello World`.

### Reading Input from a File and Passing Arguments to a Command:
```bash
cat filenames.txt | xargs rm
```
This example uses `cat` to read the content of the file `filenames.txt` and passes each line as an argument to `xargs`. The `rm` command is then executed to delete the files specified in the file.

### Reading File Names from Stdin and Deleting Them:
```
find . -name "*.txt" | xargs rm
```
Here, the `find` command is used to locate all files with the `.txt` extension in the current directory and its subdirectories. The file names are then passed to `xargs`, which executes the `rm` command to delete each file.


## Advance Examples:

Certainly! Here's an explanation of the advanced options and features of the `xargs` command:

### Parallel Execution:
The `-P` option allows you to specify the maximum number of commands to run in parallel. For example:
```bash
find . -name "*.txt" | xargs -P 4 -I {} cp {} /destination/path/
```
In this example, `xargs` executes the `cp` command to copy each file with a `.txt` extension to the `/destination/path/`. The `-P 4` option specifies that up to 4 copies of the command can be run in parallel.

### Simple Interactive Mode and Confirmation:
The `-p` option prompts for confirmation before executing each command. For example:
```bash
ls | xargs -p -n 1 -I {} mv {} {}.bak
```
This example lists all files in the current directory using `ls`. The file names are then passed to `xargs`, which prompts for confirmation (`-p`) before executing each `mv` command. The `-n 1` option specifies that one argument is passed to each `mv` command.

### Advanced Interactive Mode and Confirmation:
The `-t` option prints the command before executing it. For example:
```bash
ls | xargs -t -n 1 -I {} mv {} {}.bak
```
In this example, `xargs` prints the `mv` command for each file before executing it, providing a preview of the command to be run.

### Running a Command with Multiple Arguments:
The `-n` option specifies the maximum number of arguments passed to each command. For example:
```bash
cat filelist.txt | xargs -n 2 echo
```
Here, `xargs` reads the content of `filelist.txt` and passes two arguments at a time to the `echo` command. This allows you to process pairs of lines from the file simultaneously.

### Batching and Argument Limits:
The `-n` option specifies the maximum number of arguments passed to each command. For example:
```bash
find . -type f | xargs -n 100 echo
```
In this example, `find` locates all files in the current directory and its subdirectories. The file names are then passed to `xargs`, which executes the `echo` command with a maximum of 100 file arguments at a time.

> explore further possibilities by referring to the `xargs` manual page (`man xargs`) for more options and detailed information.


# find

The `find` command is a powerful tool in Linux and Unix-like operating systems used to search for files and directories based on various criteria. It traverses a directory hierarchy recursively and performs actions on the matched files or directories.

The basic syntax of the `find` command is as follows:
```css
find [path] [expression]
```

Here's an explanation of the key components of the `find` command:

- **`path`:** This specifies the starting directory or directories for the search. If not specified, the current directory is assumed.

- **`expression`:** This defines the conditions or tests to be applied during the search. It consists of various options, tests, and actions.

Let's explore some commonly used options and tests with the `find` command:

## Options:

- `-name pattern`: Matches files or directories with a specific name pattern. The pattern can include wildcards such as `*` (matches any characters) and `?` (matches any single character). Example: `-name "*.txt"` matches all files with the `.txt` extension.

- `-type type`: Matches files or directories of a specific type. The `type` can be `f` for regular files, `d` for directories, `l` for symbolic links, and more.

- `-mtime n`: Matches files or directories modified `n` days ago. Use `-n` for files modified more than `n` days ago, and `+n` for files modified older than `n` days.

- `-size n[c]`: Matches files of size `n` units. The `c` is an optional character that represents the unit (`c` for bytes, `k` for kilobytes, `M` for megabytes, `G` for gigabytes, etc.). Example: `-size +1M` matches files larger than 1 megabyte.

## Tests:

- `-exec command {} +`: Executes the specified `command` on the matched files or directories. The `{}` placeholder represents the file or directory name. The `+` indicates that the command is run with as many arguments as possible, similar to the `xargs` command.

- `-print`: Prints the matched file or directory path. This is the default action if no other action is specified.

- `-empty`: Matches empty files or directories.

- `-perm mode`: Matches files with specific permissions. The `mode` can be specified in octal format. Example: `-perm 644` matches files with permission `644`.

## Actions:

- `-delete`: Deletes the matched files or directories.

- `-execdir command {} \;`: Executes the specified `command` on the matched files or directories from their respective directories.

- `-ok command {} \;`: Similar to `-exec`, but prompts for confirmation before executing the command.

## Examples 

Examples that cover different options and tests of the `find` command for documentation purposes:

1. Find all files with a specific extension (`-name`):
   ```bash
   find /path/to/directory -type f -name "*.txt"
   ```

2. Find all directories with a specific name (`-name`):
   ```bash
   find /path/to/directory -type d -name "docs"
   ```

3. Find all files modified within the last 7 days (`-mtime`):
   ```bash
   find /path/to/directory -type f -mtime -7
   ```

4. Find all empty files and directories (`-empty`):
   ```bash
   find /path/to/directory -empty
   ```

5. Find all files with specific permissions (`-perm`):
   ```bash
   find /path/to/directory -type f -perm 644
   ```

6. Find all files larger than 1 megabyte (`-size`):
   ```bash
   find /path/to/directory -type f -size +1M
   ```

7. Find files with a specific name pattern and delete them (`-exec`):
   ```bash
   find /path/to/directory -type f -name "temp*.txt" -exec rm {} +
   ```

8. Find files matching multiple conditions using logical operators (`-a` for AND, `-o` for OR):
   ```bash
   find /path/to/directory \( -name "*.txt" -a -size +1M \) -o \( -name "*.log" -a -mtime +7 \)
   ```

9. Find files using the `print` action:
   ```bash
   find /path/to/directory -type f -name "*.txt" -print
   ```

10. Find files interactively and prompt for confirmation before deleting (`-ok`):
    ```bash
    find /path/to/directory -type f -name "*.tmp" -ok rm {} \;
    ```

11. Find a specific line in specific files:
you can use the combination of the `grep` and `find` commands. Here's an example:

    ```bash
    find /path/to/directory -type f -name "*.txt" -exec grep -n "search_pattern" {} +
    ```

    In this example:
    - `/path/to/directory` represents the starting directory for the search. Replace it with the actual path to the directory where you want to search for files.
    - `-type f` matches regular files.
    - `-name "*.txt"` matches files with the `.txt` extension. You can modify the extension or remove this option to search for files with different extensions or all files.
    - `-exec grep -n "search_pattern" {} +` executes the `grep` command on the matched files. Replace `"search_pattern"` with the specific line you want to search for within the files. The `-n` option with `grep` displays line numbers in the output.


> These examples cover different scenarios of using the `find` command with various options and tests. Adapt them to suit your specific documentation needs and explore further possibilities by referring to the `find` command's manual page (`man find`) for more options and detailed information.


# tr
The `tr` command in Linux and Unix-like operating systems is used to translate or delete characters from standard input or a file. It can be used to perform simple character-based transformations on text data.

The basic syntax of the `tr` command is as follows:
```bash
tr [options] SET1 [SET2]
```

Here's an explanation of the key components of the `tr` command:

- **`options`:** These are optional flags that modify the behavior of the `tr` command. Some commonly used options include:
  - `-c` or `--complement`: Inverts the translation, replacing characters not found in `SET1` with characters from `SET2`.
  - `-d` or `--delete`: Deletes characters found in `SET1`, not performing any translation.
  - `-s` or `--squeeze-repeats`: Squeezes multiple consecutive occurrences of a character in `SET1` to a single occurrence.
  - `-t` or `--truncate-set1`: Truncates `SET1` if it is longer than `SET2`.

- **`SET1`:** This represents the set of characters to be translated or deleted.

- **`SET2`:** This represents the replacement set of characters. It is optional and only used when performing character translation.

## common use cases and examples

common use cases and examples of the `tr` command:

1. **Character Translation**:
   - Translate all lowercase letters to uppercase:
     ```bash
     echo "hello world" | tr '[:lower:]' '[:upper:]'
     ```
     Output: `HELLO WORLD`

   - Translate specific characters:
     ```bash
     echo "Hello, world!" | tr 'eo' 'EO'
     ```
     Output: `HEllo, wOrld!`

2. **Character Deletion**:
   - Delete specific characters:
     ```bash
     echo "Hello, world!" | tr -d 'o'
     ```
     Output: `Hell, wrld!`

   - Delete newline characters:
     ```bash
     cat file.txt | tr -d '\n'
     ```

3. **Character Squeezing**:
   - Squeeze repeated consecutive characters to a single occurrence:
     ```bash
     echo "Hello,    world!" | tr -s ' '
     ```
   Output: `Hello, world!` 

4. **Complement Translation**:
   - Replace characters not found in `SET1` with a specific character:
     ```bash
     echo "123abc456" | tr -c '[:digit:]' 'X'
     ```
     Output: `XXXabcXXX`


## Examples

Here are the `tr` command examples along with their respective outputs:

1. Translate lowercase letters to uppercase:
   ```shell
   $ echo "hello world" | tr '[:lower:]' '[:upper:]'
   Output: HELLO WORLD
   ```

2. Translate specific characters:
   ```shell
   $ echo "Hello, world!" | tr 'eo' 'EO'
   Output: HEllo, wOrld!
   ```

3. Delete specific characters:
   ```shell
   $ echo "Hello, world!" | tr -d 'o'
   Output: Hell, wrld!
   ```

4. Delete newline characters:
   ```shell
   $ cat file.txt | tr -d '\n'
   Output: <contents of file.txt without newline characters>
   ```

5. Squeeze repeated consecutive spaces to a single space:
   ```shell
   $ echo "Hello,    world!" | tr -s ' '
   Output: Hello, world!
   ```

6. Replace characters not found in `SET1` with a specific character:
   ```shell
   $ echo "123abc456" | tr -c '[:digit:]' 'X'
   Output: XXXabcXXX
   ```

7. Translate a range of characters to a different range:
   ```shell
   $ echo "abc123xyz" | tr 'a-z' 'A-Z'
   Output: ABC123XYZ
   ```

8. Complement translation, replacing characters not found in `SET1` with characters from `SET2`:
   ```shell
   $ echo "123abc456" | tr -c '[:digit:]' '@'
   Output: @@@abc@@@
   ```

9. Truncate `SET1` if it is longer than `SET2`:
   ```shell
   $ echo "Hello, world!" | tr -t 'Hlo' '123'
   Output: 1e3 3or3!1
   ```

10. Translate octal values to ASCII characters:
    ```shell
    $ echo "141 142 143" | tr ' ' '\n' | tr -d '\n' | xargs -n 1 printf "\\%03o"
    Output: abc
    ```

# grep

The `grep` command in Linux and Unix-like operating systems is used to search for patterns in text files or streams. It stands for "Global Regular Expression Print" and is a powerful tool for pattern matching and filtering.

The basic syntax of the `grep` command is as follows:
```css
grep [options] pattern [file...]
```
## options

Here's an explanation of the key components of the `grep` command:

- **`options`:** These are optional flags that modify the behavior of the `grep` command. Some commonly used options include:
   - `-c` or `--count`: Displays only the count of matching lines rather than the actual lines.
   - `-e pattern` or `--regexp=pattern`: Allows specifying multiple patterns to search for.
   - `-f file` or `--file=file`: Reads patterns from a file instead of providing them directly on the command line.
   - `-i` or `--ignore-case`: Ignores case distinctions, making the pattern matching case-insensitive.
   - `-v` or `--invert-match`: Inverts the match, displaying lines that do not match the pattern.
   - `-r` or `--recursive`: Recursively searches directories for files matching the pattern.
   - `-l` or `--files-with-matches`: Prints only the names of files that contain matches.
   - `-n` or `--line-number`: Prefixes each line of output with its line number.
   - `-o` or `--only-matching`: Prints only the matching part of the line instead of the entire line.
   - `-B num` or `--before-context=num`: Prints `num` lines of leading context before each match.
   - `-A num` or `--after-context=num`: Prints `num` lines of trailing context after each match.
   - `-C[num]` or `--context[=num]`: Prints `num` lines of leading and trailing context around each match.
   - `-q` or `--quiet` or `--silent`: Quiet mode, suppresses normal output. Returns only the exit status.
   - `-s` or `--no-messages`: Suppresses error messages about nonexistent or unreadable files.
   - `-w` or `--word-regexp`: Matches only whole words that match the pattern.
   - `-x` or `--line-regexp`: Matches only entire lines that match the pattern.


- **`pattern`:** This represents the regular expression or string pattern to search for. It can be a simple string or a complex pattern using regular expressions.

- **`file...`:** These are optional file arguments specifying the files to search. If no file is provided, `grep` reads from standard input.

## Examples

Examples of the `grep` command along with sample outputs:

- `-c` or `--count`: Displays only the count of matching lines rather than the actual lines.
  ```shell
  $ grep -c "pattern" file.txt
  Output: 3
  ```

- `-e pattern` or `--regexp=pattern`: Allows specifying multiple patterns to search for.
  ```shell
  $ grep -e "pattern1" -e "pattern2" file.txt
  Output: <lines matching pattern1 or pattern2>
  ```

- `-f file` or `--file=file`: Reads patterns from a file instead of providing them directly on the command line.
  ```shell
  $ grep -f patterns.txt file.txt
  Output: <lines matching patterns from the patterns.txt file>
  ```

- `-n` or `--line-number`: Prefixes each line of output with its line number.
  ```shell
  $ grep -n "pattern" file.txt
  Output: 1: This is a line with pattern
          4: Another line with pattern
  ```

- `-o` or `--only-matching`: Prints only the matching part of the line instead of the entire line.
  ```shell
  $ grep -o "pattern" file.txt
  Output: pattern
           pattern
  ```

- `-i` or `--ignore-case`: Ignores case distinctions, making the pattern matching case-insensitive.
  ```shell
  $ grep -i "pattern" file.txt
  Output: This is a line with Pattern
          Another line with pattern
  ```

- `-v` or `--invert-match`: Inverts the match, displaying lines that do not match the pattern.
  ```shell
  $ grep -v "pattern" file.txt
  Output: This line does not match the pattern
          Some other line
  ```

- `-r` or `--recursive`: Recursively searches directories for files matching the pattern.
  ```shell
  $ grep -r "pattern" directory/
  Output: <lines matching the pattern in files within the directory tree>
  ```

- `-l` or `--files-with-matches`: Prints only the names of files that contain matches.
  ```bash
  $ grep -l "pattern" file1.txt file2.txt
  Output: file1.txt
  ```

> These examples illustrate the usage of additional options of the `grep` command and provide the corresponding outputs for each command. Modify them as per your specific needs and explore further possibilities by referring to the `grep` command's manual page (`man grep`) for more options and detailed information.
