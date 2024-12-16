/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:53:51 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/16 22:19:31 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_join_all(char **args)
{
	int		i;
	char	*ret;
	char	*temp;

	i = 1;
	ret = ft_strjoin(args[1], " ");
	free(args[1]);
	while (args[++i])
	{
		temp = ft_strjoin(ret, args[i]);
		free(ret);
		free(args[i]);
		args[i] = NULL;
		ret = ft_strjoin(temp, " ");
		free(temp);
	}
	args[1] = ft_strdup(ret);
	free(ret);
}

int	cmd_counter(char *str, char c)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (str[++i])
	{
		if (str[i] == c)
		{
			counter++;
			if (str[i + 1] == c)
				i++;
		}
	}
	if (c == '|')
		counter ++;
	return (counter);
}

void	ft_parse_command(t_data *data)
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(data->rl_str, '|');
	data->arg_nb = cmd_counter(data->rl_str, '|');
	data->args = (t_arg *)safe_malloc(data->arg_nb * sizeof(char **));
	while (i < data->arg_nb)
	{
		data->args[i].arg = ft_split(temp[i], ' ');
		data->args[i].type = set_bit(check_cmd(data->args[i].arg[0]));
		if (data->args[i].arg[1] != NULL)
		{
			if (data->args[i].arg[1][0] == '\"'
				|| data->args[i].arg[1][0] == '\'')
				ft_join_all(data->args[i].arg);
		}
		i++;
	}
	data->args[i].arg = NULL;
	ft_2dfree(temp);
}

void	parse_text(t_data *data)
{
	ft_parse_input_file(data);
	ft_parse_output_file(data);
	ft_parse_command(data);
}
