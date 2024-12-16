/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:28:59 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/07 13:26:49 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_bit(int value)
{
	int	x;

	x = 0;
	return (((x) |= (1 << (value))));
}

int	check_bit(int x, int value)
{
	return (((x) & (1 << (value))));
}

int	check_cmd(char *str)
{
	if (!ft_strcmp(str, "cd") || !ft_strcmp(str, "pwd")
		|| !ft_strcmp(str, "echo") || !ft_strcmp(str, "export")
		|| !ft_strcmp(str, "unset") || !ft_strcmp(str, "env")
		|| !ft_strcmp(str, "exit"))
	{
		return (OUR);
	}
	return (BUILTIN);
}


void	reset(t_data *data)
{
	if (data->inflag)
		ft_free(data->infile);
	ft_free(data->rl_str);
	close_files(data->out, data->outfile_nb);
}

int	ft_onlyspace(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isspace(str[i]))
			return (0);
	}
	return (1);
}

void	ft_concat(char *str, char *temp)
{
	char	*tp;

	tp = ft_strjoin(str, "\n");
	free(str);
	str = ft_strjoin(tp, temp);
	free(tp);
}

int	ft_str_has_chr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return (1);
	}
	return (0);
}