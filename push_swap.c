/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 06:44:19 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/07 05:46:34 by doabrour         ###   ########.fr       */
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
	printf("im here\n");

	stack_b = NULL;
	stack_a = NULL;
	
	// Parse and validate input
	numbers = make_it_clear(argc, argv);
	size_a = 0;
	if (!numbers)
		return (0);
	
	// Fill stack A
	fill_stack(numbers, &stack_a);
	write_stack(&stack_a);
	// Check if already sorted

	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	size_a = stack_size(stack_a);
	
	// Handle special cases

	if (size_a == 2)
	{
		if (stack_a->value > stack_a->next->value)
			sa(&stack_a);
	}
	else if (size_a == 3)
	{
		sort_three_in_a(&stack_a);
	}
	else
	{
		// Turk algorithm for larger stacks
		// Push all but 3 to B
		while (size_a > 3)
		{
			pb(&stack_a, &stack_b);
			size_a--;
		}
		
		// Sort the remaining 3 in A
		sort_three_in_a(&stack_a);
		
		// Push back from B to A using the cheapest move

		while (stack_b)
		{
			push_the_laziest_number(&stack_a, &stack_b);
			// printf("%d\n",stack_b->value);
			// sleep(1);
		}
		// Final rotation to put min on top
		final_rotate(&stack_a);
	}
	// write_stack(&stack_b);0
	// Clean up
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}