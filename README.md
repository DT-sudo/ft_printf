# ft_printf

*This project has been created as part of the 42 curriculum.*

## Description

`ft_printf` is a reimplementation of the C library's `printf()`. It handles
a variable number of arguments through `<stdarg.h>`, parses the format
string, dispatches each conversion to a dedicated handler, and returns the
total number of characters printed.

The result is compiled into a static library `libftprintf.a`.

## Supported conversions

| Specifier | Prints |
| --- | --- |
| `%c` | a single character |
| `%s` | a nul-terminated string (`(null)` when the pointer is `NULL`) |
| `%p` | a `void *` address in hexadecimal, prefixed with `0x` |
| `%d` | a signed decimal integer |
| `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned integer in lowercase hexadecimal |
| `%X` | an unsigned integer in uppercase hexadecimal |
| `%%` | a literal percent sign |

Flags, field width and precision are not part of the mandatory subject and
are not implemented.

## Build

```bash
make          # build libftprintf.a
make clean    # remove object files
make fclean   # remove object files and the library
make re       # fclean + make
```

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    int n = ft_printf("%s has %d chars, in hex: %x\n", "42", 42, 42);

    ft_printf("printed %d characters\n", n);
    return (0);
}
```

```bash
cc main.c -L. -lftprintf -I. -o program
```

## Project structure

```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c        # format parsing and dispatch loop
├── print_char.c       # %c
├── print_string.c     # %s
├── print_pointer.c    # %p
├── print_int.c        # %d, %i
├── print_unsigned.c   # %u
├── print_hex.c        # %x, %X
└── funcs.c            # shared helpers (ft_strlen, ft_putchar_fd, ...)
```

## How it works

`ft_printf` walks the format string one character at a time. On a `%` it
reads the next character, calls the matching `print_*` handler, and adds
that handler's return value to a running total. Every handler returns the
number of characters it wrote, so the final count is exact — including the
case where a conversion writes nothing.

## Resources

- `man 3 printf` — reference output for each conversion
- `man 3 stdarg` — `va_start`, `va_arg`, `va_end`
