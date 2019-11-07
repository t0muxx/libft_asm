NAME =	tests.bin

#FLAG AND COMPILATOR#
CC =		gcc
CFLAGS =  -g3 -Wall -Werror -Wextra

#PATH#
OBJ_PATH =  obj

SRCS =  test_ft_bzero.c \
		main.c

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)
SRC = $(SRCS)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -ldl ../libfts.a 

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
