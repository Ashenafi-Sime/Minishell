# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 21:18:39 by asdebele          #+#    #+#              #
#    Updated: 2024/11/26 18:01:59 by asdebele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC     = main ft_safe msg_print parse_text util   test_in_out_file parse_input_output ft_init
SRCS    = $(addsuffix .c, $(SRC))
OBJS    = $(SRCS:.c=.o)
NAME    = minishell

CC      = gcc 
RM      = rm -f
CFLAGS  = -Wall -Werror -Wextra  -g 
LIBFT   = libft/libft.a

all:    $(NAME)

libft:
	@make -C libft/

$(NAME): libft $(OBJS) $(LIBFT)
	$(CC) $(OBJS)  -lreadline -lncurses -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -lreadline -lncurses -Iincludes -Ilibft -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft/

re: fclean all

debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -Llibft -lft -o $(NAME)

.PHONY: libft all clean fclean re debug
