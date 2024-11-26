# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 20:25:01 by asdebele          #+#    #+#              #
#    Updated: 2024/11/20 18:10:01 by asdebele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_strtrim ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup  ft_itoa ft_substr ft_strjoin ft_split ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_hitoa ft_uitoa ft_putstr ft_strcmp
 
B_SRC		= ft_lstadd_back ft_lstnew ft_lstsize ft_lstlast ft_lstadd_front ft_lstdelone ft_lstclear ft_lstiter ft_lstmap 

SRCS		= $(addsuffix .c, ${SRC})

B_SRCS		= $(addsuffix .c, ${B_SRC})

OBJS		= ${SRCS:.c=.o}

B_OBJS		= ${B_SRCS:.c=.o}

NAME		= libft.a

CC			= clang
RM			= rm -f
AR			= ar rcs
RN			= ranlib
CFLAGS			= -Wall -Wextra -Werror

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

bonus:		${B_OBJS}
			${AR} ${NAME} ${B_OBJS}
			${RN} ${NAME}

so:
	$(CC) -fPIC $(CFLAGS) $(SRC)
	gcc -shared -o libft.so $(OBJ)

clean:
			${RM} ${OBJS} ${B_OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re

