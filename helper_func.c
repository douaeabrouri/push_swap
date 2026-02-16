/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:28:15 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/14 19:13:35 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Find cheapest number to push from A to B
t_stack	*find_cheapest_in_a(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*cheapest;
	int		min_cost;
	int		pos;
	int		size;

	tmp = a;
	cheapest = a;
	size = stack_size(a);
	pos = 0;
	min_cost = size;
	while (tmp)
	{
		if (calculate_cost(pos, size) < min_cost)
		{
			min_cost = calculate_cost(pos, size);
			cheapest = tmp;
		}
		tmp = tmp->next;
		pos++;
	}
	return (cheapest);
}

// Push cheapest number from A to B
void	push_cheapest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	t_stack	*tmp;
	int		pos;
	int		size;

	cheapest = find_cheapest_in_a(*a);
	size = stack_size(*a);
	pos = 0;
	tmp = *a;
	while (tmp && tmp != cheapest)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
		while ((pos--) > 0)
			ra(a);
	}
	else
	{
		while ((pos++) < size)
			rra(a);
	}
	pb(a, b);
}

t_stack	*find_target_in_a(t_stack *a, int x, int min)
{
	t_stack	*tmp;
	t_stack	*target;

	tmp = a;
	target = NULL;
	while (tmp)
	{
		if (tmp->value > x && (!target || tmp->value < target->value))
			target = tmp;
		tmp = tmp->next;
	}
	if (!target)
	{
		tmp = a;
		while (tmp && tmp->value != min)
			tmp = tmp->next;
		target = tmp;
	}
	return (target);
}

void	rotate_to_target(t_stack **a, t_stack *target)
{
	t_stack	*tmp;
	int		pos;
	int		size;

	pos = 0;
	tmp = *a;
	while (tmp && tmp != target)
	{
		pos++;
		tmp = tmp->next;
	}
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
}

// Push back from B to A (NO final rotation inside!)
void	push_back_to_a(t_stack **a, t_stack **b)
{
	if (!b || !(*b) || !a || !(*a))
		return ;
	pa(a, b);
}
