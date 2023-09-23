# `max()` Function

## Return Value:

The `max()` function in Python is used to find the maximum value from a sequence, such as a list.

## Syntax:

```python
max(sequence)
```

- `sequence`: The sequence from which you want to find the maximum value.

## Parameters:

- `sequence`: Any iterable object, such as a list, tuple, or set.

## Return Value:

- The `max()` function returns the maximum value from the sequence.

## Example:

```python
numbers = [4, 9, 2, 7, 5]
maximum_value = max(numbers)
print(maximum_value)  # Output: 9
```

In this example, the `max()` function is used to find the maximum value from the `numbers` list.

# `min()` Function

The `min()` function in Python is used to find the minimum value from a sequence, such as a list.

## Syntax:

```python
min(sequence)
```

- `sequence`: The sequence from which you want to find the minimum value.

## Parameters:

- `sequence`: Any iterable object, such as a list, tuple, or set.

## Return Value:

- The `min()` function returns the minimum value from the sequence.

## Example:

```python
numbers = [4, 9, 2, 7, 5]
minimum_value = min(numbers)
print(minimum_value)  # Output: 2
```

In this example, the `min()` function is used to find the minimum value from the `numbers` list.

# `len()` Function

The `len()` function in Python is used to find the length (number of elements) of a sequence, such as a list.

## Syntax:

```python
len(sequence)
```

- `sequence`: The sequence for which you want to find the length.

## Parameters:

- `sequence`: Any iterable object, such as a list, tuple, or string.

## Return Value:

- The `len()` function returns the number of elements in the sequence.

## Example:

```python
fruits = ['apple', 'banana', 'orange']
length_of_fruits = len(fruits)
print(length_of_fruits)  # Output: 3
```

In this example, the `len()` function is used to find the number of elements in the `fruits` list.

## `sorted()` Function

The `sorted()` function in Python is used to create a new sorted list from the elements of a sequence, such as a list. It does not modify the original list.

## Syntax:

```python
sorted(sequence, key=None, reverse=False)
```

- `sequence`: The sequence you want to sort.
- `key` (optional): A function that defines the sorting criteria. It takes an element as input and returns a value based on which the sorting is performed. If not provided, the elements are compared directly.
- `reverse` (optional): A boolean value indicating whether to sort the list in descending order (`True`) or ascending order (`False`). The default is `False`.

## Parameters:

- `sequence`: Any iterable object, such as a list, tuple, or set.

## Return Value:

- The `sorted()` function returns a new sorted list.

## Example:

```python
numbers = [4, 9, 2, 7, 5]
sorted_numbers = sorted(numbers)
print(sorted_numbers)  # Output: [2, 4, 5, 7, 9]
```

In this example, the `sorted()` function is used to create a new sorted list from the `numbers` list.

# `sum()` Function

The `sum()` function in Python is used to calculate the sum of all elements in a sequence, such as a list.

## Syntax:

```python
sum(sequence, start=0)
```

- `sequence`: The sequence for which you want to calculate the sum.
- `start` (optional): The initial value of the sum. The default is `0`.

## Parameters:

- `sequence`: Any iterable object, such as a list, tuple, or set.

## Return Value:

- The `sum()` function returns the sum of all elements in the sequence.

## Example:

```python
numbers = [1, 2, 3, 4, 5]
sum_of_numbers = sum(numbers)
print(sum_of_numbers)  # Output: 15
```

In this example, the `sum()` function is used to calculate the sum of all elements in the `numbers` list.