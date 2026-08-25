#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_node	*a;
	t_node	*node;
	int		i;
	t_node	*b;

	a = NULL;
	add_back(&a, 5);
	add_back(&a, 2);
	add_back(&a, 8);
	node = a;
	i = 0;
	while (i < 3)
	{
		printf("%d ", node->value);
		node = node->next;
		i++;
	}
	printf("\n");
	node = a;
	i = 0;
	while (i < 3)
	{
		printf("%d ", node->value);
		node = node->prev;
		i++;
	}
	printf("\n");
	b = NULL;
	node = pop_front(&a);
	push_front(&b, node);
	printf("a: %d %d\n", a->value, a->prev->value);   // 2 8
	printf("b: %d\n", b->value);
	
	free_stack(&a);
	free_stack(&b);
	return (0);
}
