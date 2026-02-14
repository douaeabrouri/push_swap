/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:17:46 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/14 15:33:04 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

int	find_position(t_stack *stack, int value)
{
	t_stack	*tmp;
	int		pos;

	pos++;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	find_min_position(t_stack *a, int *min_value)
{
	t_stack	*tmp;
	int		min_pos;
	int		i;

	tmp = a;
	*min_value = tmp->value;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < *min_value)
		{
			*min_value = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	rotate_b_once(t_stack **b, int dir)
{
	if (dir == 1)
		rb(b);
	else
		rrb(b);
}

void	push_the_laziest_number(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*cheapest;
	int		min_cost;
	int		current_cost;

	tmp = *a;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (tmp)
	{
		calc_costs(a, b, tmp);
		current_cost = get_total_cost(tmp);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	if (cheapest)
		how_much_pain_for_this_number(a, b, cheapest);
}
