/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:15 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/16 14:36:05 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

long int	get_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "error gettimeofday\n", 20);
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_mutex_message(t_philo *philo, char *mes)
{
	pthread_mutex_lock(philo->mutex_died);
	if (*philo->must_to_die)
	{
		pthread_mutex_unlock(philo->mutex_died);
		return ;
	}
	pthread_mutex_unlock(philo->mutex_died);
	pthread_mutex_lock(philo->mutex_for_print);
	printf("%lu %d %s\n", get_time_ms() - *philo->time_start, philo->id, mes);
	pthread_mutex_unlock(philo->mutex_for_print);
}

void	ft_ms_sleep(int time_sleep)
{
	long	start;

	start = get_time_ms();
	while (start + time_sleep >= get_time_ms())
		usleep(500);
}
