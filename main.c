#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	t_stack *head;
	t_stack *node1;
	t_stack *node2;
	t_stack *node3;
	t_stack *node4;


    head  = malloc(sizeof(t_stack));
    node1 = malloc(sizeof(t_stack));
    node2 = malloc(sizeof(t_stack));
    node3 = malloc(sizeof(t_stack));
    node4 = malloc(sizeof(t_stack));

	int v1 = 1;
	int v2 = 2;
	int v3 = 2;
	int v4 = 5;

	head->value = 0;
	head->next  = node1;
	node1->value = v1;
	node1->next = node2;
	node2->value = v2;
	node2->next = node3;
	node3->value = v3;
	node3->next = node4;
	node4->value = v4;
	node4->next = NULL;

	duplicate_number(head);
}