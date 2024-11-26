/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:00:59 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/08 19:01:03 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (n && !(*s11 == '\0' && *s22 == '\0'))
	{
		if (*s11 != *s22)
			return (*s11 - *s22);
		else
		{
			s11++;
			s22++;
		}
		n--;
	}
	return (0);
}
