/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:28:59 by asdebele          #+#    #+#             */
/*   Updated: 2024/11/26 19:31:55 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_2dfree(char **arr, int j)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] != NULL)
		{
			//printf(" %d -> %s\n",i, arr[i]);
			free (arr[i]);
			i++;
		}
	}
	if (arr != NULL)
		free (arr);
	printf("Done\n");
}

void	ft_free(char *arr)
{
	if (arr != NULL)
		free (arr);
}

void	reset(t_data *data)
{
	if (data->inflag)
		ft_free(data->infile);
	if (data->outflag || data->appendflag)
		ft_2dfree(data->outfile);
	ft_free(data->rl_str);

	ft_init(data);
}