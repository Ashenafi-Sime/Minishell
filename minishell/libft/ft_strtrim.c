/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:43:40 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/11 19:43:56 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	locator(char const *s1, char const *set, int *start, int *end)
{
	int		stop;

	stop = 0;
	while (*start != *end && *start < *end)
	{
		if (ft_strchr(set, s1[*start]) && stop != 2)
			*start += 1;
		else
		{
			if (stop + 2 == 3)
				break ;
			else
				stop = 2;
		}
		if (ft_strchr(set, s1[*end]) && stop != 1)
			*end -= 1;
		else
		{
			if (stop + 1 == 3)
				break ;
			else
				stop = 1;
		}
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	int		len;
	char	*ans;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	locator(s1, set, &start, &end);
	len = end - start;
	if (!len && ft_strchr(set, s1[start]))
		ans = (char *)malloc (sizeof(char));
	else
	{
		if (end < (int)ft_strlen(s1))
			len++;
		ans = ft_substr(s1, start, len);
	}
	*(ans + len) = '\0';
	return (ans);
}
