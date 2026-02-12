/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:28:15 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/12 16:52:16 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void update_index(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	write_stack(t_stack **stack)
{
	int index;
	t_stack *tmp;

	index = 0;
	tmp = *stack;
	while(tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int		is_only_spaces(char *str)
{
	int index;

	if (!str)
		return (1);
	index = 0;
	while(str[index])
	{
		if(str[index] != ' ' && str[index] != '\t' && str[index] != '\n')
			return 0;
		index++;
	}
	return (1);
}

int find_min_position(t_stack *stack)
{
	t_stack *tmp;
	int min;
	int pos;
	int min_pos;

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
void push_smallest_to_b(t_stack **a, t_stack **b)
{
	int min_pos;
	int size;

	size = stack_size(*a);
	min_pos = find_min_position(*a);

	// Rotate to bring min to top
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
	
	// Push to B
	pb(a, b);
}

// Optimized sort for 4-5 numbers
void sort_five(t_stack **a, t_stack **b)
{
	int size;

	size = stack_size(*a);
	
	// Push smallest to B
	push_smallest_to_b(a, b);
	
	// If size was 5, push second smallest too
	if (size == 5)
		push_smallest_to_b(a, b);
	
	// Sort remaining 3 in A
	sort_three_in_a(a);
	
	// Push back from B (they're already in order!)
	pa(a, b);
	if (size == 5)
		pa(a, b);
}

// Find cheapest number to push from A to B
t_stack *find_cheapest_in_a(t_stack *a)
{
	t_stack *tmp;
	t_stack *cheapest;
	int min_cost;
	int pos;
	int size;
	int cost;

	tmp = a;
	cheapest = a;
	size = stack_size(a);
	pos = 0;
	min_cost = size;
	
	while (tmp)
	{
		// Calculate cost to bring this element to top
		if (pos <= size / 2)
			cost = pos;  // ra cost
		else
			cost = size - pos;  // rra cost
		
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
	pos = 0;
	
	// Find position of cheapest
	tmp = *a;
	while (tmp && tmp != cheapest)
	{
		pos++;
		tmp = tmp->next;
	}
	
	// Rotate to bring cheapest to top
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
	
	pb(a, b);
}

// Push back from B to A (NO final rotation inside!)
void push_back_to_a(t_stack **a, t_stack **b)
{
	int x;
	t_stack *tmp;
	t_stack *target;
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
	// Push from B to A
	pa(a, b);
}
void	free_split(char **numbers)
{
	int index;

	index = 0;
	if (!numbers)
		return ;
	while(numbers[index] != NULL)
	{
		free(numbers[index]);
		index++;
	}
	free(numbers);
}