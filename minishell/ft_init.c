/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:18:46 by asdebele          #+#    #+#             */
/*   Updated: 2024/11/26 18:41:09 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_data *data)
{
	data->appendflag = 0;
	data->arg_nb = 0;
	data->in_fd = 0;
	data->out_fd = 0;
	data->inflag = 0;
	data->outflag = 0;
	data->in_pos.start = 0;
	data->out_pos.start = 0;
	data->cmd_pos.start = 0;
	data->in_pos.end = 0;
	data->out_pos.end = 0;
	data->cmd_pos.end = 0;
	data->outfile_nb = 0;
}