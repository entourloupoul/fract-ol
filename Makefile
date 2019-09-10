# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmasson <pmasson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 14:47:55 by pmasson           #+#    #+#              #
#    Updated: 2019/03/12 13:16:20 by pmasson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fractol

SRCSDIR		=		./srcs

OBJSDIR		=		./objs

SRCS		=		main.c						fractol_init_fract.c		\
					fractol_manage_frac.c		fractol_draw_mandelbrot.c	\
					fractol_display.c			fractol_init_fract2.c		\
					fractol_manage_zoom.c		fractol_color_pixel.c		\
					fractol_draw_julia.c		fractol_draw_invdelbrot.c	\
					fractol_init_colors.c		fractol_init_mini2.c		\
					fractol_draw_mandeldrop.c	fractol_draw_batman.c		\
					fractol_draw_burningship.c	fractol_draw_feigenbaum.c	\
					fractol_draw_tridelbrot.c	fractol_init_mini.c			\
					fractol_create_mini.c		fractol_deal_key.c			\
					fractol_putstr_win.c


OBJS		=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC			=		gcc

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/ -I libft/includes/ -I minilibx_macos/

RM			=		rm -f

FRAMEWORK	=		-framework OpenGL -framework AppKit

LIB			=		libft/libft.a

LIBMLX		=		minilibx_macos/libmlx.a

all			:		libft libmlx $(NAME)

$(NAME)		:		$(OBJS) $(LIB) $(LIBMLX)
					$(CC) $(CFLAG) $(INCL) $(OBJS) $(LIB) $(LIBMLX) \
					$(FRAMEWORK) -o $(NAME)

libft		:		
					make -C libft/

libmlx		:
					make -C minilibx_macos/

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c includes/fractol.h
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAG) $(INCL) -c $< -o $@

clean		:
					$(RM) $(OBJS)
					make -C minilibx_macos/ clean
					make -C libft/ clean

fclean		:		clean
					$(RM) $(NAME)
					rm -rf $(OBJSDIR)
					rm $(LIB)

re			:		
					@make fclean
					@make all

delsav		:
					$(RM) *~
					$(RM) */*~
					$(RM) \#*\#
					$(RM) */\#*\#

reset		:		
					@make fclean
					@make delsav
					@make -C libft reset
					@make -C minilibx_macos clean
					@rm -Rf objs

.PHONY		:		clean fclean re delsav reset libft libmlx
