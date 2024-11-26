/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:43:31 by asdebele          #+#    #+#             */
/*   Updated: 2024/02/28 18:43:40 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	found;

	i = 0;
	found = -1;
	while (s[i])
	{
		if (s[i] == (char) c)
			found = i;
		i++;
	}
	if (found >= 0)
		return ((char *)(s + found));
	else if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
