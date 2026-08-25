

/**
 * @brief Coordinates flag filtering, validation, and stack data extraction.
 * 
 * Takes the raw argument array, isolates custom flags from numbers, checks 
 * for sorting algorithm conflicts, and triggers the final parsing routine.
 */
void	init_and_parse(int argc, char **argv, t_flags *flags, t_stack *a)
{
	char	**filtered;
	int		filtered_argc;

	// Strip out custom flags (like --bench, --simple) into a separate array
	filtered = filter_flags(argc, argv, &filtered_argc, flags);
	
	// Enforce that only one sorting strategy flag is configured
	check_flag_conflict(flags);
	
	// If no numeric/positional data remains beyond the binary name, terminate early
	if (filtered_argc < 2)
	{
		free(filtered);
		exit(0);
	}
	
	// Hand off clean arguments to populate the primary data stack
	parse_args(filtered_argc, filtered, a);
	
	// Clean up temporary string array reference
	free(filtered);
}



/* From: main_flags.c */

/**
 * @brief Evaluates an incoming argument to determine if it is a configuration flag.
 * 
 * Maps recognized string literals to active flag toggle properties inside the structure.
 * Returns 1 if a structural configuration match occurs, 0 otherwise.
 */
static int	match_flag(char *arg, t_flags *flags)
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
		return (0); // Not a configuration flag
	return (1); // Flag found and processed
}

/**
 * @brief Separates operational flags from target integer arguments.
 * 
 * Iterates through system parameters, passing everything to match_flag. Once non-flag
 * data is hit, all subsequent arguments are collected directly into the filtered set.
 */
static char	**filter_flags(int argc, char **argv, int *out_argc, t_flags *flags)
{
	char	**filtered;
	int		fcount;
	int		i;
	int		flag_zone;

	// Allocate space to hold the elements up to maximum layout size
	filtered = malloc(sizeof(char *) * (argc + 1));
	if (!filtered)
		error_exit();
	fcount = 0;
	filtered[fcount++] = argv[0]; // Preserve executable context
	i = 1;
	flag_zone = 1; // Tracks if we are still checking for leading flags
	while (i < argc)
	{
		// If a string isn't a flag, or we are past the initial flag zone, keep it
		if (!(flag_zone && match_flag(argv[i], flags)))
		{
			filtered[fcount++] = argv[i];
			flag_zone = 0; // Lock further flag evaluation
		}
		i++;
	}
	*out_argc = fcount; // Update back-reference argument counter
	return (filtered);
}

/**
 * @brief Throws an execution error if incompatible flags are set together.
 * 
 * Verifies that the user did not accidentally specify multiple algorithms.
 */
static void	check_flag_conflict(t_flags *flags)
{
	int	count;

	count = flags->simple + flags->medium + flags->complex + flags->adaptive;
	if (count > 1)
		error_exit(); // Terminate if strategies conflict
}
