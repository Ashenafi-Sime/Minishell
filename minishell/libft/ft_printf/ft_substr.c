/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:58:59 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/11 20:47:29 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*ans;

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
