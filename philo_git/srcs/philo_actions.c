/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:43 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/18 12:15:17 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*philo_action(void *ph)
{
	t_philo	*philo;

	philo = ph;
	if (philo->id % 2 == 1)
		usleep(100);
	while (!philo_check_died(philo))
	{
		if (philo_eat(philo))
			break ;
		if (philo_check_died(philo))
			break ;
		print_mutex_message(philo, "is sleeping");
		ft_ms_sleep(*philo->time_to_sleep);
		if (philo_check_died(philo))
			break ;
		print_mutex_message(philo, "is thinking");
	}
	return (NULL);
}

int	philo_check_died(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_died);
	if (*(philo->must_to_die))
	{
		pthread_mutex_unlock(philo->mutex_died);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex_died);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_min);
	print_mutex_message(philo, "has taken a fork");
	if (*philo->n == 1)
	{
		pthread_mutex_unlock(philo->fork_min);
		ft_ms_sleep(*philo->time_to_die);
		return (1);
	}
	pthread_mutex_lock(philo->fork_max);
	print_mutex_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->mutex_time);
	print_mutex_message(philo, "is eating");
	pthread_mutex_lock(philo->mutex_num_ate);
	(philo->num_ate)++;
	pthread_mutex_unlock(philo->mutex_num_ate);
	philo->time_lasteating = get_time_ms();
	pthread_mutex_unlock(philo->mutex_time);
	ft_ms_sleep(*philo->time_to_eat);
	pthread_mutex_unlock(philo->fork_max);
	pthread_mutex_unlock(philo->fork_min);
	return (0);
}
