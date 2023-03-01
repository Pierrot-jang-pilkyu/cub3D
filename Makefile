# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjang <pjang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 03:49:53 by pjang             #+#    #+#              #
#    Updated: 2023/03/01 17:51:44 by pjang            ###   ########.fr        #
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

B_SRCS	= 	./bonus/srcs/main_bonus.c \
			./bonus/srcs/parsing/get_cub_bonus.c \
			./bonus/srcs/parsing/get_cub2_bonus.c \
			./bonus/srcs/parsing/get_maze_bonus.c \
			./bonus/srcs/parsing/parsing_bonus.c \
			./bonus/srcs/parsing/valid_cub_bonus.c \
			./bonus/srcs/parsing/valid_cub2_bonus.c \
			./bonus/srcs/parsing/valid_maze_bonus.c \
			./bonus/srcs/parsing/valid_maze2_bonus.c \
			./bonus/srcs/render/dda_bonus.c \
			./bonus/srcs/render/ft_mlx_img_bonus.c \
			./bonus/srcs/render/game_close_bonus.c \
			./bonus/srcs/render/keypress_bonus.c \
			./bonus/srcs/render/move_bonus.c \
			./bonus/srcs/render/raycasting_bonus.c \
			./bonus/srcs/render/render_bonus.c \
			./bonus/srcs/render/draw_bonus.c \
			./bonus/srcs/render/minimap_bonus.c \
			./bonus/srcs/render/mlx_init_bonus.c \
			./bonus/srcs/utils/ft_max_bonus.c \
			./bonus/srcs/utils/init_bonus.c \
			./bonus/srcs/utils/init2_bonus.c \
			./bonus/srcs/utils/put_error_bonus.c \
			./bonus/srcs/utils/safety_free_bonus.c \
			./bonus/srcs/utils/print_maze_bonus.c \

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
	@rm -f $(B_OBJS)
	@echo "Object files removed."

fclean : clean
	@make -s $@ -C libft
	@make -s $@ -C mlx
	@rm -f $(NAME)
	@echo "Executable file removed."

re : fclean all

.PHONY : all bonus clean fclean re