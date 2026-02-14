/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:32:48 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/14 15:41:47 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int		pos;
	int		min_pos;

	tmp = stack;
	min = stack->value;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

// Push the smallest number from A to B
void	push_smallest_to_b(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;

	size = stack_size(*a);
	min_pos = find_min_position(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
	pb(a, b);
}

// Optimized sort for 4-5 numbers
void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	push_smallest_to_b(a, b);
	if (size == 5)
		push_smallest_to_b(a, b);
	sort_three_in_a(a);
	pa(a, b);
	if (size == 5)
		pa(a, b);
}

void	rotate_b_once(t_stack **b, int dir)
{
	if (dir == 1)
		rb(b);
	else
		rrb(b);
}

void	set_cost_and_dir(t_stack *node, int pos, int size, int is_a)
{
	if (pos <= size / 2)
	{
		if (is_a)
		{
			node->cost_a = pos;
			node->dir_a = 1;
		}
		else
		{
			node->cost_b = pos;
			node->dir_b = 1;
		}
	}
	else if (is_a)
	{
		node->cost_a = size - pos;
		node->dir_a = -1;
	}
	else
	{
		node->cost_b = size - pos;
		node->dir_b = -1;
	}
}
