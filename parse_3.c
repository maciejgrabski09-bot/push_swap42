/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vijain <vijain@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 20:09:02 by vijain            #+#    #+#             */
/*   Updated: 2026/08/30 15:36:06 by vijain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if dup number, return 1, else 0
// comparison with all numbers stored in stack a
static int	dup_num(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] == value)
			return (1);
		i++;
	}
	return (0);
}

// basically ft_atoi
// exit with error, need to free all_args == str && only_nums
//		if nbr not in range (INT_MIN, INT_MAX)
//		more than 1 sign
static long	parse_number(char *str, int *pos, t_stack *a, char **only_nums)
{
	long	value;
	int		sign;
	int		has_digit;

	sign = 1;
	value = 0;
	has_digit = 0;
	if (str[*pos] == '-' || str[*pos] == '+')
	{
		if (str[*pos] == '-')
			sign = -1;
		(*pos)++;
	}
	while (ft_isdigit(str[*pos]))
	{
		value = value * 10 + (str[*pos] - '0');
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && (-value) < INT_MIN))
			error_exit(a, NULL, str, only_nums);
		has_digit = 1;
		(*pos)++;
	}
	if (!has_digit)
		error_exit(a, NULL, str, only_nums);
	return (value * sign);
}

// Parse Lvl 3: Store all numbers in Stack a
// s1: parse_number == ft_atoi; Convert str to nbr
// s2: if non digit char other than space or NULL, exit with error
// s3: Store num in data (array of integers), index == size (Stack a)
void	parse_lvl_3(char *all_args, int *pos, t_stack *a, char **only_nums)
{
	int	value;

	value = (int)parse_number(all_args, pos, a, only_nums);
	if (all_args[*pos] != ' ' && all_args[*pos] != '\0')
		error_exit(a, NULL, all_args, only_nums);
	if (dup_num(a, value))
		error_exit(a, NULL, all_args, only_nums);
	a->data[a->size++] = value;
}
