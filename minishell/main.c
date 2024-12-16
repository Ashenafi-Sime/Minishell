/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:18:03 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/11 20:25:57 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	init_env(char **env)
{
	env[0] = safe_malloc(9);
	env[1] = safe_malloc(1);
	env[0] = "PATH=/usr/bin";
	env[1] = '\0';
}

void	init_args(int ac, char **av, char ***args)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		args[i - 1] = ft_split(av[i], ' ');
	}
	args[i] = NULL;
}

int	ft_first_fork(char *pathname, char **arg, int *fd[])
{
	pid_t	id;

	ft_fork(&id);
	if (id == 0)
	{
		dup2(*fd[1], 1);
		ft_execve(pathname, arg, NULL);
		close (*fd[1]);
		close (*fd[0]);
	}
	return (0);
}

int	ft_last_fork(char *pathname, char **arg, int *fd[])
{
	pid_t	id;

	ft_fork(&id);
	if (id == 0)
	{
		close (*fd[1]);
		dup2(*fd[0], 0);
		ft_execve(pathname, arg, NULL);
		close (*fd[0]);
	}
	return (0);
}

/*
int	main(int ac, char **av)
{
	
	ft_pipe(fd);
	
	env = safe_malloc(2);
	args = safe_malloc(ac);
	init_env(env);
	init_args(ac, av, args);
	pathname = ft_strjoin("/usr/bin/", args[0][0]);
	if (!ft_first_fork(pathname, args[0], &fd))
		free(pathname);

	printf("\n%s\n", args[1][0]);
	pathname = ft_strjoin("/usr/bin/", args[1][0]);
	printf("\n%s\n", pathname);
	if (!ft_first_fork(pathname, args[1], &fd))
		free(pathname);
	close (fd[0]);
	close (fd[1]);
	return (0);
}
*/


int main(int ac, char **av, char *envp[])
{
	(void) ac;
	(void)av;
	t_data	*data;

	
	data = (t_data *)safe_malloc(sizeof(t_data));
	ft_init(data);
	set_env(&data->env_stack, envp);
	print_env(data->env_stack);
	using_history();
	while (1)
	{
		printf("start\n");
		if (data->pg_name)
			data->rl_str = readline(data->pg_name);
		else
			data->rl_str = readline("___@minishell\% ");
		if (!ft_onlyspace(data->rl_str))
		{
			parse_text(data);
			handle_cmd(data);
			add_history (data->rl_str);
			//reset(data);
			free(data->rl_str);
		}
		write(1,"====== \n",9);
		print_env(data->var_stack);
		printf("\nhere\n");
	}
	free_hist();
	
	return (0);
}


