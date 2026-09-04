/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabsk <magrabsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 00:00:00 by magrabsk          #+#    #+#             */
/*   Updated: 2026/09/04 19:21:54 by magrabsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	bench;
	int	adaptive;
}	t_flags;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	int		counts[11];
	int		strategy;
	double	disorder;
}	t_ps;

/* ------------------------- parser ------------------------------- */

int		stack_init(t_stack *stack, int len);
int		ft_isdigit(char c);
int		ft_strlen(const char *s);
int		ft_strequ(const char *a, const char *b);
void	parse_lvl_1(int argc, char **argv, t_flags *flags, t_stack *a);
void	parse_lvl_2(int new_argc, char **only_nums, t_stack *a);
void	parse_lvl_3(char *all_args, int *pos, t_stack *a, char **only_nums);
void	error_exit(t_stack *a, t_stack *b, char *str, char **arr);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr_fd(long n, int fd);

/* -------------------------t_list.c ------------------------------- */

t_node	*new_node(int value);
int		add_back(t_node **stack, int value);
void	free_stack(t_node **stack);
t_node	*pop_front(t_node **stack);
void	push_front(t_node **stack, t_node *node);

/* ------------------------- stack_build.c --------------------------------- */

int		build_stack(t_ps *ps, t_stack *parsed);
void	set_indexes(t_ps *ps);
int		is_sorted(t_node *stack, int size);

/* ------------------------- operacje -------------------------------------- */

void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

/* ------------------------- sorting.c ------------------------------------- */

void	sort_three(t_ps *ps);
void	sort_small(t_ps *ps);
int		find_position(t_node *a, int size, int index);
int		find_min_position(t_node *a, int size);
void	rotate_to(t_ps *ps, int pos);

/* ------------------------- strategy ------------------------------------- */

void	big_sort(t_ps *ps);
void	sort_simple(t_ps *ps);

#endif
