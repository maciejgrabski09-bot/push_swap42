#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_ps	ps;
	t_ps	*node;

	ps.a = NULL;
	ps.b = NULL;
	ps.size_a = 0;
	ps.size_b = 0;
	add_back(&ps.a, 5);
	add_back(&ps.a, 2);
	add_back(&ps.a, 8);
	add_back(&ps.a, 1);
	ps.size_a = 4;
	set_indexes(&ps);
	sort_simple(&ps);
	node = ps.a;
	i = 0;
	while (i < ps.size_a)
	{
	printf("%d ", node->value);
	node = node->next;
	i++;
	}
	printf("\n");
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}