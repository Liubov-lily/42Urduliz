/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:04:51 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/03 13:39:24 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int pid, unsigned char ch)
{
	int	j;
	int	bit;
	int	signal;

	j = 7;
	while (j >= 0)
	{
		bit = ch >> j & 1;
		if (bit == 1)
			signal = SIGUSR1;
		else if (bit == 0)
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			ft_putstr("Error sending bit...");
			exit(1);
		}
		j--;
		usleep(400);
	}
}

static void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, (unsigned char)str[i]);
		i++;
	}
	send_char(pid, (unsigned char)str[i]);
	return ;
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("You command must look like… ./client <PID> <message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!pid || pid < 0 || kill(pid, 0) == -1)
	{
		ft_putstr("Wrong server id\n");
		return (1);
	}
	send_message(pid, argv[2]);
	return (0);
}

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
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!pid || !(pid > 100 && pid < 99999))
		{
			ft_putstr("Wrong server id\n");
			return (0);
		}
		if (argv[2][0] == '\0')
		{
			ft_putstr("You're trying to send an empty message\n");
			return (0);
		}
		send_id(pid, getpid());
		printf("%d", getpid());
		send_message(pid, argv[2]);
	}
	else
	{
		ft_putstr("Wrong arguments! You command must look like…\n");
		ft_putstr("./client <PID> <message>\n");
	}
	return (0);
}


void sig_handler(int signum)
{
	printf("Received signal %d\n", signum);
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	
	sigaction(SIGUSR1, &sa, NULL);
	
	printf("Waiting for SIGUSR1...\n");
	while (1) {
		sleep(1);
	}
	
	return 0;
}*/