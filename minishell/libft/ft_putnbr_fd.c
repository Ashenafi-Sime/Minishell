/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:45:41 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/16 11:50:59 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	inner_part(int n, int fd)
{
	char	num;

	if (n < 0)
	{
		num = '-';
		write(fd, &num, 1);
		n = n * -1;
		inner_part(n, fd);
	}
	else
	{
		if (n > 9)
		{
			inner_part(n / 10, fd);
			inner_part(n % 10, fd);
		}
		else
		{
			num = n + '0';
			write (fd, &num, 1);
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		inner_part(n, fd);
	}
}
