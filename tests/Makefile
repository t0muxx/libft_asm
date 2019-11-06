NAME =	tests.bin

#FLAG AND COMPILATOR#
CC =		clang
CFLAGS =  -g -Wall -Werror -Wextra

#PATH#
OBJ_PATH =  obj
SRC_PATH =  src
INC_PATH := inc

SRCS = 

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	@+$(MAKE) -C libft/
	$(CC) $(CFLAGS) -I$(INC_PATH) $(OBJ) libft/libft.a -o $(NAME)

$(OBJ): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -I$(INC_PATH) -c $<

clean:
	/bin/rm -rf $(OBJ_PATH)
	(cd libft ; make clean)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re
