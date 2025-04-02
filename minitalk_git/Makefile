# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 12:35:56 by ltropina          #+#    #+#              #
#    Updated: 2024/07/03 10:55:54 by ltropina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME_CLIENT = client
NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

SRCS_CLIENT = client.c additional.c additional_write.c
SRCS_SERVER = server.c additional.c additional_write.c
SRCS_CLIENT_BONUS = client_bonus.c additional.c additional_write.c
SRCS_SERVER_BONUS = server_bonus.c additional.c additional_write.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)
bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)
$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJS_CLIENT_BONUS)
$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJS_SERVER_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
re: fclean $(NAME_CLIENT) $(NAME_SERVER)

.PHONY: clean fclean re