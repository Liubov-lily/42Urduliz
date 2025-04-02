/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:34:36 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/26 12:09:21 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_hex(unsigned long long num, int lowupp);
int	ft_printnum(long int num, int len);

#endif
