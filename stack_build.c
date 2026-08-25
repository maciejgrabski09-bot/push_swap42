/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabsk <magrabsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 10:12:53 by magrabsk          #+#    #+#             */
/*   Updated: 2026/08/25 13:27:42 by magrabsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_stack(t_ps *ps, t_stack *parsed)
{
	int	i;

	i = 0;
	while (i < parsed->size)
	{
		if (!add_back(&ps->a, parsed->data[i]))
		{
			free_stack(&ps->a);
			return (0);
		}
		i++;
	}
	ps->size_a = parsed->size;
	return (1);
}

static int	count_smaller(t_node *stack, int size, int value)
{
	t_node	*node;
	int 	count;
	int	i;

	count = 0;
	node = stack;
	i = 0;
	while (i < size)
	{
		if (node->value < value)
			count++;
		node = node->next;
		i++;
	}
	return (count);
}

void	set_indexes(t_ps *ps)
{
	t_node	*node;
	int	i;

	node = ps->a;
	i = 0;
	while (i < ps->size_a)
	{
		node->index = count_smaller(ps->a, ps->size_a, node->value);
		node = node->next;
		i++;
	}
}

int	is_sorted(t_node *stack, int size)
{
	t_node	*node;
	int	i;

	if (size < 2)
		return (1);
	node = stack;
	i = 0;
	while (i < size - 1)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
