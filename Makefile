NAME := push_swap
LIBFT_NAME = libft.a

SRCS =  ./sources/push_swap.c \
		./sources/fill_list.c \
		./sources/print_list.c \
		./sources/push.c \
		./sources/swap.c \
		./sources/rotate.c \
		./sources/reverse_rotate.c \
		./sources/map.c \
		./sources/order.c \
		./sources/algo_small.c \
		./sources/algo_small_back.c	\
		./sources/algo_pusheo.c	\
		./sources/first_last_push.c	\
		./sources/init_list.c	\
		./sources/order_2.c

OBJS = ${SRCS:.c=.o}

LIBFT_DIR := ./libft/
INC_DIR := ./headers/
EXE_DIR = ./

CC := cc
GCC := gcc
CFLAGS := -Wall -Werror -Wextra #-fsanitize=address -g3
MV := mv -f
RM := rm -f

%.o: %.c
	$(GCC)  $(CFLAGS) -c $< -I $(INC_DIR) -o $@ 

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	$(GCC) $(CFLAGS) -o $(NAME)  $^ -I $(INC_DIR)

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
