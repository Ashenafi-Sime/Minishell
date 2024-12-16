/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:56:15 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/01 17:05:48 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_pipe(t_data *data)
{
	
}

void	mid_pipe(t_data *data)
{
	
}

void	last_pipe(t_data *data)
{
	
}

void	pipe_fun(t_data *data)
{
	int	i;

	i = 0;
	first_pipe(data, i);
	while (++i < (data->arg_nb - 1))
		mid_pipe(data);
	if (i == (data->arg_nb - 1) && i > 0)
		last_pipe(data);
}