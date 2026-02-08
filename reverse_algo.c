/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:33:09 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/08 04:04:11 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
		t_stack *prev;
	t_stack *last;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack	**a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}