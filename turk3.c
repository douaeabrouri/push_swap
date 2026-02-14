/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:20:18 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/14 15:33:22 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_stack **a)
{
	int	min;
	int	min_pos;
	int	size;

	size = stack_size(*a);
	min_pos = find_min_position(*a, &min);
	if (min_pos <= size / 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
}
