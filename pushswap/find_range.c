/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:36:43 by ltropina          #+#    #+#             */
/*   Updated: 2024/06/24 11:28:33 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cubic_root(int n)
{
	int	i;

	i = 0;
	while (i * i * i <= n)
		i++;
	if (n - (i - 1) * (i - 1) * (i - 1) < i * i * i - n)
		return (i - 1);
	else
		return (i);
}

int	find_range(int n)
{
	return (1 + 3 * (cubic_root(n - 1)));
}
