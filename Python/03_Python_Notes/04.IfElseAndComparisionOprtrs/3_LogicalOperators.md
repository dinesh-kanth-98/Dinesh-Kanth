**<div align="center">Logical Operators</div>**

### Table of content
- [**Logical AND (`and`):**](#logical-and-and)
- [**Logical OR (`or`):**](#logical-or-or)
- [**Logical NOT (`not`):**](#logical-not-not)
- [**Combining Logical Operators:**](#combining-logical-operators)


# **Logical AND (`and`):**
The `and` operator returns `True` if both of its operands are `True`.

```python
x = True
y = False

result = x and y
# result is False because both x and y are not True
```

# **Logical OR (`or`):**
The `or` operator returns `True` if at least one of its operands is `True`.

```python
x = True
y = False

result = x or y
# result is True because x is True, even though y is not True
```
# **Logical NOT (`not`):**
The `not` operator is a unary operator that negates the boolean value of its operand.

```python
x = True

result = not x
# result is False because x is True, and not False is True
```

# **Combining Logical Operators:**
You can combine logical operators to create more complex conditions. Parentheses are often used to control the order of evaluation.

```python
x = True
y = False
z = True

result = (x and y) or (not z)
# result is True because (x and y) is False, and (not z) is True
```