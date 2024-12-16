/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:18:46 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/07 15:44:55 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_data *data)
{
	data->arg_nb = 0;
	data->in_fd = 0;
	data->inflag = 0;
	data->in_pos.start = 0;
	data->out_pos.start = 0;
	data->cmd_pos.start = 0;
	data->in_pos.end = 0;
	data->out_pos.end = 0;
	data->cmd_pos.end = 0;
	data->outfile_nb = 0;
	data->env = (t_env *)safe_malloc(sizeof(t_env));
	data->env_stack = (t_stack *)malloc(sizeof(t_stack));
	data->env_stack = NULL;
	data->var_stack = (t_stack *)malloc(sizeof(t_stack));
	data->var_stack = NULL;
	
}
