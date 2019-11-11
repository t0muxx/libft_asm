NAME = libfts.a

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

ifeq ($(HOSTTYPE),x86_64_Darwin)
	FORMAT = macho64
endif

ifeq ($(HOSTTYPE),x86_64_Linux)
	FORMAT = elf64
endif

#FLAG AND COMPILATOR#
CC =		nasm
CFLAGS =  -g -Wall

#PATH#
OBJ_PATH =  obj
SRC_PATH =  src

SRCS =		ft_bzero.s \
			ft_strcat.s \
			ft_isalpha.s \
			ft_isdigit.s \
			ft_isalnum.s \
			ft_isascii.s \
			ft_isprint.s \
			ft_toupper.s \
			ft_tolower.s \
			ft_puts.s \
			ft_puts_fd.s \
			ft_strlen.s \
			ft_memset.s \
			ft_memcpy.s \
			ft_strdup.s \
			ft_cat.s \
			ft_strcmp.s \
			ft_strncmp.s \
			ft_atoi.s \
			ft_strsub.s

OBJ = $(SRC:$(SRC_PATH)/%.s=$(OBJ_PATH)/%.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
#	ranlib $(NAME)

$(OBJ): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.s
	mkdir -p $(dir $@)
	$(CC) -f $(FORMAT) -o $@ $(CFLAGS) $<

test:
	@+$(MAKE) -C tests

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
