/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:41:00 by ltropina          #+#    #+#             */
/*   Updated: 2024/06/27 14:21:47 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_movenode(t_list **stacka, t_list **stackb, char ch)
{
	t_list	*node;

	node = stack_pop(stacka);
	stack_push(stackb, node);
	if (ch == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
