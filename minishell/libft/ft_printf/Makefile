# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 23:18:59 by asdebele          #+#    #+#              #
#    Updated: 2024/12/07 13:40:38 by asdebele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC		= ft_strlen_p ft_printf ft_p_str ft_pitoa ft_basic 

SRCS		= $(addsuffix .c, ${SRC})

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= clang
RM			= rm -f
AR			= ar rcs
RN			= ranlib
CFLAGS			= -Wall -Wextra -Werror -fPIE -g -fdiagnostics-color=always

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

clean:
			${RM} ${OBJS} ${B_OBJS} 

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
