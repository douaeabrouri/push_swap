/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:28:15 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/14 12:17:15 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Find cheapest number to push from A to B
t_stack	*find_cheapest_in_a(t_stack	*a)
{
	t_stack	*tmp;
	t_stack	*cheapest;
	int		min_cost;
	int		pos;
	int		size;
	int		cost;
	
	tmp = a;
	cheapest = a;
	size = stack_size(a);
	pos = 0;
	min_cost = size;
	while (tmp)
	{// Calculate cost to bring this element to top
		cost  = (pos <= size / 2) ? pos : size - pos;
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
		pos++;
	}	
	return (cheapest);
}

// Push cheapest number from A to B
void push_cheapest_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest;
	t_stack *tmp;
	int pos;
	int size;

	cheapest = find_cheapest_in_a(*a);
	size = stack_size(*a);
	pos = 0;// Find position of cheapest
	tmp = *a;
	while (tmp && tmp != cheapest)
	{
		pos++;
		tmp = tmp->next;
	}// Rotate to bring cheapest to top
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

// Push back from B to A (NO final rotation inside!)
void push_back_to_a(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	t_stack *target;
	int x;
	int min;
	int max;
	int pos;
	int size;

	x = (*b)->value;
	tmp = *a;
	min = tmp->value;
	max = tmp->value;
	target = NULL;
	
	// Find min and max in A
	if (!b || !(*b))
		return;
	if (!a || !(*a))
		return;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	// Find target: smallest number in A that's bigger than x
	tmp = *a;
	while (tmp)
	{
		if (tmp->value > x)
		{
			if (!target || tmp->value < target->value)
				target = tmp;
		}
		tmp = tmp->next;
	}
	// If no target, x should go before min
	if (!target)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->value == min)
			{
				target = tmp;
				break;
			}
			tmp = tmp->next;
		}
	}
	// Find position of target
	pos = 0;
	tmp = *a;
	while (tmp && tmp != target)
	{
		pos++;
		tmp = tmp->next;
	}
	size = stack_size(*a);
	// Rotate A to bring target to top
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a);
			pos++;
		}
	}
	pa(a, b);
}
