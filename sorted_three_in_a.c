/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_three_in_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:32:01 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/01 17:32:37 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_in_a(t_stack **a)
{
	int		a;
	int		b;
	int		c;

	a = (*a)->value;
	b = (*a)->next->value;
	c = (*a)->next->next->value;

	if (a > b && b < c && a < c)
		sa(*a);
	else if (a > b && b > c)
	{
		sa(*a);
		rra(*a);
	}
	else if (a > b && b < c && a > c)
		ra(*a);
	else if (a < b && b > c && a < c)
	{
		sa(*a);
		ra(*a);
	}
	else if (a < b && b > c && a > c)
		rra(*a);
}