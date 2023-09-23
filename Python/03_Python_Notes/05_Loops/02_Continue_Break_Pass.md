**<div align="center" >Short Circuiting</div>**

### Table of content
- [`continue` Statement:](#continue-statement)
- [`break` Statement:](#break-statement)
- [`pass` Statement:](#pass-statement)

Certainly! Here's documentation on the `continue`, `pass`, and `break` statements in Python:

# `continue` Statement:
The `continue` statement is used inside loops (such as `for` and `while` loops) to skip the rest of the current iteration and move on to the next iteration. It allows you to control the flow of the loop by skipping specific iterations based on conditions.

- When `continue` is encountered in a loop, the remaining code in the current iteration is skipped, and the loop immediately proceeds with the next iteration.
- It's useful for skipping specific iterations without exiting the loop entirely.

**Syntax:**
```python
continue
```

**Example:**
```python
for i in range(1, 6):
    if i == 3:
        continue  # Skip iteration when i is 3
    print(i)
```

# `break` Statement:
The `break` statement is used to exit a loop prematurely. When `break` is encountered inside a loop, the loop is immediately terminated, and control moves to the next statement after the loop.

- It's often used to exit a loop when a certain condition is met or to stop an infinite loop.
- It's important to use `break` judiciously to avoid unintentionally terminating loops.

**Syntax:**
```python
break
```

**Example:**
```python
for i in range(1, 6):
    if i == 4:
        break  # Exit the loop when i is 4
    print(i)
```

# `pass` Statement:
The `pass` statement in Python is a placeholder statement that does nothing. It is often used as a placeholder when writing code that is not yet implemented or when you need a statement that doesn't affect the program's behavior.

- `pass` is a no-op (no operation) statement, meaning it has no effect on the program's execution.
- It's useful for creating stubs or defining empty classes and functions.

**Syntax:**
```python
pass
```

**Example:**
```python
for i in range(3):
    pass  # Placeholder for future implementation
```

In this example, the `while` loop continues indefinitely until the user enters 'q,' at which point the loop is exited using `break`.

These control flow statements (`continue`, `pass`, and `break`) are essential for writing flexible and responsive code in Python. They allow you to skip specific iterations, create placeholders, and exit loops as needed to achieve the desired program behavior.