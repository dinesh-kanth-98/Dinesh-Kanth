**<div align="center" >Comparison Operators</div>**

### Table of content
- [Comparison Operators](#comparison-operators)
  - [Equality (`==`) and Inequality (`!=`):](#equality--and-inequality-)
  - [Greater Than (`>`) and Less Than (`<`):](#greater-than--and-less-than-)
  - [Greater Than or Equal To (`>=`) and Less Than or Equal To (`<=`):](#greater-than-or-equal-to--and-less-than-or-equal-to-)
- [compare strings in Python](#compare-strings-in-python)


 # Comparison Operators

 Comparison operators in Python are used to compare values and return Boolean results (`True` or `False`). You can use these operators in various contexts, including without using `if` and `else` statements, to perform comparisons and make decisions based on the results. Here's an overview of common comparison operators:

## Equality (`==`) and Inequality (`!=`):
   - The equality operator (`==`) checks if two values are equal, and it returns `True` if they are equal and `False` if they are not.
   - The inequality operator (`!=`) checks if two values are not equal, and it returns `True` if they are not equal and `False` if they are equal.

   Example:
   ```python
   result1 = 5 == 5  # True
   result2 = 5 != 5  # False
   ```

## Greater Than (`>`) and Less Than (`<`):
   - The greater-than operator (`>`) checks if one value is greater than another, returning `True` if it is and `False` if it's not.
   - The less-than operator (`<`) checks if one value is less than another, returning `True` if it is and `False` if it's not.

   Example:
   ```python
   result1 = 10 > 5   # True
   result2 = 5 < 10   # True
   ```

## Greater Than or Equal To (`>=`) and Less Than or Equal To (`<=`):
   - The greater-than-or-equal-to operator (`>=`) checks if one value is greater than or equal to another, returning `True` if it is and `False` if it's not.
   - The less-than-or-equal-to operator (`<=`) checks if one value is less than or equal to another, returning `True` if it is and `False` if it's not.

   Example:
   ```python
   result1 = 5 >= 5   # True
   result2 = 10 <= 5  # False
   ```

These comparison operators can be used in various contexts, such as within list comprehensions, while loops, and function return statements, to filter data, make decisions, or determine relationships between values without explicitly using `if` and `else` statements.

# compare strings in Python

Examples of comparison operators used to compare strings in Python:

```python
string1 = "apple"
string2 = "banana"
string3 = "apple"

# Equality operator (==)
result1 = (string1 == string2)  # False
result2 = (string1 == string3)  # True

# Inequality operator (!=)
result3 = (string1 != string2)  # True
result4 = (string1 != string3)  # False

# Greater than operator (>)
result5 = (string1 > string2)  # False (Lexicographically "apple" < "banana")

# Less than operator (<)
result6 = (string1 < string2)  # True (Lexicographically "apple" < "banana")

# Greater than or equal to operator (>=)
result7 = (string1 >= string2)  # False (Lexicographically "apple" < "banana")
result8 = (string1 >= string3)  # True (Lexicographically "apple" == "apple")

# Less than or equal to operator (<=)
result9 = (string1 <= string2)  # True (Lexicographically "apple" < "banana")
result10 = (string1 <= string3)  # True (Lexicographically "apple" == "apple")
```

In these examples:

- The equality operator (`==`) checks if two strings are equal.
- The inequality operator (`!=`) checks if two strings are not equal.
- The greater than operator (`>`) and less than operator (`<`) compare strings lexicographically based on their Unicode code points.
- The greater than or equal to operator (`>=`) and less than or equal to operator (`<=`) perform lexicographic comparisons with consideration for equality.

These operators allow you to perform various types of string comparisons, which can be useful when working with text data or when you need to sort strings in a specific order.