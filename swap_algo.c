/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:35:57 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/08 04:02:07 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

//swap the fisrt 2 element int the stack a
void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}
//swap the fisrt 2 element int the stack b
void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}
//the both
void 	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
