/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:40:08 by ltropina          #+#    #+#             */
/*   Updated: 2024/05/20 13:20:17 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_linetosend(char *str)
{
	size_t	len;
	char	*new;
	char	*p;

	p = ft_strchr(str, '\n');
	if (!p)
		return (str);
	len = p - str + 1;
	new = ft_subline(str, 0, len);
	if (!new)
		return (NULL);
	return (new);
}

static char	*ft_getrest(char *line)
{
	char	*rest;
	char	*p;
	size_t	pos;

	p = ft_strchr(line, '\n');
	if (!p)
		return (NULL);
	pos = p - line + 1;
	if (line[pos] == '\0')
		return (ft_free(&line));
	rest = ft_subline(line, pos, ft_strlen(line) - pos);
	if (!rest)
		return (ft_free(&line));
	ft_free(&line);
	return (rest);
}

static char	*ft_getbuf(int fd, char *line)
{
	ssize_t	bufread;
	char	*buf;

	bufread = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&line));
	while (bufread > 0)
	{
		bufread = read(fd, buf, BUFFER_SIZE);
		if (bufread == -1)
		{
			ft_free(&line);
			return (ft_free(&buf));
		}
		else if (bufread == 0)
			break ;
		buf[bufread] = '\0';
		line = ft_joinline(line, buf);
		if (ft_strchr(buf, '\n') != NULL || !line)
			break ;
	}
	ft_free(&buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&rest));
	if (!rest || (rest && !ft_strchr(rest, '\n')))
		rest = ft_getbuf(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_linetosend(rest);
	if (!line)
		return (ft_free(&rest));
	rest = ft_getrest(rest);
	return (line);
}

/*int	main(void)
{
	char    *line;
	size_t  fd = open("test.txt", O_RDONLY);
	size_t  fd = -1;
	while((line = get_next_line(fd)))
	{
		printf("Read: %s\n", line);
		free(line);
	}
	return(0);
}*/
/*int main (void)
{
	char    *line;
	while((line = get_next_line(0)))
	{
		printf("Read: %s\n", line);
		free(line);
	}
	return (0);
}*/