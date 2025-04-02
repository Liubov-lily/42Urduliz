/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:29 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/18 13:16:15 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static void	forks_for_philos(t_data *basic_data)
{
	int	i;

	i = 0;
	while (i < basic_data->n)
	{
		if (i == basic_data->n - 1)
		{
			basic_data->arr_philo[i].fork_min = &basic_data->forks[0];
			basic_data->arr_philo[i].fork_max = &basic_data->forks
			[basic_data->n - 1];
		}
		else
		{
			basic_data->arr_philo[i].fork_min = &basic_data->forks[i];
			basic_data->arr_philo[i].fork_max = &basic_data->forks[i + 1];
		}
		i++;
	}
}

void	create_philos(t_data *basic_data)
{
	int	i;

	i = 0;
	while (i < basic_data->n)
	{
		basic_data->arr_philo[i].n = &basic_data->n;
		basic_data->arr_philo[i].id = i + 1;
		basic_data->arr_philo[i].time_to_die = &basic_data->time_to_die;
		basic_data->arr_philo[i].time_to_eat = &basic_data->time_to_eat;
		basic_data->arr_philo[i].time_to_sleep = &basic_data->time_to_sleep;
		basic_data->arr_philo[i].mutex_for_print = &basic_data->mutex_for_print;
		basic_data->arr_philo[i].time_start = &basic_data->time_start;
		basic_data->arr_philo[i].must_to_die = &basic_data->died;
		basic_data->arr_philo[i].num_ate = 0;
		basic_data->arr_philo[i].mutex_time = &basic_data->mutex_time;
		basic_data->arr_philo[i].mutex_died = &basic_data->mutex_died;
		basic_data->arr_philo[i].time_lasteating = basic_data->time_start;
		basic_data->arr_philo[i].mutex_num_ate = &basic_data->mutex_num_ate;
		forks_for_philos(basic_data);
		i++;
	}
}

int	create_forks(t_data *basic_data)
{
	int	i;

	i = 0;
	while (i < basic_data->n)
	{
		if (pthread_mutex_init(&basic_data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&basic_data->forks[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	create_data_mutex(t_data *basic_data)
{
	if (pthread_mutex_init(&basic_data->mutex_for_print, NULL) != 0)
		return (4);
	if (pthread_mutex_init(&basic_data->mutex_time, NULL) != 0)
	{
		pthread_mutex_destroy(&basic_data->mutex_for_print);
		return (5);
	}
	if (pthread_mutex_init(&basic_data->mutex_died, NULL) != 0)
	{
		pthread_mutex_destroy(&basic_data->mutex_for_print);
		pthread_mutex_destroy(&basic_data->mutex_time);
		return (6);
	}
	if (pthread_mutex_init(&basic_data->mutex_num_ate, NULL) != 0)
	{
		pthread_mutex_destroy(&basic_data->mutex_for_print);
		pthread_mutex_destroy(&basic_data->mutex_time);
		pthread_mutex_destroy(&basic_data->mutex_died);
		return (7);
	}
	return (0);
}

int	create_data(t_data *basic_data)
{
	basic_data->th = malloc(sizeof(pthread_t) * basic_data->n);
	if (!basic_data->th)
		return (1);
	basic_data->arr_philo = malloc(sizeof(t_philo) * basic_data->n);
	if (!basic_data->arr_philo)
	{
		free(basic_data->th);
		return (2);
	}
	basic_data->forks = malloc(sizeof(pthread_mutex_t) * basic_data->n);
	if (!basic_data->forks)
	{
		free(basic_data->th);
		free(basic_data->arr_philo);
		return (3);
	}
	if (create_data_mutex(basic_data) != 0)
		return (4);
	return (0);
}
