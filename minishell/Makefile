# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 21:18:39 by asdebele          #+#    #+#              #
#    Updated: 2024/12/16 22:19:08 by asdebele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC     = main ft_safe msg_print util handle_envp  handle_cmd test_in_out_file  ft_init file_handler  free_fun ft_strtok stack
PARSE   = parse_text parse_input_output parse_output
SRCS    = $(addsuffix .c, $(SRC))
PARSE_PATH    = $(addprefix ./parse/, $(PARSE))
PARSES    = $(addsuffix .c, $(PARSE_PATH))
OBJS    = $(SRCS:.c=.o)
PARSE_OBJ    = $(PARSES:.c=.o)
NAME    = minishell

CC      = gcc 
RM      = rm -f
CFLAGS  = -Wall -Werror -Wextra  -g 
LIBFT   = libft/libft.a
FT_PRINTF  = libft/ft_printf/libftprintf.a 

all:    $(NAME)

libft:
	@make -C libft/
printf: 
	@make -C libft/ft_printf/

$(NAME):printf libft $(OBJS) $(PARSE_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(OBJS) $(PARSE_OBJ) $(FT_PRINTF) -lreadline -lncurses -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -lreadline -lncurses -Iincludes -Ilibft -c $< -o $@

clean:
	$(RM) $(OBJS) $(PARSE_OBJ)
	@make clean -C libft/
	@make clean -C libft/ft_printf/

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft/
	@make fclean -C libft/ft_printf/

re: fclean all

debug: $(OBJS) $(LIBFT) $(PARSE_OBJ)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) $(PARSE_OBJ) -Llibft -lft -libftprintf -o $(NAME)

.PHONY: libft all clean fclean re debug
