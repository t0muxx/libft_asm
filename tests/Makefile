NAME =	tests.bin

#FLAG AND COMPILATOR#
CC =		gcc
CFLAGS =  -g3 -Wall -Werror -Wextra

#PATH#
OBJ_PATH =  obj

SRCS =  test_ft_bzero.c \
		test_ft_strcat.c \
		test_ft_isalpha.c \
		test_ft_isdigit.c \
		test_ft_isalnum.c \
		test_ft_isascii.c \
		test_ft_isprint.c \
		test_ft_toupper.c \
		test_ft_tolower.c \
		test_ft_puts.c \
		test_ft_puts_fd.c \
		test_ft_strlen.c \
		test_ft_memset.c \
		test_ft_memcpy.c \
		test_ft_strdup.c \
		test_ft_cat.c \
		test_ft_strcmp.c \
		test_ft_strncmp.c \
		test_ft_atoi.c \
		main.c

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)
SRC = $(SRCS)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L../ -lfts

$(OBJ): $(OBJ_PATH)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -c $<

test:
	@+ make -C tests/

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
