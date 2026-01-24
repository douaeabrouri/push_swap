/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:33:17 by doabrour          #+#    #+#             */
/*   Updated: 2026/01/24 13:33:21 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    ra(t_stack **a)
{
    t_stack *first;
    t_stack *second;

    if(!(*a) || !((*a)->next))
        return;

    first = *a;
    *a = (*a)->next;
    second = *a;
    while(second->next!=NULL)
        second = second->next;
    second->next = first;
    first->next = NULL;

    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    t_stack *first;
    t_stack *second;

    if(!(*b) || !((*b)->next))
        return;
    first = *b;
    *b = (*b)->next;
    second = *b;
    while(second->next != NULL)
        second = second->next;
    second->next = first;
    first->next= NULL;

    write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    if(!(*a) || !(*b))
        return;
    ra(a);
    rb(b);

    write(1, "rr\n", 3);
}