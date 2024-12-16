/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:39:17 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/07 13:40:28 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cal_len(size_t n)
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

char	set_value(int nb)
{
	if (nb >= 10)
		return (nb + 87);
	else
		return (nb + '0');
}

static char	*_tostring_(size_t n, char *ans, int len)
{
	len--;
	ans[0] = '0';
	ans[1] = 'x';
	while (n)
	{
		ans[len] = set_value(n % 16);
		n /= 16;
		len --;
	}
	return (ans);
}

char	*ft_pitoa(size_t n) //0 -x, 1- X, 2 - p
{
	int		len;
	char	*ans;

	len = cal_len(n) + 2;
	if ((size_t)n == 0)
	{
		return (ft_strdup("(nil)"));
	}
	ans = (char *)malloc(len + 1);
	if (ans == NULL)
		return (NULL);
	_tostring_(n, ans, len);
	ans[len] = '\0';
	return (ans);
}
