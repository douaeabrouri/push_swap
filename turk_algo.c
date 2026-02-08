/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:36:07 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/08 03:34:44 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack     *bee_or_not_to_bee(t_stack *b, int value)
{
	t_stack *tmp;
	t_stack *best;
	int max;
	int min;

    if(!b)
        return NULL;
	//find max and min
	min = b->value;
	max = b->value;
	tmp = b;
	while(tmp)
	{
		if(max < tmp->value)
			max = tmp->value;
		if(min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	//do the  case 1 & 2
	//case 1:value is BIGGER than everything in B
	//case 2:value is smaller than everything in B
	if(value > max || value < min)
	{
		tmp = b;
		while(tmp)
		{
			if(tmp->value == max)
				return tmp;
			tmp = tmp->next;
		}
	}
	//case 3: value fits between two numbers
	tmp = b;
	best = NULL;
	while(tmp)
	{
		if (tmp->value > value)
		{
			if(!best || tmp->value < best->value)
				best = tmp;
		}
		tmp = tmp->next;
	}
	return (best);
}


// calculate how many moves it takes to bring a number from A to its correct position in B 
//then actually move it there
void	how_much_pain_for_this_number(t_stack **a, t_stack **b, t_stack *node)
{
	//step 1: find the position of the number and here i have a relation <cost_a = min(position, size_a - position)>
	// i use cost_a = min(pos, size_a - pos) to found the smallest number of moves to bring a number to the top od stack_A;
	// size_a - pos how many reverse rotations (rra) u need !
// combine rotations
	while (node->cost_a > 0 && node->cost_b > 0
		&& node->dir_a == node->dir_b)
	{
		if (node->dir_a == 1)
			rr(a, b);
		else
			rrr(a, b);
		node->cost_a--;
		node->cost_b--;
	}

	// finish A
	while (node->cost_a > 0)
	{
		if (node->dir_a == 1)
			ra(a);
		else
			rra(a);
		node->cost_a--;
	}

	// finish B
	while (node->cost_b > 0)
	{
		if (node->dir_b == 1)
			rb(b);
		else
			rrb(b);
		node->cost_b--;
	}
	pb(a, b);
}

int	get_total_cost(t_stack *node)
{
	if (node->dir_a == node->dir_b)
	{
		if (node->cost_a > node->cost_b)
			return (node->cost_a);
		return (node->cost_b);
	}
	return (node->cost_a + node->cost_b); 
}
void	calc_costs(t_stack **a, t_stack **b, t_stack *node)
{
	t_stack *target;
	t_stack *tmp;
	int size_a;
	int size_b;
	int	pos_a;
	int	pos_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	update_index(*a);
	update_index(*b);
	//find the position of node in stack_a
	pos_a = 0;
	tmp = *a;
	while(tmp)
	{
		if (tmp->value == node->value)
			break;
		pos_a++;
		tmp = tmp->next;
	}
	// reverse
	if (pos_a <= size_a / 2)
	{
		node->cost_a = pos_a;
		node->dir_a = 1;
	}
	else
	{
		node->cost_a = size_a - pos_a;
		node->dir_a = -1;
	}
	// also to b
	target = bee_or_not_to_bee(*b, node->value);
	if (!target)
		pos_b  = 0;
	else 
	{
		pos_b = 0;
		tmp = *a;

		while(tmp)
		{
			if (tmp->value == target->value)
				break;
			pos_b++;
			tmp = tmp->next;
		}
	}
	if (pos_b <= size_b / 2)
	{
		node->cost_b = pos_b;
		node->dir_b = 1;
	}
	else
	{
		node->cost_b = size_b - pos_b;
		node->dir_b = -1;
	}
}
// this function manager of cheapest moves.
void	push_the_laziest_number(t_stack **a, t_stack **b)
{
	//starting by scanning stack_a
	t_stack *tmp;
	t_stack *cheapest;
	int		min_cost;
	int		current_cost;

	tmp = *a;
	cheapest = NULL;
	min_cost = INT_MAX;

	while(tmp)
	{
		calc_costs(a, b, tmp);
		current_cost = get_total_cost(tmp);
		if(current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	if (cheapest)
		how_much_pain_for_this_number(a, b, cheapest);
}

void	push_back_to_a_and_finalize(t_stack **a, t_stack **b)
{
	int x;
	t_stack *tmp;
	t_stack *target;
	int min;
	int max;

	while(*b != NULL)
	{
		x = (*b)->value; // top of b
		tmp = *a;
		min = tmp->value;
		max = tmp->value;
		target = NULL;
		// Find min and max in A
		while(tmp)
		{
			if (tmp->value > max)
				max = tmp->value;
			if (tmp->value < min)
				min = tmp->value;
			tmp = tmp->next;
		}
		// Find the target position: smallest number in A that's bigger than x
		tmp = *a;
		while(tmp)
		{
			if (tmp->value > x)
			{
				if (!target || tmp->value < target->value)
					target = tmp;
			}
			tmp = tmp->next;
		}
		// If x > max or x < min, target should be the min
		if (!target)
		{
			tmp = *a;
			while(tmp)
			{
				if(tmp->value == min)
				{
					target = tmp;
					break;
				}
				tmp = tmp->next;
			}
		}
		// Rotate A until target is on top
		while((*a)->value != target->value)
			ra(a); 
		
		// Push from B to A
		pa(a, b);
	}
}

// check the final rotate in stack a
void	final_rotate(t_stack **a)
{
	t_stack *tmp;
	int min;
	int min_pos;
	int i;
	int size;

	tmp = *a;
	min = tmp->value;
	min_pos = 0;
	i = 0;
	size = stack_size(*a);

	// Find min value and its position
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}

	// Rotate in the cheapest direction
	if (min_pos <= size / 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
}