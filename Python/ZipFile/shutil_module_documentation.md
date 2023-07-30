**<div align="center" >Documentation on shutil module in Python</div>**

### Table of content
- [shutil module in Python](#shutil-module-in-python)
  - [Importing the `shutil` module](#importing-the-shutil-module)
  - [Key Functions of the `shutil` module](#key-functions-of-the-shutil-module)
- [Examples](#examples)

## shutil module in Python

The `shutil` module in Python is a standard library module that provides a set of high-level file operations. It offers a simple and efficient way to perform file and directory operations, such as copying, moving, archiving, and more. The name "shutil" stands for "shell utilities," as it provides functions similar to shell commands for file operations.

### Importing the `shutil` module
```python
import shutil
```

### Key Functions of the `shutil` module

1. **Copying Files and Directories:**

   - `shutil.copy(src, dst)`: Copy the file from `src` to `dst`.
   - `shutil.copy2(src, dst)`: Copy the file from `src` to `dst` while preserving the metadata (timestamps, permissions).
   - `shutil.copytree(src, dst)`: Recursively copy a directory from `src` to `dst`.

2. **Moving (Renaming) Files and Directories:**

   - `shutil.move(src, dst)`: Move the file or directory from `src` to `dst`. Can also be used for renaming.

3. **Deleting Files and Directories:**

   - `shutil.rmtree(path)`: Recursively delete a directory and its contents.
   - `os.remove(path)`: Delete a file.

4. **Archiving and Compression:**

   - `shutil.make_archive(base_name, format, root_dir)`: Create an archive (zip, tar, etc.) from files in `root_dir`.
   - `shutil.unpack_archive(filename, extract_dir)`: Unpack an archive into `extract_dir`.

5. **File Metadata:**

   - `shutil.copystat(src, dst)`: Copy the permission bits, timestamps, and other metadata from `src` to `dst`.

6. **File and Directory Permissions:**

   - `shutil.chown(path, user=None, group=None)`: Change the owner and group of a file or directory.

7. **Other Utilities:**

   - `shutil.disk_usage(path)`: Get disk usage statistics of a given path.
   - `shutil.which(cmd, mode=os.F_OK | os.X_OK, path=None)`: Locate the executable of a command in the system's PATH.

## Examples

1. Copy a file:
```python
import shutil

src_file = "source_file.txt"
dst_file = "destination_file.txt"
shutil.copy(src_file, dst_file)
```

2. Move (Rename) a file:
```python
import shutil

old_name = "old_file.txt"
new_name = "new_file.txt"
shutil.move(old_name, new_name)
```

3. Create a ZIP archive:
```python
import shutil

source_dir = "my_directory"
shutil.make_archive("archive", "zip", source_dir)
```

4. Unpack a ZIP archive:
```python
import shutil

archive_file = "archive.zip"
extract_dir = "extracted_contents"
shutil.unpack_archive(archive_file, extract_dir)
```

5. Remove a directory and its contents:
```python
import shutil

dir_to_delete = "my_directory"
shutil.rmtree(dir_to_delete)
```

These examples provide a glimpse of the functionality offered by the `shutil` module. It is a powerful tool for handling file and directory operations in Python and can be incredibly useful for various tasks, such as data processing, backup, and more. Remember to use these functions with caution, especially when performing operations that modify or delete files or directories. Always take care to handle important data safely.