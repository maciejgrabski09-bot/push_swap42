/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vijain <vijain@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 18:35:35 by vijain            #+#    #+#             */
/*   Updated: 2026/08/30 15:35:24 by vijain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Atleast 1 non-space char in every argv
// else free mem and exit with Error
static void	no_blank_args(int new_argc, char **only_nums)
{
	int	i;
	int	j;
	int	has_content;

	i = 0;
	while (i < new_argc)
	{
		j = 0;
		has_content = 0;
		while (only_nums[i][j])
		{
			if (only_nums[i][j] != ' ')
				has_content = 1;
			j++;
		}
		if (!has_content)
			error_exit(NULL, NULL, NULL, only_nums);
		i++;
	}
}

// s1: cal tot length including Null for each argv in only_nums
// s2: free only_nums if error
// s3: copy every char in every argv in all_args
//     delimiter space after every argv
static char	*join_args(int new_argc, char **only_nums)
{
	char	*all_args;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	while (i < new_argc)
		len += ft_strlen(only_nums[i++]) + 1;
	all_args = malloc(sizeof(char) * (len + 1));
	if (!all_args)
		error_exit(NULL, NULL, NULL, only_nums);
	len = 0;
	i = 0;
	while (i < new_argc)
	{
		j = 0;
		while (only_nums[i][j])
			all_args[len++] = only_nums[i][j++];
		all_args[len++] = ' ';
		i++;
	}
	all_args[len] = '\0';
	return (all_args);
}

// Standard func: Put in common utils
int	stack_init(t_stack *stack, int len)
{
	if (len <= 0)
	{
		stack->data = NULL;
		stack->size = 0;
		return (0);
	}
	stack->data = malloc(sizeof(int) * len);
	if (!stack->data)
		return (0);
	stack->size = 0;
	return (1);
}

// Parse Lvl 2: Processing argv only expecting numbers
// s1: if any empty argv, exit with Error
// s2: all args combined in 1 string, delimited by space
// s3: identify pos of successive num by space, call Lvl 3 parsing
void	parse_lvl_2(int new_argc, char **only_nums, t_stack *a)
{
	char	*all_args;
	int		i;

	no_blank_args(new_argc, only_nums);
	all_args = join_args(new_argc, only_nums);
	if (!stack_init(a, ft_strlen(all_args) + 1))
		error_exit(NULL, NULL, all_args, only_nums);
	i = 0;
	while (all_args[i])
	{
		while (all_args[i] == ' ')
			i++;
		if (!all_args[i])
			break ;
		parse_lvl_3(all_args, &i, a, only_nums);
	}
	if (a->size == 0)
		error_exit(a, NULL, all_args, only_nums);
	free(all_args);
}
