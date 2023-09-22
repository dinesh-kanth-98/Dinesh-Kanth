**<div align="center">f-strings in Python</div>**

### Table of content
- [f-strings](#f-strings)
  - [Basic Usage:](#basic-usage)
    - [Examples:](#examples)
  - [{var=} syntax in f-string formatting](#var-syntax-in-f-string-formatting)
  - [{var:%} Syntax in f-string formatting](#var-syntax-in-f-string-formatting-1)
  - [Hexadecimal (`:x`) and Octal (`:o`) Representations](#hexadecimal-x-and-octal-o-representations)
    - [Format Specification Mini-Language](#format-specification-mini-language)
    - [Hexadecimal Representation (`:x`)](#hexadecimal-representation-x)
    - [Octal Representation (`:o`)](#octal-representation-o)
  - [Adding Width and Center Alignment:](#adding-width-and-center-alignment)
    - [Adding Width:](#adding-width)
  - [Filling Empty Space:](#filling-empty-space)
    - [Examples:](#examples-1)
  - [Benefits:](#benefits)
  - [Limitations:](#limitations)
  - [Conclusion:](#conclusion)

# f-strings

**f-strings (Formatted String Literals) in Python**

f-strings, also known as formatted string literals, are a powerful feature introduced in Python 3.6 that allow you to embed expressions inside string literals. They provide a concise and convenient way to format strings using variables and expressions directly within the string.

## Basic Usage:

f-strings are created by prefixing the string with the letter 'f' or 'F' and enclosing the expressions to be evaluated within curly braces `{}`.

```python
f-string: f"string {expression}"
```

### Examples:

1. **Inserting Variables into Strings:**

```python
name = "John"
age = 30
formatted_string = f"My name is {name} and I am {age} years old."
print(formatted_string)  # Output: "My name is John and I am 30 years old."
```

2. **Using Expressions:**

```python
x = 10
y = 20
result = f"The sum of {x} and {y} is {x + y}."
print(result)  # Output: "The sum of 10 and 20 is 30."
```

3. **Formatting Numbers:**

```python
value = 3.14159
formatted_value = f"The value of pi is approximately {value:.2f}."
print(formatted_value)  # Output: "The value of pi is approximately 3.14."
```

The Below f-string `{30300030:_.2f}`, it formats the value of the variable `30300030` as a floating-point number with two decimal places and inserts underscores as thousands separators.

```python
value = 30300030
print(f"The formatted value is: {value:_.2f}")
# Output: "The formatted value is: 30,300,030.00"
```

In this example, the variable `value` is `30300030`. The f-string `{value:_.2f}` formats the value with two decimal places and adds underscores as thousands separators, resulting in the output `30,300,030.00`.

## {var=} syntax in f-string formatting

The `{var=}` syntax is used to include the name of a variable and its value in a formatted string in Python. This feature is available starting from Python 3.8 and is known as the "Assignment Expressions" or "Walrus Operator".

Here's how you can use the `{var=}` syntax in f-string formatting:
```python
name = "John"
age = 30
address = "New York"

print(f"Details: {name=}, {age=}, {address=}")
```

Output:
```
Details: name='John', age=30, address='New York'
```

In this example, we use the `{name=}`, `{age=}`, and `{address=}` expressions to display the names and values of the variables `name`, `age`, and `address` in a single line.

> By using this syntax, you can quickly inspect the values of multiple variables without repeating the variable names in the f-string, reducing the amount of code and making it more concise.

The `{23.333:%}` syntax is used for f-string formatting in Python, where `23.333` is the number being formatted and `%` is the format specification. The `%` format specifier is used for percentage formatting.

Here's a breakdown:

- `23.333`: This is the value you're formatting, a floating-point number.

- `%`: The `%` symbol is a format specifier that tells Python to convert the number into a percentage. It multiplies the number by 100 and adds the "%" sign at the end. The default precision for `%` is 6 digits after the decimal point, but you can specify the precision you want.

## {var:%} Syntax in f-string formatting

So `{23.333:%}` in an f-string will convert the number `23.333` to a percentage, multiply it by 100, and append the `%` symbol.

Here's an example:

```python
print(f"The number as a percentage is: {23.333:%}")
```

Output:
```
The number as a percentage is: 2333.300000%
```

In this example, the number `23.333` is formatted as a percentage and results in `2333.300000%`.

To specify a precision of 2 decimal places, you can modify the format specifier to `:.2%`:

```python
print(f"The number as a percentage with 2 decimal places is: {23.333:.2%}")
```

Output:
```
The number as a percentage with 2 decimal places is: 2333.30%
```

In this revised example, we've added `.2` before the `%` sign in the format specifier to indicate that we want the output to be rounded to 2 decimal places. The output now shows `2333.30%`, which is the result of multiplying `23.333` by 100 and rounding to 2 decimal places.

## Hexadecimal (`:x`) and Octal (`:o`) Representations

In Python, f-string formatting is a powerful and concise way to format strings by embedding expressions inside curly braces `{}`. It allows you to easily convert integers to their hexadecimal and octal representations.

### Format Specification Mini-Language

To format integers as hexadecimal or octal, you can use the Format Specification Mini-Language. The general syntax for f-string formatting with hexadecimal (`:x`) and octal (`:o`) representations is:

```python
f"{integer_variable:x}"
f"{integer_variable:o}"
```

- `integer_variable`: The integer variable you want to convert to hexadecimal or octal representation.

### Hexadecimal Representation (`:x`)

To convert an integer to its hexadecimal representation, use the `:x` format specifier inside the f-string. The `:x` format specifier converts the integer to lowercase hexadecimal.

```python
num = 255
hex_representation = f"Hexadecimal: {num:x}"
print(hex_representation)
```

Output:
```
Hexadecimal: ff
```

### Octal Representation (`:o`)

To convert an integer to its octal representation, use the `:o` format specifier inside the f-string.

```python
num = 255
octal_representation = f"Octal: {num:o}"
print(octal_representation)
```

Output:
```
Octal: 377
```

> Using f-string formatting with expressions, you can conveniently print integers in different representations like hexadecimal and octal in a concise and readable manner.

## Adding Width and Center Alignment:

You can add width formatting and center alignment to f-strings by specifying a number followed by the `^` character before the colon `:` inside the curly braces `{}`. This number represents the minimum width of the field. If the content is shorter than the specified width, it will be padded with spaces to center-align the content within the field.

### Adding Width:

You can add width formatting to f-strings by specifying a number Afetr the colon `:` inside the curly braces `{}`. This number represents the minimum width of the field. If the content is shorter than the specified width, it will be padded with spaces to meet the width requirement.

1. **Right-aligning Content:**

```python
name = "John"
age = 30
formatted_string = f"Name: {name:10} Age: {age:5}"
print(formatted_string)  # Output: "Name: John       Age:    30"
```

2. **Left-aligning Content:**

```python
value = 123
formatted_number = f"Number: {value:<8}"
print(formatted_number)  # Output: "Number: 123     "
```

3. **Center-aligning Content:**

```python
name = "John"
age = 30

# Center-aligning the name field within a width of 15
formatted_string = f"Name: {name:^15} Age: {age:^5}"
print(formatted_string)  # Output: "Name:      John      Age:  30  "
```
4. **Center-aligning Numbers:**

```python
value = 123

# Center-aligning the number field within a width of 10
formatted_number = f"Number: {value:^10}"
print(formatted_number)  # Output: "Number:   123   "
```

## Filling Empty Space:

You can fill empty space in an f-string with any character of your choice. To achieve this, you can use the format specification mini-language provided by Python. The `fill` character can be any character you want to use for padding.

### Examples:

1. **Filling with a Specific Character (e.g., '-'):**

```python
name = "John"
age = 30

# Filling with '-' and center-aligning the name field within a width of 15
formatted_string = f"Name: {name:-^15} Age: {age:-^5}"
print(formatted_string)  # Output: "Name: ----John---- Age: --30--"

# Filling with '-' and left-aligning the name field within a width of 15
formatted_string = f"Name: {name:-<15} Age: {age:-<5}"
print(formatted_string)  # Output: "Name: John----------- Age: 30---"

# Filling with '-' and right-aligning the name field within a width of 15
formatted_string = f"Name: {name:->15} Age: {age:0>5}"
print(formatted_string)  # Output: "Name: -----------John Age: 00030"
```

2. **Filling with a Specific Character (e.g., '*'):**

```python
name = "John"
age = 30

# Filling with '*' and center-aligning the name field within a width of 15
formatted_string = f"Name: {name:*^15} Age: {age:*^5}"
print(formatted_string)  # Output: "Name: ****John**** Age: **30**"
```

## Benefits:

1. **Concise and Readable**: f-strings provide a clean and clear way to incorporate variables and expressions directly into strings, making the code more readable.

2. **Flexible Formatting**: You can use various formatting options within the curly braces to control the appearance of the variables and expressions.

3. **Efficient**: f-strings are faster and more efficient compared to other string formatting methods like `%` or `str.format()`.

## Limitations:

1. **Python Version**: f-strings are available from Python 3.6 onwards. If you are using an earlier version of Python, you won't be able to use f-strings.

2. **Expression Evaluation**: f-strings evaluate the expressions inside curly braces at runtime. Be cautious about embedding complex or time-consuming operations in f-strings.

## Conclusion:

Overall, f-strings are a valuable addition to Python's string formatting capabilities, making string formatting more intuitive and efficient. They are widely used in modern Python code to produce dynamic and well-formatted strings with ease. The ability to add width and center alignment, as well as fill empty space with any character, provides added flexibility for formatting strings to suit specific needs.