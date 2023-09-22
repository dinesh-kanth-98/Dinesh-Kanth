**<div align="center">Lists in Python</div>**

### Table of content
- [Lists in Python](#lists-in-python)
- [Creating Lists](#creating-lists)
- [Accessing Elements](#accessing-elements)
- [List Slicing](#list-slicing)
  - [Syntax:](#syntax)
- [List Slicing with Negative Indices](#list-slicing-with-negative-indices)
  - [Examples:](#examples)
- [List Insertion Methods in Python](#list-insertion-methods-in-python)
  - [`list.append(element)`](#listappendelement)
  - [`list.insert(index, element)`](#listinsertindex-element)
  - [`list.extend(iterable)`](#listextenditerable)
- [List Deletion Methods in Python](#list-deletion-methods-in-python)
  - [`list.pop(index=-1)` Method](#listpopindex-1-method)
    - [Syntax:](#syntax-1)
    - [Parameters:](#parameters)
    - [Return Value:](#return-value)
    - [Examples:](#examples-1)
      - [Example 1: Removing an element by index](#example-1-removing-an-element-by-index)
      - [Example 2: Removing the last element](#example-2-removing-the-last-element)
    - [Remarks:](#remarks)
  - [`list.remove(element)` Method](#listremoveelement-method)
    - [Syntax:](#syntax-2)
    - [Parameters:](#parameters-1)
    - [Return Value:](#return-value-1)
    - [Examples:](#examples-2)
      - [Example 1: Removing an element from the list](#example-1-removing-an-element-from-the-list)
      - [Example 2: Removing a string element](#example-2-removing-a-string-element)
    - [Remarks:](#remarks-1)
  - [`list.clear()` Method](#listclear-method)
    - [Syntax:](#syntax-3)
    - [Parameters:](#parameters-2)
    - [Return Value:](#return-value-2)
    - [Example:](#example)
    - [Remarks:](#remarks-2)
  - [`del` Statement for Lists](#del-statement-for-lists)
    - [Return Value:](#return-value-3)
    - [Syntax for Deleting an Element:](#syntax-for-deleting-an-element)
      - [Example:](#example-1)
    - [Syntax for Deleting the Entire List:](#syntax-for-deleting-the-entire-list)
      - [Example:](#example-2)
    - [Remarks:](#remarks-3)
  - [`list.pop()` vs. `del list[index]`](#listpop-vs-del-listindex)
- [Updating a List in Python](#updating-a-list-in-python)
  - [Modifying Elements:](#modifying-elements)
  - [Updating Multiple Elements:](#updating-multiple-elements)
- [`list.sort(key=None, reverse=False)` Method](#listsortkeynone-reversefalse-method)
  - [Syntax:](#syntax-4)
  - [Parameters:](#parameters-3)
  - [Return Value:](#return-value-4)
  - [Examples:](#examples-3)
    - [Example 1: Sorting a list of integers](#example-1-sorting-a-list-of-integers)
    - [Example 2: Sorting a list of strings by length](#example-2-sorting-a-list-of-strings-by-length)
    - [Example 3: Sorting a list in reverse order](#example-3-sorting-a-list-in-reverse-order)
  - [Remarks:](#remarks-4)
- [`list.reverse()` Method](#listreverse-method)
  - [Syntax:](#syntax-5)
  - [Parameters:](#parameters-4)
  - [Return Value:](#return-value-5)
  - [Example:](#example-3)
  - [Remarks:](#remarks-5)
- [`list.index(element, start=0, end=len(list))` Method](#listindexelement-start0-endlenlist-method)
  - [Syntax:](#syntax-6)
  - [Parameters:](#parameters-5)
  - [Return Value:](#return-value-6)
  - [Example:](#example-4)
  - [Remarks:](#remarks-6)
- [`list.copy()` Method](#listcopy-method)
  - [Syntax:](#syntax-7)
  - [Parameters:](#parameters-6)
  - [Return Value:](#return-value-7)
  - [Example:](#example-5)
  - [Remarks:](#remarks-7)
- [`list.count(element)` Method](#listcountelement-method)
  - [Syntax:](#syntax-8)
  - [Parameters:](#parameters-7)
  - [Return Value:](#return-value-8)
  - [Example:](#example-6)
  - [Remarks:](#remarks-8)

# Lists in Python

A list in Python is a collection of elements, ordered and mutable. Lists can contain elements of different data types, including numbers, strings, other lists, and more. They are defined using square brackets `[]` and elements are separated by commas.

# Creating Lists

You can create a list in Python by simply enclosing the elements inside square brackets:

```python
# Empty list
empty_list = []

# List with elements
numbers = [1, 2, 3, 4, 5]
fruits = ['apple', 'banana', 'orange']
mixed_list = [10, 'hello', True, 3.14]
```

Lists in Python are compound data types, meaning they can hold multiple elements or values. Additionally, they are considered "heterogeneous" because they can store elements of different data types in the same list.

To clarify:

1. **Compound Data Type**:<br>
   Lists in Python are compound data types because they can hold multiple values, allowing you to create collections of items. This means you can store multiple elements in a single list, making it easy to manage and manipulate groups of data.

2. **Heterogeneous Data Type**:<br>
    Lists in Python can contain elements of different data types, such as integers, floats, strings, boolean values, or even other lists or custom objects. This heterogeneity allows for flexibility in organizing and combining various data types within a single list.

For example, a Python list can look like this:

```python
my_list = [1, 3.14, "hello", True, [5, 6, 7]]
```

In this example, the list `my_list` contains elements of different data types: an integer, a float, a string, a boolean value, and another list.

> Having this heterogeneity in lists makes them powerful and versatile data structures, enabling you to handle a wide range of data and create complex data collections for various programming tasks.

# Accessing Elements

You can access elements in a list using their index. The index starts from 0 for the first element and increments by 1 for subsequent elements.

```python
numbers = [1, 2, 3, 4, 5]
print(numbers[0])  # Output: 1
print(numbers[2])  # Output: 3
print(numbers[-1])  # Output: 5 (Negative index accesses elements from the end)
```

# List Slicing

List slicing in Python allows you to extract a portion of a list by specifying the start and end indices. When using negative indices, the slicing starts from the end of the list.

## Syntax:

```python
my_list[start:end]
```

- `start`: The index of the first element to include in the slice.
- `end`: The index of the first element to exclude from the slice.

Both `start` and `end` are optional. If you omit `start`, the slice starts from the beginning of the list (index 0). If you omit `end`, the slice goes until the end of the list.

```python
numbers = [1, 2, 3, 4, 5]
print(numbers[1:4])  # Output: [2, 3, 4] (Elements from index 1 to 3)
print(numbers[:3])  # Output: [1, 2, 3] (Elements from the beginning to index 2)
print(numbers[2:])  # Output: [3, 4, 5] (Elements from index 2 to the end)

nlist = ['a',1,'b', 2,'c', 3,'d', 4,'e', 5]
print(nlist[:7:2])  # Output: ['a''b','c','d'] (Elements slicing using step size)
```

# List Slicing with Negative Indices

List slicing in Python allows you to extract a portion of a list by specifying the start and end indices. When using negative indices, the slicing starts from the end of the list.

## Examples:

Suppose we have the following list:

```python
my_list = [10, 20, 30, 40, 50]
```

1. **Slicing with Negative Indices**:

   - `my_list[:-1]`: Slices all elements of the list except the last one (`[10, 20, 30, 40]`).
   - `my_list[-3:-1]`: Slices elements from the third-to-last up to, but not including, the last element (`[30, 40]`).
   - `my_list[-2:]`: Slices elements from the second-to-last to the end of the list (`[40, 50]`).

2. **Negative Indices with Step Size**:

   You can also use a negative step size in the slicing notation to reverse the order of the elements in the sliced list.

   - `my_list[::-1]`: Reverses the entire list (`[50, 40, 30, 20, 10]`).
   - `my_list[:-3:-1]`: Slices elements from the last two elements in reverse (`[50, 40]`).

- Negative index slicing provides a convenient way to access elements from the end of the list and to create reversed lists.
- It's a powerful feature in Python that allows for more flexible and expressive list manipulations.

# List Insertion Methods in Python

## `list.append(element)`

Appends the given element to the end of the list.

- `element`: The element to be added.

```python
numbers = [1, 2, 3]
numbers.append(4)
print(numbers)  # Output: [1, 2, 3, 4]
```

The element `4` is added to the end of the list.

## `list.insert(index, element)`

Inserts the given element at the specified index in the list.

- `index`: The index where the element will be inserted.
- `element`: The element to be inserted.

```python
fruits = ['apple', 'banana', 'orange']
fruits.insert(1, 'grape')
print(fruits)  # Output: ['apple', 'grape', 'banana', 'orange']

fruits = ['apple', 'banana', 'orange']
fruits.insert(0, 'grape')
print(fruits)  # Output: ['grape', 'apple', 'banana', 'orange']

fruits.insert(-1, 'cherry')
print(fruits)  # Output: ['grape', 'apple', 'banana', 'cherry', 'orange']

```

In this first example, `'grape'` is inserted at index `1`, shifting `'banana'` and `'orange'` one position to the right.

In the Second example, `grape` is inserted at index `0`, pushing all elements to the right.

In the third example, `cherry` is inserted at the `second-to-last` position using a negative index.

> **NOTE**: when u give out of range `index` value, it will add at the last    

## `list.extend(iterable)`

Appends elements from an iterable (e.g., another list or tuple) to the end of the list.

- `iterable`: An iterable containing elements to be added.

```python
numbers = [1, 2, 3]
extra_numbers = [4, 5]
numbers.extend(extra_numbers)
print(numbers)  # Output: [1, 2, 3, 4, 5]
```

Here, `extra_numbers` is appended to `numbers`, and the result is `[1, 2, 3, 4, 5]`.

# List Deletion Methods in Python

## `list.pop(index=-1)` Method

The `pop()` method in Python lists is used to remove and return an element from the list at the specified index. If no index is provided, it removes and returns the last element from the list.

### Syntax:

```python
list.pop(index=-1)
```

- `index` (optional): The index of the element to remove from the list. If not specified, the method removes and returns the last element of the list.

### Parameters:

- `index`: The index of the element to remove. It should be an integer. If the index is out of range (negative or greater than or equal to the length of the list), it raises an `IndexError`.

### Return Value:

- The `pop()` method returns the removed element.

### Examples:

#### Example 1: Removing an element by index

```python
fruits = ['apple', 'banana', 'orange']
removed_fruit = fruits.pop(1)
print(fruits)  # Output: ['apple', 'orange']
print(removed_fruit)  # Output: 'banana'
```

In this example, the `pop()` method removes the element at index `1` ('banana') from the `fruits` list and returns the removed element, which is then stored in the variable `removed_fruit`.

#### Example 2: Removing the last element

```python
numbers = [1, 2, 3, 4]
removed_number = numbers.pop()
print(numbers)  # Output: [1, 2, 3]
print(removed_number)  # Output: 4
```

In this example, since no index is provided, the `pop()` method removes and returns the last element of the `numbers` list, which is `4`.

### Remarks:

- The `pop()` method modifies the original list in place, removing the specified element. If you want to remove an element without modifying the original list, you can use the `del` statement.
- If the provided index is out of range (negative or greater than or equal to the length of the list), the `pop()` method raises an `IndexError`.
- It's important to check if the list is empty before using `pop()` to avoid raising an `IndexError` on an empty list.
- The `pop()` method is useful when you need to extract a specific element from the list while maintaining the list's structure.

The `pop()` method is a handy way to remove elements from lists based on their index, and it is commonly used in various Python programming tasks involving list manipulation and data extraction.


## `list.remove(element)` Method

The `remove()` method in Python lists is used to remove the first occurrence of the specified element from the list.

### Syntax:

```python
list.remove(element)
```

- `element`: The element to be removed from the list. It can be of any data type.

### Parameters:

- `element`: The element that you want to remove from the list.

### Return Value:

- The `remove()` method doesn't return anything. It modifies the original list in place by removing the first occurrence of the specified element.

### Examples:

#### Example 1: Removing an element from the list

```python
numbers = [10, 20, 30, 40, 30, 50]
numbers.remove(30)
print(numbers)  # Output: [10, 20, 40, 30, 50]
```

In this example, the `remove()` method is used to remove the first occurrence of the element `30` from the `numbers` list. After the operation, the list becomes `[10, 20, 40, 30, 50]`.

#### Example 2: Removing a string element

```python
fruits = ['apple', 'banana', 'orange', 'apple']
fruits.remove('apple')
print(fruits)  # Output: ['banana', 'orange', 'apple']
```

Here, the `remove()` method removes the first occurrence of the string `'apple'` from the `fruits` list.

### Remarks:

- If the specified element is not found in the list, the `remove()` method raises a `ValueError`. It's essential to ensure that the element exists in the list before calling the `remove()` method to avoid this error.

  ```python
  numbers = [1, 2, 3]
  if 4 in numbers:
      numbers.remove(4)
  else:
      print("Element not found in the list.")
  ```

- The `remove()` method modifies the original list in place by removing the element. If you want to remove an element by index rather than by its value, you can use the `pop()` method or the `del` statement.
- If the list contains multiple occurrences of the element you want to remove, `remove()` only removes the first occurrence. If you need to remove all occurrences, you can use a loop or list comprehension.

The `remove()` method is a useful tool for removing specific elements from lists when you know the value of the element you want to remove.

## `list.clear()` Method

The `clear()` method in Python lists is used to remove all elements from the list, making it empty.

### Syntax:

```python
list.clear()
```

### Parameters:

- The `clear()` method doesn't take any parameters.

### Return Value:

- The `clear()` method doesn't return anything. It modifies the original list in place by removing all elements.

### Example:

```python
numbers = [1, 2, 3, 4, 5]
numbers.clear()
print(numbers)  # Output: []
```

In this example, the `clear()` method is called on the `numbers` list, which removes all elements from the list, making it an empty list (`[]`).

### Remarks:

- The `clear()` method is useful when you want to remove all elements from a list without creating a new list object. It efficiently empties the list without altering its identity in memory.

- After calling `clear()`, the list becomes empty, and its length becomes zero.

  ```python
  fruits = ['apple', 'banana', 'orange']
  print(len(fruits))  # Output: 3
  
  fruits.clear()
  print(fruits)  # Output: []
  print(len(fruits))  # Output: 0
  ```

- Be cautious when using `clear()` as it permanently removes all elements from the list. If you need to preserve the original list and work with a copy of it, consider using slicing or other list manipulation techniques.

  ```python
  original_list = [1, 2, 3, 4, 5]
  modified_list = original_list[:]  # Creates a copy of the original list
  modified_list.clear()
  print(modified_list)  # Output: []
  print(original_list)  # Output: [1, 2, 3, 4, 5]
  ```

- The `clear()` method is particularly useful when you want to reset or reinitialize a list before populating it with new data.

The `clear()` method provides a straightforward and efficient way to remove all elements from a list, making it an empty list, and it's commonly used in Python programming when dealing with lists that need to be cleared for reuse or other purposes.

Certainly! Here's a detailed documentation on the `del` statement for lists in Python:

## `del` Statement for Lists

The `del` statement in Python is used to delete elements from a list or delete the entire list itself.

### Return Value:
- The `del` statement doesn't return any value. the list is modified in place

### Syntax for Deleting an Element:

```python
del list_name[index]
```

- `list_name`: The name of the list from which you want to delete the element.
- `index`: The index of the element you want to delete.

#### Example:

```python
fruits = ['apple', 'banana', 'orange']
del fruits[1]
print(fruits)  # Output: ['apple', 'orange']
```

In this example, the `del` statement is used to delete the element at index `1` ('banana') from the `fruits` list.

### Syntax for Deleting the Entire List:

```python
del list_name
```

- `list_name`: The name of the list you want to delete entirely.

#### Example:

```python
numbers = [1, 2, 3, 4]
del numbers
# The 'numbers' list is now completely deleted and no longer accessible.
```

In this example, the `del` statement is used to delete the entire `numbers` list, making it no longer accessible in the program.

### Remarks:

- The `del` statement doesn't return any value.
- When using `del` to delete an element, the list is modified in place, and the element at the specified index is removed.

- If you try to access an element or the entire list after it has been deleted using `del`, you will get a `NameError`.

  ```python
  fruits = ['apple', 'banana', 'orange']
  del fruits[1]
  print(fruits[1])  # Raises NameError: name 'fruits' is not defined
  ```

- Deleting a list using `del` also frees up the memory occupied by the list and its elements.

- You can use negative indices with `del` to delete elements from the end of the list.

  ```python
  numbers = [10, 20, 30, 40, 50]
  del numbers[-1]
  print(numbers)  # Output: [10, 20, 30, 40]
  ```

- Be cautious when using `del`, especially when deleting the entire list, as it permanently removes the list and its data from memory.

The `del` statement is a powerful tool for removing elements from lists or deleting entire lists in Python. Use it carefully to ensure that you don't accidentally delete data you need to retain.

## `list.pop()` vs. `del list[index]`

`pop()` allows you to remove an element at a specific index and retrieve its value, while `del list[index]` simply removes the element without returning it.

```python
numbers = [1, 2, 3, 4]
removed_number = numbers.pop(2)
print(numbers)  # Output: [1, 2, 4]
print(removed_number)  # Output: 3

del numbers[1]
print(numbers)  # Output: [1, 4]
```
# Updating a List in Python

## Modifying Elements:

You can modify elements in a list by directly assigning new values to specific indices.

```python
fruits = ['apple', 'banana', 'orange']
fruits[1] = 'grape'
print(fruits)  # Output: ['apple', 'grape', 'orange']
```

In this example, the element at index `1` ('banana') is replaced with `'grape'`, resulting in the updated list `['apple', 'grape', 'orange']`.

## Updating Multiple Elements:

You can update multiple elements in a list using slicing and assignment.

```python
numbers = [1, 2, 3, 4, 5]
numbers[1:4] = [10, 20, 30]
print(numbers)  # Output: [1, 10, 20, 30, 5]
```

In this example, the elements at indices `1` to `3` (inclusive) are replaced with `[10, 20, 30]`, updating the list to `[1, 10, 20, 30, 5]`.

# `list.sort(key=None, reverse=False)` Method

The `sort()` method in Python lists is used to sort the elements of the list in ascending order. It modifies the original list in place.

## Syntax:

```python
list.sort(key=None, reverse=False)
```

- `key` (optional): A function that defines the sorting criteria. It takes an element as input and returns a value based on which the sorting is performed. If not provided, the elements are compared directly.
- `reverse` (optional): A boolean value indicating whether to sort the list in descending order (`True`) or ascending order (`False`). The default is `False`.

## Parameters:

- `key`: A function that takes an element from the list as input and returns a value for sorting. For example, you can use `key=len` to sort strings based on their lengths.

## Return Value:

- The `sort()` method doesn't return anything. It modifies the original list in place, sorting its elements.

## Examples:

### Example 1: Sorting a list of integers

```python
numbers = [5, 2, 9, 1, 5, 6]
numbers.sort()
print(numbers)  # Output: [1, 2, 5, 5, 6, 9]
```

In this example, the `sort()` method sorts the `numbers` list in ascending order.

### Example 2: Sorting a list of strings by length

```python
fruits = ['apple', 'orange', 'banana', 'kiwi']
fruits.sort(key=len)
print(fruits)  # Output: ['kiwi', 'apple', 'orange', 'banana']
```

Here, the `sort()` method sorts the `fruits` list based on the length of each string element.

### Example 3: Sorting a list in reverse order

```python
numbers = [5, 2, 9, 1, 5, 6]
numbers.sort(reverse=True)
print(numbers)  # Output: [9, 6, 5, 5, 2, 1]
```

The `sort()` method can be used with the `reverse=True` argument to sort the list in descending order.

## Remarks:

- The `sort()` method modifies the original list in place. It doesn't create a new sorted list.
- If the elements in the list are not of the same data type, the `sort()` method raises a `TypeError`.

    ```python
    mixed_list = [3, 'apple', 1.5, 'orange']
    mixed_list.sort()  # Raises TypeError: '<' not supported between instances of 'str' and 'int'
    ```

- If you want to sort a list without modifying the original list, you can use the `sorted()` function.

    ```python
    numbers = [5, 2, 9, 1, 5, 6]
    sorted_numbers = sorted(numbers)
    print(sorted_numbers)  # Output: [1, 2, 5, 5, 6, 9]
    print(numbers)  # Output: [5, 2, 9, 1, 5, 6] (Original list remains unchanged)
    ```

# `list.reverse()` Method

The `reverse()` method in Python lists is used to reverse the order of elements in the list. It modifies the original list in place and does not return a new list.

## Syntax:

```python
list.reverse()
```

## Parameters:

- The `reverse()` method doesn't take any parameters.

## Return Value:

- The `reverse()` method doesn't return anything. It modifies the original list in place, reversing the order of its elements.

## Example:

```python
numbers = [1, 2, 3, 4, 5]
numbers.reverse()
print(numbers)  # Output: [5, 4, 3, 2, 1]
```

In this example, the `reverse()` method is used to reverse the `numbers` list.

## Remarks:

- The `reverse()` method modifies the original list in place, meaning it does not create a new list with reversed elements. Instead, it reverses the order of elements directly within the original list.

- If you want to create a new list with reversed elements without modifying the original list, you can use the slice notation.

    ```python
    numbers = [1, 2, 3, 4, 5]
    reversed_numbers = numbers[::-1]
    print(reversed_numbers)  # Output: [5, 4, 3, 2, 1]
    print(numbers)  # Output: [1, 2, 3, 4, 5] (Original list remains unchanged)
    ```

- If the list contains elements of different data types, `reverse()` will still reverse the order of elements without raising any errors.

    ```python
    mixed_list = [1, 'apple', 2.5, [3, 4]]
    mixed_list.reverse()
    print(mixed_list)  # Output: [[3, 4], 2.5, 'apple', 1]
    ```

- Since the `reverse()` method modifies the original list, any references to the list will reflect the reversed order.

    ```python
    fruits = ['apple', 'banana', 'orange']
    reversed_fruits = fruits
    reversed_fruits.reverse()
    print(reversed_fruits)  # Output: ['orange', 'banana', 'apple']
    print(fruits)  # Output: ['orange', 'banana', 'apple'] (Original list is reversed)
    ```


# `list.index(element, start=0, end=len(list))` Method

The `index()` method in Python lists is used to find the index of the first occurrence of a specified element within the list.

## Syntax:

```python
list.index(element, start=0, end=len(list))
```

- `element`: The element whose index you want to find in the list.
- `start` (optional): The starting index for the search. It specifies the index from which the search will begin. The default is `0`.
- `end` (optional): The ending index for the search. It specifies the index at which the search will stop (exclusive). The default is `len(list)`.

## Parameters:

- `element`: The element for which you want to find the index.
- `start`: The index from which the search should start. If specified, the method will search for the element from this index onwards.
- `end`: The index at which the search should stop. If specified, the method will search for the element up to this index (exclusive).

## Return Value:

- The `index()` method returns the index of the first occurrence of the specified element in the list.

## Example:

```python
fruits = ['apple', 'banana', 'orange', 'banana']
first_banana_index = fruits.index('banana')
print(first_banana_index)  # Output: 1

# update value using index method
fruits[fruits.index("banana")] = "grapes"
print(fruits) # Output: ['apple', 'grapes', 'orange', 'banana']
```

In this example, the `index()` method is used to find the index of the first occurrence of the element `'banana'` in the `fruits` list.

## Remarks:

- The `index()` method raises a `ValueError` if the specified element is not found in the list.

    ```python
    numbers = [1, 2, 3, 4, 5]
    index_of_six = numbers.index(6)  # Raises ValueError: 6 is not in list
    ```

- If the specified element appears multiple times in the list, the `index()` method will return the index of the first occurrence.

- You can specify the `start` and `end` parameters to limit the search range within the list.

    ```python
    numbers = [1, 2, 3, 4, 2, 5, 2]
    first_index_of_two = numbers.index(2)
    second_index_of_two = numbers.index(2, first_index_of_two + 1)
    print(first_index_of_two)  # Output: 1
    print(second_index_of_two)  # Output: 4
    ```

- The `index()` method is useful when you want to find the position of a specific element within a list and perform actions based on its location.

- If the list contains nested elements (e.g., lists), the `index()` method only finds the index of the first direct occurrence of the specified element.

# `list.copy()` Method

The `copy()` method in Python lists is used to create a shallow copy of the original list. It returns a new list with the same elements as the original list.

## Syntax:

```python
list.copy()
```

## Parameters:

- The `copy()` method doesn't take any parameters.

## Return Value:

- The `copy()` method returns a new list that is a shallow copy of the original list.

## Example:

```python
fruits = ['apple', 'banana', 'orange']
fruits_copy = fruits.copy()
print(fruits_copy)  # Output: ['apple', 'banana', 'orange']
```

In this example, the `copy()` method is used to create a new list `fruits_copy` that is a shallow copy of the `fruits` list.

## Remarks:

- A shallow copy of a list creates a new list object, but it does not create new objects for the elements within the list. Instead, it copies the references to the same elements. This means that if the elements are mutable objects (e.g., lists, dictionaries), changes made to the elements in one list will be reflected in the other list as well.

    ```python
    original_list = [[1, 2], [3, 4]]
    shallow_copy = original_list.copy()

    # Modifying an element in the original list affects the shallow copy
    original_list[0][0] = 100
    print(shallow_copy)  # Output: [[100, 2], [3, 4]]
    ```

- To create a deep copy (a new list with completely independent copies of the elements), you can use the `copy` module's `deepcopy()` function from the `copy` module.

    ```python
    import copy

    original_list = [[1, 2], [3, 4]]
    deep_copy = copy.deepcopy(original_list)

    # Modifying an element in the original list doesn't affect the deep copy
    original_list[0][0] = 100
    print(deep_copy)  # Output: [[1, 2], [3, 4]]
    ```

- The `copy()` method is an effective way to duplicate a list and perform separate operations on each copy without affecting the original list.

- Shallow copies are generally faster than deep copies because they share the same references for elements.

# `list.count(element)` Method

The `count()` method in Python lists is used to count the number of occurrences of a specified element in the list.

## Syntax:

```python
list.count(element)
```

- `element`: The element whose occurrences you want to count in the list.

## Parameters:

- `element`: The element for which you want to count occurrences.

## Return Value:

- The `count()` method returns an integer that represents the number of occurrences of the specified element in the list.

## Example:

```python
numbers = [1, 2, 2, 3, 2, 4]
count_of_twos = numbers.count(2)
print(count_of_twos)  # Output: 3
```

In this example, the `count()` method is used to count the occurrences of the element `2` in the `numbers` list.

## Remarks:

- The `count()` method is case-sensitive, so it will count occurrences of the specified element as they are in the list.

    ```python
    fruits = ['apple', 'Apple', 'banana', 'apple']
    count_of_apple = fruits.count('apple')
    print(count_of_apple)  # Output: 2
    ```

- If the specified element is not found in the list, the `count()` method returns `0`.

    ```python
    numbers = [1, 2, 3, 4, 5]
    count_of_six = numbers.count(6)
    print(count_of_six)  # Output: 0
    ```

- The `count()` method can be useful when you want to check how many times a particular element appears in a list, and you can use it to find duplicates or frequencies of elements.

- It's important to note that the `count()` method only counts direct occurrences of the element, not nested occurrences in sub-lists (if the list contains nested lists).

    ```python
    nested_list = [1, [2, 3], [2, 4], 2]
    count_of_twos = nested_list.count(2)
    print(count_of_twos)  # Output: 1 (Only the direct occurrence of 2 is counted)
    ```