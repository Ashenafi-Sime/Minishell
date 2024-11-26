/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:51:44 by asdebele          #+#    #+#             */
/*   Updated: 2024/07/11 20:27:07 by asdebele         ###   ########.fr       */
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

char	*set_value(int n, char *ans, int len)
{
	len--;
	while (n)
	{
		ans[len] = n % 10 + '0';
		n /= 10;
		len --;
	}
	return (ans);
}

char	*ft_uitoa(int n)
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
	set_value(n, ans, len);
	ans[len] = '\0';
	return (ans);
}
