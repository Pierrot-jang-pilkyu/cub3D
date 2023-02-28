# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <pjang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 03:49:53 by pjang             #+#    #+#              #
#    Updated: 2023/02/28 20:07:35 by pjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

LIBC	=	-L ./libft/ -lft -L ./mlx/ -lmlx -framework OpenGL -framework AppKit
MLX		=	mlx/libmlx.a
LFT		=	libft/libft.a
SRCS	= 	./srcs/main.c \
			./srcs/parsing/get_cub.c \
			./srcs/parsing/get_cub2.c \
			./srcs/parsing/get_maze.c \
			./srcs/parsing/parsing.c \
			./srcs/parsing/valid_cub.c \
			./srcs/parsing/valid_cub2.c \
			./srcs/parsing/valid_maze.c \
			./srcs/parsing/valid_maze2.c \
			./srcs/render/dda.c \
			./srcs/render/ft_mlx_img.c \
			./srcs/render/game_close.c \
			./srcs/render/keypress.c \
			./srcs/render/move.c \
			./srcs/render/raycasting.c \
			./srcs/render/render.c \
			./srcs/render/draw.c \
			./srcs/render/mlx_init.c \
			./srcs/utils/ft_max.c \
			./srcs/utils/init.c \
			./srcs/utils/init2.c \
			./srcs/utils/put_error.c \
			./srcs/utils/safety_free.c \
			./srcs/utils/print_maze.c \

B_SRCS	= 	./bonus/ft_mlx_img_bonus.c \
			./bonus/game_clear_bonus.c \
			./bonus/game_fail_bonus.c \
			./bonus/game_close_bonus.c \
			./bonus/get_linelen_bonus.c \
			./bonus/get_map_bonus.c \
			./bonus/get_player_position_bonus.c \
			./bonus/inits_bonus.c \
			./bonus/keypress_bonus.c \
			./bonus/main_bonus.c \
			./bonus/map_check_bonus.c \
			./bonus/map_regen_bonus.c \
			./bonus/move_bonus.c \
			./bonus/put_error_bonus.c 

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

BONUS	= $(NAME)

ifdef WITH_BONUS
OBJS_FILES	= $(B_OBJS)
else
OBJS_FILES	= $(OBJS)
endif

all : $(MLX) $(LFT) $(NAME)

$(NAME) : $(OBJS_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBC)

$(MLX) : 
	@make -s -C mlx
	@echo "MLX Success."

$(LFT) :
	@make -s bonus -C libft
	@echo "Libft Success."

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	@make WITH_BONUS=1 all

clean :
	@make -s $@ -C mlx
	@make -s $@ -C libft
	@rm -f $(OBJS)
	@echo "Object files removed."

fclean : clean
	@make -s $@ -C libft
	@make -s $@ -C mlx
	@rm -f $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all bonus clean fclean re