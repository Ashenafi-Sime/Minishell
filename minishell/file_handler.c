/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:13:13 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/01 14:07:43 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_open(t_out *out, int i, int flags)
{
	int	fd;

	if (flags == CREATE)
	{
		out[i].fd = open(out[i].name, O_CREAT | O_RDWR | O_TRUNC, 00700);
	}
	else if (flags == OPEN)
	{
		out[i].fd = open(out[i].name, O_APPEND | O_RDWR, 00700);
	}
	else
		fd = -1;
	if (fd < 0)
		perror("File Error");
}

void	open_files(t_out *out, int out_nb)
{
	int	i;

	i = 0;
	while (i < out_nb)
	{
		if (check_bit(out[i].flag, NEW_FILE))
		{
			ft_open(out, i, CREATE);
		}
		else if (check_bit(out[i].flag, APPEND))
		{
			ft_open(out, i, OPEN);
		}
		i++;
	}
}

void	close_files(t_out *out, int out_nb)
{
	int	i;

	i = 0;
	while (i < out_nb)
	{
		close(out[i].fd);
		i++;
	}
}
