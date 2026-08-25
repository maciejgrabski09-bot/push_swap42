#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_ps	ps;
	t_node	*node;
	int		i;

	ps.a = NULL;
	ps.b = NULL;
	ps.size_b = 0;
	add_back(&ps.a, 5);
	add_back(&ps.a, 2);
	add_back(&ps.a, 8);
	ps.size_a = 3;
	set_indexes(&ps);
	node = ps.a;
	i = 0;
	while (i < ps.size_a)
	{
		printf("value=%d index=%d\n", node->value, node->index);
		node = node->next;
		i++;
	}
	free_stack(&ps.a);
	return (0);
}
