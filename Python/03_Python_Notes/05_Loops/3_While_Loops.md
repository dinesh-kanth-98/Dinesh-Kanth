**<div align="center" >While Loop</div>**
### Table of content
- [`while` Loop:](#while-loop)
  - [Examples](#examples)
- [`while...else` Loop](#whileelse-loop)
  - [Basic Syntax:](#basic-syntax)
  - [How It Works](#how-it-works)
  - [Common Use Cases](#common-use-cases)
  - [Examples](#examples-1)
    - [Example 1: Countdown Timer](#example-1-countdown-timer)
    - [Example 2: User Input Validation](#example-2-user-input-validation)
    - [Example 3: Sum of Natural Numbers](#example-3-sum-of-natural-numbers)
  
Certainly! Here's a more detailed and precise explanation of the `while` loop in Python:

# `while` Loop:
The `while` loop is used to repeatedly execute a block of code as long as a specified condition remains `True`. It's a fundamental control flow structure in Python, allowing you to create loops that continue until a specific condition is met or until a certain situation arises. Here's the syntax:

```python
while condition:
    # Code to execute as long as the condition is True
```

- `condition` is a boolean expression that determines whether the loop should continue or terminate.
- The loop iterates as long as the `condition` remains `True`.
- Be cautious when using `while` loops to avoid creating infinite loops, which can lead to your program running indefinitely if the condition never becomes `False`.

## Examples

**Example 1: Basic `while` Loop:**
```python
count = 0
while count < 5:
    print(count)
    count += 1
```

In this example, the loop starts with `count` as 0. It continues to execute the code block as long as `count` is less than 5. With each iteration, `count` is incremented by 1, and the loop continues until the condition is no longer met.

**Example 2: Using `break` to Exit the Loop:**
```python
count = 0
while True:
    print(count)
    count += 1
    if count >= 5:
        break  # Exit the loop when count is greater than or equal to 5
```

In this case, an infinite loop is created using `while True`. The loop continues indefinitely until `break` is encountered, which allows you to exit the loop when a specific condition (e.g., `count >= 5`) is met.

**Example 3: Using `continue` to Skip Iterations:**
```python
count = 0
while count < 5:
    count += 1
    if count == 3:
        continue  # Skip iteration when count is 3
    print(count)
```

Here, `continue` is used to skip a specific iteration when `count` equals 3. The loop continues with the next iteration, bypassing the code below `continue` for that particular iteration.

**Example 4: Infinite Loop with User Input:**
```python
while True:
    user_input = input("Enter 'q' to quit: ")
    if user_input == 'q':
        break  # Exit the loop when 'q' is entered
    print("You entered:", user_input)
```

This example demonstrates how to create a loop that repeatedly prompts the user for input. It continues until the user enters 'q,' at which point the loop is exited using `break`.

> The `while` loop is a versatile and powerful tool in Python, allowing you to create loops that adapt to changing conditions. However, it's important to ensure that your loop's condition eventually becomes `False` to prevent it from running indefinitely.

Certainly! Here's detailed documentation on the `while...else` construct in Python:

# `while...else` Loop

The `while...else` loop is a variation of the standard `while` loop in Python. It provides a way to execute a block of code when a `while` loop finishes its iterations without encountering a `break` statement. This construct is often used when you want to perform an action or check a condition after a loop has completed its execution.

## Basic Syntax:
```python
while condition:
    # Code to execute while the condition is True
else:
    # Code to execute when the loop finishes without a break statement
```

- `condition`: A boolean expression that determines whether the loop should continue or terminate.
- The `while` loop iterates as long as the `condition` remains `True`.

## How It Works

1. The `while` loop starts executing as long as the `condition` is `True`.
2. If a `break` statement is encountered during the loop's execution, the loop is terminated, and the `else` block is skipped.
3. If the loop completes all iterations without encountering a `break` statement, the `else` block is executed once, indicating that the loop finished successfully.

## Common Use Cases

- **Search and Found**: You can use `while...else` to search for an item or condition and handle scenarios where the item or condition is not found.
- **Validation**: It's useful for validation checks within a loop, where you want to check a condition after the loop completes.
- **Loop Completion Checks**: You can determine if a loop has finished its execution without interruptions using the `else` block.

## Examples

### Example 1: Countdown Timer
```python
countdown = 5

while countdown > 0:
    print(countdown)
    countdown -= 1
else:
    print("Blastoff!")
```

In this basic example, a countdown timer starts at 5 and decrements with each iteration of the `while` loop. When the countdown reaches 0, the `else` block executes, displaying "Blastoff!".

### Example 2: User Input Validation
```python
password = "secure123"
attempts = 3

while attempts > 0:
    user_input = input("Enter the password: ")
    if user_input == password:
        print("Access granted!")
        break
    else:
        attempts -= 1
else:
    print("Access denied. Out of attempts.")
```

In this basic example, the program asks the user for a password. The `while` loop allows three attempts to enter the correct password. If the correct password is entered, the loop breaks, and "Access granted!" is displayed. If all attempts are used without success, the `else` block indicates "Access denied."

### Example 3: Sum of Natural Numbers
```python
n = 5
total = 0
counter = 1

while counter <= n:
    total += counter
    counter += 1
else:
    print(f"The sum of the first {n} natural numbers is {total}.")
```

In this basic example, the program calculates the sum of the first 5 natural numbers (1 + 2 + 3 + 4 + 5). The `while` loop iterates through the numbers, accumulating the sum. When the loop completes without a `break`, the `else` block displays the total.