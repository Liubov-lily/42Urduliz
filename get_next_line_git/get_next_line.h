/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:40:34 by ltropina          #+#    #+#             */
/*   Updated: 2024/05/15 12:20:39 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_subline(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_joinline(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_free(char **str);

#endif