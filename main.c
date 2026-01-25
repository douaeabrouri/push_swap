#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	print_stack(t_stack *head)
{
	while (head != NULL)
	{
		printf("%d", head->value);
		head = head->next;
	}
	printf("\n");
}


int main(void)
{
	t_stack *head;
	t_stack *node1;
	t_stack *node2;
	// t_stack *node3;
	// t_stack *node4;


    head  = malloc(sizeof(t_stack));
    node1 = malloc(sizeof(t_stack));
    node2 = malloc(sizeof(t_stack));
    // node3 = malloc(sizeof(t_stack));

	int v1 = 3;
	int v2 = 1;
	int v3 = 2;
	// int v4 = 0;

	head->value = v1;
	head->next  = node1;
	node1->value = v2;
	node1->next = node2;
	node2->value = v3;
	node2->next = NULL;
	// node3->value = v4;
	// node3->next = NULL;

	(&head);
	print_stack(head);
	return 0;
	// duplicate_number(head);
}