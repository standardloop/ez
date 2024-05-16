# Palindrome

## Background

A palindrome is a word, number, phrase, or other sequence of symbols that reads the same backwards as forwards

## Task

I want you to write a program that does the following:
- read inputs from `argv`
- process the inputs to see if the given words are palindromes
- print the results and return 0
- if no input is provided, display an error message and return 1

This program should be 30 - 70 LOC (lines of code)

Mine was 45 lines including empty lines

## Example Execution 

```txt
$ ./palindrome
Need an input string!

$ ./palindrome racecar
racecar is a palindrome

$ ./palindrome no rotator josh ez
no is NOT a palindrome
rotator is a palindrome
josh is NOT a palindrome
ez is NOT a palindrome

$ ./palindrome mom dad pop kayak noon wow peep
mom is a palindrome
dad is a palindrome
pop is a palindrome
kayak is a palindrome
noon is a palindrome
wow is a palindrome
peep is a palindrome
```
