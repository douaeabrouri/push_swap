/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:36:07 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/15 20:14:30 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*target(int min, int max, int value, t_stack *b)
{
	t_stack	*target;
	t_stack	*tmp;

	if (value > max || value < min)
	{
		tmp = b;
		while (tmp)
		{
			if (tmp->value == max)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = b;
	target = NULL;
	while (tmp)
	{
		if ((tmp->value < value) && (!target || tmp->value > target->value))
			target = tmp;
		tmp = tmp->next;
	}
	return (target);
}

t_stack	*be_or_not_to_be(t_stack *b, int value)
{
	t_stack	*tmp;
	int		max;
	int		min;

	if (!b)
		return (NULL);
	min = b->value;
	max = b->value;
	tmp = b;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (target(min, max, value, b));
}

void	how_much_pain_for_this_number(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a > 0 && node->cost_b > 0
		&& node->dir_a == node->dir_b)
	{
		if (node->dir_a == 1)
			rr(a, b);
		else
			rrr(a, b);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a > 0)
	{
		if (node->dir_a == 1)
			ra(a);
		else
			rra(a);
		node->cost_a--;
	}
	while (node->cost_b > 0)
	{
		rotate_b_once(b, node->dir_b);
		node->cost_b--;
	}
	pb(a, b);
}

int	get_total_cost(t_stack *node)
{
	if (node->dir_a == node->dir_b)
	{
		if (node->cost_a > node->cost_b)
			return (node->cost_a);
		return (node->cost_b);
	}
	return (node->cost_a + node->cost_b);
}

void	calc_costs(t_stack **a, t_stack **b, t_stack *node)
{
	t_stack	*target;
	int		size_a;
	int		size_b;
	int		pos;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	update_index(*a);
	update_index(*b);
	pos = find_position(*a, node->value);
	set_cost_and_dir(node, pos, size_a, 1);
	target = be_or_not_to_be(*b, node->value);
	if (!target)
		pos = 0;
	else
		pos = find_position(*b, target->value);
	set_cost_and_dir(node, pos, size_b, 0);
}
