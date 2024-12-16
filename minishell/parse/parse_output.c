/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:28:14 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/16 22:19:27 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	substring_update(int *i, int *j, int *k, t_data *data)
{
	data->out[*k].name = ft_substr(data->rl_str, *i, *j);
	(*k)++;
	*i = *i + *j - 1;
	*j = 0;
}

void	parse_with_qoute(int *i, int *j, int *k, t_data *data)
{
	char	*temp;
	int		done;

	done = 0;
	while (data->rl_str[*i + *j] != '\"' && data->rl_str[*i + *j])
	{
		(*j)++;
		if (data->rl_str[*i + *j + 1] == 0 && data->rl_str[*i + *j] != '\"')
		{
			data->out[*k].name = ft_substr(data->rl_str, *i, (*j + 1));
			while (1)
			{
				temp = readline("dquote>");
				done = ft_str_has_chr(temp, '\"');
				ft_concat(data->out[*k].name, temp);
				//free(temp); //create Double free error
				if (done)
					break ;
			}
			break ;
		}
	}
	if (!done)
		substring_update(i, j, k, data);
}

void	parse_without_qoute(int *i, int *j, int *k, t_data *data)
{
	while (!ft_isspace(data->rl_str[*i + *j])
		&& data->rl_str[*i + *j] != '>')
		(*j)++;
	substring_update(i, j, k, data);
}

void	set_output_data(int *i, int *j, int *k, t_data *data)
{
	while (data->rl_str[++(*i)] && *k < data->outfile_nb)
	{
		if (data->rl_str[*i] == '>')
		{
			(*i)++;
			if (data->rl_str[*i] == '>')
			{
				data->out[*k].flag = set_bit(APPEND);
				(*i)++;
			}
			else
				data->out[*k].flag = set_bit(NEW_FILE);
			while (ft_isspace(data->rl_str[*i]))
				(*i)++;
			if (data->rl_str[*i + *j] == '\"')
			{
				(*j)++;
				parse_with_qoute(i, j, k, data);
			}
			else
				parse_without_qoute(i, j, k, data);
		}
	}
}

void	ft_parse_output_file(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	data->outfile_nb = cmd_counter(data->rl_str, '>');
	if (!data->outfile_nb)
		return ;
	data->out = (t_out *)safe_malloc(sizeof(t_out) * (data->outfile_nb));
	set_output_data(&i, &j, &k, data);
	open_files(data->out, data->outfile_nb);
}
