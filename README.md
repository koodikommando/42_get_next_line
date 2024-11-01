# Get Next Line

A project from the 42 curriculum focused on reading a line from a file descriptor, one line at a time. This project aims to demonstrate file handling, buffer management, and memory allocation in C.

## Overview

The get_next_line function reads a line (ending with a newline character) from a file descriptor each time it is called. It’s designed to handle both small and large buffers efficiently, without exceeding memory constraints.

### Features

	•	Reads one line at a time from a given file descriptor.
	•	Uses a specified buffer size for optimized memory handling.
	•	Handles edge cases, such as lines longer than the buffer size, end-of-file, and empty files and lines.

## Usage

1. Cloning the Repository

To start, clone the repository:

git clone https://github.com/koodikommando/42_get_next_line.git
cd get_next_line

2. Compilation

Use the provided Makefile to compile get_next_line:

make

3. Function Prototype

In your project, include the following function prototype:

char *get_next_line(int fd);

4. Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Project Structure

	•	get_next_line.c: Contains the main get_next_line function.
	•	get_next_line_utils.c: Helper functions for memory management.
	•	get_next_line.h: Header file with function prototypes and constants.
	•	Makefile: To compile the project and create the executable.

