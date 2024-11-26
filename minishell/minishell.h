/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:18:31 by asdebele          #+#    #+#             */
/*   Updated: 2024/11/26 19:23:58 by asdebele         ###   ########.fr       */
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

typedef	struct	s_pos
{
	int	start;
	int	end;
}	t_pos;


typedef struct s_minishell_data
{
	char	*infile;
	char	**outfile;
	char	**env;
	char	***args;
	char	*pathname;
	char	*pg_name;
	char	*rl_str;
	char	**rl_hist;
	int		*arg_type; //1 use function   0 use exeve
	int		arg_nb;
	int		fd[2];
	int		in_fd;
	int		outfile_nb;
	int		out_fd;
	int		inflag;
	int		outflag;
	int		appendflag;
	t_pos	in_pos;
	t_pos	out_pos;
	t_pos	cmd_pos;
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
//main


//parse input output 
void	ft_parse_output_file(t_data *data);
void	ft_parse_input_file(t_data *data);

//util
void	reset(t_data *data);
void	ft_2dfree(char **arr, int j);
void	ft_free(char *arr);




//delete those later

void	test_infile(t_data *data);
void	test_outfile(t_data *data);


#endif
