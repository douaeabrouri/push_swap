# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 19:35:39 by doabrour          #+#    #+#              #
#    Updated: 2026/02/07 17:22:25 by doabrour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap.a

SRC := error.exit.c free_stack.c helper_func.c indexing.c \
		is_sorted.c parsing.c push_algo.c push_swap.c reverse_algo \
		rotate_algo.c sorted_three_in_stack.c split_args.c stack_size.c \
		wap_algo.c turk_algo.c 

OBG := $(SRC:.c=.o)


CC := cc
CFLAGS := -Wall -Wextra -Werror
LIB := ar rcs

#------targets-------
all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c %< -o $@

clean:
	@rm -f $(OBG) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

