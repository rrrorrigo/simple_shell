<div align=center>
    <img style="height:70px;text-align:center" src="https://dl.dropboxusercontent.com/s/bfcg5nzqunl9q6c/Holberton.png?dl=0" alt="Holberton School"/>
    <h1 align="center">Project: 0x16. C - Simple Shell</h1>
</div>

## Requeriments
### General
- Allowed editors: `vi`, `vim`, `emacs`
- All files will be compiled on Ubuntu 14.04 LTS
- The C programs and functions will be compiled with `gcc` 4.8.4 using the flags `-Wall -Werror -Wextra and -pedantic`
- All files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- The code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- The shell should not have any memory leaks
- No more than 5 functions per file
- All header files should be include guarded

## More Info
### Output
- The program must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.
- The only difference is when an error is printed, the name of the program must be equivalent to argv[0]
Example of error with `sh`:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with your program `hsh`:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## List of allowed functions and system calls
- `access`
- `chdir`
- `close`
- `closedir`
- `execve`
- `exit`
- `_exit`
- `fflush`
- `fork`
- `free`
- `getcwd`
- `getline`
- `getpid`
- `isatty`
- `kill`
- `malloc`
- `open`
- `opendir`
- `perror`
- `read`
- `readdir`
- `signal`
- `stat`
- `lstat`
- `fstat`
- `strtok`
- `wait`
- `waitpid`
- `wait3`
- `wait4`
- `write`

### Compilation
The shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

### Testing
The shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Authors
Rodrigo Briones |[GitHub](https://github.com/rrrorrigo) & Rodrigo Delgado |[GitHub](https://github.com/Ro8s).