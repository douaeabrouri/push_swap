/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 04:33:16 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/29 18:12:44 by doabrour         ###   ########.fr       */
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
char **take_arguments(char **argv);
int	is_valid_number(int argc, char **argv);
long ft_atoi(const char *arg);
char 	**make_it_clear(int argc, char **argv);
void	duplicate_number(t_stack *a);

//is_sorted
int is_sorted(t_stack *stack);

//indexing
t_stack	*stack_new(int value);
t_stack *stack_add_back(t_stack **stack, t_stack *new);

//stack_size
int stack_size(t_stack *a);

#endif