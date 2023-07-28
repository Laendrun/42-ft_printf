# 🚀 Description

The goal of this project is pretty simple, recreate the well-known printf function.

It will not need to be as complete as the real one but it will respect the 42 Norm and include some of the most used formats.

This project is mainly focused on understanding how variadic arguments work.

> Because ft_putnbr() and ft_putstr() are not enough...

# Mandatory part

|     |     |
| --- | --- |
| Program name | libftprintf.a |
| Turn in files | Makefile, *.h, */*.h, *.c, */*.c |
| Makefile | NAME, all, clean, fclean, re |
| External functs. | malloc, free, write, va_start, va_arg, va_copy, va_end |
| Libft authorized | Yes | 
| Description | Write a library that contains ft_printf(), a function that will mimic the original printf() |

- Don’t implement the buffer management of the original printf().
- Your function has to handle the following conversions: cspdiuxX%
- Your function will be compared against the original printf()
- You must use the command ar to create your library. Using the libtool command is forbidden.
- Your libftprintf.a has to be created at the root of your repository.

You have to implement the following conversions:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

# 🌟 Bonus part

- Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
- Manage all the following flags: ’# +’ (Yes, one of them is a space)

# Final note

This project was done without the bonuses and is already included in my libft.