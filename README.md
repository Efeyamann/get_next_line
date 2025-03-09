# get_next_line

A function that reads a line from a file descriptor, one at a time, without using standard I/O functions like `fgets` or `getline`.

## Overview

The `get_next_line` project is part of the 42 curriculum and involves creating a function that reads from a file descriptor and returns each line, handling multiple file descriptors efficiently.

## Features

- Reads from a file descriptor (`fd`) and returns one line at a time.
- Handles multiple file descriptors simultaneously.
- Works with any buffer size (`BUFFER_SIZE`).
- Memory-efficient, using dynamic allocation.

## Function Prototype

```c
char *get_next_line(int fd);
