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

void    rotate_to(t_ps *ps, int pos)
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

int     find_position(t_node *a, int size, int index)
{
        t_node  *node;
        int     i;
	
        node = a;
        i = 0;
        while (i < size)
        {
                if (node->index > index)
                        return (i);
                node = node -> next;
                i++;
        }
        return (0);
}


int     find_min_position(t_node *a, int size)
{
        t_node  *node;
        int     i;
	int	min;
	int	pos;

	min = a->index;
	pos = 0;
        node = a;
        i = 0;
        while (i < size)
        {
                if (node->index < min)
		{
			node = node->next;
			pos = i;
		}
		node = node->next;
		i++;
        }
	return (pos);
}

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

void	sort_small(t_ps *ps)
{
	int	pos;

	while (ps->size_a > 3)
		pb(ps);
	sort_three(ps);
	while (ps->size_b > 0)
	{
		pos = find_position(ps->a, ps->size_a, ps->b->index);
		rotate_to(ps, pos);
		pa(ps);
	}
	pos = find_min_position(ps->a, ps->size_a);
	rotate_to(ps, pos);
}
