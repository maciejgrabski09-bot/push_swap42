/**
 * @brief Extracts an individual signed numeric token and pushes it onto Stack A.
 * 
 * Reads characters, handles bounds checks, checks duplicates, and saves the item.
 */
static void	parse_one_number(char *joined, int *idx, t_stack *a)
{
	int	value;

	// Extract long integer token value and increment scanner tracking index
	value = (int)parse_number(joined, idx);
	
	// If it doesn't end cleanly with a space or string null terminator, it's malformed
	if (joined[*idx] != ' ' && joined[*idx] != '\0')
		error_exit();
		
	// Enforce that values cannot occur multiple times in the collection
	if (already_seen(a, value))
		error_exit();
		
	// Commit standard validated value to stack memory array index
	a->data[a->size++] = value;
}

/**
 * @brief Guards against completely blank or empty parameter strings (e.g., "").
 * 
 * Iterates through parameters ensuring at least one character isn't a plain space.
 */
static void	check_no_blank_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	has_content;

	i = 1;
	while (i < argc)
	{
		j = 0;
		has_content = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				has_content = 1;
			j++;
		}
		if (!has_content)
			error_exit(); // Throws error if string contains nothing but whitespace
		i++;
	}
}

/**
 * @brief Entry point for structural number conversions.
 * 
 * Normalizes input layout, initializes raw buffer capacity, and slices tokens.
 */
void	parse_args(int argc, char **argv, t_stack *a)
{
	char	*joined;
	int		i;

	if (argc < 2)
	{
		stack_init(a, 0); // Handle direct fall-through empty parameters
		return ;
	}
	check_no_blank_args(argc, argv); // Reject empty strings
	joined = join_args(argc, argv);  // Flatten array components down to one space-delimited string
	
	// Safe over-allocation sizing trick based on string length
	stack_init(a, ft_strlen(joined) + 1);
	i = 0;
	while (joined[i])
	{
		// Skip spaces between arguments
		while (joined[i] == ' ')
			i++;
		if (!joined[i])
			break ;
		parse_one_number(joined, &i, a); // Parse token safely
	}
	if (a->size == 0)
		error_exit();
	free(joined); // Free flattened data allocations
}
