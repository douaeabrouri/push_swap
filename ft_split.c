/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 02:23:13 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/23 12:39:45 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	is_sep(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (charset[index] == c)
			return (1);
		index++; 
	}
	return (0);
}
int	count_word(char *str, char *charset)
{
	int	index;
	int	count_word;
	int	flag;

	index = 0;
	count_word = 0;
	flag = 0;
	while (str[index])
	{
		if (is_sep(str[index], charset))
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count_word++;
		}
		index++;
	}
	return (count_word);
}
char	*ft_strdup(char *start, int len)
{
	char	*tmp;
	int		index;

	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		tmp[index] = start[index];
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}
char	**ft_split(char *str, char *charset)
{
	int		index;
	int		i;
	char	**tmp;
	char	*start;
	int		len;

	index = 0;
	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	while (str[index])
	{
		while (is_sep(str[index], charset) && str[index])
			index++;
		start = &str[index];
		len = 0;
		while (!is_sep(str[index], charset) && str[index])
		{
			index++;
			len++;
		}
		if (len > 0)
			tmp[i++] = ft_strdup(start, len);
	}
	tmp[i] = NULL;
	return (tmp);
}

void	fill_stack(char **numbers, stack_t **stack)
{
	int index;
	int value;
	t_stack *new;

	index = 0;
	while(index < index)
	{
		value = ft_atoi(numbers[index]);
		if(value < INT_MIN || value > INT_MAX )
			//error function
		new = stack_new(value);
		if(!new)
			//error function
	}
}

t_stack	*stack_new(int value)
{
	t_stack	*node;
	
	node = malloc(sizeof(t_stack));
	if(!node)
		//error function
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_stack *stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack *back;
	
	if(!stack || !new)
		return;
	if(*stack == NULL)
	{
		*stack = new;
		return;
	}
	back = *stack;
	while(back->next)
		back = back -> next;
	back->next =  new;
}