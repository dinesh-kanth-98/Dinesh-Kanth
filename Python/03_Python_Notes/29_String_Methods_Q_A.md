**<div align="center" >String Methods and Functions</div>**

### Table of content
- [100 questions](#100-questions)
- [100 questions Answers](#100-questions-answers)
- [Extra Question And Answer](#extra-question-and-answer)
- [200 Questions](#200-questions)

# 100 questions

100 questions related to string methods in Python:

1. What is a string in Python?
2. How do you create a string in Python?
3. What are some common string methods in Python?
4. How do you access individual characters in a string?
5. How do you find the length of a string?
6. What is string slicing in Python?
7. How do you extract a substring from a string?
8. How do you concatenate two strings?
9. How do you repeat a string multiple times?
10. How do you convert a string to uppercase?
11. How do you convert a string to lowercase?
12. How do you check if a string is in uppercase?
13. How do you check if a string is in lowercase?
14. How do you capitalize the first letter of a string?
15. How do you check if a string starts with a specific prefix?
16. How do you check if a string ends with a specific suffix?
17. How do you check if a string contains a specific substring?
18. How do you check if a string contains only alphanumeric characters?
19. How do you check if a string contains only digits?
20. How do you check if a string contains only letters?
21. How do you check if a string contains only whitespace characters?
22. How do you check if a string contains only printable characters?
23. How do you check if a string contains any non-printable characters?
24. How do you check if a string is empty or contains only whitespace characters?
25. How do you remove leading and trailing whitespace from a string?
26. How do you remove leading and trailing characters from a string?
27. How do you remove all occurrences of a specific character from a string?
28. How do you remove all occurrences of multiple characters from a string?
29. How do you remove specific substrings from a string?
30. How do you split a string into a list of substrings?
31. How do you join a list of strings into a single string?
32. How do you find the index of a specific character in a string?
33. How do you find the index of a specific substring in a string?
34. How do you find the first occurrence of a specific character in a string?
35. How do you find the last occurrence of a specific character in a string?
36. How do you count the occurrences of a specific character in a string?
37. How do you count the occurrences of a specific substring in a string?
38. How do you replace a specific substring with another string in a string?
39. How do you replace all occurrences of a specific character with another character in a string?
40. How do you replace all occurrences of multiple characters with another character in a string?
41. How do you check if a string is a palindrome?
42. How do you reverse a string?
43. How do you split a multiline string into a list of lines?
44. How do you remove all newline characters from a string?
45. How do you remove all punctuation characters from a string?
46. How do you convert a string to a list of characters?
47. How do you convert a list of characters back to a string?
48. How do you check if a string contains non-alphanumeric characters?
49. How do you check if a string contains any special characters?
50. How do you check if a string contains only ASCII characters?
51. How do you convert a string to ASCII values?
52. How do you convert a list of ASCII values back to a string?
53. How do you find the maximum and minimum characters (based on ASCII values) in a string?
54. How do you remove all non-ASCII characters from a string?
55. How do you find the most common character in a string?
56. How do you remove all occurrences of a specific word from a string?
57. How do you check if a string contains a specific word (case-insensitive)?
58. How do you capitalize the first letter of each word in a sentence?
59. How do you check if a string is a valid email address?
60. How do you check if a string is a valid URL?
61. How do you split a string into words?
62. How do you extract the first word from a string?
63. How do you check if a string is a valid Python identifier?
64. How do you check if a string contains only alphanumeric characters and whitespace?
65. How do you convert a string to title case?
66. How do you convert a string to uppercase while keeping the original string unchanged?
67. How do you convert a string to lowercase while keeping the original string unchanged?
68. How do you capitalize the first letter of a string while keeping the original string unchanged?
69. How do you remove all occurrences of a specific substring from a string?
70. How do you check if a string contains any non-alphanumeric characters?
71. How do you check if a string is empty?
72. How do you check if a string is not empty?
73. How do you check if a string is a valid number (integer or float)?
74. How do you check if a string is a valid integer?
75. How do you check if a string is a valid floating-point number?
76. How do you convert a string to an integer?
77. How do you convert a string to a floating-point number?
78. How do you remove whitespace characters from a string?
79. How do you check if a string contains only printable ASCII characters?
80. How do you remove specific non-printable characters from a string?
81. How do you find the first occurrence of a specific character in a string after a certain index?
82. How do you find the last occurrence of a specific character in a string before a certain index?
83. How do you remove all occurrences of a specific character from the beginning of a string?
84. How do you remove all occurrences of a specific character from the end of a string?
85. How do you check if a string contains a specific word (case-sensitive)?
86. How do you check if a string contains a specific word (case-sensitive) without changing the original string?
87. How do you find the index of the last occurrence of a specific substring in a string?
88. How do you remove all occurrences of multiple substrings from a string?
89. How do you remove all occurrences of multiple characters from the beginning of a string?
90. How do you remove all occurrences of multiple characters from the end of a string?
91. How do you remove all occurrences of multiple characters from the beginning and end of a string?
92. How do you check if a string contains any non-alphanumeric characters without using the `isalnum()` method?
93. How do you check if a string contains any special characters without using a predefined list of special characters?
94. How do you remove all occurrences of a specific substring from the beginning and end of a string?
95. How do you remove all occurrences of a specific character from the beginning and end of a string?
96. How do you remove all occurrences of multiple substrings from the beginning and end of a string?
97. How do you remove all occurrences of multiple characters from the beginning and end of a string?
98. How do you check if a string is a valid identifier without using the `isidentifier()` method?
99. How do you find the longest word in a string?
100. How do you find the shortest word in a string?

# 100 questions Answers

1. A string in Python is a sequence of characters enclosed in single quotes ('') or double quotes ("").
2. To create a string in Python, you can use single quotes or double quotes:
```python
str1 = 'Hello, World!'
str2 = "Python is awesome!"
```
1. Some common string methods in Python are `lower()`, `upper()`, `strip()`, `split()`, `replace()`, `startswith()`, `endswith()`, and `find()` among others.
2. You can access individual characters in a string using indexing:
```python
my_string = "Hello"
first_char = my_string[0]  # 'H'
second_char = my_string[1]  # 'e'
```
1. You can find the length of a string using the `len()` function:
```python
my_string = "Hello, World!"
length = len(my_string)  # 13
```
1. String slicing allows you to extract a substring from a string by specifying start and end indices:
```python
my_string = "Hello, World!"
substring = my_string[7:12]  # 'World'
```
1. To extract a substring from a string, you can use slicing or string methods like `split()` or `find()`.
```python
my_string = "Hello, World!"
substring1 = my_string[7:12]  # 'World'
substring2 = my_string.split(", ")[1]  # 'World!'
substring3 = my_string[my_string.find(", ") + 2:]  # 'World!'
```
1. You can concatenate two strings using the `+` operator:
```python
str1 = "Hello"
str2 = "World"
result = str1 + ", " + str2  # 'Hello, World'
```
1. To repeat a string multiple times, you can use the `*` operator:
```python
my_string = "Hello "
repeated_string = my_string * 3  # 'Hello Hello Hello '
```
1.  To convert a string to uppercase, use the `upper()` method:
```python
my_string = "Hello, World!"
uppercase_string = my_string.upper()  # 'HELLO, WORLD!'
```
1.  To convert a string to lowercase, use the `lower()` method:
```python
my_string = "Hello, World!"
lowercase_string = my_string.lower()  # 'hello, world!'
```
1.  To check if a string is in uppercase, use the `isupper()` method:
```python
my_string = "HELLO"
is_uppercase = my_string.isupper()  # True
```
1.  To check if a string is in lowercase, use the `islower()` method:
```python
my_string = "hello"
is_lowercase = my_string.islower()  # True
```
1.  To capitalize the first letter of a string, use the `capitalize()` method:
```python
my_string = "hello, world!"
capitalized_string = my_string.capitalize()  # 'Hello, world!'
```
1.  To check if a string starts with a specific prefix, use the `startswith()` method:
```python
my_string = "Hello, World!"
starts_with_hello = my_string.startswith("Hello")  # True
```
1.  To check if a string ends with a specific suffix, use the `endswith()` method:
```python
my_string = "Hello, World!"
ends_with_world = my_string.endswith("World!")  # True
```
1.  To check if a string contains a specific substring, use the `in` keyword:
```python
my_string = "Hello, World!"
contains_hello = "Hello" in my_string  # True
```
1.  To check if a string contains only alphanumeric characters, use the `isalnum()` method:
```python
my_string = "Hello123"
is_alphanumeric = my_string.isalnum()  # True
```
1.  To check if a string contains only digits, use the `isdigit()` method:
```python
my_string = "12345"
contains_digits = my_string.isdigit()  # True
```
1.  To check if a string contains only letters, use the `isalpha()` method:
```python
my_string = "Hello"
contains_letters = my_string.isalpha()  # True
```
1.  To check if a string contains only whitespace characters, use the `isspace()` method:
```python
my_string = "   "
contains_whitespace = my_string.isspace()  # True
```
22. To check if a string contains only printable characters, use the `isprintable()` method:
```python
my_string = "Hello, World!"
is_printable = my_string.isprintable()  # True
```
1.  To check if a string contains any non-printable characters, use the `isprintable()` method in combination with `not`:
```python
my_string = "Hello\nWorld!"
has_non_printable = not my_string.isprintable()  # True
```
1.  To check if a string is empty or contains only whitespace characters, use the `isspace()` method in combination with `not`:
```python
my_string = "   "
is_empty_or_whitespace = not my_string.strip()  # True
```
1.  To remove leading and trailing whitespace from a string, use the `strip()` method:
```python
my_string = "  Hello, World!  "
trimmed_string = my_string.strip()  # 'Hello, World!'
```
1.  To remove leading and trailing characters from a string, use the `lstrip()` and `rstrip()` methods respectively:
```python
my_string = "****Hello, World!****"
trimmed_string = my_string.lstrip("*").rstrip("*")  # 'Hello, World!'
```
1.  To remove all occurrences of a specific character from a string, use the `replace()` method:
```python
my_string = "Hello, World!"
modified_string = my_string.replace(",", "")  # 'Hello World!'
```
1.  To remove all occurrences of multiple characters from a string, use the `translate()` method:
```python
my_string = "Hello, World!"
translation_table = str.maketrans('', '', ',!')
modified_string = my_string.translate(translation_table)  # 'Hello World'
```
1.  To remove specific substrings from a string, use the `replace()` method:
```python
my_string = "Hello, World!"
modified_string = my_string.replace("Hello, ", "")  # 'World!'
```
1.  To split a string into a list of substrings, use the `split()` method:
```python
my_string = "Hello, World!"
split_list = my_string.split(", ")  # ['Hello', 'World!']
```
1.  To join a list of strings into a single string, use the `join()` method:
```python
words = ['Hello', 'World!']
joined_string = ', '.join(words)  # 'Hello, World!'
```
1.  To find the index of a specific character in a string, use the `index()` method:
```python
my_string = "Hello, World!"
index = my_string.index("W")  # 7


```
33. To find the index of a specific substring in a string, use the `find()` method:
```python
my_string = "Hello, World!"
index = my_string.find("World")  # 7
```
34. To find the first occurrence of a specific character in a string, use the `find()` method:
```python
my_string = "Hello, World!"
first_occurrence = my_string.find("o")  # 4
```
35. To find the last occurrence of a specific character in a string, use the `rfind()` method:
```python
my_string = "Hello, World!"
last_occurrence = my_string.rfind("o")  # 8
```
36. To count the occurrences of a specific character in a string, use the `count()` method:
```python
my_string = "Hello, World!"
count = my_string.count("o")  # 2
```
37. To count the occurrences of a specific substring in a string, use the `count()` method:
```python
my_string = "Hello, World!"
count = my_string.count("l")  # 3
```
38. To replace a specific substring with another string in a string, use the `replace()` method:
```python
my_string = "Hello, World!"
modified_string = my_string.replace("Hello", "Hi")  # 'Hi, World!'
```
39. To replace all occurrences of a specific character with another character in a string, use the `replace()` method:
```python
my_string = "Hello, World!"
modified_string = my_string.replace("o", "x")  # 'Hellx, Wxrld!'
```
40. To replace all occurrences of multiple characters with another character in a string, use the `translate()` method:
```python
my_string = "Hello, World!"
translation_table = str.maketrans('oW', 'xY')
modified_string = my_string.translate(translation_table)  # 'Hellx, Yrld!'
```
Sure! Here are the answers to the questions in code format:

41. To check if a string is a palindrome:
```python
def is_palindrome(s):
    return s == s[::-1]

print(is_palindrome("radar"))  # True
print(is_palindrome("hello"))  # False
```

42. To reverse a string:
```python
def reverse_string(s):
    return s[::-1]

print(reverse_string("hello"))  # "olleh"
```

43. To split a multiline string into a list of lines:
```python
multiline_string = "Line 1\nLine 2\nLine 3"
lines_list = multiline_string.split("\n")
print(lines_list)
# Output: ['Line 1', 'Line 2', 'Line 3']
```

44. To remove all newline characters from a string:
```python
def remove_newlines(s):
    return s.replace("\n", "")

print(remove_newlines("Line 1\nLine 2\nLine 3"))
# Output: "Line 1Line 2Line 3"
```

45. To remove all punctuation characters from a string:
```python
import string

def remove_punctuation(s):
    return s.translate(str.maketrans("", "", string.punctuation))

print(remove_punctuation("Hello, World!"))
# Output: "Hello World"
```

46. To convert a string to a list of characters:
```python
my_string = "Hello"
char_list = list(my_string)
print(char_list)
# Output: ['H', 'e', 'l', 'l', 'o']
```

47. To convert a list of characters back to a string:
```python
char_list = ['H', 'e', 'l', 'l', 'o']
my_string = ''.join(char_list)
print(my_string)
# Output: "Hello"
```

48. To check if a string contains non-alphanumeric characters:
```python
def has_non_alphanumeric(s):
    return not s.isalnum()

print(has_non_alphanumeric("Hello123"))  # False
print(has_non_alphanumeric("Hello 123!"))  # True
```

49. To check if a string contains any special characters:
```python
def has_special_characters(s):
    return any(char for char in s if not char.isalnum() and not char.isspace())

print(has_special_characters("Hello 123!"))  # True
print(has_special_characters("Hello123"))  # False
```

50. To check if a string contains only ASCII characters:
```python
def contains_only_ascii(s):
    return all(ord(char) < 128 for char in s)

print(contains_only_ascii("Hello"))  # True
print(contains_only_ascii("こんにちは"))  # False
```

51. To convert a string to ASCII values:
```python
def string_to_ascii(s):
    return [ord(char) for char in s]

print(string_to_ascii("Hello"))  # [72, 101, 108, 108, 111]
```

52. To convert a list of ASCII values back to a string:
```python
ascii_list = [72, 101, 108, 108, 111]
my_string = ''.join(chr(ascii_val) for ascii_val in ascii_list)
print(my_string)  # "Hello"
```

53. To find the maximum and minimum characters (based on ASCII values) in a string:
```python
def find_max_min_characters(s):
    return max(s), min(s)

print(find_max_min_characters("Hello"))  # ('o', 'H')
```

54. To remove all non-ASCII characters from a string:
```python
def remove_non_ascii(s):
    return ''.join(char for char in s if ord(char) < 128)

print(remove_non_ascii("Helloこんにちは"))  # "Hello"
```

55. To find the most common character in a string:
```python
from collections import Counter

def most_common_character(s):
    char_counts = Counter(s)
    most_common_char, occurrences = char_counts.most_common(1)[0]
    return most_common_char, occurrences

print(most_common_character("Hello, World!"))  # ('l', 3)
```

56. To remove all occurrences of a specific word from a string:
```python
def remove_word_from_string(s, word):
    return s.replace(word, "")

print(remove_word_from_string("Hello, World!", "World"))  # "Hello, !"
```

57. To check if a string contains a specific word (case-insensitive):
```python
def contains_word(s, word):
    return word.lower() in s.lower()

print(contains_word("Hello, World!", "world"))  # True
```

58. To capitalize the first letter of each word in a sentence:
```python
def capitalize_first_letters(s):
    return s.title()

print(capitalize_first_letters("hello, world!"))  # "Hello, World!"
```

59. To check if a string is a valid email address:
```python
import re

def is_valid_email(s):
    pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    return re.match(pattern, s) is not None

print(is_valid_email("user@example.com"))  # True
print(is_valid_email("invalid-email"))  # False
```

60. To check if a string is a valid URL:
```python
import re

def is_valid_url(s):
    pattern = r'^(http|https)://[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    return re.match(pattern, s) is not None

print(is_valid_url("http://www.example.com"))  # True
print(is_valid_url("invalid-url"))  # False
```

61. To split a string into words:
```python
my_string = "Hello, World!"
words_list = my_string.split()
print(words_list)
# Output: ['Hello,', 'World!']
```

62. To extract the first word from a string:
```python
my_string = "Hello, World!"
first_word = my_string.split()[0]
print(first_word)  # 'Hello,'
```

63. To check if a string is a valid Python identifier:
```python
def is_valid_identifier(s):
    return s.isidentifier()

print(is_valid_identifier("variable_name"))  # True
print(is_valid_identifier("123abc"))  # False
```

64. To check if a string contains only alphanumeric characters and whitespace:
```python
def is_alphanumeric_with_whitespace(s):
    return all(char.isalnum() or char.isspace() for char in s)

print(is_alphanumeric_with_whitespace("Hello 123"))  # True
print(is_alphanumeric_with_whitespace("Hello, 123!"))  # False
```

65. To convert a string to title case:
```python
my_string = "hello, world!"
title_case_string = my_string.title()
print(title_case_string)  # "Hello, World!"
```

66. To convert a string to uppercase while keeping the original string unchanged:
```python
my_string = "hello, world!"
uppercase_string = my_string.upper()
print(uppercase_string)  # "HEL

LO, WORLD!"
print(my_string)  # "hello, world!"
```

67. To convert a string to lowercase while keeping the original string unchanged:
```python
my_string = "HELLO, WORLD!"
lowercase_string = my_string.lower()
print(lowercase_string)  # "hello, world!"
print(my_string)  # "HELLO, WORLD!"
```

68. To capitalize the first letter of a string while keeping the original string unchanged:
```python
my_string = "hello, world!"
capitalized_string = my_string.capitalize()
print(capitalized_string)  # "Hello, world!"
print(my_string)  # "hello, world!"
```

69. To remove all occurrences of a specific substring from a string:
```python
def remove_substring(s, substring):
    return s.replace(substring, "")

print(remove_substring("Hello, World!", "World"))  # "Hello, !"
```

70. To check if a string contains any non-alphanumeric characters:
```python
def has_non_alphanumeric(s):
    return any(not char.isalnum() for char in s)

print(has_non_alphanumeric("Hello123"))  # False
print(has_non_alphanumeric("Hello 123!"))  # True
```

71. To check if a string is empty:
```python
def is_empty(s):
    return not bool(s)

print(is_empty(""))  # True
print(is_empty("Hello"))  # False
```

72. To check if a string is not empty:
```python
def is_not_empty(s):
    return bool(s)

print(is_not_empty(""))  # False
print(is_not_empty("Hello"))  # True
```

73. To check if a string is a valid number (integer or float):
```python
def is_valid_number(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

print(is_valid_number("123"))  # True
print(is_valid_number("12.34"))  # True
print(is_valid_number("abc"))  # False
```

74. To check if a string is a valid integer:
```python
def is_valid_integer(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

print(is_valid_integer("123"))  # True
print(is_valid_integer("12.34"))  # False
print(is_valid_integer("abc"))  # False
```

75. To check if a string is a valid floating-point number:
```python
def is_valid_float(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

print(is_valid_float("123"))  # True
print(is_valid_float("12.34"))  # True
print(is_valid_float("abc"))  # False
```

76. To convert a string to an integer:
```python
my_string = "123"
integer_value = int(my_string)
print(integer_value)  # 123
```

77. To convert a string to a floating-point number:
```python
my_string = "12.34"
float_value = float(my_string)
print(float_value)  # 12.34
```

78. To remove whitespace characters from a string:
```python
def remove_whitespace(s):
    return ''.join(char for char in s if not char.isspace())

print(remove_whitespace("Hello 123"))  # "Hello123"
```

79. To check if a string contains only printable ASCII characters:
```python
def contains_only_printable_ascii(s):
    return all(char.isprintable() for char in s)

print(contains_only_printable_ascii("Hello"))  # True
print(contains_only_printable_ascii("Hello\n"))  # False
```

80. To remove specific non-printable characters from a string:
```python
def remove_non_printable(s):
    return ''.join(char for char in s if char.isprintable())

print(remove_non_printable("Hello\nWorld"))  # "HelloWorld"
```

Sure! Here are the answers to the questions in code format:

81. To find the first occurrence of a specific character in a string after a certain index:
```python
def find_first_occurrence_after_index(s, char, index):
    return s.find(char, index)

my_string = "Hello, World!"
index = find_first_occurrence_after_index(my_string, 'o', 5)
print(index)  # 7
```

82. To find the last occurrence of a specific character in a string before a certain index:
```python
def find_last_occurrence_before_index(s, char, index):
    return s.rfind(char, 0, index)

my_string = "Hello, World!"
index = find_last_occurrence_before_index(my_string, 'o', 7)
print(index)  # 4
```

83. To remove all occurrences of a specific character from the beginning of a string:
```python
def remove_character_from_start(s, char):
    return s.lstrip(char)

my_string = ">>>Hello<<<"
new_string = remove_character_from_start(my_string, '>')
print(new_string)  # "Hello<<<"
```

84. To remove all occurrences of a specific character from the end of a string:
```python
def remove_character_from_end(s, char):
    return s.rstrip(char)

my_string = ">>>Hello<<<"
new_string = remove_character_from_end(my_string, '<')
print(new_string)  # ">>>Hello"
```

85. To check if a string contains a specific word (case-sensitive):
```python
def contains_word_case_sensitive(s, word):
    return word in s

my_string = "Hello, World!"
contains_hello = contains_word_case_sensitive(my_string, 'Hello')
print(contains_hello)  # True
```

86. To check if a string contains a specific word (case-sensitive) without changing the original string:
```python
def contains_word_case_sensitive_without_change(s, word):
    return word in s

my_string = "Hello, World!"
contains_hello = contains_word_case_sensitive_without_change(my_string, 'hello')
print(contains_hello)  # False
```

87. To find the index of the last occurrence of a specific substring in a string:
```python
def find_last_occurrence_of_substring(s, sub):
    return s.rfind(sub)

my_string = "Hello, World! Hello!"
index = find_last_occurrence_of_substring(my_string, 'Hello')
print(index)  # 13
```

88. To remove all occurrences of multiple substrings from a string:
```python
def remove_substrings(s, substrings):
    for sub in substrings:
        s = s.replace(sub, '')
    return s

my_string = "Hello, World! How are you?"
substrings_to_remove = ['Hello', 'you']
new_string = remove_substrings(my_string, substrings_to_remove)
print(new_string)  # ", World! How are ?"
```

89. To remove all occurrences of multiple characters from the beginning of a string:
```python
def remove_characters_from_start(s, chars):
    return s.lstrip(chars)

my_string = ">>>Hello<<<"
characters_to_remove = '><'
new_string = remove_characters_from_start(my_string, characters_to_remove)
print(new_string)  # "Hello<<<"
```

90. To remove all occurrences of multiple characters from the end of a string:
```python
def remove_characters_from_end(s, chars):
    return s.rstrip(chars)

my_string = ">>>Hello<<<"
characters_to_remove = '><'
new_string = remove_characters_from_end(my_string, characters_to_remove)
print(new_string)  # ">>>Hello"
```

91. To remove all occurrences of multiple characters from the beginning and end of a string:
```python
def remove_characters_from_both_ends(s, chars):
    return s.strip(chars)

my_string = ">>>Hello<<<"
characters_to_remove = '><'
new_string = remove_characters_from_both_ends(my_string, characters_to_remove)
print(new_string)  # "Hello"
```

92. To check if a string contains any non-alphanumeric characters without using the `isalnum()` method:
```python
def has_non_alphanumeric_without_isalnum(s):
    return any(not char.isalpha() and not char.isdigit() for char in s)

print(has_non_alphanumeric_without_isalnum("Hello123"))  # False
print(has_non_alphanumeric_without_isalnum("Hello 123!"))  # True
```

93. To check if a string contains any special characters without using a predefined list of special characters:
```python
import string

def has_special_characters_without_list(s):
    return any(char for char in s if char not in string.ascii_letters and char not in string.digits)

print(has_special_characters_without_list("Hello123"))  # False
print(has_special_characters_without_list("Hello 123!"))  # True
```

94. To remove all occurrences of a specific substring from the beginning and end of a string:
```python
def remove_substring_from_both_ends(s, sub):
    return s.strip(sub)

my_string = ">>>Hello<<<"
new_string = remove_substring_from_both_ends(my_string, '><')
print(new_string) 

These 200 questions cover a wide range of topics related to basic string manipulation in Python. They should give you a good understanding of the various string operations and functionalities available in Python and help you become proficient in working with strings.
 # "Hello"
```

95. To remove all occurrences of a specific character from the beginning and end of a string:
```python
def remove_character_from_both_ends(s, char):
    return s.strip(char)

my_string = ">>>Hello<<<"
new_string = remove_character_from_both_ends(my_string, '><')
print(new_string)  # "Hello"
```

96. To remove all occurrences of multiple substrings from the beginning and end of a string:
```python
def remove_substrings_from_both_ends(s, substrings):
    for sub in substrings:
        s = s.replace(sub, '')
    return s.strip()

my_string = ">>>Hello<<<, >>>World<<<!"
substrings_to_remove = ['>>>', '<<<']
new_string = remove_substrings_from_both_ends(my_string, substrings_to_remove)
print(new_string)  # "Hello, World!"
```

97. To remove all occurrences of multiple characters from the beginning and end of a string:
```python
def remove_characters_from_both_ends(s, chars):
    return s.strip(chars)

my_string = ">>>Hello<<<"
characters_to_remove = '><'
new_string = remove_characters_from_both_ends(my_string, characters_to_remove)
print(new_string)  # "Hello"
```

98. To check if a string is a valid identifier without using the `isidentifier()` method:
```python
import keyword

def is_valid_identifier_without_isidentifier(s):
    return s.isidentifier() and not keyword.iskeyword(s)

print(is_valid_identifier_without_isidentifier("variable_name"))  # True
print(is_valid_identifier_without_isidentifier("123abc"))  # False
print(is_valid_identifier_without_isidentifier("if"))  # False
```

99. To find the longest word in a string:
```python
def find_longest_word(s):
    words_list = s.split()
    return max(words_list, key=len)

my_string = "Hello, World! How are you?"
longest_word = find_longest_word(my_string)
print(longest_word)  # "Hello,"
```

100. To find the shortest word in a string:
```python
def find_shortest_word(s):
    words_list = s.split()
    return min(words_list, key=len)

my_string = "Hello, World! How are you?"
shortest_word = find_shortest_word(my_string)
print(shortest_word)  # "are"
```

# Extra Question And Answer

Sure! Here are 50 questions and answers based on string methods:

1. How do you check if a string contains a specific substring?
   - Answer: Using the `in` keyword.
   ```python
   string = "Hello, World!"
   contains_substring = "World" in string  # True
   ```

2. How do you check if a string does not contain a specific substring?
   - Answer: Using the `not in` keyword.
   ```python
   string = "Hello, World!"
   does_not_contain_substring = "Python" not in string  # True
   ```

3. How do you check if a string contains any alphanumeric characters?
   - Answer: Using the `isalnum()` method.
   ```python
   string = "Hello123"
   has_alphanumeric = string.isalnum()  # True
   ```

4. How do you check if a string contains any alphabetic characters?
   - Answer: Using the `isalpha()` method.
   ```python
   string = "Hello"
   has_alphabetic = string.isalpha()  # True
   ```

5. How do you check if a string contains any digits?
   - Answer: Using the `isdigit()` method.
   ```python
   string = "123"
   has_digits = string.isdigit()  # True
   ```

6. How do you check if a string contains any lowercase letters?
   - Answer: Using the `islower()` method.
   ```python
   string = "hello"
   has_lowercase = string.islower()  # True
   ```

7. How do you check if a string contains any uppercase letters?
   - Answer: Using the `isupper()` method.
   ```python
   string = "HELLO"
   has_uppercase = string.isupper()  # True
   ```

8. How do you check if a string contains only whitespace characters?
   - Answer: Using the `isspace()` method.
   ```python
   string = "   "
   has_whitespace = string.isspace()  # True
   ```

9. How do you check if a string is titlecased?
   - Answer: Using the `istitle()` method.
   ```python
   string = "Hello World"
   is_titlecased = string.istitle()  # True
   ```

10. How do you check if a string contains only printable characters (excluding whitespace)?
    - Answer: Using the `isprintable()` method.
    ```python
    string = "Hello, World!"
    is_printable = string.isprintable()  # True
    ```

11. How do you check if a string contains only ASCII characters?
    - Answer: Using the `isascii()` method (Python 3.7+).
    ```python
    string = "Hello, World!"
    is_ascii = string.isascii()  # True
    ```

12. How do you check if a string is a valid identifier?
    - Answer: Using the `isidentifier()` method.
    ```python
    string = "my_var"
    is_valid_identifier = string.isidentifier()  # True
    ```

13. How do you check if a string starts with a specific prefix?
    - Answer: Using the `startswith()` method.
    ```python
    string = "Hello, World!"
    starts_with_hello = string.startswith("Hello")  # True
    ```

14. How do you check if a string ends with a specific suffix?
    - Answer: Using the `endswith()` method.
    ```python
    string = "Hello, World!"
    ends_with_world = string.endswith("World!")  # True
    ```

15. How do you capitalize the first letter of a string?
    - Answer: Using the `capitalize()` method.
    ```python
    string = "hello"
    capitalized_string = string.capitalize()  # "Hello"
    ```

16. How do you convert all characters of a string to uppercase?
    - Answer: Using the `upper()` method.
    ```python
    string = "hello"
    uppercase_string = string.upper()  # "HELLO"
    ```

17. How do you convert all characters of a string to lowercase?
    - Answer: Using the `lower()` method.
    ```python
    string = "HELLO"
    lowercase_string = string.lower()  # "hello"
    ```

18. How do you swap the cases of characters in a string?
    - Answer: Using the `swapcase()` method.
    ```python
    string = "Hello, World!"
    swapped_case_string = string.swapcase()  # "hELLO, wORLD!"
    ```

19. How do you remove leading whitespace from a string?
    - Answer: Using the `lstrip()` method.
    ```python
    string = "   Hello"
    trimmed_string = string.lstrip()  # "Hello"
    ```

20. How do you remove trailing whitespace from a string?
    - Answer: Using the `rstrip()` method.
    ```python
    string = "Hello   "
    trimmed_string = string.rstrip()  # "Hello"
    ```

21. How do you remove leading and trailing whitespace from a string?
    - Answer: Using the `strip()` method.
    ```python
    string = "   Hello   "
    trimmed_string = string.strip()  # "Hello"
    ```

22. How do you replace occurrences of a substring with another string?
    - Answer: Using the `replace()` method.
    ```python
    string = "Hello, World!"
    replaced_string = string.replace("World", "Python")  # "Hello, Python!"
    ```

23. How do you count the occurrences of a specific character in a string?
    - Answer: Using the `count()` method.
    ```python
    string = "Hello, World!"
    char_occurrences = string.count("l")  # 3
    ```

24. How do you find the index of the first occurrence of a substring in a string?
    - Answer: Using the `index()` method.
    ```python
    string = "Hello, World!"
    index = string.index("World")  # 7
    ```

25. How do you find the index of the first occurrence of a substring within a specific range?
    - Answer: Using the `index()` method with the `start` and `end` arguments.
    ```python
    string = "Hello, World!"
    index = string.index("o", 5, 10)  # 7
    ```

26. How do you find the index of the last occurrence of a substring in a string?
    - Answer: Using the `rindex()` method.
    ```python
    string = "Hello, World!"
    index = string.rindex("o")  # 8
    ```

27. How do you find the index of the last occurrence of a substring within a specific range?
    - Answer: Using the `rindex()` method with the `start` and `end` arguments.
    ```python
    string = "Hello, World!"
    index = string.rindex("o", 5, 10)  # 7
    ```

28. How do you check if a string contains only decimal digits

?
    - Answer: Using the `isdecimal()` method.
    ```python
    string = "12345"
    is_decimal = string.isdecimal()  # True
    ```

29. How do you check if a string contains only digits (including superscripts, subscripts, etc.)?
    - Answer: Using the `isdigit()` method.
    ```python
    string1 = "123"
    string2 = "²³"  # Superscript 2 and 3
    is_digit1 = string1.isdigit()  # True
    is_digit2 = string2.isdigit()  # True
    ```

30. How do you check if a string contains only numeric characters (including fractions, exponents, etc.)?
    - Answer: Using the `isnumeric()` method.
    ```python
    string1 = "½"  # Fraction 1/2
    string2 = "⁴"  # Superscript 4
    is_numeric1 = string1.isnumeric()  # True
    is_numeric2 = string2.isnumeric()  # True
    ```

31. How do you find the length of a string?
    - Answer: Using the `len()` function.
    ```python
    string = "Hello, World!"
    string_length = len(string)  # 13
    ```

32. How do you split a string into a list of substrings using a delimiter?
    - Answer: Using the `split()` method.
    ```python
    string = "Hello,World"
    substrings = string.split(",")  # ["Hello", "World"]
    ```

33. How do you split a string into a list of substrings using a delimiter and limit the number of splits?
    - Answer: Using the `split()` method with the `maxsplit` argument.
    ```python
    string = "Hello,World,Python"
    substrings = string.split(",", maxsplit=1)  # ["Hello", "World,Python"]
    ```

34. How do you join a list of strings into a single string using a separator?
    - Answer: Using the `join()` method.
    ```python
    words = ["Hello", "World"]
    joined_string = ",".join(words)  # "Hello,World"
    ```

35. How do you remove duplicates from a string while maintaining the order of characters?
    - Answer: Using a loop and a set to keep track of seen characters.
    ```python
    string = "Hello, World!"
    unique_chars = []
    seen_chars = set()
    for char in string:
        if char not in seen_chars:
            unique_chars.append(char)
            seen_chars.add(char)
    unique_string = "".join(unique_chars)  # "Helo, Wrd!"
    ```

36. How do you find the longest word in a string?
    - Answer: Using the `split()` method to separate words and the `max()` function with a custom key.
    ```python
    string = "Hello, World! Welcome to Python."
    longest_word = max(string.split(), key=len)  # "Welcome"
    ```

37. How do you find the most common word in a string?
    - Answer: Using the `collections.Counter` class and the `split()` method.
    ```python
    from collections import Counter

    string = "Hello, World! Welcome to Python. Hello Python!"
    words = string.split()
    word_count = Counter(words)
    most_common_word, count = word_count.most_common(1)[0]  # ('Hello', 2)
    ```

38. How do you find the number of occurrences of a specific word in a string?
    - Answer: Using the `split()` method and counting occurrences in a loop.
    ```python
    string = "Hello, World! Welcome to Python. Hello Python!"
    word_to_count = "Hello"
    words = string.split()
    word_count = sum(1 for word in words if word == word_to_count)  # 2
    ```

39. How do you remove all occurrences of a specific word from a string?
    - Answer: Using the `replace()` method.
    ```python
    string = "Hello, World! Welcome to Python. Hello Python!"
    word_to_remove = "Hello"
    removed_word_string = string.replace(word_to_remove, "")  # ", World! Welcome to Python.  Python!"
    ```

40. How do you replace all occurrences of a specific word in a string with another word?
    - Answer: Using the `replace()` method.
    ```python
    string = "Hello, World! Welcome to Python. Hello Python!"
    word_to_replace = "Hello"
    replacement_word = "Hi"
    replaced_string = string.replace(word_to_replace, replacement_word)
    # "Hi, World! Welcome to Python. Hi Python!"
    ```

41. How do you remove all non-alphanumeric characters from a string?
    - Answer: Using the `translate()` method with a translation table.
    ```python
    string = "Hello, World!"
    translation_table = str.maketrans("", "", "!@#$%^&*()_-+=~`[]{}|;:'\",.<>/?\\")
    alphanumeric_string = string.translate(translation_table)  # "Hello World"
    ```

42. How do you remove all digits from a string?
    - Answer: Using the `translate()` method with a translation table.
    ```python
    string = "Hello123"
    translation_table = str.maketrans("", "", "0123456789")
    no_digits_string = string.translate(translation_table)  # "Hello"
    ```

43. How do you remove all whitespace characters from a string?
    - Answer: Using the `replace()` method.
    ```python
    string = "Hello, World!"
    no_whitespace_string = string.replace(" ", "")  # "Hello,World!"
    ```

44. How do you check if a string is a valid palindrome (reads the same backward as forward)?
    - Answer: Using string slicing and the `==` operator.
    ```python
    string = "racecar"
    is_palindrome = string == string[::-1]  # True
    ```

45. How do you reverse a string?
    - Answer: Using string slicing with step `-1`.
    ```python
    string = "Hello"
    reversed_string = string[::-1]  # "olleH"
    ```

46. How do you concatenate two or more strings together?
    - Answer: Using the `+` operator or the `join()` method.
    ```python
    string1 = "Hello"
    string2 = "World"
    concatenated_string = string1 + ", " + string2  # "Hello, World"
    concatenated_string = ", ".join([string1, string2])  # "Hello, World"
    ```

47. How do you check if a string is a valid email address?
    - Answer: By checking for the presence of "@" and "." in the string.
    ```python
    email = "user@example.com"
    is_valid_email = "@" in email and "." in email  # True
    ```

48. How do you check if a string is a valid URL?
    - Answer: By

 checking for the presence of "http://" or "https://" in the string.
    ```python
    url = "https://www.example.com"
    is_valid_url = url.startswith("http://") or url.startswith("https://")  # True
    ```

49. How do you find the most common character in a string?
    - Answer: Using a dictionary to count character occurrences and finding the maximum value.
    ```python
    string = "Hello, World!"
    char_count = {}
    for char in string:
        char_count[char] = char_count.get(char, 0) + 1
    most_common_char = max(char_count, key=char_count.get)  # "l"
    ```

50. How do you find the least common character in a string?
    - Answer: Using a dictionary to count character occurrences and finding the minimum value.
    ```python
    string = "Hello, World!"
    char_count = {}
    for char in string:
        char_count[char] = char_count.get(char, 0) + 1
    least_common_char = min(char_count, key=char_count.get)  # "H"
    ```

# 200 Questions

1. What is a string in Python?
2. How do you define a string in Python?
3. Can you create a string with single quotes?
4. Can you create a string with double quotes?
5. What is the difference between single and double quotes when creating strings?
6. How do you create a multi-line string in Python?
7. What is the len() function used for with strings?
8. How do you access individual characters in a string?
9. Can you modify characters in a string directly?
10. How do you concatenate two strings in Python?
11. What happens if you add two strings together?
12. Can you use the + operator to concatenate other data types with strings?
13. How do you repeat a string multiple times?
14. How do you check if a substring is present in a string?
15. What is the difference between the find() and index() methods for finding substrings?
16. What happens if a substring is not found in the string with the find() method?
17. What happens if a substring is not found in the string with the index() method?
18. How do you count the occurrences of a substring in a string?
19. How do you replace occurrences of a substring in a string?
20. How do you convert a string to uppercase?
21. How do you convert a string to lowercase?
22. How do you capitalize the first letter of a string?
23. How do you swap the case of a string?
24. How do you remove leading and trailing whitespace from a string?
25. How do you split a string into a list of substrings?
26. What is the default separator used by the split() method?
27. How do you specify a custom separator for the split() method?
28. How do you join a list of strings into a single string?
29. How do you check if a string starts with a specific substring?
30. How do you check if a string ends with a specific substring?
31. How do you check if a string contains only alphabetic characters?
32. How do you check if a string contains only numeric characters?
33. How do you check if a string contains only alphanumeric characters?
34. How do you check if a string contains only whitespace characters?
35. How do you check if a string is a valid identifier (variable name) in Python?
36. How do you check if a string is in title case?
37. How do you check if a string is in uppercase?
38. How do you check if a string is in lowercase?
39. How do you check if a string is printable (contains printable characters)?
40. How do you check if a string is numeric (can be converted to a number)?
41. How do you check if a string is composed of digits?
42. How do you check if a string is composed of letters?
43. How do you check if a string is composed of letters and digits?
44. How do you check if a string is composed of alphanumeric characters and underscores?
45. How do you check if a string contains only whitespace characters or is empty?
46. How do you check if a string is a valid email address?
47. How do you check if a string is a valid URL?
48. How do you remove a specific character from a string?
49. How do you remove all occurrences of a specific character from a string?
50. How do you remove all whitespace characters from a string?
51. How do you remove all non-alphanumeric characters from a string?
52. How do you remove all digits from a string?
53. How do you reverse a string in Python?
54. How do you check if a string is a palindrome?
55. How do you check if a string is an anagram of another string?
56. How do you count the number of words in a string?
57. How do you find the longest word in a string?
58. How do you find the shortest word in a string?
59. How do you capitalize the first letter of each word in a string?
60. How do you capitalize the first letter of each word in a string while ignoring certain words (e.g., "the", "and", "of")?
61. How do you replace all occurrences of a word in a string with another word?
62. How do you reverse the order of words in a string?
63. How do you remove duplicate characters from a string?
64. How do you remove duplicate words from a string?
65. How do you find the most common character in a string?
66. How do you find the least common character in a string?
67. How do you check if two strings are anagrams of each other?
68. How do you check if a string is a valid Python identifier (variable name)?
69. How do you split a string into words using a custom delimiter (not whitespace)?
70. How do you remove all punctuation from a string?
71. How do you remove all special characters from a string?
72. How do you find the index of the first occurrence of a character in a string?
73. How do you find the index of the last occurrence of a character in a string?
74. How do you find the index of the first occurrence of a substring in a string?
75. How do you find the index of the last occurrence of a substring in a string?
76. How do you extract a substring from a string based on its index?
77. How do you extract a substring between two specified indices?
78. How do you extract the first n characters from a string?
79. How do you extract the last n characters from a string?
80. How do you swap two substrings in a string?
81. How do you concatenate two strings while removing the common characters from the end of the first string and the beginning of the second string?
82. How do you create a string that is a repetition of a specific substring n times?
83. How do you remove the first occurrence of a substring from a string?
84. How do you remove the last occurrence of a substring from a string?
85. How do you remove all occurrences of a substring from a string?
86. How do you replace the first occurrence of a substring with another substring in a string?
87. How do you replace the last occurrence of a substring with another substring in a string?
88. How do you replace all occurrences of a substring with another substring in a string?
89. How do you replace a substring in a string using regular expressions?
90. How do you convert a list of strings into a single string with elements separated by a specific character?
91. How do you remove leading zeros from a string representing a number?
92. How do you remove trailing zeros from a string representing a number?
93. How do you check if a string is a valid decimal number?
94. How do you check if a string is a valid integer number?
95. How do you convert a string to a list of characters?
96. How do you convert a list of characters back to a string?
97. How do you convert a string containing binary digits to an integer?
98. How do you convert an integer to a binary string?
99. How do you convert a string containing octal digits to an integer?
100. How do you convert an integer to an octal string?
101. How do you convert a string containing hexadecimal digits to an integer?
102. How do you convert an integer to a hexadecimal string?
103. How do you check if a string contains only printable characters (ASCII characters 32 to 126)?
104. How do you check if a string contains only ASCII characters?
105. How do you encode a string into a byte sequence using a specific encoding (e.g., UTF-8, UTF-16)?
106. How do you decode a byte sequence back to a string using a specific encoding?
107. How do you check if a string contains any non-ASCII characters?
108. How do you remove all non-ASCII characters from a string?
109. How do you remove all ASCII characters from a string?
110. How do you encode a string using base64 encoding?
111. How do you decode a base64 encoded string back to the original string?
112. How do you convert a string to a byte array?
113. How do you convert a byte array to a string?
114. How do you check if a string contains only alphabetic characters and spaces?
115. How do you remove all punctuation and whitespace characters from a string?
116. How do you convert a string to a list of words using whitespace as the delimiter?
117. How do you convert a list of words back to a string using a space as the separator?
118. How do you convert a list of words to a string using a custom delimiter?
119. How do you remove leading and trailing spaces from each word in a string?
120. How do you count the number of occurrences of each word in a string?
121. How do you find the most common word in a string?
122. How do you find the least common word in a string?
123. How do you check if a string contains only alphabetic characters and spaces, ignoring case?
124. How do you remove all non-alphabetic characters and spaces from a string?
125. How do you find the number of uppercase letters in a string?
126. How do you find the number of lowercase letters in a string?
127. How do you find the number of digits in a string?
128. How do you find the number of punctuation characters in a string?
129. How do you find the number of whitespace characters in a string?
130. How do you find the number of alphanumeric characters in a string?
131. How do you find the number of special characters in a string?
132. How do you find the number of occurrences of a specific character in a string?
133. How do you find the number of occurrences of a specific substring in a string?
134. How do you find the number of occurrences of each character in a string?
135. How do you find the number of occurrences of each substring in a string?
136. How do you convert a string containing escape sequences to a raw string?
137. How do you convert a raw string to a string containing escape sequences?
138. How do you check if a string contains any escape sequences?
139. How do you remove all escape sequences from a string?
140. How do you escape special characters in a string using escape sequences?
141. How do you find the first occurrence of a substring in a string using regular expressions?
142. How do you find all occurrences of a substring in a string using regular expressions?
143. How do you find the first occurrence of a word in a string using regular expressions?
144. How do you find all occurrences of a word in a string using regular expressions?
145. How do you extract the first occurrence of a substring in a string using regular expressions?
146. How do you extract all occurrences of a substring in a string using regular expressions?
147. How do you extract the first occurrence of a word in a string using regular expressions?
148. How do you extract all occurrences of a word in a string using regular expressions?
149. How do you replace the first occurrence of a substring with another substring in a string using regular expressions?
150. How do you replace all occurrences of a substring with another substring in a string using regular expressions?
151. How do you replace the first occurrence of a word with another word in a string using regular expressions?
152. How do you replace all occurrences of a word with another word in a string using regular expressions?
153. How do you split a string into words using regular expressions?
154. How do you split a string into sentences using regular expressions?
155. How do you split a string into paragraphs using regular expressions?
156. How do you extract all numbers from a string using regular expressions?
157. How do you extract all email addresses from a string using regular expressions?
158. How do you extract all URLs from a string using regular expressions?
159. How do you extract all dates from a string using regular expressions?
160. How do you extract all phone numbers from a string using regular expressions?
161. How do you extract all IP addresses from a string using regular expressions?
162. How do you extract all domain names from a string using regular expressions?
163. How do you validate a string representing an email address using regular expressions?
164. How do you validate a string representing a URL using regular expressions?
165. How do you validate a string representing a date using regular expressions?
166. How do you validate a string representing a phone number using regular expressions?
167. How do you validate a string representing an IP address using regular expressions?
168. How do you validate a string representing a domain name using regular expressions?
169. How do you extract all words that start with a specific prefix from a string using regular expressions?
170. How do you extract all words that end with a specific suffix from a string using regular expressions?
171. How do you extract all words that contain a specific substring from a string using regular expressions?
172. How do you find the first occurrence of a substring in a string while ignoring case?
173. How do you find all occurrences of a substring in a string while ignoring case?
174. How do you find the first occurrence of a word in a string while ignoring case?


175. How do you find all occurrences of a word in a string while ignoring case?
176. How do you extract the first occurrence of a substring in a string while ignoring case?
177. How do you extract all occurrences of a substring in a string while ignoring case?
178. How do you extract the first occurrence of a word in a string while ignoring case?
179. How do you extract all occurrences of a word in a string while ignoring case?
180. How do you replace the first occurrence of a substring with another substring in a string while ignoring case?
181. How do you replace all occurrences of a substring with another substring in a string while ignoring case?
182. How do you replace the first occurrence of a word with another word in a string while ignoring case?
183. How do you replace all occurrences of a word with another word in a string while ignoring case?
184. How do you split a string into words while ignoring case?
185. How do you split a string into sentences while ignoring case?
186. How do you split a string into paragraphs while ignoring case?
187. How do you extract all numbers from a string while ignoring case?
188. How do you extract all email addresses from a string while ignoring case?
189. How do you extract all URLs from a string while ignoring case?
190. How do you extract all dates from a string while ignoring case?
191. How do you extract all phone numbers from a string while ignoring case?
192. How do you extract all IP addresses from a string while ignoring case?
193. How do you extract all domain names from a string while ignoring case?
194. How do you validate a string representing an email address while ignoring case?
195. How do you validate a string representing a URL while ignoring case?
196. How do you validate a string representing a date while ignoring case?
197. How do you validate a string representing a phone number while ignoring case?
198. How do you validate a string representing an IP address while ignoring case?
199. How do you validate a string representing a domain name while ignoring case?
200. How do you find all words that match a specific pattern (e.g., containing at least two vowels) in a string using regular expressions?
