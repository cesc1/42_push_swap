## header
##

NAME = push_swap
LIB = libft

LIB_PATH = $(LIB)/$(LIB).a
SRC_PATH = src
OBJ_PATH = obj

HEAD = header/push_swap.h

SRCS = src/main.c \
       src/stack.c \
       src/dstack.c \
       src/read_args.c \
       src/operation_swap.c \
       src/operation_push.c \
       src/operation_rotate.c \
       src/utils.c \
       src/transform.c \
       src/sort_cesc.c \
       src/sort_radix.c

SRCS_BONUS = NULL

OBJS = $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRCS))
OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

CC = cc
CFLAGS = -Iheader/ -I. -Wall -Wextra -Werror -g

#===============================================

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) Makefile $(LIB_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH) -o $(NAME)

$(LIB_PATH):
	cd $(LIB) && make

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

superclean: fclean
	cd $(LIB) && make fclean

mc: all clean
	cd $(LIB) && make clean

.PHONY: all clean fclean re superclean mc
