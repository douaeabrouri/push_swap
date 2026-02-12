/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 06:44:19 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/12 15:53:26 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int size_a;
	char **numbers;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = NULL;

	// Parse and validate input
	numbers = make_it_clear(argc, argv);
	if (!numbers)
		return (0);
	// Fill stack A
	fill_stack(numbers, &stack_a);
	size_a = stack_size(stack_a);
	// Check if already sorted
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	// Handle special cases
	if (size_a == 2)
	{
		if (stack_a->value > stack_a->next->value)
			sa(&stack_a);
	}
	else if (size_a == 3)
		sort_three_in_a(&stack_a);
	else if (size_a <= 5)
	{
		sort_five(&stack_a, &stack_b);
	}
	else
	{
		// Turk algorithm for larger stacks
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		size_a -= 2;
		while (size_a > 5) {
			push_the_laziest_number(&stack_a, &stack_b);
			size_a--;
		}
		sort_five(&stack_a, &stack_b);
		// Push back from B to A using the cheapest mov

	}
	// Clean up
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}