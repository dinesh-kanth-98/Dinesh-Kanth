**<div align="center" >String Slicing Q&A</div>**


### Table of content
- [string slicing](#string-slicing)
  - [string slicing questions](#string-slicing-questions)
  - [string slicing Answers](#string-slicing-answers)

# string slicing

## string slicing questions

1. Given the string `"Hello, World!"`, extract the substring `"Hello"`.
2. Extract the substring `"World"` from the string `"Hello, World!"`.
3. Get the first three characters from the string `"Python is fun"`.
4. Get the last four characters from the string `"Python is awesome"`.
5. Extract every second character from the string `"Programming"`.
6. Reverse the string `"Hello"`.
7. Get the substring `"is"` from the string `"This is a sentence"`.
8. Extract the last three characters from the string `"1234567890"`.
9. Extract the first five characters from the string `"abcdefghijk"` using negative indices.
10. Get the substring `"Python"` from the string `"Python is a powerful language"`.
11. Reverse the string `"12345"`.
12. Extract the last two characters from the string `"Hello, World!"`.
13. Get the substring `"Hello"` from the string `"Hello, Python!"` using negative indices.
14. Reverse the string `"Python is great"`.
15. Extract the first four characters from the string `"Beautiful"`.
16. Get the substring `"world"` from the string `"Hello, world!"`.
17. Reverse the string `"abcdefghijklmnopqrstuvwxyz"`.
18. Extract the substring `"world!"` from the string `"Hello, world!"`.
19. Get the last five characters from the string `"Coding is fun!"`.
20. Extract every third character from the string `"abcdefghijk"`.
21. Reverse the string `"Programming is fun"`.
22. Get the substring `"Hello, World"` from the string `"Hello, World!"`.
23. Extract the first and last characters from the string `"Python"`.
24. Get the substring `"python"` from the string `"Python is easy"`.
25. Reverse the string `"Racecar"`.
26. Extract the last four characters from the string `"Lorem ipsum dolor sit amet"`.
27. Get the substring `"is fun"` from the string `"Coding is fun"`.
28. Reverse the string `"abcdefgh"`.
29. Extract the first three characters and the last three characters from the string `"Data Science"`.
30. Get the substring `"sit"` from the string `"Lorem ipsum dolor sit amet"`.
31. Reverse the string `"Hello, Python"`.
32. Extract the substring `"quick"` from the string `"The quick brown fox"`.
33. Get the last two characters from the string `"Coding is awesome!"`.
34. Extract every fourth character from the string `"abcdefghijklmnopqrstuvwxyz"`.
35. Reverse the string `"Lorem ipsum dolor sit amet, consectetur adipiscing elit"`.
36. Extract the first five characters from the string `"Python is amazing"`.
37. Get the substring `"the"` from the string `"The quick brown fox jumps over the lazy dog"`.
38. Reverse the string `"Hello, World"`.
39. Extract the last six characters from the string `"abcdefghijklmnopqrstuvwxyz"`.
40. Get the substring `"Hello"` from the string `"Hello, World! How are you?"`.
41. Reverse the string `"abcdefg"`.
42. Extract the first and last characters from the string `"Hello, World"`.
43. Get the substring `"fox jumps over"` from the string `"The quick brown fox jumps over the lazy dog"`.
44. Reverse the string `"1234567890"`.
45. Extract the last three characters from the string `"Hello, Python!"`
46. Get the substring `"apple"` from the string `"apple, banana, cherry"`.
47. Reverse the string `"Coding is fun"`.
48. Extract every fifth character from the string `"abcdefghijklmnopqrstuvwxyz"`.
49. Get the substring `"lorem"` from the string `"Lorem ipsum dolor sit amet, consectetur adipiscing elit"`.
50. Reverse the string `"Python is great"`.

## string slicing Answers
    
Practice these string slicing questions to enhance your skills and familiarity with string manipulation in Python.

```python
# Question 1: Given the string "Hello, World!", extract the substring "Hello".
string1 = "Hello, World!"
result1 = string1[:5]
print(result1)  # Output: "Hello"

# Question 2: Extract the substring "World" from the string "Hello, World!".
result2 = string1[7:12]
print(result2)  # Output: "World"

# Question 3: Get the first three characters from the string "Python is fun".
string2 = "Python is fun"
result3 = string2[:3]
print(result3)  # Output: "Pyt"

# Question 4: Get the last four characters from the string "Python is awesome".
string3 = "Python is awesome"
result4 = string3[-4:]
print(result4)  # Output: "some"

# Question 5: Extract every second character from the string "Programming".
string4 = "Programming"
result5 = string4[::2]
print(result5)  # Output: "Pormig"

# Question 6: Reverse the string "Hello".
string5 = "Hello"
result6 = string5[::-1]
print(result6)  # Output: "olleH"

# Question 7: Get the substring "is" from the string "This is a sentence".
string6 = "This is a sentence"
result7 = string6[2:4]
print(result7)  # Output: "is"

# Question 8: Extract the last three characters from the string "1234567890".
string7 = "1234567890"
result8 = string7[-3:]
print(result8)  # Output: "890"

# Question 9: Extract the first five characters from the string "abcdefghijk" using negative indices.
string8 = "abcdefghijk"
result9 = string8[:-6]
print(result9)  # Output: "abcde"

# Question 10: Get the substring "Python" from the string "Python is a powerful language".
string9 = "Python is a powerful language"
result10 = string9[:6]
print(result10)  # Output: "Python"

# Question 11: Reverse the string "12345".
string10 = "12345"
result11 = string10[::-1]
print(result11)  # Output: "54321"

# Question 12: Extract the last two characters from the string "Hello, World!".
result12 = string1[-2:]
print(result12)  # Output: "ld"

# Question 13: Get the substring "Hello" from the string "Hello, Python!" using negative indices.
result13 = string1[:-7]
print(result13)  # Output: "Hello"

# Question 14: Reverse the string "Python is great".
string11 = "Python is great"
result14 = string11[::-1]
print(result14)  # Output: "taerg si nohtyP"

# Question 15: Extract the first four characters from the string "Beautiful".
string12 = "Beautiful"
result15 = string12[:4]
print(result15)  # Output: "Beau"

# Question 16: Get the substring "world" from the string "Hello, world!".
string13 = "Hello, world!"
result16 = string13[7:12]
print(result16)  # Output: "world"

# Question 17: Reverse the string "abcdefghijklmnopqrstuvwxyz".
string14 = "abcdefghijklmnopqrstuvwxyz"
result17 = string14[::-1]
print(result17)  # Output: "zyxwvutsrqponmlkjihgfedcba"

# Question 18: Extract the substring "orld!" from the string "Hello, world!".
result18 = string13[7:]
print(result18)  # Output: "orld!"

# Question 19: Get the substring " is fun" from the string "Coding is fun!".
string15 = "Coding is fun!"
result19 = string15[-5:]
print(result19)  # Output: " is fun"

# Question 20: Extract characters at positions 2, 5, and 8 from the string "abcdefghijk".
string16 = "abcdefghijk"
result20 = string16[2:9:3]
print(result20)  # Output: "cfi"

# Question 21: Reverse the string "Programming is fun".
string17 = "Programming is fun"
result21 = string17[::-1]
print(result21)  # Output: "nuf si gnimmargorP"

# Question 22: Extract the substring "World" from the string "Hello, World!" using negative indices.
result22 = string1[7:-1]
print(result22)  # Output: "World"

# Question 23: Get the substring "Hello, Python" from the string "Hello, Python!" using negative indices.
string18 = "Hello, Python!"
result23 = string18[:-1]
print(result23)  # Output: "Hello, Python"

# Question 24: Extract the character "n" from the string "Hello, Python!" using negative index.
result24 = string22[-2]
print(result24)  # Output: "n"

# Question 25: Extract the substring "on!" from the string "Hello, Python!" using negative indices.
result25 = string20[-3:]
print(result25)  # Output: "on!"

# Question 26: Get the substring "fox jumps over" from the string "The quick brown fox jumps over the lazy dog".
string21 = "The quick brown fox jumps over the lazy dog"
result26 = string21[16:30]
print(result26)  # Output: "fox jumps over"

# Question 27: Reverse the string "Hello, Python!".
result27 = string22[::-1]
print(result27)  # Output: "!nohtyP ,olleH"

# Question 28: Extract characters at positions 0, 3, 6, 9, etc. from the string "Programming is fun".
string23 = "Programming is fun"
result28 = string23[::3]
print(result28)  # Output: "Pgmn  u"

# Question 29: Get the substring ",olleH" from the string "Hello, Python!" using negative indices.
string24 = "Hello, Python!"
result29 = string24[6:-8:-1]
print(result29)  # Output: " ,olleH"

# Question 30: Extract characters at positions 0, 2, 4, 6, etc. from the string "Python is awesome".
string25 = "Python is awesome"
result30 = string25[::2]
print(result30)  # Output: "Pto swe"

# Question 31: Reverse the string "Hello, World!".
string26 = "Hello, World!"
result31 = string26[::-1]
print(result31)  # Output: "!dlroW ,olleH"

# Question 32: Extract the substring "Hello" from the string "Hello, Python!" using negative indices.
result32 = string24[:-8]
print(result32)  # Output: "Hello"

# Question 33: Get the substring "is a powerful" from the string "Python is a powerful language".
string27 = "Python is a powerful language"
result33 = string27[7:18]
print(result33)  # Output: "is a powerful"

# Question 34: Reverse the string "Python is awesome".
string28 = "Python is awesome"
result34 = string28[::-1]
print(result34)  # Output: "emosewa si nohtyP"

# Question 35: Extract the substring "orld!Hello" from the string "Hello, World!Hello".
string29 = "Hello, World!Hello"
result35 = string29[7:14] + string29[:5]
print(result35)  # Output: "orld!Hello"

# Question 36: Get the substring "12345" from the string "12345".
string30 = "12345"
result36 = string30[:]
print(result36)  # Output: "12345"

# Question 37: Reverse the string "Coding is fun!".
string31 = "Coding is fun!"
result37 = string31[::-1]
print(result37)  # Output: "!nuf si gnidoC"

# Question 38: Extract the last four characters from the string "Hello, Python!" using negative indices.
result38 = string24[-4:]
print(result38)  # Output: "thon"

# Question 39: Get the substring "elppa" from the string "apple".
string32 = "apple"
result39 = string32[1:6]
print(result39)  # Output: "elppa"

# Question 40: Extract the character "w" from the string "Hello, world!" using negative index.
result40 = string13[-6]
print(result40)  # Output: "w"

# Question 41: Reverse the string "Python is fun".
string33 = "Python is fun"
result41 = string33[::-1]
print(result41)  # Output: "nuf si nohtyP"

# Question 42: Extract the substring "Python!" from the string "Hello, Python!" using negative indices.
result42 = string24[7:-1]
print(result42)  # Output: "Python"

# Question 43: Get the substring "Python is great" from the string "Python is great".
string34 = "Python is great"
result43 = string34[:]
print(result43)  # Output: "Python is great"

# Question 44: Reverse the string "Programming is fun".
string35 = "Programming is fun"
result44 = string35[::-1]
print(result44)  # Output: "nuf si gnimmargorP"

# Question 45: Extract the substring "Coding" from the string "Coding is fun!".
result45 = string15[:6]
print(result45)  # Output: "Coding"

# Question 46: Get the substring "Program" from the string "Programming is fun".
string36 = "Programming is fun"
result46 = string36[0:7]
print(result46)  # Output: "Program"

# Question 47: Reverse the string "Hello, Python!".
result47 = string24[::-1]
print(result47)  # Output: "!nohtyP ,olleH"

# Question 48: Extract the substring "o, " from the string "Hello, Python!".
result48 = string24[5:8]
print(result48)  # Output: "o, "

# Question 49: Get the substring "gramming is fun" from the string "Programming is fun".
result49 = string35[1:]
print(result49)  # Output: "gramming is fun"

# Question 50: Reverse the string "Hello, Python!".
string37 = "Hello, Python!"
result50 = string37[::-1]
print(result50)  # Output: "!nohtyP ,olleH"
```