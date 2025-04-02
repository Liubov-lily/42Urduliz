/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:38:26 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/18 12:48:53 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	ft_check_input(int argc, char **argv)
{
	int		i;
	int		j;
	long	number;

	i = 1;
	if (!(argc == 5 || argc == 6))
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		number = ft_atol(argv[i]);
		if (number == 0 || (i == 1 && !(number > 0 && number <= 200))
			|| (i == 5 && number > INT_MAX))
			return (0);
		else if ((i > 1 && i < 5) && !(number >= 60 && number <= INT_MAX))
			return (0);
		i++;
	}
	return (1);
}
