/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:45:22 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/12 09:08:17 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*copy_sort_arr(int *arr, int n)
{
	int	*sort_arr;
	int	i;

	sort_arr = (int *)malloc(sizeof(int) * n);
	if (!sort_arr)
		return (0);
	i = 0;
	while (i < n)
	{
		sort_arr[i] = arr[i];
		i++;
	}
	bubble_sort(sort_arr, n);
	return (sort_arr);
}

int	find_index(int *arr, int n, int num)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (i);
}
