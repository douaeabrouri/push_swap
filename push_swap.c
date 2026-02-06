/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 06:44:19 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/06 22:42:43 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int	size_a;
	char **numbers;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	numbers = make_it_clear(argc, argv);
	fill_stack(numbers, &stack_a);
	size_a = stack_size(stack_a);
	if (is_sorted(stack_a))
		return (0);
	// if size == 2
 
	//if(size == 3)
	else if(size_a == 3)
		sort_three_in_a(&stack_a);
	else
	{
		while(size_a > 3)
		{
			pb(&stack_a, &stack_b);
			size_a--;
		}
		sort_three_in_a(&stack_a);

		while(stack_b)
			push_the_laziest_number(&stack_a, &stack_b);
		final_rotate(&stack_a);
	}
}