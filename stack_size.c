/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:10:13 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/29 18:13:05 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *stack_A)
{
	int size;

	size = 0;
	while(stack_A != NULL)
	{
		size++;
		stack_A = stack_A->next;
	}
	return (size);
}