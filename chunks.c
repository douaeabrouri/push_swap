/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:36:07 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/29 20:04:21 by doabrour         ###   ########.fr       */
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

int		how_much_pain_for_this_number(t_stack *b, t_stack *a, int nb)
{
	//step 1: find the position of the number and here i have a relation <cost_a = min(position, size_a - position)>
	// i use cost_a = min(pos, size_a - pos) to found the smallest number of moves to bring a number to the top od stack_A;
	// size_a - pos how many reverse rotations (rra) u need !
 	t_stack *tmp_a;
	int 	const_nb;
	int		pos_a;
	int		size_a;

	tmp_a = a;
	const_nb = 0;
	size_a = stack_size(a);
	while(tmp_a != NULL)
	{
		if(tmp_a->value != nb)
			tmp_a = tmp_a->next;
		else if(tmp_a->value == nb)
		{
			pos_a = tmp_a->index;
			if (pos_a <= size_a / 2)
				const_nb = pos_a;
			else
				const_nb = size_a - pos_a;
		}
	}
	//step 2 : find the target node in stack B
	int		size_b;
	t_stack	*tmp_b;
	int		pos_b;

	tmp_b = bee_or_not_to_bee(b, nb);
	size_b = stack_size(b);
	pos_b = tmp_b->index;
	if(pos_b <= size_b / 2)
		const_nb = pos_b;
	else
		const_nb = size_b - pos_b;
	//step 3: Decide rotation direction

	
	
}