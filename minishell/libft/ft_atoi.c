/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:28:04 by asdebele          #+#    #+#             */
/*   Updated: 2024/02/28 18:28:26 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	operation(int flag, int res, char c)
{
	if (flag % 2)
	{
		if (res == 0)
			res = res - (c - 48);
		else
			res = res * 10 - (c - 48);
	}
	else
	{
		if (res == 0)
			res = res + c - 48;
		else
			res = res * 10 + c - 48;
	}
	return (res);
}

int	ft_isspace(const char c)
{
	if (c == '\f' || c == '\n' || c == '\t')
	{
		return (1);
	}
	else if (c == '\r' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	flag;
	int	i;
	int	res;

	i = 0;
	res = 0;
	flag = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		flag = 1;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			res = operation(flag, res, str[i]);
		else
			return (res);
		i++;
	}
	return (res);
}
