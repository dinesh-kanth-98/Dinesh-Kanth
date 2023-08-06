**<div align="center" >Arithmetic Operators in Python</div>**

### Table of content
- [Arithmetic Operators in Python](#arithmetic-operators-in-python)
  - [Examples:](#examples)
- [Precedence in Python](#precedence-in-python)
  - [Operator Precedence Table:](#operator-precedence-table)
  - [Example:](#example)
- [Operator Associativity:](#operator-associativity)
- [BODMAS, BIDMAS, and PEMDAS Usage](#bodmas-bidmas-and-pemdas-usage)

## Arithmetic Operators in Python

Arithmetic operators in Python are used to perform various mathematical operations on numeric values. Python provides the following arithmetic operators:

1. **Addition (`+`)**: Adds two operands.
2. **Subtraction (`-`)**: Subtracts the second operand from the first operand.
3. **Multiplication (`*`)**: Multiplies two operands.
4. **Division (`/`)**: Divides the first operand by the second operand.
5. **Floor Division (`//`)**: Performs integer division, discarding the decimal part.
6. **Modulus (`%`)**: Returns the remainder after division.
7. **Exponentiation (`**`)**: Raises the first operand to the power of the second operand.

### Examples:

```python
# Addition
a = 5
b = 3
result = a + b
print(result)  # Output: 8

# Subtraction
x = 10
y = 7
result = x - y
print(result)  # Output: 3

# Multiplication
p = 4
q = 5
result = p * q
print(result)  # Output: 20

# Division
m = 15
n = 4
result = m / n
print(result)  # Output: 3.75

# Floor Division
p = 15
q = 4
result = p // q
print(result)  # Output: 3

# Modulus
x = 13
y = 4
result = x % y
print(result)  # Output: 1

# Exponentiation
a = 2
b = 3
result = a ** b
print(result)  # Output: 8
```

In addition to using arithmetic operators with numeric variables, you can also use them with numeric literals:

```python
result = 10 + 5
print(result)  # Output: 15

result = 7 * 3
print(result)  # Output: 21

result = 16 / 3
print(result)  # Output: 5.333333333333333

result = 16 // 3
print(result)  # Output: 5

result = 20 % 3
print(result)  # Output: 2

result = 2 ** 4
print(result)  # Output: 16
```

Arithmetic operators can be used with variables of different numeric data types (integers, floats, complex numbers) and also mixed data types, as Python automatically performs type conversion when needed.

```python
x = 10
y = 3.5
result = x + y
print(result)  # Output: 13.5

a = 5
b = 2
result = a ** b
print(result)  # Output: 25
```

Arithmetic operators are fundamental for performing mathematical calculations in Python. They allow you to perform addition, subtraction, multiplication, division, and more, making Python a versatile language for numeric computations.

## Precedence in Python

In Python, precedence refers to the order in which operators are evaluated in an expression. It determines which operator is executed first when an expression contains multiple operators.

Python follows the rules of operator precedence similar to the rules used in mathematics. Operators with higher precedence are evaluated first, followed by operators with lower precedence.

Here is a brief overview of the precedence rules in Python from highest to lowest:

1. **Parentheses**: Operators within parentheses are evaluated first.
2. **Exponentiation (`**`)**: Exponentiation is performed next.
3. **Multiplication (`*`), Division (`/`), Floor Division (`//`), Modulus (`%`)**: These multiplication and division operations are evaluated next, from left to right.
4. **Addition (`+`), Subtraction (`-`)**: Addition and subtraction operations are evaluated next, from
5. **Assignment Operators**: These include `=`, `+=`, `-=` and so on. They are evaluated last.

### Operator Precedence Table:

Below is a table that summarizes the precedence of operators in Python from highest to lowest:

| Operator                               | Description                             |
|----------------------------------------|-----------------------------------------|
| `( ... )`                              | Parentheses (grouping)                  |
| `**`                                   | Exponentiation                          |
| `*`, `/`, `//`, `%`                    | Multiplication, Division, Modulus       |
| `+`, `-`                               | Addition, Subtraction                   |
| `=`                                    | Assignment (right to left evaluation)   |
| `+=`, `-=` and other assignment ops    | Assignment with operation               |

### Example:

```python
result = 5 + 3 * 2
print(result)  # Output: 11

result = (5 + 3) * 2
print(result)  # Output: 16

result = 2 ** 3 + 1
print(result)  # Output: 9

result = 10 / 2 * 3
print(result)  # Output: 15.0

result = 10 / (2 * 3)
print(result)  # Output: 1.6666666666666667
```
Understanding operator precedence is crucial when writing complex expressions, as it helps you ensure that your calculations are performed in the desired order. Using parentheses can help explicitly specify the evaluation order in expressions.

## Operator Associativity:

If two operators have the same precedence, their associativity determines the order of evaluation. In Python, most binary operators, such as `+`, `-`, `*`, `/`, `//` and `%`are left-associative, which means they are evaluated from left to right.

For example, in the expression `5 - 3 + 1`, the subtraction (`-`) and addition (`+`) operators have the same precedence, and they are evaluated from left to right. So, the expression is equivalent to `(5 - 3) + 1`, which results in `3`.

However, there are some right-associative operators in Python. The exponentiation operator `**` is right-associative, which means expressions with multiple `**` operators are evaluated from right to left. For example, in the expression `2 ** 3 ** 2`, the rightmost `**` operator is evaluated first, followed by the next one.

Using parentheses can change the order of evaluation and override the default precedence and associativity. For example, in the expression `(2 + 3) * 4`, the addition inside the parentheses is evaluated first due to its higher precedence.

It's essential to understand operator precedence and associativity to ensure that expressions are evaluated correctly and to avoid unexpected results in your Python programs.

## BODMAS, BIDMAS, and PEMDAS Usage

In mathematics and computer programming, BODMAS, BIDMAS, and PEMDAS are mnemonic devices used to remember the order of operations for evaluating arithmetic expressions. They help ensure that expressions are evaluated correctly and consistently, regardless of their complexity. Here's how each system is used:

1. **BODMAS**: Bracket, Order, Division and Multiplication, Addition and Subtraction
   - **Usage**: Follow the order of operations step by step when evaluating an expression.
   - **Example**: `2 + 3 * (5 - 1) / 2`
     - Evaluate parentheses: `5 - 1 = 4`
     - Perform division: `3 * 4 / 2 = 6`
     - Finally, perform addition: `2 + 6 = 8`

2. **BIDMAS**: Bracket, Indices, Division and Multiplication, Addition and Subtraction
   - **Usage**: Similar to BODMAS but emphasizes "Indices" instead of "Order" to handle exponents or powers.
   - **Example**: `2 + 3 ** (5 - 1) / 2`
     - Evaluate parentheses: `5 - 1 = 4`
     - Evaluate exponent: `3 ** 4 = 81`
     - Perform division: `81 / 2 = 40.5`
     - Finally, perform addition: `2 + 40.5 = 42.5`

3. **PEMDAS**: Parentheses, Exponents, Multiplication and Division, Addition and Subtraction
   - **Usage**: Use parentheses to group parts of the expression and follow the order of operations accordingly.
   - **Example**: `2 + 3 * (5 - 1) / 2`
     - Evaluate parentheses: `5 - 1 = 4`
     - Perform multiplication: `3 * 4 = 12`
     - Perform division: `12 / 2 = 6`
     - Finally, perform addition: `2 + 6 = 8`

**Common Principles**:
- Parentheses (Brackets) are always evaluated first, and calculations inside them are done before anything else.
- Exponents (Indices, Order) are evaluated next.
- Division and Multiplication are performed before Addition and Subtraction.
- If there are multiple operations of the same type, they are evaluated from left to right.

**Usage in Programming**:
- In computer programming, understanding the order of operations is crucial for writing correct and efficient code with arithmetic expressions.
- Programming languages, including Python, adhere to the BODMAS, BIDMAS, or PEMDAS rules when evaluating expressions.
- Use parentheses to clarify the order of evaluation or override the default precedence when needed.

**Conclusion**:
BODMAS, BIDMAS, and PEMDAS are important concepts for mathematicians and programmers alike. They provide a systematic approach to handle complex arithmetic expressions and ensure that the results are consistent and accurate. When writing code that involves arithmetic calculations, it's essential to follow the appropriate order of operations to obtain the intended results.