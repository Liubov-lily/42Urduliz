/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_to_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:23:55 by ltropina          #+#    #+#             */
/*   Updated: 2024/06/24 11:29:04 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_find_firstpos_range(t_list *stack, int range)
{
	int	pos;

	pos = 0;
	while (stack->index >= range)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static int	stack_find_lastpos_range(t_list *stack, int range)
{
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	while (stack)
	{
		if (stack->index <= range)
			pos = i;
		i++;
		stack = stack->next;
	}
	return (pos);
}

void	direction_to_rotate(t_list **stacka, int n, int range)
{
	int	first;
	int	last;

	first = stack_find_firstpos_range(*stacka, range);
	last = stack_find_lastpos_range(*stacka, range);
	if (first <= (n - last))
	{
		while ((*stacka)->index > range)
			stack_rotate(stacka, 'a');
	}
	else
	{
		while ((*stacka)->index > range)
			stack_reverse_rotate(stacka, 'a');
	}
}
