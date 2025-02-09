# Pipex - Unix Pipeline Implementation

A program that simulates the Unix pipeline mechanism, implementing functionality similar to shell command: `< infile cmd1 | cmd2 > outfile`

## 🌟 Features

### Mandatory Part
- Handles exactly 4 arguments: `./pipex infile cmd1 cmd2 outfile`
- Behaves like: `< infile cmd1 | cmd2 > outfile`
- Proper error handling and memory management
- Handles command paths and arguments

### Bonus Part
- Multiple pipes: `./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile`
- Support for `<<` and `>>` operators
- Support for heredoc: `./pipex here_doc LIMITER cmd1 cmd2 outfile`

## 📁 Project Structure

### Mandatory Implementation
```
mandatory_pipex/
├── pipex.c         # Main program
├── pipex.h         # Header file
└── m_utils1-5.c    # Utility functions
```

### Bonus Implementation
```
bonus_pipex/
├── pipex_bonus.c    # Bonus main program
├── pipex_bonus.h    # Bonus header file
├── b_utils1-5.c     # Bonus utility functions
└── get_next_line/   # GNL implementation for heredoc
```

### Printf Implementation
```
ft_printf/
├── Makefile
├── ft_printf.c
├── ft_printf.h
└── print_*.c        # Various printing utilities
```

## 🛠️ Usage

### Compilation
```bash
make        # Compile mandatory part
make bonus  # Compile bonus part
```

### Basic Usage
```bash
./pipex infile "ls -l" "wc -l" outfile
```

### Heredoc Usage (Bonus)
```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

### Multiple Pipes (Bonus)
```bash
./pipex infile "cmd1" "cmd2" "cmd3" "cmd4" outfile
```

## 📝 Examples

### Mandatory Example
```bash
./pipex infile "grep hello" "wc -w" outfile
# Equivalent to: < infile grep hello | wc -w > outfile
```

### Bonus Examples
```bash
# Multiple pipes
./pipex infile "ls -l" "grep .c" "wc -l" outfile

# Heredoc
./pipex here_doc EOF "cat" "grep hello" outfile
```

## ⚠️ Error Handling

- Invalid number of arguments
- File permission errors
- Command not found
- Memory allocation failures
- Pipe creation failures
- Fork failures

## 🔍 Implementation Details

- Uses pipe(), fork(), dup2() system calls
- Proper file descriptor management
- Environment variable handling
- Command path resolution
- Process creation and management
- Signal handling
- Memory leak prevention

## 🧪 Testing

Test with various commands and scenarios:
```bash
# Basic test
./pipex infile "ls" "wc" outfile

# Error handling test
./pipex infile "invalid_cmd" "wc" outfile

# Complex command test
./pipex infile "grep -i hello" "sort -r" outfile
```

## 📜 License

This project is part of the 42 curriculum and is provided as-is.
