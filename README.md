# Holberton Project: simple_shell


## Table of Contents
* [Description](#description)
* [File Structure](#file-structure)
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Authors](#authors)
* [License](#license)
## Description

This **shell** is intentionally minimalistic, was made in order to practice the basics of C learning, yet includes the basic functionality of a traditional Unix-like command line user interface.
In other words, simple_shell is a program that reads commands provided, check if exists and execute

**Interactive mode**

    test@ubuntu:~/holbertonschool-simple_shell$ ./hsh
    ($) ls
    file1 file2 file3 file4
    ($)

**Non-interactive mode**

    test@ubuntu:~/holbertonschool-simple_shell$ echo "ls" | ./hsh
    file1 file2 file3 file4
    test@ubuntu:~/holbertonschool-simple_shell$

## File Structure

File|Description
---|---
[simple_shell.c](./simple_shell.c)|execute the shell
[main.h](./main.h)|header
[tokenize_line.c](./tokenize_line.c)|tokenize input
[getting_command.c](./getting_command.c)|get path of command
[print_env.c](./print_env.c)|print environment
[3-add_node_end.c](./3-add_node_end.c])|add node at the end of list
[4-free_list.c](./4-free_list.c])|free a list
[man_simple_shell](./man_simple_shell)|man page
[spaces.c](./spaces.c)|validate spaces

## Requirements

simple_shell is designed to run in the `Ubuntu 20.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 9.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

### Allowed functions that we use in SIMPLE_SHELL
* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror`(man 3 perror)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__ xstat) (man 2 stat)
* `lstat` (__ lxstat) (man 2 lstat)
* `fstat` (__ fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)

## Installation

	 - Clone this repository: `https://github.com/EduRamos95/holbertonschool-simple_shell.git`
	 - Change directories into the repository: `cd holbertonschool-simple_shell`
	 - Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
	 - Run the shell in interactive mode: `./hsh`
	 - Or run the shell in non-interactive mode: example `echo "pwd" | ./hsh`

## Usage

The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality. The development of this shell is ongoing. The below features will be checked as they become available (see man page for complete information on usage):
### Features
- [x] uses the PATH
- [x] implements builtins
- [x] handles command line arguments
- [x] custom strtok function
- [x] uses exit status
- [x] shell continues upon Crtl+C (**^C**)
- [ ] handles comments (#)
- [x] handles **;**
- [x] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases
- [ ] variable replacement

### Built-ins

- [x] exit
- [x] env
- [ ] setenv
- [ ] unsetenv
- [ ] cd
- [ ] help
- [ ] history

## Example of Use
Run the executable in your terminal after compiling:
```
($) ls
README.md  3-add_node_end.c  4-free_list.c  getting_command.c  tokenize_line.c
hsh  simple_shell.c  print_env.c  main.h  man_1_simple_shell  spaces.c 
($) pwd
/home/fonsy20/simple_shell
```

```
($) ls -la
total 80
drwxr-xr-x 1 root root  4096 Aug  8 23:51 .
drwxr-xr-x 1 root root  4096 Aug  3 09:30 ..
drwxr-xr-x 1 root root  4096 Aug  8 23:51 .git
-rw-r--r-- 1 root root    15 Aug  8 23:50 .gitignore
-rw-r--r-- 1 root root   643 Aug  8 23:40 3-add_node_end.c
-rw-r--r-- 1 root root   269 Aug  8 23:37 4-free_list.c
-rw-r--r-- 1 root root  4868 Aug  8 23:37 README.md
-rw-r--r-- 1 root root  1356 Aug  8 23:37 getting_command.c
-rwxr-xr-x 1 root root 18272 Aug  8 23:48 hsh
-rw-r--r-- 1 root root   678 Aug  8 23:46 main.h
-rw-r--r-- 1 root root   140 Aug  8 23:43 print_env.c
-rw-r--r-- 1 root root  1114 Aug  8 23:37 simple_shell.c
-rw-r--r-- 1 root root   847 Aug  8 23:37 spaces.c
-rw-r--r-- 1 root root  1146 Aug  8 23:42 tokenize_line.c
($) 
```

## Authors
Edu Ramos | [GitHub](https://github.com/EduRamos95)

Cesar Evanan | [GitHub](https://github.com/Cesar240998)

## License
simple_shell is open source and therefore free to download and use without permission.
