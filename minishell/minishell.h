/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:18:31 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/08 18:40:30 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

# define RED "\033[0;31m"
# define RST "\033[m"
# define GREEN "\033[0;32m" 

# define APPEND 1
# define NEW_FILE 3

# define OPEN 2
# define CREATE 4
# define BUILTIN 5
# define OUR 6

typedef struct stacks
{
	char			*var;
	struct stacks	*next;
	struct stacks	*prev;
	int				id;
}	t_stack;


typedef struct s_pos
{
	int	start;
	int	end;
}	t_pos;

typedef struct s_output
{
	char	*name;
	int		flag;
	int		fd;
}	t_out;

typedef struct s_hist
{
	HIST_ENTRY		**list;
	HISTORY_STATE	*state;
}	t_hist;

typedef struct s_arg
{
	char	**arg;
	int		type;
	int		has_out;
	int		has_in;
}	t_arg;

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;


typedef struct s_minishell_data
{
	char		*infile;
	char		*pathname;
	char		*pg_name;
	char		*rl_str;
	int			arg_nb;
	int			fd[2];
	int			in_fd;
	int			outfile_nb;
	int			inflag;
	t_pos		in_pos;
	t_pos		out_pos;
	t_pos		cmd_pos;
	t_out		*out;
	t_hist		*hist;
	t_arg		*args;
	t_env		*env;
	t_stack		*env_stack;
	t_stack		*var_stack;
}	t_data;

void	ft_init(t_data *data);

// parse text 
void	ft_remove_outfile(t_data *data);
void	ft_join_all(char **args);
void	parse_text(t_data *data);
int		cmd_counter(char *str, char c);

//msg_print
void	print_error_msg(void);
void	exit_error_msg(char *str);

//safe
//void	error_handler(int res, t_op_code op_code);
void	*safe_malloc(size_t bytes);
void	ft_execve(const char *pathname, char *const argv[],
			char *const envp[]);
void	ft_pipe(int *fd);
void	ft_fork(int *pid);
void	ft_create_file(int *fd, char *name);

//
void	ft_open(t_out *out, int i, int flags);
void	close_files(t_out *out, int out_nb);
void	open_files(t_out *out, int out_nb);
//main
//parse input output 
void	ft_parse_output_file(t_data *data);
void	ft_parse_input_file(t_data *data);

//util
void	reset(t_data *data);
void	ft_2dfree(char **arr);
void	ft_free(char *arr);
void	ft_concat(char *str, char *temp);
int		check_bit(int x, int value);
int		set_bit(int value);
int		ft_str_has_chr(const char *s, int c);
int		ft_onlyspace(char *str);
int		check_cmd(char *str);

//delete those later
void	test_infile(t_data *data);
void	test_outfile(t_data *data);

void	free_hist(void);

void	ft_strtok(t_env *env, char *str, char c);
char	*ft_strkey(char *str, char c);

//stack
void	push(t_stack **head, char *var);
//t_stack	*find_in_stack(t_stack **st, char *var);
void	find_n_remove(t_stack **st, char *key);
//void	pop(t_stack **head, char *var);
int		is_empty(t_stack *check);
int		st_len(t_stack *st);
int		not_sorted(t_stack **st);
void	print_stack(t_stack *st);

//handle_env
void	set_env(t_stack **env_stack, char *envp[]);
void	print_env(t_stack *env_stack);
void	add_env(t_stack **env_stack, char *var);

//handle cmd

void	handle_cmd(t_data *data);

#endif
