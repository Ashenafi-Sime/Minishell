/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:59:09 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/06 20:59:12 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest <= src)
	{
		while (n)
		{
			*d++ = *s++;
			n--;
		}
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n)
		{
			*d-- = *s--;
			n--;
		}
	}
	return (dest);
}
