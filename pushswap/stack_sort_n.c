/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:52:56 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/12 09:44:52 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algoritm_atob(t_list **stacka, t_list **stackb, int range, int n)
{
	int	count;

	count = 0;
	while (*stacka)
	{
		if ((*stacka)->index <= count)
		{
			stack_movenode(stacka, stackb, 'b');
			n--;
			count++;
			stack_rotate(stackb, 'b');
		}
		else if ((*stacka)->index <= count + range)
		{
			stack_movenode(stacka, stackb, 'b');
			n--;
			count++;
		}
		else
			direction_to_rotate(stacka, n, count + range);
	}
	algoritm_btoa(stacka, stackb, count);
}

int	stack_find_pos(t_list *stack, int num)
{
	int	pos;

	pos = 0;
	while (stack->index != num)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	algoritm_btoa(t_list **stacka, t_list **stackb, int count)
{
	while (count > 0)
	{
		if (stack_find_pos(*stackb, count - 1) <= count / 2)
		{
			while ((*stackb)->index != count - 1)
				stack_rotate(stackb, 'b');
			stack_movenode(stackb, stacka, 'a');
		}
		else
		{
			while ((*stackb)->index != count - 1)
				stack_reverse_rotate(stackb, 'b');
			stack_movenode(stackb, stacka, 'a');
		}
		count--;
	}
}
