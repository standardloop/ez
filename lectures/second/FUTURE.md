
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
