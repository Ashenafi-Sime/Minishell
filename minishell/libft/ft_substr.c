/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:58:59 by asdebele          #+#    #+#             */
/*   Updated: 2024/07/11 20:28:49 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*ans;

	i = 0;
	if (ft_strlen(s) < start)
	{
		ans = (char *)malloc (sizeof(char));
		if (ans == NULL)
			return (NULL);
		ans[0] = '\0';
		return (ans);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	ans = (char *)malloc (len + 1);
	if (ans == NULL)
		return (NULL);
	while (i < len)
	{
		ans[i] = s[start];
		start++;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
