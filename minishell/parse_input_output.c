/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:19:21 by asdebele          #+#    #+#             */
/*   Updated: 2024/11/26 20:05:10 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_output_file_sign(t_data *data)
{
	int	i;

	i = 0;
	while (data->rl_str[i])
	{
		if (data->rl_str[i] == '>')
		{
			i++;
			if (data->rl_str[i] == '>')
			{
				data->appendflag = 1;
				i++;
			}
			else
				data->outflag = 1;
			while (ft_isspace(data->rl_str[i]))
				i++;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	ft_parse_output_file1(t_data *data)
{
	int	i;
	int	len;

	data->out_pos.start = ft_output_file_sign(data);
	i = data->out_pos.start;
	if (i != -1)
	{
		if (data->rl_str[i] != '\"')
		{
			while (!ft_isspace(data->rl_str[i]) && data->rl_str[i])
				i++;
			data->out_pos.end = i;
		}
		else
		{
			while (data->rl_str[i] != '\"' && data->rl_str[i])
				i++;
				// create readline if qoute is not closed.
			data->out_pos.end = i;
		}
		len = data->out_pos.end - data->out_pos.start;
		data->outfile[0] = ft_substr(data->rl_str, data->out_pos.start, len);
		while (ft_isspace(data->rl_str[data->out_pos.start]))
			data->out_pos.start --;
	}
}







void	ft_parse_output_file(t_data *data) // this is easy way 
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	data->outfile_nb = cmd_counter(data->rl_str, '>');
	data->outfile = (char **) safe_malloc(sizeof(char *) * data->outfile_nb);
	while (data->rl_str[++i] && k < data->outfile_nb)
	{
		if (data->rl_str[i] == '>')
		{
			i++;
			if (data->rl_str[i] == '>')
			{
				data->appendflag = 1;
				i++;
			}
			else
				data->outflag = 1;
			while (ft_isspace(data->rl_str[i]))
				i++;
			while (!ft_isspace(data->rl_str[i + j]))
				j++;
			data->outfile[k] = ft_substr(data->rl_str, i, j);
			printf("name :%s \n", data->outfile[k]);
			k++;
			i = i + j;
			j = 0;
		}
	}
}


