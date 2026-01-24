/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:35:25 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/24 19:35:29 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	pa(t_stack	**a, t_stack	**b)
{
	t_stack *top;

	if(!(*b))
		return;
	top = (*b);
	(*b) = (*b)->next;
	top->next = (*a);
	(*a) = top;
	write(1, "pa\n", 3);
}
void	pb(t_stack	**a, t_stack	**b)
{
	t_stack *top;

	if(!(*a))
		return;
	top = (*a);
	(*a) = (*a)->next;
	top->next = (*b);
	(*b) = top;
	write(1, "pb\n" ,3);
}