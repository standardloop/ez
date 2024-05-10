# Agenda

## Questions

### Begineer Operating Systems

- What are the 3 main operating systems?
  - GNU/Linux (commonly known as just Linux)
  - macOS
  - Windows

- Why is Linux so important?
  - It is FOSS (free and open source)

- What is a Linux Distribution?
  - a Linux distribution is essentially a skin of linux
  - It's linux with further customizations and typically added programs
  - Android uses Linux but it is technically not a traditional distribution

- What is the difference between a Kernel and an Operating System?
  - What is the Job of the Kernel?

- If you were programming something small, let's say a TV remote, or maybe a older Radio, would you need an entire operating system installed?
  - No, the purpose of a full operating system is to be able to run more than one program and the same time and download and run new programs
  - Sidetrack point → embedded systems, aka embedded programming, aka embedded systems programming
    - Programing a microcontroller
    - An embedded system is not a general-purpose computer that runs a variety of user installed programs. It generally has a special-limited function (or functions) and the software (firmware) is generally installed at factory.

### Shell

- What is a Shell?
  - A shell is a type of computer program called a command-line interpreter that lets users control their operating systems with command-line.
  - What is the default shell for Linux?
    - bash
  - What is the default shell for Windows?
    - powershell
- What do the following bash commands do:
  - `ls`
  - `pwd`
  - `mkdir <NAME>`
  - `touch <NAME>`
  - `cd <NAME>`
  - `cd ..`
  - `echo`
  - `cat <NAME>`
  - `clear`
  - `history`

## Setup on WSL

- GitHub
  - CLI install https://github.com/cli/cli/blob/trunk/docs/install_linux.md
  - Pull a private repo
- apt
- C locally

## Words of Wisom

Programming is an Art. There is beauty in the logic and organization of information.

In League of Legends. It takes a long time to get to the point where you understand the game and then can start actually playing.

Programming is the same. You need understand what you can do and what tools can accomblish it.

You do not have to learn how to solve everything single problem. You have to learn how to identify patterns and common strategies to tackle them.

---

Later on:

Programming should be the easy part. You are just implementing the logic.

The hard part is designing the solution given constraints.



## Compilers and Programming Languages

- What does it mean to create a programming language?
- AOT vs JIT
- JVM?
- gcc explained
  - introduction to GNU (GNU + Linux)

### How does C get to Binary (Machine Code)?

#### Preprocessing:

At this stage, the preprocessor handles directives starting with '#' in your source code. These directives include #include to include header files, #define for macros, and more. The preprocessor expands macros and includes the content of header files.

```sh
$ gcc -E main.c -o main.i
```
Notice the following:
- `<stdio.h>` was expanded out
- comment was removed
- defined constant was substituted out
- still "C" code

#### Compilation:

The compiler proper translates the preprocessed source code (in the form of an intermediate file) into assembly code specific to the target platform.

```sh
$ gcc -S main.i -o main.s
```
Notice the following:
- We now have assembly code and it is CPU archiecture dependant (x86 or ARM64)
- code that we don't need is discarded (file is relatively small)

#### Assembly:

In this step, the assembly code is converted into machine code. GCC generates an assembly file (with a '.s' extension), which is then passed to an assembler to create an object file (with a '.o' extension)

```sh
$ gcc -c main.s -o main.o
```

Notice following:
- we cannot open this file in a text editor (not human readable anymore)
- `hexdump -C main.o` so see some information

-> quick sidetrack note on binary and hex


#### Linking:

The final step is linking, where the object files generated in the previous step are combined into a single executable file. During this process, unresolved references to functions or variables are resolved. Libraries and runtime support code are also linked to the executable.


```sh
$ gcc main.o -o main
```

Notice the following:
- not human readable
- `hexdump -C main` so see some information
- we can run this program now with `./main`


### AOT vs JIT and Interpreter

#### AOT (Ahead of Time)

example: C

When you compile C, everything is packed and linked up into a single binary that can be run.
But, when you compile, it targets a specific computer archiecture (x86, Arm64). Also, portability of libraries

#### JIT (Just in Time)

example: Java

Jave you first compile into bytecode.

Then the JVM (Java Virtual Machine) uses a JIT to convert the bytecode to Machine code.

Java is very portable


#### Interpreter

example: bash

An interpreter does not generate new machine code.
An interpreter is already a binary.

The interpreter reads a program as an input and then runs (it is already machine code)

An interpreted language is usually more portable, since it can know what system it is running on and adapt.

The bash interpreter is written in C!

hexdump -C /bin/bash

https://git.savannah.gnu.org/cgit/bash.git/

Running bash as a file

```sh
$ which bash
/bin/bash
$ ls
program.sh
$ cat program.sh
#!/bin/bash

echo "Hello World!"

$ chmod +x program.sh  # telling your computer this is an executable
$ ./program.sh         # run normal way
Hello World!
```

#### Corrections

bash doesn't have to be an interpreter language
C doesn't have to be a compiled (AOT) language

A programming language is a defined spec!

You can *implement* a language in 3 ways:
- Static (AOT)
- JIT
- Interpreted


#### Back to C
- C Programming Fundamentals
  - Stack
  - Pointers
  - Heap
  - Memory
  - System Calls

- Projects
  - Write cat in C

## CPU Architecture

### Instruction Sets
- What is a CPU?
  - ISA
    - The Physical Hardware that implements a set of instructions
    - RISC
      - ARM (Apple M1, M2)
      - MIPS
        - I made this at school
    - CISC
      - x86 (AMD (Ryzen), Intel i7)
        - Made originally by Intel, then AMD made it 64bit
      - Complex Instruction Set
  - Stages
    - Fetch
    - Decode
      - [...."opcode" ...."register" ...."register" .... .... ....]
    - Execute
    - Memory
    - WriteBack

- 8 Ideas in Computer Architecture
  - Moores Law
  - Abstraction
  - Common Case Fast
  - Performance via Paarllelism
  - Performance via Pipelining
  - Performance via Prediction
  - Hierarchy of Memories
  - Dependaability via Redundancy
