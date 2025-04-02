/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:04:59 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/04 13:08:33 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	ft_print_message(char **str, siginfo_t *siginfo)
{
	ft_putstr(*str);
	free(*str);
	*str = NULL;
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
	{
		ft_putstr("Failed to send end of message");
		return ;
	}
}

void	signal_handler(int signum, siginfo_t *siginfo, void *context)
{
	static size_t			cbit = 0;
	static unsigned char	res = 0;
	static char				*str = NULL;

	if (signum == SIGINT)
	{
		free(str);
		exit(1);
	}
	(void)context;
	if (!str)
		str = ft_strdup("");
	add_bit(signum, &res, &cbit);
	kill(siginfo->si_pid, SIGUSR1);
	if (cbit < 8)
		return ;
	if (!str)
		return ;
	if (res != 0)
		add_ch_to_str(&str, res);
	if (res == 0)
		ft_print_message(&str, siginfo);
	cbit = 0;
	res = 0;
}

int	main(void)
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
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
	{
		ft_putstr("sigation...");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sigact, NULL) == -1)
	{
		ft_putstr("sigation...");
		exit(1);
	}
	sigaction(SIGINT, &sigact, NULL);
	while (1)
		pause();
}

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

	ft_writestr("Start server. PID = ");
	ft_putnbr(getpid());
	ft_writestr("\n");
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