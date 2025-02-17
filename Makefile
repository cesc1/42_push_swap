## header
##

NAME = push_swap
LIB = libft

LIB_PATH = $(LIB)/$(LIB).a

HEAD = push_swap.h

SRCS = main.c \
       stack.c \
       read_args.c

SRCS_BONUS = NULL

OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

#===============================================

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) Makefile $(LIB_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH) -o $(NAME)

$(LIB_PATH):
	cd $(LIB) && make

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

superclean: fclean
	cd $(LIB) && make fclean

.PHONY: all clean fclean re superclean

