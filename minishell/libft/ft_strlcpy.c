/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:12:56 by asdebele          #+#    #+#             */
/*   Updated: 2024/07/11 20:16:59 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;

	if (size == 0)
		return (ft_strlen((char *)src));
	i = 0;
	while ((i < size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (ft_strlen(src) == i || size - 1 == i)
		dst[i] = '\0';
	return (ft_strlen(src));
}
