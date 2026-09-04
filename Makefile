NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= srcs
OBJS_DIR	= objs
INC_DIR		= includes

SRCS		= main.c \
			  parse_1.c \
			  parse_2.c \
			  parse_3.c \
			  utils.c \
			  ft_utils.c \
			  operations_1.c \
			  operations_2.c \
			  operations_3.c \
			  stack_build.c \
			  t_list.c \
			  sorting.c \
			  sort_simple.c

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re