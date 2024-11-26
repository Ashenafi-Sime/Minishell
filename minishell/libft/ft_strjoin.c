/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:47:13 by asdebele          #+#    #+#             */
/*   Updated: 2024/07/11 20:29:08 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*ans;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			ans[i] = s1[i];
		else
			ans[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	ans[len] = '\0';
	return (ans);
}
