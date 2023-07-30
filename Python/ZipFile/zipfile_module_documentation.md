**<div align="center" >Intro to zipfile</div>**

### Table of content
- [Overview](#overview)
- [Importing the Module](#importing-the-module)
- [Classes](#classes)
  - [`zipfile.ZipFile`](#zipfilezipfile)
  - [Constructor](#constructor)
  - [Methods](#methods)
- [`zipfile.ZipInfo`](#zipfilezipinfo)
  - [Properties](#properties)
- [Constants](#constants)
- [Examples](#examples)
- [Compresslevel](#compresslevel)
- [Conclusion](#conclusion)

This module provides tools to create, read, write, append, and manipulate ZIP archives.

## Overview

The `zipfile` module allows you to work with compressed files and folders in the ZIP format. It provides classes and functions to create, extract, and manipulate ZIP archives. ZIP archives are widely used for compressing and packaging files for storage, distribution, and backup.

## Importing the Module

To use the `zipfile` module in your Python code, you need to import it first:

```python
import zipfile
```

## Classes

### `zipfile.ZipFile`

The `ZipFile` class represents a ZIP archive and provides methods to work with the archive's contents.

### Constructor

- `zipfile.ZipFile(file, mode='r', compression=ZIP_STORED, allowZip64=True)`: Opens a ZIP archive specified by the file path. The `mode` parameter defines the access mode, and the `compression` parameter defines the type of compression used. By default, the archive is opened in read mode (`'r'`). Set `allowZip64` to `False` if you don't want ZIP64 extensions.

### Methods

- `close()`: Closes the ZIP archive.

- `extract(member, path=None, pwd=None)`: Extracts a member (file) from the ZIP archive to the given `path`. If `path` is not provided, it will extract to the current working directory. Optionally, you can provide a password (`pwd`) if the member is password-protected.

- `extractall(path=None, members=None, pwd=None)`: Extracts all members from the ZIP archive to the given `path`. If `path` is not provided, it will extract to the current working directory. Optionally, you can provide a list of specific members to extract (`members`). You can also provide a password (`pwd`) if the members are password-protected.

- `namelist()`: Returns a list of the names of all members in the ZIP archive.

- `read(name, pwd=None)`: Reads the contents of a file (`name`) from the ZIP archive and returns it as bytes. Optionally, you can provide a password (`pwd`) if the member is password-protected.

- `write(filename, arcname=None, compress_type=None, compresslevel=None)`: Writes a file (`filename`) to the ZIP archive with an optional new name (`arcname`). Optionally, you can specify the compression type and compression level.

## `zipfile.ZipInfo`

The `ZipInfo` class represents information about a file in the ZIP archive.

### Properties

- `filename`: The name of the file in the ZIP archive.

- `file_size`: Size of the uncompressed file.

- `compress_size`: Size of the compressed file.

- `date_time`: Last modification date and time of the file.

- `compress_type`: Type of compression used.

## Constants

The `zipfile` module provides several constants to define compression types:

- `zipfile.ZIP_STORED`: No compression (store the file as is).

- `zipfile.ZIP_DEFLATED`: Standard ZIP compression.

- `zipfile.ZIP_BZIP2`: BZIP2 compression.

- `zipfile.ZIP_LZMA`: LZMA compression.

## Examples

Here are some common examples of using the `zipfile` module:

1. Creating a new ZIP archive and adding files to it:

```python
import zipfile

with zipfile.ZipFile('example.zip', 'w') as myzip:
    myzip.write('file1.txt')
    myzip.write('file2.txt')
```

2. Extracting the contents of a ZIP archive:

```python
import zipfile

with zipfile.ZipFile('example.zip', 'r') as myzip:
    myzip.extractall('extracted_files')
```

3. Reading the contents of a file from a ZIP archive:

```python
import zipfile

with zipfile.ZipFile('example.zip', 'r') as myzip:
    contents = myzip.read('file1.txt')
    print(contents)zip_filename
```

4. Getting information about the members in a ZIP archive:

```python
import zipfile

with zipfile.ZipFile('example.zip', 'r') as myzip:
    for member in myzip.namelist():
        print(member)
```

## Compresslevel

The `compresslevel` parameter in the `zipfile.write()` method of the `zipfile` module is used to specify the level of compression to be applied when adding a file to a ZIP archive. The compression level determines the trade-off between the compression speed and the amount of compression achieved.

The `compresslevel` parameter accepts an integer value between 0 and 9, where:

- `0` (No Compression): This level indicates that no compression will be applied to the file. The file will be stored as-is in the ZIP archive, taking up the same space as the original file. Use this level if you want to include the file without any compression.

- `1` to `9` (Compression Level): These levels specify the degree of compression applied to the file. Higher levels (e.g., `9`) provide better compression but may take more time to compress. Lower levels (e.g., `1`) provide faster compression but may result in a larger file size. Level `9` typically provides the highest compression ratio, while level `1` provides faster compression.

For example, to add a file to a ZIP archive with maximum compression (level `9`), you can use the following code:

```python
import zipfile

with zipfile.ZipFile('example.zip', 'w') as myzip:
    myzip.write('file1.txt', compresslevel=9)
```

By default, if you do not specify the `compresslevel` parameter, it will use the default compression level, which is generally determined by the `zlib` library used internally by Python's `zipfile` module.

Keep in mind that setting higher compression levels may require more processing time, so the choice of compression level depends on your specific needs and the balance between compression ratio and compression speed that you desire for your ZIP archive.

## Conclusion

The `zipfile` module in Python is a powerful tool for working with ZIP archives. It allows you to create, read, write, and manipulate compressed files and folders. Use the provided classes and methods to handle ZIP archives in your Python projects efficiently.