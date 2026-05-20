# ft_printf

A reimplementation of the C standard library `printf` function, written from scratch as part of the 42 school curriculum. It produces a static library (`libftprintf.a`) that can be linked into any C project.

---

## Features

### Supported conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal (lowercase) |
| `%X` | Unsigned hexadecimal (uppercase) |
| `%p` | Pointer address |
| `%%` | Literal percent sign |

### Supported flags

| Flag | Description |
|------|-------------|
| `-` | Left-align the output within the field width |
| `+` | Force a sign (`+` or `-`) for numeric conversions |
| `0` | Pad with zeros instead of spaces |
| ` ` | Insert a space before positive numbers |
| `#` | Prefix `0x` / `0X` for `%x` / `%X` |

Width and precision (`.`) are also supported and can be combined with the flags above.

---

## Building

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + all
```

---

## Usage

Include the header and link the library when compiling your project:

```c
#include "ft_printf.h"

int main(void)
{
    int written;

    written = ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    ft_printf("Wrote %d characters.\n", written);
    ft_printf("Hex: %#010x\n", 255);
    ft_printf("Pointer: %p\n", (void *)&written);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -I include -o my_program
```

`ft_printf` returns the number of characters written to stdout, or `-1` on error (e.g., a width or precision value that overflows).

---

## Project structure

```
ft_printf/
├── include/
│   └── ft_printf.h       # Public header
├── srcs/
│   ├── ft_printf.c       # Entry point, format string parser
│   ├── ft_draft.c        # Dispatch to the right handler
│   ├── parsing.c         # Flag and precision parsing
│   ├── pad_manager.c     # Width and precision padding helpers
│   ├── ft_int.c          # Integer length and atoi utilities
│   ├── c_handler.c       # %c
│   ├── s_handler.c       # %s
│   ├── d_handler.c       # %d / %i
│   ├── u_handler.c       # %u
│   ├── x_handler.c       # %x / %X
│   └── p_handler.c       # %p
└── Makefile
```

---

## Notes

- The library writes exclusively to `stdout` (file descriptor 1).
- Behaviour on an invalid or unknown conversion specifier is undefined, matching the standard.
- NULL pointers passed to `%s` are printed as `(null)`, consistent with glibc behaviour (subject to precision rules).
- NULL pointers passed to `%p` are printed as `(nil)`.

---

## AI Disclosure

This README was written with the assistance of Claude (Anthropic). Parts of the code were written with the assistance of GitHub Copilot. All implementation decisions and final code were authored by Akhmed Dovletov.
