# get_next_line @42-alberto "albrodri"
This project delivers a robust function to read from file descriptors, handling various BUFFER_SIZE values and multiple FDs simultaneously. No leaks, just clean and optimized C code for the 42 Core Curriculum.

<p align="center">
  <img src="https://img.shields.io/badge/Score-0%2F100-success?style=for-the-badge&logo=42" alt="Score 125/100" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C" />
  <img src="https://img.shields.io/badge/Project-42_Core-black?style=for-the-badge" alt="42 Project" />
</p>

## Overview

**get_next_line** is the second project in the 42 Common Core. The goal is to program a function that returns a single line read from a file descriptor (file or standard input) efficiently.

This project introduces the fundamental concept of **static variables** in C and dives deep into dynamic memory management, challenging you to handle data buffers without losing track of the reading process between consecutive calls.

---

## Technical Specifications

* **Prototype:** `char *get_next_line(int fd);`
* **Parameters:** A file descriptor (fd) for reading.
* **Return Value:** * The read line: `String` containing the line value + `\n` (if present).
    * `NULL`: If there is nothing left to read or if an error occurs.
* **Authorized Functions:** `read`, `malloc`, `free`.
* **Bonus:** * Ability to manage **multiple file descriptors** simultaneously.
    * Use of a **single static variable**.

---

## How to Use

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/42-alberto/get_next_line.git
    ```

2.  **Compilation:**
    You must include the `-D BUFFER_SIZE=n` flag to define the read size:
    ```bash
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
    ```

3.  **Basic Usage in C:**
    ```c
    #include "get_next_line.h"
    #include <fcntl.h>
    #include <stdio.h>

    int main(void)
    {
        int     fd;
        char    *line;

        fd = open("test.txt", O_RDONLY);
        while ((line = get_next_line(fd)))
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
        return (0);
    }
    ```

---

## Key Concepts Learned

* **Static Variables:** Learning how to keep data persistent across function calls in the data segment.
* **Buffer Management:** Manipulating reading buffers of variable sizes efficiently.
* **Memory Leak Prevention:** Absolute control over dynamic memory to ensure every `malloc` has a corresponding `free`, especially during read failures.
* **File Descriptors:** Understanding how the OS tracks open files.

---

## Repository Structure

* `get_next_line.c`: Core logic and read flow control.
* `get_next_line_utils.c`: Helper functions for string manipulation.
* `get_next_line.h`: Header file with prototypes, libraries, and macros.

---

<p align="center">
  Developed with coffe and love by Alberto (42 Madrid)
</p>
