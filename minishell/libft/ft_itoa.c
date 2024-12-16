/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:03:39 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/07 13:31:16 by asdebele         ###   ########.fr       */
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
		n /= 10;
	}
	return (len);
}

static char	*set_value1(int n, char *ans, int len)
{
	len--;
	if (n < 0)
	{
		n *= -1;
		ans[0] = '-';
	}
	while (n)
	{
		ans[len] = n % 10 + '0';
		n /= 10;
		len --;
	}
	return (ans);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ans;

	len = cal_len(n);
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
		set_value1(-214748364, ans, len - 1);
	}
	else
		set_value1(n, ans, len);
	ans[len] = '\0';
	return (ans);
}
