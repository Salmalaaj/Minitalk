# Minitalk

## Overview

Minitalk is a small data exchange program that uses UNIX signals for communication between a client and a server. The project demonstrates the fundamentals of inter-process communication (IPC) by sending and receiving messages between different processes using only two UNIX signals: `SIGUSR1` and `SIGUSR2`.

## Features

- **Client and Server Implementation**: The project consists of a client and a server. The server must be started first and will print its Process ID (PID) upon launch. The client then uses this PID to send a string message to the server.
- **Signal-Based Communication**: The client sends a message to the server, character by character, using UNIX signals. The server receives the message and prints it out.
- **No Signal Queueing**: The implementation accounts for the fact that Linux does not queue multiple signals of the same type when they are pending.
- **Error Handling**: The program includes thorough error handling to prevent unexpected crashes and memory leaks.

## Files

- **client.c**: Contains the implementation of the client program, which sends a string to the server using signals.
- **server.c**: Contains the implementation of the server program, which receives and prints the string sent by the client.
- **ft_printf.c, ft_putchar.c, ft_putnbr.c**: Utility functions for formatted output, printing characters, and printing numbers. These are used to assist with message formatting and display.
- **ft_atoi.c**: A utility function for converting strings to integers, used for processing command-line arguments (e.g., the server PID).
- **minitalk.h**: Header file containing function prototypes and necessary includes for the project.
- **Makefile**: Automates the compilation of the project. It includes standard rules like `all`, `clean`, `fclean`, and `re`. It also supports compiling the project with or without bonus features.

## Bonus Features

- **Acknowledgement Signal**: The server acknowledges every message received by sending back a signal to the client.
- **Unicode Support**: The implementation includes support for sending and receiving Unicode characters.

## How to Use

### Compilation

To compile the project, use the provided Makefile. The following commands are available:

- `make`: Compiles the mandatory part of the project.
- `make bonus`: Compiles the project with bonus features.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and binaries.
- `make re`: Recompiles the project from scratch.

### Running the Programs

1. Start the server:
   ```bash
   ./server
   ```
   The server will print its PID, which you will need to run the client.
2. Run the client with the server PID and the string to send:
    ```bash
    ./client <server_pid> "Your message here"
    ```
    The server will receive and display the message sent by the client.
## Example
   ```bash
$ ./server
Server PID: 12345

$ ./client 12345 "Hello, World!"
Received message: Hello, World!
   ```
## Notes

- Ensure that you run the server before the client.
- The server can handle multiple clients sending messages sequentially without needing to restart.
- The project handles errors gracefully, and all dynamically allocated memory is properly freed.

## Bonus Notes

- The server will send a confirmation signal back to the client upon successful message reception.
- Extended support for Unicode characters allows the transmission of a wider range of text.


   




