/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:48:20 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/01 14:06:26 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*safe_malloc(size_t bytes)
{
	void	*rtn;

	rtn = malloc(bytes);
	if (rtn == NULL)
		exit_error_msg("Error with Malloc");
	return (rtn);
}

void	ft_execve(const char *pathname, char *const argv[],	char *const envp[])
{
	if (execve(pathname, argv, envp) == -1)
	{
		perror("execve failed");
	}
}

void	ft_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	ft_fork(int *pid)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

void	ft_create_file(int *fd, char *name)
{
	*fd = open(name, O_WRONLY | O_CREAT | O_TRUNC);
	if (*fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
}

/*
void	error_handler(int res, t_op_code op_code)
{
	if (op_code == INIT && res)
		exit_error_msg("Mutex initialization fault");
	else if (op_code == UNLOCK && res)
		exit_error_msg("Mutex Unlock fault");
	else if (op_code == LOCK && res)
		exit_error_msg("Mutex lock fault");
	else if (op_code == DESTROY && res)
		exit_error_msg("Mutex destroy fault");
	else if (op_code == CREATE && res)
		exit_error_msg("Create Thread fault");
	else if (op_code == JOIN && res)
		exit_error_msg("Join Thread fault");
	else if (op_code == DETACH && res)
		exit_error_msg("Detach Thread fault");
}
*/
