/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:48:17 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/16 12:57:47 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	create_threads(t_data *basic_data)
{
	int	i;

	i = 0;
	while (i < basic_data->n)
	{
		basic_data->arr_philo[i].time_lasteating = get_time_ms();
		if (pthread_create(
				&basic_data->th[i], NULL,
				&philo_action, &basic_data->arr_philo[i]))
			return (1);
		i++;
	}
	return (0);
}

int	join_threads(t_data *basic_data)
{
	int	i;

	i = 0;
	while (i < basic_data->n)
	{
		if (pthread_join(basic_data->th[i], NULL))
			return (1);
		i++;
	}
	return (0);
}
