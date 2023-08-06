**<div align="center" >Variables and Data Types</div>**

### Table of content
- [What is a variable?](#what-is-a-variable)
- [What is a Data Type?](#what-is-a-data-type)
  - [Numeric Data Types: int, float, complex](#numeric-data-types-int-float-complex)
  - [Text Data Type: str](#text-data-type-str)
  - [Boolean Data Type: bool](#boolean-data-type-bool)
  - [Sequence Data Types: list, tuple](#sequence-data-types-list-tuple)
  - [Mapping Data Type: dict](#mapping-data-type-dict)
  - [None Type](#none-type)
  - [Set Data Types](#set-data-types)
  - [Binary Data Types](#binary-data-types)

## What is a variable?

A variable is like a container that holds data. It is similar to how our kitchen containers hold sugar, salt, etc. Creating a variable is like creating a placeholder in memory and assigning it a value. In Python, it's as easy as writing:

```python
a = 1
b = True
c = "Harry"
d = None
```
These are four variables of different data types.

> When you create a variable, you are essentially allocating a specific memory location to store the value assigned to it. This value can be of any data type, such as an integer, float, string, list, etc.

## What is a Data Type?

A data type specifies the type of value a variable holds. This is required in programming to perform various operations without causing errors.<br>
- In Python, we can print the type of any variable using the `type()` function:

```python
a = 1
print(type(a))
b = "1"
print(type(b))
```

> Python is a dynamically-typed language, which means you don't need to explicitly declare the data type of a variable. The data type is automatically determined based on the value assigned to the variable.

Python provides the following built-in data types:

### Numeric Data Types: int, float, complex
   - `int`: Represents integer values, e.g., `10`, `-5`, `0`.
   - `float`: Represents floating-point or decimal values, e.g., `3.14`, `-2.5`, `0.0`.
   - `complex`: Represents complex numbers, e.g., `2 + 3j`, `-4j`.

### Text Data Type: str
   - `str`: Represents strings of characters, e.g., `"Hello"`, `'Python'`.

### Boolean Data Type: bool
   - `bool`: Represents Boolean values, `True` or `False`.

### Sequence Data Types: list, tuple

- `list`: An ordered collection of data with elements separated by commas and enclosed within square brackets. Lists are mutable and can be modified after creation.

   **Example**:
   ```python
   list1 = [8, 2.3, [-4, 5], ["apple", "banana"]]
   print(list1)
   ```
   **Output**:
   ```
   [8, 2.3, [-4, 5], ['apple', 'banana']]
   ```

- `tuple`: An ordered collection of data with elements separated by commas and enclosed within parentheses. Tuples are immutable and cannot be modified after creation.

   **Example**:
   ```python
   tuple1 = (("parrot", "sparrow"), ("Lion", "Tiger"))
   print(tuple1)
   ```
   **Output**:
   ```
   (('parrot', 'sparrow'), ('Lion', 'Tiger'))
   ```

### Mapping Data Type: dict

  - `dict`: A dictionary is an collection of data containing key-value pairs. The key-value pairs are enclosed within curly brackets.

   **Example**:
   ```python
   dict1 = {"name": "Sakshi", "age": 20, "canVote": True}
   print(dict1)
   ```
   **Output**:
   ```
   {'name': 'Sakshi', 'age': 20, 'canVote': True}
   ```

### None Type
   - `NoneType`: Represents the absence of a value, typically denoted by `None`.

### Set Data Types
   - `set`: Represents an unordered collection of unique elements, e.g., `{1, 2, 3}`, `{'apple', 'banana', 'orange'}`.
   - `frozenset`: Represents an immutable set, e.g., `frozenset({1, 2, 3})`.

### Binary Data Types
   - `bytes`: Represents a sequence of bytes, e.g., `b'hello'`.
   - `bytearray`: Represents an array of bytes that can be modified, e.g., `bytearray(b'hello')`.
   - `memoryview`: Represents a view of the memory, e.g., `memoryview(b'hello')`.

Each data type in Python comes with its own set of operations and methods that can be applied to it. Understanding data types is essential for writing correct and efficient Python code, as it allows you to perform operations and manipulate data appropriately.