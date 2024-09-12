/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:12:30 by ltropina          #+#    #+#             */
/*   Updated: 2024/06/20 14:17:11 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_list *node1, t_list *node2, char ch)
{
	int		index;
	int		num;

	index = node1->index;
	node1->index = node2->index;
	node2->index = index;
	num = node1->num;
	node1->num = node2->num;
	node2->num = num;
	if (ch == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	stack_rotate(t_list **stack, char ch)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack)->prev && !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (ch == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	stack_reverse_rotate(t_list **stack, char ch)
{
	t_list	*last;
	t_list	*second_last;

	if (!(*stack)->prev && !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	second_last = last->prev;
	if (second_last != NULL)
		second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	if (ch == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	stack_push(t_list **stack, t_list *node)
{
	ft_lstadd_before(stack, node);
}

t_list	*stack_pop(t_list **head)
{
	t_list	*node;

	node = *head;
	if (!node->prev && !node->next)
		*head = NULL;
	else
	{
		*head = node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		node->next = NULL;
	}
	return (node);
}
