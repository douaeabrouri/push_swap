/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douaeoxo <douaeoxo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:10:13 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/13 22:11:23 by douaeoxo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack_A)
{
	int	size;

	size = 0;
	while (stack_A != NULL)
	{
		size++;
		stack_A = stack_A->next;
	}
	return (size);
}
