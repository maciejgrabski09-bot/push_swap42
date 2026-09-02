/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabsk <magrabsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:09:50 by magrabsk          #+#    #+#             */
/*   Updated: 2026/09/02 15:11:43 by magrabsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_ps *ps)
{
	int	pos;

	while (ps->size_a > 0)
	{
		pos = find_min_position(ps->a, ps->size_a);
		rotate_to(ps, pos);
		pb(ps);
	}
	while (ps->size_b > 0)
		pa(ps);
}
