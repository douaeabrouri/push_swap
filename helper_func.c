/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:28:15 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/07 02:23:40 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void update_index(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	write_stack(t_stack **stack)
{
	int index;
	t_stack *tmp;

	index = 0;
	tmp = *stack;
	while(tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}