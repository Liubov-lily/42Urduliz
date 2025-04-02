/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:33:04 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/26 12:07:40 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printstr(char *str, int len)
{
	if (!str)
		len += write(1, "(null)", 6);
	else
		len += write(1, str, ft_strlen(str));
	return (len);
}

static int	ft_checksign(va_list *argptr, char ch, int len)
{
	if (ch == '%')
		len += write(1, &ch, 1);
	else if (ch == 'c')
	{
		ft_putchar_fd(va_arg(*argptr, int), 1);
		len++;
	}
	else if (ch == 's')
		len = ft_printstr(va_arg(*argptr, char *), len);
	else if (ch == 'p')
		len += ft_hex(va_arg(*argptr, unsigned long long), 3);
	else if (ch == 'x')
		len += ft_hex(va_arg(*argptr, unsigned int), 1);
	else if (ch == 'X')
		len += ft_hex(va_arg(*argptr, unsigned int), 2);
	else if (ch == 'i' || ch == 'd')
		len = ft_printnum(va_arg(*argptr, int), len);
	else if (ch == 'u')
		len = ft_printnum(va_arg(*argptr, unsigned int), len);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		len;
	char	*signs;

	signs = "cspdiuxX%";
	va_start(argptr, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *ft_strrchr(signs, *(format + 1)))
		{
			format++;
			len = ft_checksign(&argptr, *format, len);
		}
		else if (*format == '%')
			format++;
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	va_end(argptr);
	return (len);
}
