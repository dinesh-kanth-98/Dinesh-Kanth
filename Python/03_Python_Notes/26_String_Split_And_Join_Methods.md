Certainly! Here's a detailed documentation of the `str.split()` and `str.join()` functions in Python:

# Python String Methods: `split()` and `join()`

In Python, strings are sequences of characters and have a variety of built-in methods that allow you to manipulate and work with them. Two commonly used methods for splitting and joining strings are `split()` and `join()`.

## `str.split([sep=None[, maxsplit=-1]])`

**Description:**
- `split()` method returns a list of substrings obtained by splitting the original string at occurrences of the `sep` separator. If `sep` is not specified, the string is split on whitespaces.
- You can also specify the `maxsplit` parameter, which limits the number of splits that can be performed. By default, it is set to -1, which means there is no limit.

**Example:**
```python
text = "apple,orange,banana"
fruits = text.split(",")
print(fruits)  # Output: ['apple', 'orange', 'banana']

text = "Hello World"
words = text.split()  # Default separator is whitespace
print(words)  # Output: ['Hello', 'World']

text = "one two three four"
parts = text.split(" ", 2)  # Maxsplit is 2
print(parts)  # Output: ['one', 'two', 'three four']
```

## `str.join(iterable)`

**Description:**
- `join()` method concatenates the elements of an `iterable` (e.g., list, tuple, set) into a single string using the original string as the separator between elements.
- The iterable should contain strings because the method can only join strings together.

**Example:**
```python
fruits = ['apple', 'orange', 'banana']
text = ",".join(fruits)
print(text)  # Output: 'apple,orange,banana'

words = ['Hello', 'World']
text = " ".join(words)  # Join with whitespace separator
print(text)  # Output: 'Hello World'

numbers = ['1', '2', '3', '4']
text = "-".join(numbers)  # Join with hyphen separator
print(text)  # Output: '1-2-3-4'
```

Both `split()` and `join()` methods are powerful tools for handling strings in Python. They are commonly used for parsing strings, working with delimited data, and formatting output. Remember that `split()` returns a list of substrings, while `join()` returns a single string. Additionally, `join()` requires the elements of the iterable to be strings.

For more detailed information and additional usage scenarios, refer to the official Python documentation on [String Methods](https://docs.python.org/3/library/stdtypes.html#string-methods).