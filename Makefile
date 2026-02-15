# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 19:35:39 by doabrour          #+#    #+#              #
#    Updated: 2026/02/15 18:46:12 by doabrour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ COLORS ==================================== #
CYAN		:= \033[0;36m
BOLD_WHITE	:= \033[1;37m
BOLD_GREEN	:= \033[1;32m
BOLD_YELLOW	:= \033[1;33m
BOLD_PURPLE	:= \033[1;35m
BOLD_CYAN	:= \033[1;36m
RESET		:= \033[0m

# ================================ VARIABLES ===================================== #

NAME		:= push_swap

SRCS		:=error_exit.c \
			free_stack.c	\
			helper_func.c	\
			helper_func2.c	\
			indexing.c      \
			is_sorted.c 	\
			parsing.c 		\
			parsing2.c 		\
			push_algo.c 	\
			push_swap.c 	\
			reverse_algo.c 	\
			rotate_algo.c 	\
			sorted_three_in_a.c \
			split_args.c 	\
			stack_size.c 	\
			swap_algo.c 	\
			turk_algo.c 	\
			turk2.c 		\
			turk3.c 	

RM 			:= rm -f
CFLAGS 		:= -Wall -Wextra -Werror 
OBJS		:= $(SRCS:.c=.o)

# ================================ TARGETS===================================== #

all: header $(NAME) footer

header:
	@clear
	@echo ""
	@echo "$(BOLD_CYAN)"
	@echo "        ██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "        ██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "        ██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "        ██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "        ██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     "
	@echo "        ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo "$(RESET)"
	@echo "$(BOLD_PURPLE)        ═══════════════════════════════════════════════════════════════$(RESET)"
	@echo "$(BOLD_YELLOW)                              ⚡ BY doabrour ⚡                          $(RESET)"
	@echo "$(BOLD_PURPLE)        ═══════════════════════════════════════════════════════════════$(RESET)"
	@echo ""
	@echo "$(BOLD_GREEN)        🚀 Starting compilation...$(RESET)"
	@echo ""


%.o: %.c
	@printf "$(CYAN)⚙  $(RESET)Compiling: $(BOLD_WHITE)%-25s$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(BOLD_GREEN) ✓$(RESET)\n"

$(NAME): $(OBJS)
	@echo ""
	@printf "$(BOLD_PURPLE)        🔗 Linking objects together...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(BOLD_GREEN) ✓$(RESET)\n"
	@echo ""

footer:
	@echo "$(BOLD_GREEN)"
	@echo "        ╔═══════════════════════════════════════════════════════════════╗"
	@echo "        ║                                                               ║"
	@echo "        ║               ✨  COMPILATION SUCCESSFUL! ✨                 	║"
	@echo "        ║                                                               ║"
	@echo "        ║                  $(BOLD_CYAN)./$(NAME) is ready!$(BOLD_GREEN) 			║"
	@echo "        ║                                                               ║"
	@echo "        ╚═══════════════════════════════════════════════════════════════╝"
	@echo "$(RESET)"
	@echo "$(BOLD_YELLOW)        💡 Try: ./push_swap 4 67 3 87 23$(RESET)"
	@echo ""

clean:
	@echo ""
	@echo "$(BOLD_YELLOW)       🧹 Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@echo  "$(BOLD_GREEN)       ✓ Clean complete!$(RESET)"
	@echo ""
fclean: clean
	@echo "$(BOLD_YELLOW)       🗑️  Removing executable...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(BOLD_GREEN)       ✓ Full clean complete!$(RESET)"
	@echo ""
re: fclean all

norm:
	@echo ""
	@echo "$(BOLD_CYAN)        📋 Running Norminette...$(RESET)"
	@echo ""
	@norminette $(SRCS) *.h || true
	@echo ""

help:
	@echo ""
	@echo "$(BOLD_CYAN)        ╔═══════════════════════════════════════════════════════════════╗"
	@echo "        ║                      PUSH_SWAP MAKEFILE                       ║"
	@echo "        ╚═══════════════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(BOLD_GREEN)        Available commands:$(RESET)"
	@echo ""
	@echo "        $(BOLD_YELLOW)make$(RESET)          - Compile the project"
	@echo "        $(BOLD_YELLOW)make clean$(RESET)    - Remove object files"
	@echo "        $(BOLD_YELLOW)make fclean$(RESET)   - Remove object files and executable"
	@echo "        $(BOLD_YELLOW)make re$(RESET)       - Recompile everything"
	@echo "        $(BOLD_YELLOW)make norm$(RESET)     - Run norminette"
	@echo "        $(BOLD_YELLOW)make help$(RESET)     - Show this help message"
	@echo ""

.PHONY: all clean fclean re  norm help header footer