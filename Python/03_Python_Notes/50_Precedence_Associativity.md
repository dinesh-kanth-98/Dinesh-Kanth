**<div align="center" >Precedence and Associativity of Operators</div>**

### Table of content
- [Operator Precedence:](#operator-precedence)
- [Operator Associativity:](#operator-associativity)

In Python, the precedence and associativity of operators determine the order in which operators are evaluated in an expression. This is important because it can affect the result of the expression. Operators with higher precedence are evaluated first, and in case of operators with the same precedence, the associativity decides the order of evaluation. Here's a documentation on precedence and associativity of operators in Python:

## Operator Precedence:

The table below lists the precedence of operators in Python, from highest to lowest:

| Precedence | Operators                              | Description                          |
|------------|----------------------------------------|--------------------------------------|
| 1          | `**`                                   | Exponentiation                       |
| 2          | `+x`, `-x`, `~x`                       | Unary positive, unary negation, bitwise NOT |
| 3          | `*`, `/`, `//`, `%`                    | Multiplication, division, floor division, modulus |
| 4          | `+`, `-`                               | Addition, subtraction                |
| 5          | `<<`, `>>`                             | Bitwise left shift, bitwise right shift |
| 6          | `&`                                    | Bitwise AND                          |
| 7          | `^`                                    | Bitwise XOR                          |
| 8          | `|`                                    | Bitwise OR                           |
| 9          | `<`, `<=`, `>`, `>=`, `==`, `!=`       | Comparison operators                 |
| 10         | `not`                                  | Boolean NOT                          |
| 11         | `and`                                  | Boolean AND                          |
| 12         | `or`                                   | Boolean OR                           |

Operators with higher precedence are evaluated before operators with lower precedence. For example, in the expression `2 + 3 * 4`, the multiplication (`*`) is evaluated first due to its higher precedence, and then the addition (`+`) is evaluated.

## Operator Associativity:

If two operators have the same precedence, their associativity determines the order of evaluation. In Python, most binary operators, such as `+`, `-`, `*`, `/`, `//`, `%`, `<<`, `>>`, `&`, `^`, and `|`, are left-associative, which means they are evaluated from left to right.

For example, in the expression `5 - 3 + 1`, the subtraction (`-`) and addition (`+`) operators have the same precedence, and they are evaluated from left to right. So, the expression is equivalent to `(5 - 3) + 1`, which results in `3`.

However, there are some right-associative operators in Python. The exponentiation operator `**` is right-associative, which means expressions with multiple `**` operators are evaluated from right to left. For example, in the expression `2 ** 3 ** 2`, the rightmost `**` operator is evaluated first, followed by the next one.

Using parentheses can change the order of evaluation and override the default precedence and associativity. For example, in the expression `(2 + 3) * 4`, the addition inside the parentheses is evaluated first due to its higher precedence.

It's essential to understand operator precedence and associativity to ensure that expressions are evaluated correctly and to avoid unexpected results in your Python programs.