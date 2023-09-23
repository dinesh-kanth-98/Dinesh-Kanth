**<div align="center" >Precedence and Associativity of Operators</div>**

### Table of content
- [Python String Methods](#python-string-methods)
  - [`str.capitalize()`](#strcapitalize)
  - [`str.title()`](#strtitle)
  - [`str.istitle()`](#stristitle)
  - [`str.upper()`](#strupper)
  - [`str.isupper()`](#strisupper)
  - [`str.lower()`](#strlower)
  - [`str.islower()`](#strislower)
  - [`str.swapcase()`](#strswapcase)
  - [`str.index(substring)`](#strindexsubstring)
  - [`str.find(substring)`](#strfindsubstring)
  - [`str.replace(old, new[, count])`](#strreplaceold-new-count)
  - [`str.count(substring)`](#strcountsubstring)
  - [`str.isspace()`](#strisspace)
  - [`str.startswith(prefix[, start[, end]])`](#strstartswithprefix-start-end)
  - [`str.endswith(suffix[, start[, end]])`](#strendswithsuffix-start-end)
  - [`str.isidentifier()`](#strisidentifier)
  - [`str.isalpha()`](#strisalpha)
  - [`str.isdecimal()`](#strisdecimal)
  - [`str.isdigit()`](#strisdigit)
  - [`str.isnumeric()`](#strisnumeric)
  - [`str.isalnum()`](#strisalnum)

# Python String Methods

In Python, strings are sequences of characters and have a variety of built-in methods that allow you to manipulate and work with them.

## `str.capitalize()`

**Description:**
- Returns a copy of the string with its first character capitalized and the rest in lowercase.

**Example:**
```python
text = "hello world"
print(text.capitalize())  # Output: "Hello world"
```

## `str.title()`

**Description:**
- Returns a copy of the string with the first character of each word capitalized and the rest in lowercase.

**Example:**
```python
text = "hello world"
print(text.title())  # Output: "Hello World"
```

## `str.istitle()`

**Description:**
- Returns `True` if the string is in title case (i.e., the first character of each word is capitalized), otherwise returns `False`.

**Example:**
```python
text1 = "Hello World"
text2 = "hello World"
print(text1.istitle())  # Output: True
print(text2.istitle())  # Output: False
```

## `str.upper()`

**Description:**
- Returns a copy of the string with all characters converted to uppercase.

**Example:**
```python
text = "hello world"
print(text.upper())  # Output: "HELLO WORLD"
```

## `str.isupper()`

**Description:**
- Returns `True` if all characters in the string are in uppercase, otherwise returns `False`.

**Example:**
```python
text1 = "HELLO WORLD"
text2 = "Hello World"
print(text1.isupper())  # Output: True
print(text2.isupper())  # Output: False
```

## `str.lower()`

**Description:**
- Returns a copy of the string with all characters converted to lowercase.

**Example:**
```python
text = "Hello World"
print(text.lower())  # Output: "hello world"
```

## `str.islower()`

**Description:**
- Returns `True` if all characters in the string are in lowercase, otherwise returns `False`.

**Example:**
```python
text1 = "hello world"
text2 = "Hello World"
print(text1.islower())  # Output: True
print(text2.islower())  # Output: False
```

## `str.swapcase()`

**Description:**
- Returns a copy of the string with all uppercase characters converted to lowercase and vice versa.

**Example:**
```python
text = "Hello World"
print(text.swapcase())  # Output: "hELLO wORLD"
```

## `str.index(substring)`

**Description:**
- Returns the lowest index of the first occurrence of the `substring` in the string.
- Raises a `ValueError` if the `substring` is not found.

**Example:**
```python
text = "apple orange apple banana apple"
print(text.index("apple"))  # Output: 0
print(text.index("banana"))  # Output: 13
```

## `str.find(substring)`

**Description:**
- Returns the lowest index of the first occurrence of the `substring` in the string.
- Returns -1 if the `substring` is not found.

**Example:**
```python
text = "apple orange apple banana apple"
print(text.find("apple"))  # Output: 0
print(text.find("banana"))  # Output: 13
print(text.find("pear"))  # Output: -1
```

## `str.replace(old, new[, count])`

**Description:**
- `replace()` method returns a copy of the string with all occurrences of `old` replaced by `new`.
- You can also specify the optional `count` parameter, which limits the number of replacements to be made. By default, all occurrences are replaced.

**Example:**
```python
text = "Hello World"
new_text = text.replace("World", "Universe")
print(new_text)  # Output: "Hello Universe"

text = "apple orange apple banana apple"
new_text = text.replace("apple", "pear", 2)  # Replaces only first 2 occurrences
print(new_text)  # Output: "pear orange pear banana apple"
```

## `str.count(substring)`

**Description:**
- `count()` method returns the number of non-overlapping occurrences of the `substring` in the string.

**Example:**
```python
text = "apple orange apple banana apple"
count = text.count("apple")
print(count)  # Output: 3
```

## `str.isspace()`

**Description:**
- `isspace()` method returns `True` if all characters in the string are whitespace characters (spaces, tabs, newlines), otherwise returns `False`.

**Example:**
```python
text1 = "   "
text2 = " Hello "
print(text1.isspace())  # Output: True
print(text2.isspace())  # Output: False
```

## `str.startswith(prefix[, start[, end]])`

**Description:**
- `startswith()` method returns `True` if the string starts with the specified `prefix`, otherwise returns `False`.
- You can also specify optional `start` and `end` parameters to check for the prefix within a specific substring of the original string.

**Example:**
```python
text = "Hello World"
print(text.startswith("Hello"))  # Output: True
print(text.startswith("World"))  # Output: False
```

## `str.endswith(suffix[, start[, end]])`

**Description:**
- `endswith()` method returns `True` if the string ends with the specified `suffix`, otherwise returns `False`.
- You can also specify optional `start` and `end` parameters to check for the suffix within a specific substring of the original string.

**Example:**
```python
text = "Hello World"
print(text.endswith("World"))  # Output: True
print(text.endswith("Hello"))  # Output: False
```

## `str.isidentifier()`

**Description:**
- `isidentifier()` method returns `True` if the string is a valid identifier in Python, i.e., it follows the rules for naming variables.
- A valid identifier must start with a letter (a-z, A-Z) or an underscore (_), followed by zero or more letters, digits (0-9), or underscores.

**Example:**
```python
identifier1 = "variable_name"
identifier2 = "_private_variable"
identifier3 = "123_invalid"

print(identifier1.isidentifier())  # Output: True
print(identifier2.isidentifier())  # Output: True
print(identifier3.isidentifier())  # Output: False
```

## `str.isalpha()`

**Description:**
- `isalpha()` method returns `True` if all characters in the string are alphabetic (letters), otherwise returns `False`.

**Example:**
```python
text1 = "Hello"
text2 = "Hello123"

print(text1.isalpha())  # Output: True
print(text2.isalpha())  # Output: False
```

## `str.isdecimal()`

**Description:**
- `isdecimal()` method returns `True` if all characters in the string are decimal (0-9) digits, otherwise returns `False`.

**Example:**
```python
text1 = "123"
text2 = "123.45"

print(text1.isdecimal())  # Output: True
print(text2.isdecimal())  # Output: False
```

## `str.isdigit()`

**Description:**
- `isdigit()` method returns `True` if all characters in the string are digits (0-9), otherwise returns `False`.

**Example:**
```python
text1 = "123"
text2 = "123abc"

print(text1.isdigit())  # Output: True
print(text2.isdigit())  # Output: False
```

## `str.isnumeric()`

**Description:**
- `isnumeric()` method returns `True` if all characters in the string are numeric (digits, fractions, subscripts, superscripts, etc.), otherwise returns `False`.

**Example:**
```python
text1 = "123"
text2 = "½"
text3 = "²"

print(text1.isnumeric())  # Output: True
print(text2.isnumeric())  # Output: True
print(text3.isnumeric())  # Output: True
```

## `str.isalnum()`

**Description:**
- `isalnum()` method returns `True` if all characters in the string are alphanumeric (letters and digits), otherwise returns `False`.

**Example:**
```python
text1 = "Hello123"
text2 = "Hello 123"

print(text1.isalnum())  # Output: True
print(text2.isalnum())  # Output: False
```

These are some of the commonly used string methods in Python. They are useful for various string operations, such as replacing substrings, counting occurrences, checking patterns, and validating input. For more detailed information and additional methods, refer to the official Python documentation on [String Methods](https://docs.python.org/3/library/stdtypes.html#string-methods).