NAME = libfts.a

#FLAG AND COMPILATOR#
CC =		clang
CFLAGS =  -g -Wall -Werror -Wextra

#PATH#
OBJ_PATH =  obj
SRC_PATH =  src

SRCS = 

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))

all: $(NAME)

$(NAME): $(OBJ) test
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.s
	mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -c $<

test:
	@+$(MAKE) -C tests

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
