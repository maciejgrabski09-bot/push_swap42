/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vijain <vijain@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:31:44 by vijain            #+#    #+#             */
/*   Updated: 2026/08/30 15:34:37 by vijain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// valid flag == return 1 else return 0 
static int	store_flags(char *arg, t_flags *flags)
{
	if (ft_strequ(arg, "--simple"))
		flags->simple = 1;
	else if (ft_strequ(arg, "--medium"))
		flags->medium = 1;
	else if (ft_strequ(arg, "--complex"))
		flags->complex = 1;
	else if (ft_strequ(arg, "--adaptive"))
		flags->adaptive = 1;
	else if (ft_strequ(arg, "--bench"))
		flags->bench = 1;
	else
		return (0);
	return (1);
}

// s1: store flags listed immediately after executable in flags  
// s2: everything else goes to only_nums
// 		error exit if flags given after numbers, as per examples in subject 
static char	**fil_flags(int argc, char **argv, int *new_argc, t_flags *flags)
{
	char	**only_nums;
	int		fcount;
	int		i;
	int		flag_zone;

	only_nums = malloc(sizeof(char *) * argc);
	if (!only_nums)
		error_exit(NULL, NULL, NULL, NULL);
	fcount = 0;
	i = 1;
	flag_zone = 1;
	while (i < argc)
	{
		if (flag_zone && store_flags(argv[i], flags))
		{
			i++;
			continue ;
		}
		flag_zone = 0;
		only_nums[fcount++] = argv[i++];
	}
	only_nums[fcount] = NULL;
	*new_argc = fcount;
	return (only_nums);
}

// s1: fil_flags: all initial flags in flags & all numbers in only_nums
// s2: if no args, free mem and exit (does not print Error)
// s3: if multiple strategies, free mem and exit with Error
// only_nums stores the pointers to argv and not actual argv
// since argv not allocated by malloc, no need to free argv
void	parse_lvl_1(int argc, char **argv, t_flags *flags, t_stack *a)
{
	char	**only_nums;
	int		new_argc;

	only_nums = fil_flags(argc, argv, &new_argc, flags);
	if (new_argc == 0)
	{
		free(only_nums);
		exit(0);
	}
	if ((flags->simple + flags->medium + flags->complex + flags->adaptive) > 1)
		error_exit(NULL, NULL, NULL, only_nums);
	parse_lvl_2(new_argc, only_nums, a);
	free(only_nums);
}
