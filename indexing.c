/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:37:11 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/25 13:37:34 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*node;
	
	node = malloc(sizeof(t_stack));
	if(!node)
		//error function
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_stack *stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *back;
	
	if(!stack || !new)
		return;
	if(*stack == NULL)
	{
		*stack = new;
		return;
	}
	back = *stack;
	while(back->next)
		back = back -> next;
	back->next =  new;
}