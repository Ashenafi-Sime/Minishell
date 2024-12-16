/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:19:21 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/16 22:19:22 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_input_file_sign(t_data *data)
{
	int	i;

	i = 0;
	while (data->rl_str[i])
	{
		if (data->rl_str[i] == '<')
		{
			i++;
			if (data->rl_str[i] == '<')
			{
				//data->readwithdelimiter = 1;
				i++;
			}
			else
				data->inflag = 1;
			while (ft_isspace(data->rl_str[i]))
				i++;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	ft_parse_input_file(t_data *data)
{
	int	i;
	int	len;

	data->in_pos.start = ft_input_file_sign(data);
	i = data->in_pos.start;
	if (i != -1)
	{
		if (data->rl_str[i] != '\"')
		{
			while (!ft_isspace(data->rl_str[i]) && data->rl_str[i])
				i++;
			data->in_pos.end = i;
		}
		else
		{
			while (data->rl_str[i] != '\"' && data->rl_str[i])
				i++;
				// create readline if qoute is not closed.
			data->in_pos.end = i;
		}
		len = data->in_pos.end - data->in_pos.start;
		data->infile = ft_substr(data->rl_str, data->in_pos.start, len);
		while (data->rl_str[data->in_pos.start])
			data->in_pos.start --;
	}
}


