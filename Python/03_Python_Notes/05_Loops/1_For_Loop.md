**<div align="center" >For Loop</div>**

### Table of content
- [`for` Loop:](#for-loop)
  - [Examples](#examples)
- [for...else](#forelse)
  - [Basic Syntax:](#basic-syntax)
  - [How It Works:](#how-it-works)
  - [Common Use Cases:](#common-use-cases)
  - [Examples:](#examples-1)
  
# `for` Loop:

The `for` loop in Python is used to iterate over a sequence (such as a list, tuple, string, or range) or any iterable object. It allows you to perform a set of statements for each item in the sequence.

The general syntax of a `for` loop is as follows:

```python
for variable in sequence:
    # Code to execute for each item in the sequence
```

- `variable` is a variable that takes on the value of each item in the `sequence` during each iteration.
- `sequence` is the iterable object over which the loop iterates.

## Examples

**Example 1: Iterating Over a List:**
```python
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)
```

**Example 2: Iterating Over a Range:**
```python
for number in range(1, 6):
    print(number)
```

**Example 3: Iterating Over a String:**
```python
word = "Python"
for letter in word:
    print(letter)
```

**Example 4: Using `enumerate` to Get Index and Value:**
```python
fruits = ["apple", "banana", "cherry"]
for index, fruit in enumerate(fruits):
    print(f"Index {index}: {fruit}")
```

**Example 5: Using `for` Loop to Calculate Sum:**
```python
numbers = [1, 2, 3, 4, 5]
sum = 0
for num in numbers:
    sum += num
print("Sum:", sum)
```

**Example 6: Using `for` Loop with Dictionary:**
```python
person = {"name": "Alice", "age": 30, "city": "New York"}
for key, value in person.items():
    print(f"{key}: {value}")
```

# for...else

The `for...else` construct is a unique feature in Python that allows you to add an `else` block to a `for` loop. This `else` block is executed when the loop completes all its iterations without encountering a `break` statement. Here's a detailed explanation of how the `for...else` construct works:

## Basic Syntax:
```python
for variable in iterable:
    # Loop body
else:
    # Code to execute when the loop finishes without a break statement
```

- `variable`: A variable that takes on each item in the `iterable` during each iteration.
- `iterable`: An object that can be iterated over, such as a list, tuple, string, or range.
- The `for` loop iterates through the items in the `iterable`.

## How It Works:

1. The `for` loop starts iterating over the items in the `iterable` one by one, and the loop body is executed for each item.

2. If a `break` statement is encountered during the loop's execution, the loop is immediately terminated, and the `else` block is not executed.

3. If the loop completes all its iterations without encountering a `break` statement, the `else` block is executed once, after the loop finishes.

## Common Use Cases:
- **Search and Found:** You can use `for...else` to search for an item in a collection and perform an action if the item is found or execute an action if the item is not found.

- **Validation:** It can be used for validation checks within a loop. If all items in the collection meet a certain condition, the `else` block can handle the case where no item violates the condition.

- **Loop Completion Checks:** You can use it to determine if a loop has completed successfully without any interruptions.

## Examples:

**Example 1: Finding a Number in a List:**
```python
numbers = [1, 3, 5, 7, 9]
search_number = 5

for num in numbers:
    if num == search_number:
        print(f"{search_number} found!")
        break
else:
    print(f"{search_number} not found in the list.")
```

In this example, we search for a specific number (in this case, 5) within a list of numbers. If the number is found, it prints that it's found and breaks out of the loop. If the loop completes without finding the number, the `else` block is executed, indicating that the number is not in the list.

**Example 2: Finding an Element in a List:**
```python
fruits = ["apple", "banana", "cherry", "date"]
search_item = "cherry"

for fruit in fruits:
    if fruit == search_item:
        print(f"{search_item} found!")
        break
else:
    print(f"{search_item} not found in the list.")
```

In this example, we search for a specific fruit in a list. If the fruit is found, it prints that it's found and breaks out of the loop. If the loop completes without finding the fruit, the `else` block is executed, indicating that the fruit is not in the list.

**Example 3: Loop Completion Check:**
```python
numbers = [1, 2, 3, 4, 5]
for num in numbers:
    if num > 10:
        break
else:
    print("All numbers are less than or equal to 10.")
```

In this example, the loop checks if any number in the list is greater than 10. If it finds such a number, it breaks out of the loop. If none of the numbers exceed 10, the `else` block is executed, indicating that all numbers are less than or equal to 10.

**Example 4: Searching for a Specific Character:**
```python
text = "Hello, World!"
search_char = "o"

for char in text:
    if char == search_char:
        print(f"'{search_char}' found!")
        break
else:
    print(f"'{search_char}' not found in the text.")
```

In this example, we search for a specific character (in this case, "o") within a string. If the character is found, it prints that it's found and breaks out of the loop. If the loop completes without finding the character, the `else` block is executed, indicating that the character is not in the text.

**Example 5: Checking for Vowels:**
```python
word = "Python"
vowels = "AEIOUaeiou"

for char in word:
    if char in vowels:
        print(f"'{char}' is a vowel.")
    else:
        print(f"'{char}' is not a vowel.")
else:
    print("Loop completed.")
```

In this example, we iterate through each character in the word "Python" and check if it's a vowel (either uppercase or lowercase). If a character is a vowel, it prints that it's a vowel; otherwise, it prints that it's not a vowel. After completing the loop, the `else` block is executed to indicate that the loop has finished.

> The `for...else` construct is a useful tool for handling scenarios where you want to perform an action after completing a loop without interruptions. It helps you write more concise and expressive code for certain situations.