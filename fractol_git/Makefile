# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltropina < ltropina@student.42urduliz.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 13:19:31 by ltropina          #+#    #+#              #
#    Updated: 2024/07/28 13:31:17 by ltropina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m # No color

DEL			=	rm -f
CC			=	gcc
CFLAGS		=	 -Wall -Wextra -Werror
MLX			=	-lXext -lX11 -lm #-g3 -fsanitize=address

NAME		=	fractol
NAME_BONUS	=	fractol_bonus

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
SRC_DIR_BONUS = ./srcs_bonus/
OBJ_DIR_BONUS = ./objs_bonus/

SRC_FILES		=	fractol ft_atof check_input dif_fractals hooks pixels init_mlx
SRC_FILES_BONUS	=	fractol_bonus ft_atof_bonus check_input_bonus \
					dif_fractals_bonus hooks_bonus pixels_bonus init_mlx_bonus

SRC				=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC_BONUS		=	$(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS		=	$(addprefix $(OBJ_DIR_BONUS), $(addsuffix .o, $(SRC_FILES_BONUS)))

MINILIBX	=	minilibx-linux
 
LIBS		= minilibx-linux/libmlx.a $(MLX) 

all:	minilibx $(NAME)
bonus:	minilibx $(NAME_BONUS)
 
$(NAME):$(OBJ)
		@$(CC) $(OBJ) $(LIBS) -o $(NAME)
			@echo "$(GREEN)FRACTOL HAS BEEN COMPILED!$(NC)"

$(NAME_BONUS):$(OBJ_BONUS)
		@$(CC) $(OBJ_BONUS) $(LIBS) -o $(NAME_BONUS)
			@echo "$(GREEN)FRACTOL_BONUS HAS BEEN COMPILED!$(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling mandatory part: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(YELLOW)Compiled mandatory part!$(NC)"

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@echo "$(YELLOW)Compiling bonus part: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(YELLOW)Compiled bonus part!$(NC)"

minilibx:
	@echo "$(YELLOW)COMPILING MINILIBX...$(NC)"
	@$(MAKE) -C ./$(MINILIBX)
	@echo "$(GREEN)MINILIBX HAS BEEN COMPILED$(NC)"

clean:
	@$(DEL) -r $(OBJ_DIR)
	@echo "$(RED)OBJS AND DIRECTORY MANDATORY CLEANED!$(NC)"
clean_bonus:
	@$(DEL) -r $(OBJ_DIR_BONUS)
	@echo "$(RED)OBJS AND DIRECTORY BONUS CLEANED!$(NC)"

fclean_mlx:
	@make clean -C ./$(MINILIBX)
	@echo "$(RED)MINILIBX FULL CLEANED!$(NC)"

fclean: clean
	@$(DEL) $(NAME)
	@echo "$(RED)EXECUTABLE MANDATORY CLEANED!$(NC)"
fclean_bonus: clean_bonus
	@$(DEL) $(NAME_BONUS)
	@echo "$(RED)EXECUTABLE BONUS CLEANED!$(NC)"
	
re: fclean all