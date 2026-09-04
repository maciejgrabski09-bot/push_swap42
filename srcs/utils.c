/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vijain <vijain@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:39:26 by vijain            #+#    #+#             */
/*   Updated: 2026/08/30 15:30:45 by vijain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b, char *str, char **arr)
{
	if (a && a->data)
	{
		free(a->data);
		a->data = NULL;
	}
	if (b && b->data)
	{
		free(b->data);
		b->data = NULL;
	}
	if (str)
		free(str);
	if (arr)
		free(arr);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
