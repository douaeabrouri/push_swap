/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:28:15 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/08 06:31:20 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int		is_only_spaces(char *str)
{
	int index;

	if (!str)
		return (1);
	index = 0;
	while(str[index])
	{
		if(str[index] != ' ' && str[index] != '\t' && str[index] != '\n')
			return 0;
		index++;
	}
	return (1);
}