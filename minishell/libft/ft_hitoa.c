/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:51:28 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/22 20:51:34 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cal_len(int n)
{
	int		len;

	if (n == 0)
		return (1);
	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static char	set_value_cap(int nb)
{
	if (nb >= 10)
		return (nb + 55);
	else
		return (nb + '0');
}

static char	set_value(int nb)
{
	if (nb >= 10)
		return (nb + 87);
	else
		return (nb + '0');
}

char	*_tostring_(int n, char *ans, int len, int flag)
{
	len--;
	if (n < 0 && flag != 2)
	{
		n *= -1;
		ans[0] = '-';
	}
	if (flag == 2)
	{
		ans[0] = '0';
		ans[1] = 'x';
	}
	while (n)
	{
		if (flag == 1)
			ans[len] = set_value_cap(n % 16);
		else
			ans[len] = set_value(n % 16);
		n /= 16;
		len --;
	}
	return (ans);
}

char	*ft_hitoa(int n, int flag) //0 -x, 1- X, 2 - p
{
	int		len;
	char	*ans;

	len = cal_len(n);
	if (flag == 2)
		len += 2;
	ans = (char *)malloc(len + 1);
	if (ans == NULL)
		return (NULL);
	if (n == 0)
	{
		ans[0] = '0';
		ans[1] = '\0';
	}
	else if (n == -2147483648)
	{
		ans[len - 1] = '8';
		_tostring_(-80000000, ans, len - 1, flag);
	}
	else
		_tostring_(n, ans, len, flag);
	ans[len] = '\0';
	return (ans);
}
