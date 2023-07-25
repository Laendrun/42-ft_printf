SRC = ft_printf.c \
		helpers.c

OBJS := $(SRC:%.c=%.o)
OBJS_HELPERS := $(SRC_HELPERS:%.c=%.o)
OBJS_PRINTERS := $(SRC_PRINTERS:%.c=%.o)

NAME = libftprintf.a
CC = gcc
CCFLAGS = -Werror -Wall -Wextra
INC_DIR = .

%.o: %.c
	$(CC) -I$(INC_DIR) $(CCFLAGS) -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_HELPERS) $(OBJS_PRINTERS)
	ar rcs $(NAME) $(OBJS) $(OBJS_HELPERS) $(OBJS_PRINTERS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_HELPERS) $(OBJS_PRINTERS)

fclean: clean
	rm -f $(NAME)

re: fclean all

clear: fclean 
	clear

test: all
	gcc $(CCFLAGS) -I. -L. -lftprintf main.c