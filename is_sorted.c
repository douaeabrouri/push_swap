/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:35:38 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/25 13:36:09 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
	if(!stack || !stack->next)
	    return 1;

	while(stack->next != NULL)
	{
		if(stack->value > stack->next->value)
		     return 0;
	    stack = stack->next;
	}
	return 1;
}