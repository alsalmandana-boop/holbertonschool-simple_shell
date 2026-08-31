# Simple Shell

## Description
Simple Shell is a basic UNIX command-line interpreter written in C. It reads commands entered by the user, processes the command and its arguments, and executes the requested program. The project demonstrates core UNIX concepts such as process creation, command execution, environment variables, and process synchronization using functions and system calls such as `fork()`, `execve()`, and `wait()`. The shell supports both interactive and non-interactive modes, command execution through the `PATH`, and built-in commands such as `exit` and `env`.

## Compilation
Compile all source files using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

After compiling the source files, start the shell by running:

```bash
./hsh
```

The shell can be used in both interactive and non-interactive modes.

### Interactive Mode

Run the shell and enter commands at the prompt:

```bash
$ ./hsh
#cisfun$ /bin/ls
README.md  shell.c  shell.h  hsh
#cisfun$ pwd
/home/user/holbertonschool-simple_shell
#cisfun$ exit
$
```

### Non-Interactive Mode

Commands can also be passed to the shell through standard input:

```bash
$ echo "/bin/ls" | ./hsh
README.md  shell.c  shell.h  hsh
```

## Examples

The shell supports commands with arguments:

```bash
#cisfun$ ls -l /tmp
```

It can locate executable commands using the `PATH` environment variable:

```bash
#cisfun$ ls
```

It also supports built-in commands such as:

```bash
#cisfun$ env
#cisfun$ exit
```

* `env` — Displays the current environment variables.
* `exit` — Exits the shell.

## Authors

This project was developed collaboratively by:

* **Mohammed Abdulaziz Alzouman**
* **Dana Ibrahim Alsalman**
