/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabsk <magrabsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:36:22 by magrabsk          #+#    #+#             */
/*   Updated: 2026/08/26 08:43:37 by magrabsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ps *ps)
{
	t_node	*node;

	if (ps->size_a == 0)
		return ;
	node = pop_front(&ps->a);
	push_front(&ps->b, node);
	ps->size_a--;
	ps->size_b++;
	ps->counts[OP_PB]++;
	write(1, "pb\n", 3);
}

void	pa(t_ps *ps)
{
	t_node	*node;

	if (ps->size_b == 0)
		return ;
	node = pop_front(&ps->b);
	push_front(&ps->a, node);
	ps->size_b--;
	ps->size_a++;
	ps->counts[OP_PA]++;
	write(1, "pa\n", 3);
}

void	sa(t_ps *ps)
{
	int	temp;

	if (ps->size_a < 2)
		return ;
	temp = ps->a->value;
	ps->a->value = ps->a->next->value;
	ps->a->next->value = temp;
	temp = ps->a->index;
	ps->a->index = ps->a->next->index;
	ps->a->next->index = temp;
	ps->counts[OP_SA]++;
	write(1, "sa\n", 3);
}

void	sb(t_ps *ps)
{
	int	temp;

	if (ps->size_b < 2)
		return ;
	temp = ps->b->value;
	ps->b->value = ps->b->next->value;
	ps->b->next->value = temp;
	temp = ps->b->index;
	ps->b->index = ps->b->next->index;
	ps->b->next->index = temp;
	ps->counts[OP_SB]++;
	write(1, "sb\n", 3);
}
