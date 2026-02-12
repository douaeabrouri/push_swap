/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:14:47 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/12 15:52:45 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_the_laziest_for_a(t_stack **a, t_stack **b , int *size_b)
{
	t_stack *tmp;
	t_stack *cheapeast;
	int max_cost;
	int current_cost;

	tmp = *b;
	cheapeast = NULL;
	max_cost = INT_MAX;

	while(tmp)
	{
		calc_costs(b, a, tmp);
		current_cost = get_total_cost(tmp);
		if (current_cost < max_cost)
		{
			max_cost = current_cost;
			cheapeast = tmp;
		}
		tmp = tmp->next;
	}
	if (cheapeast)
		how_much_pain_for_this_number(b, a,cheapeast, size_b);
}

void	

void	final_push_to_stack_a(t_stack **a, t_stack **b)
{

}