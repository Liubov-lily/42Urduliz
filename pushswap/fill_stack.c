/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:34:14 by ltropina          #+#    #+#             */
/*   Updated: 2024/06/12 13:08:34 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_stack(int *arr, int *sortarr, int n)
{
	t_list	*stack;
	t_list	*node;
	int		i;

	stack = NULL;
	i = 0;
	while (i < n)
	{
		node = create_node(arr[i], find_index(sortarr, n, arr[i]));
		if (!node)
		{
			free_list(stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}
