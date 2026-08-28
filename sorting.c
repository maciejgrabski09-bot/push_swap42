/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabsk <magrabsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 09:05:26 by magrabsk          #+#    #+#             */
/*   Updated: 2026/08/28 13:11:22 by magrabsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->a->index;
	second = ps->a->next->index;
	third = ps->a->next->next->index;

	if (first == 0 && second == 2)
	{
		rra(ps);
		sa(ps);
	}
	else if (first == 1 && second == 2)
		rra(ps);
	else if (first  == 1 && second == 0)
		sa(ps);
	else if (first == 2 && second == 0)
		ra(ps);
	else if (first == 2 && second == 1)
	{
		sa(ps);
		rra(ps);
	}
}

void	rotate_to(t_ps *ps, int pos)
{
	if (pos < ps->size_a / 2)
	{
		while (pos > 0)
		{
			ra(ps);
			pos--;
		}
	}
	else
	{
		while (pos < ps->size_a)
		{
			rra(ps);
			pos++;
		}
	}
}
