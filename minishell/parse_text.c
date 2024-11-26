/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:53:51 by asdebele          #+#    #+#             */
/*   Updated: 2024/11/26 20:04:48 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_join_all(char **args) // to join all flags of command 
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

int	cmd_counter(char *str, char c) // to count pipe and output file 
{
	int	i;
	int	counter;

	i = 0;
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

int	check_cmd(char *str) // to check builtin function 
{
	if (!ft_strcmp(str, "cd") || !ft_strcmp(str, "pwd")
		|| !ft_strcmp(str, "echo") || !ft_strcmp(str, "export")
		|| !ft_strcmp(str, "unset") || !ft_strcmp(str, "env")
		|| !ft_strcmp(str, "exit"))
	{
		return (1);
	}
	return (0);
}

void	ft_parse_command(t_data *data) // parse command only from command only string 
{
	char	**temp;
	int		i;

	i = 0;
	temp = ft_split(data->rl_str, '|');
	data->arg_nb = cmd_counter(data->rl_str, '|');
	data->args = (char ***)safe_malloc(data->arg_nb * sizeof(char **));
	data->arg_type = (int *)safe_malloc(data->arg_nb * sizeof(int));
	while (i < data->arg_nb)
	{
		data->args[i] = ft_split(temp[i], ' ');
		data->arg_type[i] = check_cmd(data->args[i][0]);
		if (data->args[i][1] != NULL)
		{
			if (data->args[i][1][0] == '\"' || data->args[i][1][0] == '\'')
				ft_join_all(data->args[i]);
		}
		int j = 0;
		printf(" %d \t", data->arg_type[i]);
		while (data->args[i][j])
		{
			printf("%s ", data->args[i][j]);
			j++;
		}
		printf("\t\t%d\n",  j);
		i++;
	}
	ft_2dfree(temp);
}

void	ft_remove_outfile(t_data *data) // not fully implemented
{
	int	len;
	int	i;

	len = ft_strlen(data->rl_str);
	if (data->out_pos.start != data->out_pos.end)
	{
		i = data->out_pos.start;
		while (ft_isspace(data->rl_str[i]) || data->rl_str[i] == '<')
		{
			if (i == 0)
				break ;
			i --;
		}
		if (i == 0)
		{
			while (ft_isspace(data->rl_str[++data->out_pos.end]))
				continue ;
			data->cmd_pos.start = data->out_pos.end;
			data->cmd_pos.end = len;
		}
		else
		{
			data->cmd_pos.start = 0;
			data->cmd_pos.end = i;
		}
		len = data->cmd_pos.end - data->cmd_pos.start;
	}
}



void	ft_prepare_cmd_str(t_data *data)
{
	if (data->inflag)
		ft_remove_outfile (data);
	if (data->outflag)
		ft_remove_outfile (data);
}

void	parse_text(t_data *data)
{
	data->rl_hist = (char **)safe_malloc(10*sizeof(char *));
	data->rl_hist[0] = ft_strdup(data->rl_str);
	ft_parse_input_file(data);
	ft_parse_output_file(data);
	ft_prepare_cmd_str(data);
	ft_parse_command(data);
}
