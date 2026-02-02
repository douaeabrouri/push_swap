/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 06:44:19 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/01 20:32:51 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	size_a;
	t_stack *stack;

	stack = fill_stack(); 
	size_a = stack_size(stack);
	if (!is_sorted(stack))
		return (1);
	// if size == 2 -> sa
	// if size == 3 -> sorted three_in_a
	// else -> pb pb 
	// while(size a > 3)
	//{
	// push_the_laziest_number
	//sort_three_in_a
	//push_back_to_a_and_finalize
	//final_rotate	
	//}
}