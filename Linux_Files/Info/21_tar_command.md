**<div align="center" >About tar command</div>**

### Table of content

- [**tar**](#tar)
  - [**Usage:**](#usage)
  - [**Common Options:**](#common-options)
  - [**Examples:**](#examples)
  - [**Notes:**](#notes)

# **tar**

`tar` is a command-line utility in Unix-like operating systems used for creating and manipulating archive files. The name "tar" stands for "tape archive," which reflects its historical use for backing up data to tape drives. Nowadays, it's commonly used for compressing and archiving files and directories. Below is a brief documentation of the `tar` command:

## **Usage:**

```bash
tar [OPTION...] [FILE]...
```

## **Common Options:**

- `-c, --create`: Create a new archive.
- `-x, --extract, --get`: Extract files from an archive.
- `-v, --verbose`: Verbosely list the files processed.
- `-f, --file=ARCHIVE`: Specify the archive file's name.
- `-z, --gzip`: Filter the archive through gzip for compression (commonly used for `.tar.gz` files).
- `-j, --bzip2`: Filter the archive through bzip2 for compression (commonly used for `.tar.bz2` files).
- `-t, --list`: List the contents of an archive.
- `-r, --append`: Append files to the end of an archive.
- `-u, --update`: Append files to the archive if they are newer than the copy in the archive.
- `--delete`: Delete from the archive (not widely supported).
- `-A, --catenate, --concatenate`: Add one archive to another.
- `--wildcards`: Use wildcards in file selection.
- `--exclude=PATTERN`: Exclude files that match the pattern.
- `--strip-components=NUMBER`: Remove the specified number of leading path components.
- `--directory=DIR`: Change to the specified directory before processing the archive.

## **Examples:**

1. Create a `.tar` archive of a directory:

   ```bash
   tar -cvf archive.tar directory/
   ```

2. Extract files from a `.tar` archive:

   ```bash
   tar -xvf archive.tar
   ```

3. Create a `.tar.gz` compressed archive:

   ```bash
   tar -czvf archive.tar.gz directory/
   ```

4. Extract files from a `.tar.gz` compressed archive:

   ```bash
   tar -xzvf archive.tar.gz
   ```

5. Append files to an existing archive:

   ```bash
   tar -rvf archive.tar newfile.txt
   ```

6. List the contents of an archive:

   ```bash
   tar -tvf archive.tar
   ```

## **Notes:**

- You can combine options, e.g., `-czvf` to create a compressed archive.
- The order of options may matter, especially when dealing with archived files.
- The `tar` command is highly versatile and can handle various archive formats, compression methods, and options. It's a powerful tool for creating and managing archives in Unix-based systems.

For more detailed information and advanced usage, you can refer to the `tar` manual page using the command `man tar`. This will provide you with extensive documentation and usage examples.
