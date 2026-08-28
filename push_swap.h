
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define OP_SA  0
# define OP_SB  1
# define OP_SS  2
# define OP_PA  3
# define OP_PB  4
# define OP_RA  5
# define OP_RB  6
# define OP_RR  7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int		value;
	int		index;
}	t_node;

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

typedef struct s_ps
{
	t_node *a;
	t_node *b;
	int	size_a;
	int	size_b;
	int	counts[11];
	int	strategy;
	double	disorder;
}	t_ps;


int		main(int argc, char **argv);

void	stack_init(t_stack *stack, int capacity);
void	stack_free(t_stack *stack);
void	stack_print(t_stack *stack, char name);

t_node	*new_node(int value);
int	add_back(t_node **stack, int value);
void	free_stack(t_node **stack);
t_node	*pop_front(t_node **stack);
void	push_front(t_node **stack, t_node *node);

int	build_stack(t_ps *ps, t_stack *parsed);
void	set_indexes(t_ps *ps);
int	is_sorted(t_node *stack, int size);

void	error_exit(void);
char	*join_args(int argc, char **argv);
long	parse_number(char *str, int *idx);
int		already_seen(t_stack *a, int value);
void	parse_args(int argc, char **argv, t_stack *a);
void	init_and_parse(int argc, char **argv, t_flags *flags, t_stack *a);

int		ft_isdigit(char c);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(long n, int fd);
void	ft_putstr_fd(const char *s, int fd);
int		ft_strequ(const char *a, const char *b);

#endif
