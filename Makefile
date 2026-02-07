# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 19:35:39 by doabrour          #+#    #+#              #
#    Updated: 2026/02/07 19:15:24 by doabrour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PINK		= \033[38;5;213m
LAVENDER	= \033[38;5;183m
MINT		= \033[38;5;158m
PEACH		= \033[38;5;217m
LILAC		= \033[38;5;189m
ROSE		= \033[38;5;211m
GOLD		= \033[38;5;222m
CORAL		= \033[38;5;210m
BOLD_PINK	= \033[1;38;5;213m
BOLD_MINT	= \033[1;38;5;158m
RESET		= \033[0m

NAME		:= push_swap

SRCS		:=parsing.c \
			free_stack.c \
			error_exit.c \
			is_sorted.c \
			indexing.c \
			push_algo.c \
			push_swap.c \
			reverse_algo.c \
			rotate_algo.c \
			sorted_three_in_a.c \
			split_args.c \
			stack_size.c \
			swap_algo.c \
			turk_algo.c


OBJS		= $(SRCS:.c=.o)

# ================================ RULES ===================================== #

all: banner $(NAME) success

banner:
	@echo ""
	@echo "$(BOLD_PINK)"
	@echo "   ♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡"
	@echo "   ♡                                                 ♡"
	@echo "   ♡         ✿  P U S H   S W A P  ✿              ♡"
	@echo "   ♡                                                 ♡"
	@echo "   ♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡"
	@echo "$(RESET)"
	@echo "$(LAVENDER)        ･ﾟ✧ Compiling with love ✧ﾟ･$(RESET)"
	@echo ""

%.o: %.c
	@printf "$(PINK)   ✿  $(RESET)Compiling $(PEACH)%-25s$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(MINT) ✓$(RESET)\n"

$(NAME): $(OBJS)
	@echo ""
	@printf "$(LAVENDER)   ･ﾟ･ Linking files together$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(MINT) ･ﾟ･$(RESET)\n"
	@echo ""

success:
	@echo "$(BOLD_PINK)"
	@echo "   ♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡"
	@echo "   ♡                                                 ♡"
	@echo "   ♡          ✨  Success, babe! ✨                 ♡"
	@echo "   ♡                                                 ♡"
	@echo "   ♡         $(GOLD)./push_swap$(BOLD_PINK) is ready! 💕             ♡"
	@echo "   ♡                                                 ♡"
	@echo "   ♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡"
	@echo "$(RESET)"
	@echo "$(PEACH)   ･ﾟ･ You did great! Keep going! ･ﾟ･$(RESET)"
	@echo ""

clean:
	@echo ""
	@echo "$(ROSE)"
	@echo "   ♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡"
	@echo "   ♡                                                 ♡"
	@echo "   ♡           ･ﾟ･ Tidying up ･ﾟ･                  ♡"
	@echo "   ♡                                                 ♡"
	@echo "   ♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡"
	@echo "$(RESET)"
	@echo ""
	@for file in $(OBJS); do \
		if [ -f $$file ]; then \
			printf "$(CORAL)   ♡  Removing $(PEACH)%-30s$(RESET)" $$file; \
			$(RM) $$file; \
			printf "$(ROSE) ✓$(RESET)\n"; \
		fi; \
	done
	@echo ""
	@echo "$(MINT)   ✿ All clean and pretty! ✿$(RESET)"
	@echo ""

fclean: clean
	@echo "$(ROSE)"
	@echo "   ♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡"
	@echo "  ♡                                               ♡"
	@echo "  	♡         ･ﾟ･ Deep cleaning ･ﾟ･                 ♡"
	@echo "  ♡                                                 ♡"
	@echo "   ♡━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━♡"
	@echo "$(RESET)"
	@echo ""
	@if [ -f $(NAME) ]; then \
		printf "$(CORAL)   ♡  Removing $(GOLD)$(NAME)$(RESET)"; \
		$(RM) $(NAME); \
		printf "$(ROSE) ✓$(RESET)\n"; \
	else \
		echo "$(LAVENDER)   ･ﾟ･ Nothing to clean, babe! ･ﾟ･$(RESET)"; \
	fi
	@echo ""
	@echo "$(MINT)   ✨ Sparkly clean! ✨$(RESET)"
	@echo ""

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus banner success