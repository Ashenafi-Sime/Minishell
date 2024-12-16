/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:05:57 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/08 19:55:39 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_hist(void)
{
	t_hist	*hist;
	int		i;

	i = 0;
	hist = (t_hist *) safe_malloc(sizeof(t_hist));
	hist->list = history_list ();
	hist->state = history_get_history_state ();
	while (i < hist->state->length)
	{
		free(hist->list[i]);
		i++;
	}
	free(hist->list);
	free(hist->state);
	free(hist);
}

void	ft_2dfree(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

void	ft_free(char *arr)
{
	if (arr != NULL)
		free (arr);
}
