/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:54:39 by doabrour          #+#    #+#             */
/*   Updated: 2026/02/14 11:07:12 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_spaces(char	*str)
{
	int	index;

	if (!str)
		return (1);
	index = 0;
	while (str[index])
	{
		if (str[index] != ' ' && str[index] != '\t' && str[index] != '\n')
			return (0);
		index++;
	}
	return (1);
}

char	**make_it_clear(int argc, char **argv)
{
	char	**nmbrs;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		if (!argv[1] || !argv[1][0] || is_only_spaces(argv[1]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		nmbrs = split_args(argv[1], ' ');
	}
	else
		nmbrs = take_arguments(argv + 1);
	if (!nmbrs || !nmbrs[0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (nmbrs);
}
