**<div align="center" >Parameters and Arguments</div>**

### Table of content
- [Parameters and Arguments](#parameters-and-arguments)
  - [Parameters:](#parameters)
  - [Arguments:](#arguments)


# Parameters and Arguments

In Python, when defining and calling functions or methods, we use the terms "`parameters`" and "`arguments`" to describe the inputs.


## Parameters:

Parameters are like placeholders or variables that you define in the function/method definition. They act as containers for the values that you will provide when calling the function. Parameters are placed inside the parentheses in the function definition and are used to define what kind of input the function expects.

For example, let's create a function called `add_numbers` that takes two parameters, `num1` and `num2`, and returns their sum:

```python
def add_numbers(num1, num2):
    return num1 + num2
```

In this function, `num1` and `num2` are the parameters. They are like blank spaces waiting to be filled with actual values.

## Arguments:

Arguments, on the other hand, are the actual values or expressions that you provide when calling the function. They are the real data that gets passed to the function, filling in the placeholders (parameters) defined in the function's definition.

Now, let's call our `add_numbers` function and provide it with the required arguments:

```python
result = add_numbers(5, 3)
print(result)  # Output: 8
```

In this example, `5` and `3` are the arguments. They are the values that are placed into the `num1` and `num2` parameters when the function is called. So, in this case, `num1` will be `5` and `num2` will be `3` during the execution of the function.

> In summary, parameters are defined in the function's definition, and they act as placeholders for the values you pass to the function when calling it. Arguments are the actual values you provide when calling the function, and they fill in the placeholders (parameters) in the function's code.
