# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 19:35:39 by doabrour          #+#    #+#              #
#    Updated: 2026/01/25 13:21:12 by doabrour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap.a

SRC := main.c \
		

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

