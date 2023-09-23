**<div align="center" >String Methods and Functions</div>**

### Table of content
- [String Methods and Functions](#string-methods-and-functions)
  - [ASCII Values](#ascii-values)
    - [`ord(c)`](#ordc)
    - [`chr(i)`](#chri)
  - [String Length](#string-length)
    - [`len(str)`](#lenstr)
  - [Finding Minimum and Maximum Characters](#finding-minimum-and-maximum-characters)
    - [`min(str)` and `max(str)`](#minstr-and-maxstr)
  - [Sorting a String](#sorting-a-string)
    - [`sorted(str[, key=None, reverse=False])`](#sortedstr-keynone-reversefalse)

# String Methods and Functions

## ASCII Values

**ASCII (American Standard Code for Information Interchange)** is a character encoding standard used to represent text in computers and other devices that use text. Each character in ASCII is represented by a unique 7-bit binary number, which corresponds to a decimal value from 0 to 127.

### `ord(c)`

**Description:**
- `ord()` function returns the ASCII value of a character `c` in a string.
- The argument `c` can be a string of length 1, representing a single character.

**Example:**
```python
ascii_value = ord('A')
print(ascii_value)  # Output: 65

ascii_value = ord('a')
print(ascii_value)  # Output: 97
```

**Usage:**
- `ord()` is commonly used when you need to convert a character to its corresponding ASCII value, especially when working with encryption, encoding, or character manipulation tasks.

### `chr(i)`

**Description:**
- `chr()` function returns the character represented by the ASCII value `i`.
- The argument `i` should be an integer in the range 0 to 127.

**Example:**
```python
character = chr(65)
print(character)  # Output: 'A'

character = chr(97)
print(character)  # Output: 'a'
```

**Usage:**
- `chr()` is useful for converting an ASCII value back to its corresponding character. It is often used in decoding tasks or when you need to represent integer values as characters.

## String Length

Python provides the built-in function `len()` to determine the length of a string.

### `len(str)`

**Description:**
- `len()` function returns the number of characters in a string.

**Example:**
```python
text = "Hello, World!"
length = len(text)
print(length)  # Output: 13
```

**Usage:**
- `len()` is commonly used to find the length of a string, which is essential for various operations, such as looping through characters or validating input length.

## Finding Minimum and Maximum Characters

Python provides the built-in functions `min()` and `max()` to find the smallest and largest characters in a string.

### `min(str)` and `max(str)`

**Description:**
- `min()` function returns the smallest character in a string.
- `max()` function returns the largest character in a string.

**Example:**
```python
text = "Hello, World!"
minimum_char = min(text)
maximum_char = max(text)
print(minimum_char)  # Output: ' '
print(maximum_char)  # Output: 'r'
```

**Usage:**
- `min()` and `max()` are helpful when you need to find specific characters based on their ASCII values or for comparing characters in a string.

## Sorting a String

Python provides the built-in function `sorted()` to sort the characters in a string.

### `sorted(str[, key=None, reverse=False])`

**Description:**
- `sorted()` function returns a new sorted list of characters from the string.
- The optional `key` parameter specifies a function to determine the sort order.
- The optional `reverse` parameter is a boolean value indicating whether to sort in ascending (`False`, default) or descending (`True`) order.

**Example:**
```python
text = "Hello, World!"
sorted_text = sorted(text)
print(sorted_text)  # Output: [' ', ' ', '!', ',', 'H', 'W', 'd', 'e', 'l', 'l', 'l', 'o', 'o', 'r']

sorted_text_descending = sorted(text, reverse=True)
print(sorted_text_descending)  # Output: ['r', 'o', 'o', 'l', 'l', 'l', 'e', 'd', 'W', 'H', ',', '!', ' ', ' ']
```

**Usage:**
- `sorted()` is useful when you need to rearrange the characters in a string based on a specific order, whether it is in ascending or descending ASCII values. It creates a new sorted list, and the original string remains unchanged.

These functions are essential when working with strings in Python, whether you need to find the ASCII values of characters, determine the length, find the minimum and maximum characters, or sort the characters in a specific order. They provide valuable functionality for string manipulation and processing tasks.