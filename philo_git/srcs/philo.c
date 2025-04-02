/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:48:01 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/18 13:19:29 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	clean_mutexes_free_memory(t_data *basic_data)
{
	int	i;

	i = 0;
	while (i < basic_data->n)
	{
		pthread_mutex_destroy(&basic_data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&basic_data->mutex_died);
	pthread_mutex_destroy(&basic_data->mutex_for_print);
	pthread_mutex_destroy(&basic_data->mutex_time);
	free(basic_data->arr_philo);
	free(basic_data->forks);
	free(basic_data->th);
}

int	check_for_philodead_or_finished(t_data *basic_data, int i, int finished)
{
	pthread_mutex_lock(&basic_data->mutex_time);
	if (get_time_ms() - basic_data->arr_philo[i].time_lasteating
		> basic_data->time_to_die + 4 || finished == basic_data->n)
	{
		pthread_mutex_unlock(&basic_data->mutex_time);
		if (finished != basic_data->n)
			print_mutex_message(&basic_data->arr_philo[i], "died");
		pthread_mutex_lock(&basic_data->mutex_died);
		basic_data->died = 1;
		pthread_mutex_unlock(&basic_data->mutex_died);
		join_threads(basic_data);
		clean_mutexes_free_memory(basic_data);
		return (1);
	}
	pthread_mutex_unlock(&basic_data->mutex_time);
	return (0);
}

int	check_philo(t_data *basic_data)
{
	int	i;
	int	finished;

	while (1)
	{
		i = 0;
		finished = 0;
		while (i < basic_data->n)
		{
			pthread_mutex_lock(&basic_data->mutex_num_ate);
			if (basic_data->num_to_eat != -1 && basic_data->arr_philo[i].num_ate
				>= basic_data->num_to_eat)
				finished++;
			pthread_mutex_unlock(&basic_data->mutex_num_ate);
			if (check_for_philodead_or_finished(basic_data, i, finished))
				return (0);
			i++;
		}
		usleep(100);
	}
	return (0);
}

int	start_philo(t_data *basic_data)
{
	int	res;

	res = create_data(basic_data);
	if (res != 0)
	{
		if (res == 4)
		{
			free(basic_data->arr_philo);
			free(basic_data->forks);
			free(basic_data->th);
		}
		return (1);
	}
	if (create_forks(basic_data) != 0)
		return (2);
	create_philos(basic_data);
	if (create_threads(basic_data) != 0)
		return (3);
	check_philo(basic_data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	basic_data;

	if (!ft_check_input(argc, argv))
	{
		printf("Error \n./philo n_philo <= 200\n time_to_die, time_to_eat," \
				"time_to_sleep - 60 <= time <= 2147483647," \
				"[number__must_eat] 60 <= time <= 2147483647");
		return (0);
	}
	basic_data.n = ft_atoi(argv[1]);
	basic_data.died = 0;
	basic_data.num_to_eat = -1;
	basic_data.time_to_die = ft_atoi(argv[2]);
	basic_data.time_to_eat = ft_atoi(argv[3]);
	basic_data.time_to_sleep = ft_atoi(argv[4]);
	basic_data.time_start = get_time_ms();
	if (argc == 6)
		basic_data.num_to_eat = ft_atoi(argv[5]);
	start_philo(&basic_data);
	return (0);
}
