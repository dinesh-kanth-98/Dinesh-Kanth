**<div align="center" >Comparison Operators</div>**

### Table of content
- ["if" Statement:](#if-statement)
- ["else" Statement:](#else-statement)
- ["elif" (Else If) Statement:](#elif-else-if-statement)
- [Nested "if" Statements:](#nested-if-statements)


# "if" Statement:
   - The "if" statement is used to conditionally execute a block of code based on a specified condition.
   - Syntax:
     ```python
     if condition:
         # Code block to execute if the condition is True
     ```
   - If the condition specified in the "if" statement is true, the code block under the "if" statement is executed; otherwise, it is skipped.
   - Example:
     ```python
     x = 10
     if x > 5:
         print("x is greater than 5")
     ```
   - In this example, since `x` is greater than 5, the code block under the "if" statement is executed, and the message "x is greater than 5" is printed.

# "else" Statement:
   - The "else" statement is used in conjunction with the "if" statement to provide an alternative code block to execute when the "if" condition is false.
   - Syntax:
     ```python
     if condition:
         # Code block to execute if the condition is True
     else:
         # Code block to execute if the condition is False
     ```
   - If the condition specified in the "if" statement is true, the code block under the "if" is executed; otherwise, the code block under the "else" statement is executed.
   - Example:
     ```python
     x = 3
     if x > 5:
         print("x is greater than 5")
     else:
         print("x is not greater than 5")
     ```
   - In this example, since `x` is not greater than 5, the code block under the "else" statement is executed, and the message "x is not greater than 5" is printed.

Certainly! Here's a detailed explanation of the "elif" (else if) statement and nested "if" statements in Python:

# "elif" (Else If) Statement:
   - The "elif" statement is used when you want to test multiple conditions in sequence after an initial "if" condition is false.
   - It allows you to provide alternative conditions to check if the initial "if" condition is false.
   - Syntax:
     ```python
     if condition1:
         # Code block to execute if condition1 is True
     elif condition2:
         # Code block to execute if condition2 is True
     else:
         # Code block to execute if none of the conditions are True
     ```
   - The conditions are evaluated in order. If `condition1` is true, the code block under `condition1` is executed. If `condition1` is false but `condition2` is true, the code block under `condition2` is executed. If none of the conditions are true, the code block under `else` is executed.
   - Example:
     ```python
     x = 3
     if x > 5:
         print("x is greater than 5")
     elif x == 5:
         print("x is equal to 5")
     else:
         print("x is less than 5")
     ```
   - In this example, since `x` is less than 5, the "elif" condition `x == 5` is checked, and since it's also false, the code block under "else" is executed, resulting in the message "x is less than 5."

# Nested "if" Statements:
   - You can nest "if" statements inside each other to handle more complex conditional logic.
   - This allows you to check conditions within conditions.
   - Syntax:
     ```python
     if condition1:
         # Outer if block
         if condition2:
             # Inner if block
         else:
             # Inner else block
     else:
         # Outer else block
     ```
   - The inner "if" and "else" statements are only evaluated if the condition of the outer "if" statement is true.
   - Example:
     ```python
     x = 10
     y = 5
     if x > 5:
         if y > 2:
             print("Both x and y are greater than their respective thresholds.")
     ```
   - In this example, the inner "if" statement is only evaluated because the outer "if" condition (`x > 5`) is true. If both `x` and `y` meet their respective conditions, the message is printed.