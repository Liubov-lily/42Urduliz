# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 10:03:27 by ltropina          #+#    #+#              #
#    Updated: 2024/04/18 13:05:42 by ltropina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFILES = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c
CBONUS = ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c
OFILES = $(CFILES:.c=.o)
OBONUS = $(CBONUS:.c=.o)
CC = cc
RM = rm -rf
AR = ar rcs
CFLAGS += -Wall -Wextra -Werror -I.
all: $(NAME)
$(NAME): $(OFILES)
			$(AR) $(NAME) $(OFILES)
%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@
bonus: $(OFILES) $(OBONUS)
		$(AR) $(NAME) $(OFILES) $(OBONUS)
clean:
		$(RM) $(OFILES) $(OBONUS)
fclean: clean
		$(RM) $(NAME)
re: fclean all