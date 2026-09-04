/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabsk <magrabsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:09:50 by magrabsk          #+#    #+#             */
/*   Updated: 2026/09/04 19:21:22 by magrabsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_ps *ps)
{
	(void)ps;
}

void    sort_simple(t_ps *ps)
{
        if (ps->size_a <= 3)
                sort_three(ps);
        else if (ps->size_a <= 5)
                sort_small(ps);
        else
                big_sort(ps); 
}
