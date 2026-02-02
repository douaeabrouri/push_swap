/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 04:33:16 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/02 13:00:34 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int value;
	int index;
	int	cost_a;
	int	cost_b;
	int dir_a;
	int dir_b;
	struct s_stack *next;
}	t_stack;

//operations function
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//parsing function 
char	**take_arguments(char **argv);
int		is_valid_number(int argc, char **argv);
long	ft_atoi(const char *arg);
char 	**make_it_clear(int argc, char **argv);
int 	duplicate_number(t_stack *a, int value);

//is_sorted
int		is_sorted(t_stack *stack);

//indexing
t_stack	*stack_new(int value);
t_stack *stack_add_back(t_stack **stack, t_stack *new);

//stack_size
int		stack_size(t_stack *a);

//free stack
void	free_stack(t_stack **stack);

//turk algo
t_stack *bee_or_not_to_bee(t_stack *b, int value);
void	how_much_pain_for_this_number(t_stack *b, t_stack *a, int nb);
int		get_total_cost(t_stack *node);
void	calc_costs(t_stack **a, t_stack **b, t_stack *node);
void	push_the_laziest_number(t_stack **a, t_stack **b);
void	sort_three_in_a(t_stack **a);
void	push_back_to_a_and_finalize(t_stack **a, t_stack **b);
void	final_rotate(t_stack **a);

// error exit function
void	error_exit(t_stack **a);

#endif