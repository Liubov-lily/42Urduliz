/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:20:01 by ltropina          #+#    #+#             */
/*   Updated: 2024/07/03 13:20:55 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>

int		ft_atoi(char *str);
void	ft_putnbr(int num);
void	ft_putstr(char *str);
char	*ft_strdup(const char *str);
size_t	ft_strlen(char *str);

#endif