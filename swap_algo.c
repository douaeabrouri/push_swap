/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:35:57 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/24 19:36:01 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//swap the fisrt 2 element int the stack a
void	sa(t_stack **a)
{
	t_stack *first;
	t_stack *second;

	if(!(*a) || !((*a) ->next))
		return;
	
	first = *a;
	second =(*a)->next;

	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
}
//swap the fisrt 2 element int the stack b
void	sb(t_stack **b)
{
	t_stack *first;
	t_stack *second;

	if(!(*b) || !((*b) ->next))
		return;
	
	first = *b;
	second =(*b)->next;

	first->next = second->next;
	second->next = first;
	*b = second;
	write(1, "sb\n", 3);
}
//the both
void 	ss(t_stack **a, t_stack **b)
{

	if(!(*b) || !(*a))
		return;
		
	sb(b);
	sa(a);
	write(1, "ss\n", 3);
}
