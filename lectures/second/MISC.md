## Assignemnts

### print a rectangle

argv[1] to be the art to print

argv[2] to be the width

argv[3] to be the heigh

example:

```sh
$ ./main "*" 3 3
* * * 
* * * 
* * * 
$ ./main "*" 3 2
* * * 
* * * 
$ ./main "*" 2 3
* * 
* *
* *
```

### Convert snake_case to dash-case

argv[1] to be the string to convert

example:

```sh
$ ./main foo_bar
foo-bar
$ ./main 1_2_3_4_5_1
1-2-3-4-5-1
```

### Count the number of words in a file

argv[1] to be the filename

```sh
$ cat file.txt
The quick brown fox jumped over the lazy dog
$ ./main file.txt
8
```
