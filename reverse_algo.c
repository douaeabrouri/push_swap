/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:33:09 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/24 17:02:24 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
#include "push_swap.h"

void	rra(t_stack	**a)
{
	t_stack *first;
	t_stack *last;
	t_stack *second_last;

	if(!(*a) || !((*a)->next))
		return;
	
	first = *a;
	last = *a;
	second_last = NULL;

	while(last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = first;
	*a = last;

	write(1, "rra\n", 4);
}
void	rrb(t_stack **b)
{
	t_stack *first;
	t_stack *last;
	t_stack *second_last;

	if(!(*b) || !((*b)->next))
		return;

	first = *b;
	last = *b;
	second_last = NULL;

	while((last)->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = first;
	*b = last;

	write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
	if(!(*a) || !(*b))
		return;

	rra(a);
	rrb(b);

	write(1, "rrr\n", 4);
}