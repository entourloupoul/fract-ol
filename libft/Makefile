#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmasson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 14:39:35 by pmasson           #+#    #+#              #
#    Updated: 2019/03/06 11:10:18 by pmasson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCSDIR	=	srcs

OBJSDIR	=	objs

SRCS	= 	ft_putchar.c ft_strlen.c ft_strcmp.c ft_strdup.c\
	  		ft_putstr.c ft_putendl.c ft_itoa.c ft_putnbr.c\
	  		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	  		ft_putnbr_fd.c ft_memset.c ft_bzero.c ft_strcpy.c\
	  		ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
	  		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c\
	  		ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c\
	  		ft_strncmp.c ft_atoi.c ft_islower.c ft_isupper.c\
	  		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	  		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c\
	  		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	  		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
	  		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
	  		ft_strtrim.c ft_strsplit.c ft_print_table.c ft_memccpy.c\
	  		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c\
	  		ft_lstiter.c ft_lstmap.c ft_convert_base.c ft_lstappend.c\
	  		ft_abs.c ft_ltoa.c ft_lltoa_no_signe.c ft_ulltoa.c\
			get_next_line.c ft_msg_int.c

OBJS	=	$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

INCL	=	-I includes/

all		:	$(NAME)

$(NAME)	:	$(OBJS) includes/libft.h includes/get_next_line.h
			ar rc $(NAME) $(OBJS)

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c
			@mkdir -p $(OBJSDIR)
			$(CC) $(FLAGS) $(INCL) -c $< -o $@

clean	:
			rm -f $(OBJS)
			rm -rf $(OBJSDIR)

fclean	:	clean
			rm -f $(NAME)

re		: 	fclean all

delsav	:	
			rm -f */*~
			rm -f *~
			rm -f *#*\#
			rm -f */\#*\#

reset	:	fclean delsav
			rm -rf objs/

.PHONY	:	clean fclean re delsav reset
