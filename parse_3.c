/**
 * @brief Flattens multi-argument matrices into a single space-delimited string array.
 */
char	*join_args(int argc, char **argv)
{
	char	*joined;
	int		total_len;
	int		i;
	int		pos;
	int		j;

	total_len = 0;
	i = 1;
	while (i < argc)
		total_len += ft_strlen(argv[i++]) + 1; // Precompute cumulative size requirements
	joined = malloc(sizeof(char) * (total_len + 1));
	if (!joined)
		error_exit();
	pos = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			joined[pos++] = argv[i][j++]; // Transfer elements
		joined[pos++] = ' '; // Pad out segments with space delimiter separator
		i++;
	}
	joined[pos] = '\0'; // Seal with termination character
	return (joined);
}

/**
 * @brief Evaluates dynamic text data, tracking signs and INT bounds configurations.
 * 
 * Extends evaluation into a 64-bit long integer to safely detect 32-bit overflows.
 */
long	parse_number(char *str, int *idx)
{
	long	value;
	int		sign;
	int		has_digit;

	sign = 1;
	value = 0;
	has_digit = 0;
	// Evaluate sign modifier properties
	if (str[*idx] == '-' || str[*idx] == '+')
	{
		if (str[*idx] == '-')
			sign = -1;
		(*idx)++;
	}
	// Parse continuous digit blocks
	while (ft_isdigit(str[*idx]))
	{
		value = value * 10 + (str[*idx] - '0');
		// Catch overflow against strict limits before casting to 32-bit int
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && value > (long)INT_MAX + 1))
			error_exit();
		has_digit = 1;
		(*idx)++;
	}
	if (!has_digit) // Rejects standard loose '+' or '-' without digits following
		error_exit();
	return (value * sign);
}

/**
 * @brief Checks for values already recorded in the target sequence.
 * 
 * Returns 1 if a target match is already inside Stack A, 0 otherwise.
 */
int	already_seen(t_stack *a, int value)
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

/**
 * @brief Allocates an interior integer storage track base array dynamically.
 */
void	stack_init(t_stack *stack, int capacity)
{
	if (capacity <= 0)
	{
		stack->data = NULL;
		stack->size = 0;
		return ;
	}
	// Secure storage allocation block for numeric values
	stack->data = malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	stack->size = 0; // Initialize track tracking counter
}