/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:24:20 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/02 23:22:15 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strtok(t_env *env, char *str, char c)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	while (str[++i])
	{
		if (str[i] == c)
			break ;
	}
	env->key = ft_substr(str, 0, i);
	env->value = ft_substr(str, (i + 1), (len - i));
}


char	*ft_strkey(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			break ;
	}
	return (ft_substr(str, 0, i));
}