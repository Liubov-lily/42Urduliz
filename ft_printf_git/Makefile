# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 14:59:49 by ltropina          #+#    #+#              #
#    Updated: 2024/04/26 12:09:25 by ltropina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFILES = ft_printf.c ft_hex.c ft_printnum.c
OFILES = $(CFILES:.c=.o)
MAKELIB = make -C 
MAKEPATH = ./libft
OLIBFT = $(MAKEPATH)/*.o
CC = cc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
all: $(NAME) 
$(NAME): $(OFILES)
		$(MAKELIB) $(MAKEPATH)
		$(AR) $(NAME) $(OFILES) $(OLIBFT)
%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		$(RM) $(OFILES)
		$(MAKELIB) $(MAKEPATH) clean
fclean: clean
		$(RM) $(NAME)
		$(MAKELIB) $(MAKEPATH) fclean
re: fclean all