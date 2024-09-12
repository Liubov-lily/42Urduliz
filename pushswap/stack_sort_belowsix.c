/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_below_6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:11:54 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/12 09:36:15 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort_three(t_list **stack)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *stack;
	b = a->next;
	c = b->next;
	if (a->num > b->num && a->num > c->num)
		stack_rotate(stack, 'a');
	else if (b->num > a->num && b->num > c->num)
		stack_reverse_rotate(stack, 'a');
	a = *stack;
	b = a->next;
	if (a->num > b->num)
		stack_swap(a, b, 'a');
}

void	stack_sort_belowsix(t_list **stacka, t_list **stackb, int n)
{
	int	i;

	i = 0;
	while (i < n / 2)
	{
		if (stack_find_pos(*stacka, i) <= n / 2)
		{
			while ((*stacka)->index != i)
				stack_rotate(stacka, 'a');
		}
		else
		{
			while ((*stacka)->index != i)
				stack_reverse_rotate(stacka, 'a');
		}
		stack_movenode(stacka, stackb, 'b');
		if (n == 4)
			break ;
		i++;
	}
	stack_sort_three(stacka);
	while (*stackb)
		stack_movenode(stackb, stacka, 'a');
}
