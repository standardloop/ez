
  - Compiler Frontend
    - frontend translates a computer programming source code into an intermediate representation
    - backend works with the intermediate representation to produce code in a computer output language.
- Later on, we will come back to this (how do compilers analyze code?) but sufficient for now


## Linux Philosophy

- Write small programs that do one thing (within reason)
- Have the output of one program be the input of another program
  - `|` Piping
    - `$ cat foo.txt | grep "josh"`
    - `$ cat foo.txt | tail -1`
    - `$ cat foo.txt | head -1`
      - `cat` a file but use `tail` to see x amount of lines
    - `$ curl https://api.chucknorris.io/jokes/random | jq`
      - output of `curl` into `jq` to format it


## bash commands

`$ echo $? # exit code of last program run`


## System calls
https://www.geeksforgeeks.org/introduction-of-system-call/


## Programming Patterns and Rules

- What Computers and Programming is about
  - logic and organization of information


- Engineering Stratagies
  - You do not have to learn how to solve everything single problem. 
    - You have to learn how to identify patterns and common strategies to tackle them.

- 3 things every program does
  - take in some input
  - process the input
  - send the processed input as output somewhere

- Program Categories Broadly 
  - writing a program to store something
  - writing a program to calculate something on the fly


