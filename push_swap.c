/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 06:44:19 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/15 20:26:39 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (size == 3)
		sort_three_in_a(a);
	else if (size <= 5)
		sort_five(a, b);
}

void	sort_large(t_stack **a, t_stack **b, int size)
{
	pb(a, b);
	pb(a, b);
	size -= 2;
	while (size > 5)
	{
		push_the_laziest_number(a, b);
		size--;
	}
	sort_five(a, b);
	while (*b != NULL)
		push_back_to_a(a, b);
	final_rotate(a);
}

int	main(int argc, char **argv)
{
	char	**numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;

	stack_b = NULL;
	stack_a = NULL;
	numbers = make_it_clear(argc, argv);
	if (!numbers)
		return (0);
	fill_stack(numbers, &stack_a);
	free_split(numbers);
	size_a = stack_size(stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	if (size_a <= 5)
		sort_small(&stack_a, &stack_b, size_a);
	else
		sort_large(&stack_a, &stack_b, size_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
