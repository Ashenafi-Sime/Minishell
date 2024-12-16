/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:03:55 by asdebele          #+#    #+#             */
/*   Updated: 2024/07/29 18:30:14 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chardup(char c)
{
	char	*str;

	if (c != '\0')
	{
		str = malloc(sizeof(char) * 2);
		str[0] = (char)c;
		str[1] = '\0';
	}
	else
	{
		str = malloc(sizeof(char) * 3);
		str[0] = (char)255;
		str[1] = (char)c;
		str[2] = '\0';
	}
	return (str);
}
