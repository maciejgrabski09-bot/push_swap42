/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabsk <magrabsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:59:36 by magrabsk          #+#    #+#             */
/*   Updated: 2026/08/28 13:29:32 by magrabsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	if (ps->size_a < 2)
		return ;
	ps->a = ps->a->next;
	ps->counts[OP_RA]++;
	write(1, "ra\n", 3);
}

void	rb(t_ps *ps)
{
	if (ps->size_b < 2)
		return ;
	ps->b = ps->b->next;
	ps->counts[OP_RB]++;
	write(1, "rb\n", 3);
}

void	rra(t_ps *ps)
{
	if (ps->size_a < 2)
		return;
	ps->a = ps->a->prev;
	ps->counts[OP_RRA]++;
	write(1, "rra\n", 4);
}

void	rrb(t_ps *ps)
{
	if (ps->size_b < 2)
		return ;
	ps->b = ps->b->prev;
	ps->counts[OP_RRB]++;
	write(1, "rrb\n", 4);
}

