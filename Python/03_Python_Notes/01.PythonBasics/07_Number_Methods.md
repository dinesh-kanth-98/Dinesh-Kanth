**<div align="center" >Variables and Data Types</div>**

### Table of content
- [Built-in Functions](#built-in-functions)
  - [Built-in Arithmetic Functions](#built-in-arithmetic-functions)
    - [**`abs(x)`**:](#absx)
    - [**`pow(x, y, z=None)`**:](#powx-y-znone)
  - [Rounding and Truncation Functions](#rounding-and-truncation-functions)
    - [**`round(number, ndigits=None)`**:](#roundnumber-ndigitsnone)
    - [**`int(x)`**:](#intx)
  - [Conversion Functions:](#conversion-functions)
    - [**`int(x, base=10)`**:](#intx-base10)
    - [**`float(x)`**:](#floatx)
  - [Mathematical Functions:](#mathematical-functions)
    - [**`min(iterable)`**:](#miniterable)
    - [**`max(iterable)`**:](#maxiterable)
    - [**`sum(iterable)`**:](#sumiterable)
- [Math Module](#math-module)
  - [Power and Square Root Functions:](#power-and-square-root-functions)
    - [**`math.pow(x, y)`**:](#mathpowx-y)
    - [**`math.sqrt(x)`**:](#mathsqrtx)
  - [Exponential and Logarithmic Functions:](#exponential-and-logarithmic-functions)
    - [**`math.exp(x)`**:](#mathexpx)
    - [**`math.log(x, base=math.e)`**:](#mathlogx-basemathe)
    - [**`math.log10(x)`**:](#mathlog10x)
  - [Other Functions:](#other-functions)
    - [**`math.floor(x)`**:](#mathfloorx)
    - [**`math.ceil(x)`**:](#mathceilx)
    - [**`math.factorial(x)`**:](#mathfactorialx)
  
# Built-in Functions

In Python, there are several built-in arithmetic functions that you can use to perform various mathematical operations on numbers. These functions are part of the core Python language and do not require any additional module import. Here is a detailed explanation of each of these functions:

## Built-in Arithmetic Functions

### **`abs(x)`**:
   - Returns the absolute value of `x`, which is the distance of `x` from zero.
   - The result is always positive or zero, regardless of the sign of `x`.
   - If `x` is an integer or a float, the return value is also an integer or a float, respectively.

   Example:
   ```python
   result = abs(-5)
   print(result)  # Output: 5
   ```

### **`pow(x, y, z=None)`**:
   - Returns `x` raised to the power of `y`.
   - If `z` is present, it returns `(x ** y) % z`, which is the result of raising `x` to the power of `y` and then taking the modulus of `z`.

   Example:
   ```python
   result1 = pow(2, 3)
   result2 = pow(2, 3, 5)
   print(result1)  # Output: 8
   print(result2)  # Output: 3
   ```

These arithmetic functions provide essential mathematical operations and are useful for performing calculations in Python. Remember that Python also has arithmetic operators like `+`, `-`, `*`, `/`, `**`, `%`, and `//` that you can use directly with numbers to achieve similar results.

For more detailed information on these functions and their usage, refer to the official Python documentation on Built-in Functions:
- `abs()`: [Python abs()](https://docs.python.org/3/library/functions.html#abs)
- `pow()`: [Python pow()](https://docs.python.org/3/library/functions.html#pow)

## Rounding and Truncation Functions

In Python, there are built-in functions that allow you to round numbers or truncate them to a specific number of decimal places. Here's a detailed explanation of each of these rounding and truncation functions:

### **`round(number, ndigits=None)`**:
   - The `round()` function is used to round a floating-point number to the nearest integer or to a specific number of decimal places.
   - The first argument `number` is the floating-point number you want to round.
   - The second argument `ndigits` is optional. If provided, `round()` rounds the number to the specified number of decimal places. If `ndigits` is not provided, the number is rounded to the nearest integer.
   - The `round()` function follows the "round half to even" or "round half to nearest even" rule, also known as "bankers' rounding" or "unbiased rounding." This means that if the number to be rounded is exactly halfway between two integers, it is rounded to the nearest even integer.

   Example:
   ```python
   num1 = 3.49
   num2 = 3.51
   num3 = 4.5
   num4 = 5.5

   rounded_num1 = round(num1)        # Output: 3
   rounded_num2 = round(num2)        # Output: 4
   rounded_num3 = round(num3, 1)     # Output: 4.5
   rounded_num4 = round(num4, 1)     # Output: 5.5
   ```

### **`int(x)`**:
   - The `int()` function is used to convert a number or a string representing a whole number to an integer.
   - If the argument `x` is already an integer, it returns the same integer. If `x` is a floating-point number, it truncates the fractional part and returns the integer part.
   - If `x` is a string, it attempts to convert the string to an integer. The string should contain only digits (optionally preceded by a sign) with an optional leading sign or whitespace.

   Example:
   ```python
   integer_value1 = int(3.7)      # Output: 3
   integer_value2 = int(-4.2)     # Output: -4
   integer_value3 = int("123")    # Output: 123
   integer_value4 = int("-456")   # Output: -456
   ```

These rounding and truncation functions are useful for various mathematical operations and converting between different numeric representations in Python.

For more detailed information on these functions and their usage, refer to the official Python documentation:
- `round()`: [Python round()](https://docs.python.org/3/library/functions.html#round)
- `int()`: [Python int()](https://docs.python.org/3/library/functions.html#int)

## Conversion Functions:

In Python, there are built-in conversion functions that allow you to convert data from one type to another. Here's a detailed explanation of each of these conversion functions:

### **`int(x, base=10)`**:
   - The `int()` function is used to convert a number or a string representing a whole number to an integer.
   - If the argument `x` is already an integer, it returns the same integer. If `x` is a floating-point number, it truncates the fractional part and returns the integer part.
   - If `x` is a string, it attempts to convert the string to an integer. The string should contain only digits (optionally preceded by a sign) with an optional leading sign or whitespace.
   - The optional argument `base` specifies the base (radix) of the input string when converting from a string. By default, it is set to 10.

   Example:
   ```python
   integer_value1 = int(3.7)      # Output: 3
   integer_value2 = int(-4.2)     # Output: -4
   integer_value3 = int("123")    # Output: 123
   integer_value4 = int("-456")   # Output: -456
   ```

### **`float(x)`**:
   - The `float()` function is used to convert a number or a string representing a floating-point number to a float data type.
   - If the argument `x` is already a float, it returns the same float. If `x` is an integer, it converts it to a floating-point number.
   - If `x` is a string, it attempts to convert the string to a floating-point number. The string should be a valid representation of a floating-point number, such as `"-3.14"` or `"2.0"`.

   Example:
   ```python
   float_value1 = float(10)       # Output: 10.0
   float_value2 = float("3.14")   # Output: 3.14
   float_value3 = float("-2.5")   # Output: -2.5
   ```

These conversion functions are useful for converting between different numeric representations in Python, such as converting integers to floats or vice versa. They are also helpful for parsing numeric data from strings.

For more detailed information on these functions and their usage, refer to the official Python documentation:
- `int()`: [Python int()](https://docs.python.org/3/library/functions.html#int)
- `float()`: [Python float()](https://docs.python.org/3/library/functions.html#float)

Certainly! Here's the documentation on each of the topics along with examples for each function from the `math` module in Python:

## Mathematical Functions:

### **`min(iterable)`**:
  - Returns the smallest item in an iterable or the smallest of two or more arguments.
  - The function takes either a single iterable argument (e.g., list, tuple, set) or multiple arguments.
  - If the iterable is empty, `min()` raises a `ValueError`.
  - If two or more items are smallest, the first encountered one will be returned.

  Example:
  ```python
  numbers = [4, 2, 7, 1, 6]
  smallest_num = min(numbers)
  print(smallest_num)  # Output: 1
  ```

### **`max(iterable)`**:
  - Returns the largest item in an iterable or the largest of two or more arguments.
  - The function takes either a single iterable argument (e.g., list, tuple, set) or multiple arguments.
  - If the iterable is empty, `max()` raises a `ValueError`.
  - If two or more items are largest, the first encountered one will be returned.

  Example:
  ```python
  numbers = [4, 2, 7, 1, 6]
  largest_num = max(numbers)
  print(largest_num)  # Output: 7
  ```

### **`sum(iterable)`**:
  - Returns the sum of all elements in an iterable.
  - The function takes a single iterable argument (e.g., list, tuple, set).
  - If the iterable is empty, `sum()` returns 0.

  Example:
  ```python
  numbers = [1, 2, 3, 4, 5]
  total_sum = sum(numbers)
  print(total_sum)  # Output: 15
  ```

# Math Module

## Power and Square Root Functions:

### **`math.pow(x, y)`**:
  - Returns `x` raised to the power of `y`.
  - The function takes two arguments, `x` (base) and `y` (exponent).
  - The result is a floating-point number representing `x` raised to the power of `y`.

  Example:
  ```python
  import math

  power_value = math.pow(2, 3)
  print(power_value)  # Output: 8.0
  ```

### **`math.sqrt(x)`**:
  - Returns the square root of `x`.
  - The function takes a single argument `x`, which can be a non-negative number.
  - The result is a floating-point number representing the positive square root of `x`.

  Example:
  ```python
  import math

  sqrt_value = math.sqrt(25)
  print(sqrt_value)  # Output: 5.0
  ```

## Exponential and Logarithmic Functions:

### **`math.exp(x)`**:
  - Returns the exponential value of `x`.
  - The function takes a single argument `x`, which can be any floating-point number.
  - The result is the value of Euler's number `e` raised to the power of `x` (e^x).

  Example:
  ```python
  import math

  exp_value = math.exp(2)
  print(exp_value)  # Output: 7.3890560989306495
  ```

### **`math.log(x, base=math.e)`**:
  - Returns the natural logarithm (base `e`) of `x`.
  - The function takes two arguments, `x` (the number) and `base` (optional), which specifies the logarithm base.
  - If `base` is not provided, the default is the natural logarithm.

  Example:
  ```python
  import math

  log_value = math.log(10)
  print(log_value)  # Output: 2.302585092994046
  ```

### **`math.log10(x)`**:
  - Returns the base-10 logarithm of `x`.
  - The function takes a single argument `x`, which can be any positive number.
  - The result is a floating-point number representing the base-10 logarithm of `x`.

  Example:
  ```python
  import math

  log10_value = math.log10(1000)
  print(log10_value)  # Output: 3.0
  ```

## Other Functions:

### **`math.floor(x)`**:
  - Returns the largest integer less than or equal to `x`.
  - The function takes a single argument `x`, which can be a floating-point number.
  - It rounds down the number to the nearest integer that is less than or equal to `x`.

  Example:
  ```python
  import math

  floor_value = math.floor(3.7)
  print(floor_value)  # Output: 3
  ```

### **`math.ceil(x)`**:
  - Returns the smallest integer greater than or equal to `x`.
  - The function takes a single argument `x`, which can be a floating-point number.
  - It rounds up the number to the nearest integer that is greater than or equal to `x`.

  Example:
  ```python
  import math

  ceil_value = math.ceil(3.7)
  print(ceil_value)  # Output: 4
  ```

### **`math.factorial(x)`**:
  - Returns the factorial of `x`, which is the product of all positive integers from 1 to `x`.
  - The function takes a single argument `x`, which must be a non-negative integer.
  - The result is the value of `x!` (x factorial).

  Example:
  ```python
  import math

  factorial_value = math.factorial(5)
  print(factorial_value)  # Output: 120
  ```

These are some of the commonly used functions from the `math` module in Python. To use these functions, you need to import the `math` module in your Python code. For more detailed information, you can refer to the official Python documentation on the `math` module: [Python math — Mathematical functions](https://docs.python.org/3/library/math.html).