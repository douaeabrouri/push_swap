# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 19:35:39 by doabrour          #+#    #+#              #
#    Updated: 2026/02/07 22:05:32 by doabrour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ COLORS ==================================== #
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
PURPLE		= \033[0;35m
CYAN		= \033[0;36m
BOLD_RED	= \033[1;31m
BOLD_GREEN	= \033[1;32m
BOLD_YELLOW	= \033[1;33m
BOLD_BLUE	= \033[1;34m
BOLD_PURPLE	= \033[1;35m
BOLD_CYAN	= \033[1;36m
BOLD_WHITE	= \033[1;37m
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
TOTAL_FILES	= $(words $(SRCS))
CURRENT		= 0

# ================================ RULES ===================================== #

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

define show_progress
	$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	$(eval PERCENT=$(shell echo $$(($(CURRENT)*100/$(TOTAL_FILES)))))
	@printf "$(BOLD_CYAN)[$(RESET)"
	@printf "$(BOLD_GREEN)"
	@for i in `seq 1 $(shell echo $$(($(PERCENT)/2)))`; do printf "█"; done
	@printf "$(RESET)"
	@for i in `seq 1 $(shell echo $$((50-$(PERCENT)/2)))`; do printf "░"; done
	@printf "$(BOLD_CYAN)]$(RESET) "
	@printf "$(BOLD_GREEN)%3d%%$(RESET) " $(PERCENT)
endef

%.o: %.c
	@$(call show_progress)
	@printf "$(CYAN)⚙  $(RESET)Compiling: $(BOLD_WHITE)%-25s$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@ 2>/dev/null || (printf "$(BOLD_RED) ✗$(RESET)\n"; exit 1)
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
	@echo "        ║                  $(BOLD_CYAN)./$(NAME) is ready!$(BOLD_GREEN)                      ║"
	@echo "        ║                                                               ║"
	@echo "        ╚═══════════════════════════════════════════════════════════════╝"
	@echo "$(RESET)"
	@echo "$(BOLD_YELLOW)        💡 Try: ./push_swap 4 67 3 87 23$(RESET)"
	@echo ""

clean:
	@echo ""
	@echo "$(BOLD_RED)"
	@echo "        ╔═══════════════════════════════════════════════════════════════╗"
	@echo "        ║                                                               ║"
	@echo "        ║                🧹  CLEANING IN PROGRESS  🧹                  	║"
	@echo "        ║                                                               ║"
	@echo "        ╚═══════════════════════════════════════════════════════════════╝"
	@echo "$(RESET)"
	@echo ""
	@COUNT=0; \
	for file in $(OBJS); do \
		if [ -f $$file ]; then \
			COUNT=$$((COUNT+1)); \
			printf "$(RED)        🗑  Removing: $(BOLD_WHITE)%-30s$(RESET)" $$file; \
			$(RM) $$file; \
			printf "$(BOLD_RED) ✗$(RESET)\n"; \
		fi; \
	done; \
	if [ $$COUNT -eq 0 ]; then \
		echo "$(YELLOW)        ⚠  Nothing to clean!$(RESET)"; \
	else \
		echo ""; \
		echo "$(BOLD_GREEN)        ✨ Removed $$COUNT object file(s)!$(RESET)"; \
	fi
	@echo ""

fclean: clean
	@echo "$(BOLD_RED)"
	@echo "        ╔═══════════════════════════════════════════════════════════════╗"
	@echo "        ║                                                               ║"
	@echo "        ║                 🔥  FULL CLEAN MODE  🔥                      	║"
	@echo "        ║                                                               ║"
	@echo "        ╚═══════════════════════════════════════════════════════════════╝"
	@echo "$(RESET)"
	@echo ""
	@if [ -f $(NAME) ]; then \
		printf "$(RED)        💥 Destroying executable: $(BOLD_WHITE)$(NAME)$(RESET)"; \
		$(RM) $(NAME); \
		printf "$(BOLD_RED) ✗$(RESET)\n"; \
		echo ""; \
		echo "$(BOLD_GREEN)        🎉 Everything is wiped clean!$(RESET)"; \
	else \
		echo "$(YELLOW)        ⚠  No executable to remove!$(RESET)"; \
	fi
	@echo ""

re: fclean all

bonus: all

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

.PHONY: all clean fclean re bonus norm help header footer