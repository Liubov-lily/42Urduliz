/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:04:59 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/04 13:07:55 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	add_ch_to_str(char **str, int ch)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (ft_strlen(*str) + 2));
	if (!new)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	i = 0;
	while ((*str)[i])
	{
		new[i] = (*str)[i];
		i++;
	}
	new[i] = ch;
	new[i + 1] = '\0';
	free(*str);
	*str = new;
}

static void	add_bit(int signum, unsigned char *res, size_t *cbit)
{
	if (signum == SIGUSR1)
		*res |= 1;
	if (*cbit != 7)
		*res <<= 1;
	(*cbit)++;
}

int	free_message(char **str)
{
	if (*str)
		free(*str);
	return (0);
}

void	signal_handler(int signum)
{
	static size_t			cbit = 0;
	static unsigned char	res = 0;
	static char				*str = NULL;

	if (signum == SIGINT)
		exit(free_message(&str));
	if (!str)
		str = ft_strdup("");
	add_bit(signum, &res, &cbit);
	if (cbit < 8)
		return ;
	if (!str)
		return ;
	if (res != 0)
		add_ch_to_str(&str, res);
	if (res == 0)
	{
		ft_putstr(str);
		free(str);
		str = NULL;
	}
	cbit = 0;
	res = 0;
}

int	main(void)
{
	ft_putstr("Start server. PID = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGINT, signal_handler);
	while (1)
		pause();
	return (0);
}

/*int	main(void)
{
	struct sigaction	sigact;

	ft_putstr("Start server. PID = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}*/

/*#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int				cbit;
	static unsigned char	res = 0;

	(void)context;
	(void)siginfo;
	if (signum == SIGUSR1)
		res |= 1;
	if (cbit != 7)
		res <<= 1;
	cbit++;
	if (cbit == 8)
	{
		write(1, &res, 1);
		cbit = 0;
		res = 0;
	}
}

int	main(void)
{
	struct sigaction	sigrec;

	ft_putstr("Start server. PID = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	//sigrec.sa_handler = signal_handler;
	sigemptyset(&sigrec.sa_mask);
	sigaddset(&sigrec.sa_mask, SIGUSR1);
	sigaddset(&sigrec.sa_mask, SIGUSR2);
	sigrec.sa_flags = SA_SIGINFO;
	//sigrec.sa_handler = signal_handler;
	sigrec.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sigrec, NULL);
	sigaction(SIGUSR2, &sigrec, NULL);
	while (1)
		pause();
}

void handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "you can't end me\n", 17);
	//the same write(1, "you can't end me\n", 17);
}

int main(void)
{
	//signal(SIGINT, handler);
	signal(SIGUSR1, handler);
	while (1)
	{
		printf("hi!  %d \n", getpid());
		sleep(1);
	}
	return (0);
}*/