#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_stack	parsed;
	t_ps	ps;

	if (argc < 2)
		return (0);
	flags = (t_flags){0, 0, 0, 0, 0};
	parsed.data = NULL;
	parsed.size = 0;
	parse_lvl_1(argc, argv, &flags, &parsed);
	ps.a = NULL;
	ps.b = NULL;
	ps.size_a = 0;
	ps.size_b = 0;
	if (!build_stack(&ps, &parsed))
		error_exit(&parsed, NULL, NULL, NULL);
	free(parsed.data);
	set_indexes(&ps);
	if (!is_sorted(ps.a, ps.size_a))
		sort_simple(&ps);
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}
