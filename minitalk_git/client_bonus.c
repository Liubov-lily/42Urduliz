/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:04:51 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/04 13:08:30 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_mes_received = 0;

static void	send_bit(int pid, unsigned char ch)
{
	int			j;
	static int	ping_num = 0;

	j = 7;
	while (j >= 0)
	{
		if ((ch >> j & 1) == 1)
			kill(pid, SIGUSR1);
		else if ((ch >> j & 1) == 0)
			kill(pid, SIGUSR2);
		j--;
		while (!g_mes_received)
		{
			if (ping_num >= 10)
			{
				ft_putstr("Server is not responding...");
				exit(0);
			}
			ping_num++;
			usleep(100000);
		}
		ping_num = 0;
		g_mes_received = 0;
		usleep(100);
	}
}

static void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bit(pid, (unsigned char)str[i]);
		i++;
	}
	send_bit(pid, (unsigned char)str[i]);
}

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signum == SIGUSR1)
		g_mes_received = 1;
	if (signum == SIGUSR2)
	{
		ft_putstr("Received!");
		exit(0);
	}
}

void	ft_wait(void)
{
	static int	ping_num = 0;

	while (1)
	{
		while (!g_mes_received)
		{
			if (ping_num >= 10)
			{
				ft_putstr("Server is not responding...");
				exit(0);
			}
			ping_num++;
			usleep(100000);
		}
		ping_num = 0;
		g_mes_received = 0;
		pause();
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sigact;

	if (argc != 3)
	{
		ft_putstr("You command must look like… ./client <PID> <message>\n");
		return (1);
	}
	pid = atoi(argv[1]);
	if (!pid || pid < 0 || kill(pid, 0) == -1)
	{
		ft_putstr("Wrong server id\n");
		return (1);
	}
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	send_message(pid, argv[2]);
	ft_wait();
	return (0);
}

/*static void	send_message(int pid, char *str)
{
	int			i;
	static int	ping_num = 0;

	i = 0;
	while (str[i])
	{
		send_bit(pid, (unsigned char)str[i]);
		i++;
	}
	send_bit(pid, (unsigned char)str[i]);
	while (!g_mes_received)
	{
		if (ping_num >= 10)
		{
			ft_putstr("server is not responding...");
			exit(0);
		}
		ping_num++;
		usleep(100000);
	}
	ping_num = 0;
}*/
/*#include "minitalk.h"

static void	send_id(int pid, int num)
{
	int	j;

	j = 31;
	while (j >= 0)
	{
		if ((num >> j & 1) == 1)
			kill(pid, SIGUSR1);
		else if ((num >> j & 1) == 0)
			kill(pid, SIGUSR2);
		j--;
		usleep(100);
	}
}

static void	send_bit(int pid, unsigned char ch)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ((ch >> j & 1) == 1)
			kill(pid, SIGUSR1);
		else if ((ch >> j & 1) == 0)
			kill(pid, SIGUSR2);
		j--;
		usleep(100);
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bit(pid, (unsigned char)str[i]);
		i++;
	}
	send_bit(pid, (unsigned char)str[i]);
}*/