# Word Count

## Background
Many programs track the number of words in a file. For example, Google Doc.

Let's write a C program that can do it for us!

## Task

I want you to write a program that does the following:
- User inputs a single command line argument, the filename to check
- If the user does not provide an argument, exit 1 and print an error message
- Open the file and calculate how many words there are
  - If there are zero words, print "File: empty.txt, does not contain any words"
  - If there is exactly one word, print "File: two.txt, contains 1 word"
  - If there is more than one word in the file, print "File: example.txt, contains 14 words"
  - If the file was able to opened, exit 0

This program should be around 40 - 100 LOC (lines of code)

Mine was 66 lines including empty lines

## Example Execution 

```txt
$ ./word-count fake.txt
Unable to open file fake.txt

$ ./word-count foo.txt
File: foo.txt, contains 9 words

$ ./word-count two.txt
File: two.txt, contains 2 words

$ ./word-count one.txt
File: two.txt, contains 1 word

$ ./word-count empty.txt
File: empty.txt, does not contain any words
```
