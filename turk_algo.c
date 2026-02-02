/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:36:07 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/01 17:32:27 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack     *bee_or_not_to_bee(t_stack *b, int value)
{
	t_stack *tmp;
	int max;
	int min;

    if(!b)
        return NULL;

	//find max and min
	tmp = b;
	min = b->value;
	max = b->value;
	while(tmp != NULL)
	{
		if(max < tmp->value)
			max = tmp->value;
		if(min > tmp->value);
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
	while(tmp->next)
	{
		if(tmp->value > value && tmp->next->value < value)
			return tmp->next;
		tmp = tmp->next;
	}
	return NULL;
}


// calculate how many moves it takes to bring a number from A to its correct position in B 
//then actually move it there
void	how_much_pain_for_this_number(t_stack *b, t_stack *a, int nb)
{
	//step 1: find the position of the number and here i have a relation <cost_a = min(position, size_a - position)>
	// i use cost_a = min(pos, size_a - pos) to found the smallest number of moves to bring a number to the top od stack_A;
	// size_a - pos how many reverse rotations (rra) u need !
 	t_stack *tmp_a;
	int		pos_a;
	int		size_a;

	tmp_a = a;
	size_a = stack_size(a);
	while(tmp_a)
	{
		if (tmp_a->value == nb)
		{
			pos_a = tmp_a->index;
			break;
		}
		tmp_a = tmp_a->next;
	}
	//step 2 : find the target node in stack B
	int		size_b;
	t_stack	*tmp_b;
	int		pos_b;

	tmp_b = bee_or_not_to_bee(b, nb);
	size_b = stack_size(b);
	pos_b = tmp_b->index;
	//step 3: Decide rotation direction
	if (pos_a <= size_a / 2)
	{
		tmp_a->cost_a = pos_a;
		tmp_a->dir_a = 1;
	}
	else
	{
		tmp_a->cost_a = size_a - pos_a;
		tmp_a->dir_a = -1;
	}
	// also to b
	if (pos_b <= size_b / 2)
	{
		tmp_b->cost_b = pos_b;
		tmp_b->dir_b = 1;
	}
	else 
	{
		tmp_b->cost_b = size_b - pos_b;
		tmp_b->dir_b = -1;
	}
	// step 4: combine moves 
	while(tmp_a->cost_a > 0 && tmp_b->cost_b > 0 && tmp_a->dir_a == tmp_b->dir_b)
	{
		if (tmp_a->dir_a == 1)
				rr(tmp_a, tmp_b);
		else
			rrr(tmp_a, tmp_b);

		tmp_a->cost_a--;
		tmp_b->cost_b--;
	}
	while(tmp_a->cost_a > 0)
	{
		if(tmp_a->dir_a == 1)
			ra(tmp_a);
		else
			rra(tmp_a);
		tmp_a->cost_a--;
	}
	while(tmp_b->cost_b > 0)
	{
		if(tmp_b->dir_b == 1)
			rb(tmp_b);
		else
			rrb(tmp_b);
		tmp_b->cost_b--;
	}
	pb(a,b);
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
	int size_a;
	int size_b;
	int	pos_a;
	int	pos_b;
	t_stack *target;

	size_a = stack_size(a);
	size_b = stack_size(b);
	
	pos_a = node->index;
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
	target = bee_or_not_to_bee(b, node->value);
	pos_b = target->index;
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
	min_cost = 2147483647;

	while(tmp)
	{
		calc_costs(*a, *b, tmp);
		current_cost = get_total_cost(tmp);
		if(current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	if (cheapest)
		how_much_pain_for_this_number(*b, *a, cheapest->value);
}

void push_back_to_a_and_finalize(t_stack **a, t_stack **b)
{
	int		x;
	t_stack *tmp;
	t_stack *target;
	int 	min;
	int		max;


	while(*b != NULL)
	{
		x = (*b)->value; // top of b
		tmp = *a;
		target = *a;
		min = tmp->value;
		max = tmp->value;
		while(tmp)
		{
			if (tmp->value > max)
				max  = tmp->value;
			if (tmp->value < min)
				min = tmp->value;
			//case the first numbeer bigger than x
			if (tmp->value > x && tmp->value < target->value)
				target = tmp;

			tmp = tmp->next;
		}
		//if x > max or x < in ->target = min
		if (x > max || x < min)
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
		// rotate A until target is on top 
		while((*a)->value != target ->value)
		{
			ra(a);
		}
		pa(a,b);

		// final rotation so min is on top

		tmp = *a;
		int min_val = tmp->value;
		while(tmp)
		{
			if (tmp->value < min_val)
				min_val = tmp->value;
			tmp = tmp->value;
		}
		while ((*a)->value != min_val)
			ra(a);
	}
}

// check the final rotate in stack a
void	final_rotate(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		min_pos;
	int		i;
	int		size;

	tmp = *a;
	min = tmp->value;
	min_pos = 0;
	i = 0;
	size = stack_size(*a);

	/* step 1: find min value and its position */
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

	/* step 2: rotate in the cheapest direction */
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