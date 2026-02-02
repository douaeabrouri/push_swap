/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:47:18 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/02 16:55:34 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"


char **take_arguments(char **argv)
{
	int len;
	char **copy;

	len = 0;
	while(argv[len])
		len++;
	copy = (char **)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	len = 0;
	while(argv[len])
	{
		copy[len] = ft_strdup(argv[len], lenght(argv[1]));
		if (!copy)
			return (NULL);
		len++;
	}
	copy[len] = "\0";
	return (copy);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);

	// optional sign
	if (str[i] == '+' || str[i] == '-')
		i++;

	// must have at least one digit
	if (!str[i])
		return (0);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
long ft_atoi(const char *arg)
{
	int		index;
	long	nb;
	int		sign;

	index = 0;
	sign = 1;
	if(arg[index] == '-' || arg[index] == '+')
	{
		if (arg[index] == '-')
			sign *= -1;
 		index++;
	}
	while((arg[index] >= '0' && arg[index] <= '9') || arg[index] == 32)
	{
		nb = nb * 10 + (arg[index] - '0');
		index++;
	}
	return (sign * nb);
}
char 	**make_it_clear(int argc, char **argv)
{
	char	**nmbrs;
	
	if (argc < 2)
		return (NULL);
	if(argc == 2)
		nmbrs = split_args(argv[1], ' ');
	else
		nmbrs = take_arguments(argv + 1);
	if (!nmbrs)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (nmbrs);
}
int	duplicate_number(t_stack *stack, int value)
{
	while(stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	fill_stack(char **numbers, t_stack **stack)
{
	int index;
	long value;
	t_stack *new;

	index = 0;
	while(numbers[index])
	{
		if(!is_valid_number(numbers[index]))
			error_exit(stack);
		value = ft_atoi(numbers[index]);
		if(value < INT_MIN || value > INT_MAX)
			error_exit(stack);
		if(duplicate_number(*stack, (int)value))
			error_exit(stack);
		new = stack_new((int)value);
		if(!new)
			error_exit(stack);
		stack_add_back(stack, new);
		index++;

	}
}
