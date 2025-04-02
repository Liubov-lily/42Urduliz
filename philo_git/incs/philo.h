/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:52:23 by ltropina          #+#    #+#             */
/*   Updated: 2024/09/18 13:21:49 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include "../libs/libft/libft.h"
# include <limits.h>

typedef struct s_philo
{
	int				*n;
	int				id;
	int				num_ate;
	int				*time_to_eat;
	int				*time_to_die;
	int				*time_to_sleep;
	pthread_mutex_t	*fork_min;
	pthread_mutex_t	*fork_max;
	long int		time_lasteating;
	int				*must_to_die;
	long int		*time_start;
	pthread_mutex_t	*mutex_time;
	pthread_mutex_t	*mutex_died;
	pthread_mutex_t	*mutex_for_print;
	pthread_mutex_t	*mutex_num_ate;
}	t_philo;

typedef struct s_data
{
	int				n;
	int				num_to_eat;
	int				died;
	pthread_mutex_t	mutex_for_print;
	pthread_mutex_t	mutex_died;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_num_ate;
	pthread_t		*th;
	t_philo			*arr_philo;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	long int		time_start;
}	t_data;

void	create_philos(t_data *basic_data);
int		create_forks(t_data *basic_data);
int		create_data(t_data *basic_data);

long	int	get_time_ms(void);
void	ft_ms_sleep(int time_sleep);
void	print_mutex_message(t_philo *philo, char *mes);

int		create_threads(t_data *basic_data);
int		join_threads(t_data *basic_data);

void	*philo_action(void *ph);
int		philo_eat(t_philo *philo);
int		philo_check_died(t_philo *philo);
int		start_philo(t_data	*basic_data);

int		ft_check_input(int argc, char **argv);
long	ft_atol(char *s);

void	clean_mutexes_free_memory(t_data *basic_data);
#endif