/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:09:31 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/18 18:12:20 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			max;
	unsigned char	*crt;

	max = 2147483647;
	if ((size > max || nmemb > max || size * nmemb > max) && size && nmemb)
		return (NULL);
	crt = malloc (size * nmemb);
	if (!crt)
		return (NULL);
	ft_memset(crt, 0, (nmemb * size));
	return ((crt));
}
