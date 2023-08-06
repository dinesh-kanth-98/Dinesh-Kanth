**<div align="center">Numeric Data Types</div>**

### Table of content
- [Integers (`int`):](#integers-int)
- [Floating-Point Numbers (`float`):](#floating-point-numbers-float)
- [Complex Numbers (`complex`):](#complex-numbers-complex)

Python supports several numeric data types, and they are categorized as follows:

## Integers (`int`):

- Integers represent whole numbers without a fractional part. They can be positive or negative.
- In Python, you can create integers using regular integer literals, such as `42`, `-10`, or `0`.
- Python's `int` type can represent integers of arbitrary size, limited only by available memory.

**Example**:
```python
num1 = 42
num2 = -10
num3 = 0
```

## Floating-Point Numbers (`float`):

- Floating-point numbers represent real numbers with a fractional part. They can be written with a decimal point or in scientific notation.
- In Python, you can create floating-point numbers using decimal literals, such as `3.14`, `-2.5`, or `1.23e6`.
- Python uses the IEEE 754 double-precision format for representing floating-point numbers, providing high precision for most practical purposes.

**Example**:
```python
num1 = 3.14
num2 = -2.5
num3 = 1.23e6  # Equivalent to 1230000.0
```

## Complex Numbers (`complex`):

- Complex numbers consist of a real part and an imaginary part. They are written in the form `a + bj`, where `a` is the real part and `b` is the imaginary part.
- In Python, you can create complex numbers using the `j` or `J` suffix to denote the imaginary unit.
- Complex numbers are useful in mathematical calculations involving imaginary numbers.

**Example**:
```python
num1 = 3 + 2j
num2 = -4j
```

In Python, you can perform various arithmetic operations on these numeric data types, including addition, subtraction, multiplication, division, and more. You can also use comparison operators to compare numbers and get Boolean results.

**Example Arithmetic Operations**:
```python
num1 = 10
num2 = 3.5

addition_result = num1 + num2   # 13.5
subtraction_result = num1 - num2   # 6.5
multiplication_result = num1 * num2   # 35.0
division_result = num1 / num2   # 2.857142857142857
```

Example Comparison:
```python
num1 = 5
num2 = 3

is_equal = num1 == num2   # False
is_greater = num1 > num2   # True
```

For more comprehensive information about numeric data types, mathematical operations, and additional functions available in Python, refer to the official Python documentation at python.org. You can find detailed information about numbers in Python under the "Numeric Types" section.