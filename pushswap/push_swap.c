/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:11:57 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/12 09:06:58 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_sort(t_list **stacka, int n)
{
	t_list	*stackb;
	int		range;

	stackb = NULL;
	if (n > 5)
		range = find_range(n);
	if (n == 5)
		range = 1;
	if (n == 2)
		stack_swap(*stacka, (*stacka)->next, 'a');
	else if (n == 3)
		stack_sort_three(stacka);
	else if (n >= 4 && n <= 6)
		stack_sort_belowsix(stacka, &stackb, n);
	else
		algoritm_atob(stacka, &stackb, range, n);
}

static int	create_stacka(int n, int *arr)
{
	int		*sortarr;
	t_list	*stacka;

	sortarr = copy_sort_arr(arr, n);
	if (!sortarr)
		return (-1);
	if (n == 1 || check_sort(arr, n))
	{
		free(sortarr);
		return (0);
	}
	stacka = fill_stack(arr, sortarr, n);
	free(sortarr);
	if (!stacka)
		return (-1);
	choose_sort(&stacka, n);
	free_list(stacka);
	return (0);
}

static int	check(int argc, char *argv[], int *arr, int n)
{
	char	**arr_split;

	if (argc == 2)
	{
		arr_split = ft_split(argv[1], ' ');
		if (!arr_split)
			return (0);
		if (!check_input(n, arr_split, arr))
		{
			ft_free(arr_split);
			return (0);
		}
	}
	if (argc > 2 && !check_input(n, &argv[1], arr))
		return (0);
	if (create_stacka(n, arr) == -1)
		return (0);
	return (1);
}

static int	check_string(char *argv[], int *arr, int n)
{
	char	**arr_split;

	arr_split = ft_split(argv[1], ' ');
	if (!arr_split)
		return (0);
	if (!check_input(n, arr_split, arr))
	{
		ft_free(arr_split);
		return (0);
	}
	if (create_stacka(n, arr) == -1)
		return (0);
	ft_free(arr_split);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	n;
	int	*arr;

	if (argc >= 2)
	{
		if (argc == 2)
			n = count_words(argv[1], ' ');
		else
			n = argc - 1;
		arr = (int *)ft_calloc(sizeof(int), n);
		if (!arr)
			return (0);
		if (argc == 2)
			check_string(argv, arr, n);
		else
			check(argc, argv, arr, n);
		free(arr);
	}
	return (0);
}
