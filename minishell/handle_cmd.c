/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:59:01 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/08 19:45:48 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_equal_sign(char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (str[i] == '=')
			flag = 1;
		if (ft_isspace(str[i]))
			return (0);
	}
	if (!flag)
		return (0);
	return (1);
}

void	set_variable(t_data *data, int i)
{
	int	j;

	j = -1;
	while (data->args[i].arg[++j])
	{
		if (check_equal_sign(data->args[i].arg[j]))
		{
			add_env(&data->var_stack, data->args[i].arg[j]);
		}
	}
}

void	execute_args(t_data *data)
{
	int	i;

	i = -1;
	while (data->args[++i].arg)
	{
		set_variable(data, i);
	}
}

void	handle_cmd(t_data *data)
{
	execute_args(data);
}