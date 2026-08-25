

#include "push_swap.h"


// flags: simple/complex/bench -- total 5 options
// 
int	main(int argc, char **argv)
{
	t_flags		flags;
	t_stack		a;
	t_stack		b;

	if (argc < 2)
		return (0);
	flags = (t_flags){0, 0, 0, 0, 0};
	init_and_parse(argc, argv, &flags, &a);
	stack_init(&b, a.size);
}
