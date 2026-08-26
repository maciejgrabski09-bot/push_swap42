/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabsk <magrabsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 08:21:24 by magrabsk          #+#    #+#             */
/*   Updated: 2026/08/26 08:46:25 by magrabsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_ps *ps)
{
	if (ps->size_a < 2 && ps->size_b < 2)
		return ;
	if (ps->size_a > 1)
		ps->a = ps->a->next;
	if (ps->size_b > 1)
		ps->b = ps->b->next;
	ps->counts[OP_RR]++;
	write(1, "rr\n", 3);
}

void rrr(t_ps *ps)
{
	if (ps->size_a < 2 && ps->size_b < 2)
		return ;
	if (ps->size_a > 1)
		ps->a = ps->a->prev;
	if (ps->size_b > 1)
		ps->b = ps->b->prev;
	ps->counts[OP_RRR]++;
	write(1, "rrr\n", 4);
}

void ss(t_ps *ps)
{
	int	temp;

	if (ps->size_a < 2  && ps->size_b < 2)
		return ;
	if (ps->size_a > 1)
	{
		temp = ps->a->value;
		ps->a->value = ps->a->next->value;
		ps->a->next->value = temp;
		temp = ps->a->index;
		ps->a->index = ps->a->next->index;
		ps->a->next->index = temp;
	}
	if (ps->size_b > 1)
	{
		temp = ps->b->value;
		ps->b->value = ps->b->next->value;
		ps->b->next->value = temp;
		temp = ps->b->index;
		ps->b->index = ps->b->next->index;
		ps->b->next->index = temp;
	}
	ps->counts[OP_SS]++;
	write(1, "ss\n", 3);
}
