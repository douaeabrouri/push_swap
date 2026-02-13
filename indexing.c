/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douaeoxo <douaeoxo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:37:11 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/13 22:01:24 by douaeoxo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->cost_a = 0;
	node->cost_b = 0;
	node->dir_a = 0;
	node->dir_b = 0;
	return (node);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*back;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	back = *stack;
	while (back->next)
		back = back -> next;
	back->next = new;
}
