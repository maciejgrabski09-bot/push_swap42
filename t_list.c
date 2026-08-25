/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabsk <magrabsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:05:39 by magrabsk          #+#    #+#             */
/*   Updated: 2026/08/22 13:07:11 by magrabsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Creating new node point to adress: next = node, prev = node.
t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	//set a value of new node
	new->value = value;
	new->index = -1;
	new->next = new;
	new->prev = new;
	return (new);
}

//Add new node at the "end" of the list after tail and before the head of list
int	add_back(t_node **stack, int value)
{
	t_node	*new;
	//tail is the last actual node
	t_node	*tail;

	//check if the adress od list doesn't exist
	if (!stack)
		return (0);
	//using new_node function
	new = new_node(value);
	if (!new)
		return (0);
	// condition when the adress of list exists but is empty
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	//Point the adress of tail
	tail = (*stack)->prev;
	//Set an adress of new node 
	new->prev = tail;
	new->next = *stack;
	//change the adresses of existed nodes before
	tail->next = new;
	(*stack)->prev = new;
	return (1);
}

//Cut the cyclical double list and free
void	free_stack(t_node **stack)
{
	t_node	*node;
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	//Set a value "next" of last element of list (tail) to NULL
	(*stack)->prev->next = NULL;
	node = *stack;
	//inside the loop free the single node one after one till the last one
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*stack = NULL;
}

//Detaches the first node (head) from the stack and returns it without freeing
t_node	*pop_front(t_node **stack)
{
	t_node	*node;

	if (!stack || !*stack)
		return (NULL);
	node = *stack;
	//if stack has only one node then the stack will be empty after operations
	if (node->next == node)
	{
		*stack = NULL;
		return (node);
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	//Next node is the head of stack now
	*stack = node->next;
	return (node);
}

//Attaches an existing node to the top of stack
void	push_front(t_node **stack, t_node *node)
{
	t_node	*tail;
	
	if (!stack || !node)
		return ;
	// if list is empty 
	if (!*stack)
	{
		node->next = node;
		node->prev = node;
		//set a head of stack at attached node
		*stack = node;
		return ;
	}
	// else if list is not empty 
	tail = (*stack)->prev;
	node->next = *stack;
	node->prev = tail;
	tail->next = node;
	(*stack)->prev = node;
	(*stack) = node;
}