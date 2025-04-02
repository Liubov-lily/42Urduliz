# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:31:33 by ltropina          #+#    #+#              #
#    Updated: 2024/09/13 13:31:38 by ltropina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEL			=	rm -f
CC			=	gcc
CFLAGS		=	 -Wall -Wextra -Werror

NAME = philo

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/

SRC_FILES = philo check_input ft_atol additional \
		init_struct philo_actions threads

SRC	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIBFT = libs/libft
LIBS = $(LIBFT)/libft.a

all : libft $(NAME)

$(NAME):$(OBJ)
		@$(CC) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

libft:
	@$(MAKE) -C ./$(LIBFT)

clean:
	@$(DEL) -r $(OBJ_DIR)

fclean_libft:
	@make fclean -C ./$(LIBFT)

fclean: clean fclean_libft
	@$(DEL) $(NAME)

re: fclean all