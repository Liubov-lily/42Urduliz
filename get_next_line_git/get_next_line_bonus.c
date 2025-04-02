/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:40:08 by ltropina          #+#    #+#             */
/*   Updated: 2024/05/20 13:20:43 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*rest[FD_COUNT];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_COUNT)
		return (ft_free(&rest[fd]));
	if (!rest[fd] || (rest[fd] && !ft_strchr(rest[fd], '\n')))
		rest[fd] = ft_getbuf(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = ft_linetosend(rest[fd]);
	if (!line)
		return (ft_free(&rest[fd]));
	rest[fd] = ft_getrest(rest[fd]);
	return (line);
}

/*int	main(void)
{
	char    *line1, *line2, *line3;
	size_t  fd1 = open("1.txt", O_RDONLY);
    size_t  fd2 = open("2.txt", O_RDONLY);
    size_t  fd3 = open("3.txt", O_RDONLY);
    
    while ((line1 = get_next_line(fd1)) && (line2 = get_next_line(fd2)) 
	&& ((line3 = get_next_line(fd3))))
	{
            printf("file 1 : %s\n", line1);
		    free(line1);
			printf("file 2 : %s\n", line2);
		    free(line2);
			printf("file 3 : %s\n", line3);
		    free(line3);
    }   
	return(0);
}*/