/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:15:53 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/26 17:11:22 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_type(char s, va_list *ptr)
{
	char	*tmp;

	if (s == 's')
		tmp = ft_strdup(va_arg(*ptr, char *));
	else if (s == '%')
		tmp = ft_chardup('%');
	else if (s == 'u')
		tmp = ft_uitoa(va_arg(*ptr, unsigned int));
	else if (s == 'c')
		tmp = ft_chardup(va_arg(*ptr, int));
	else if (s == 'p')
		tmp = ft_pitoa(va_arg(*ptr, size_t));
	else if (s == 'X')
		tmp = ft_hitoa(va_arg(*ptr, unsigned int), 1);
	else if (s == 'x')
		tmp = ft_hitoa(va_arg(*ptr, unsigned int), 0);
	else if (s == 'i' || s == 'd' )
		tmp = ft_itoa(va_arg(*ptr, int));
	else
		tmp = NULL;
	return (tmp);
}

int	cal_len(const char *s)
{
	int		len;
	char	*sub;

	len = 0;
	sub = ft_strchr(s, '%');
	if (!sub && s)
		len = ft_strlen(s);
	else if (sub)
		len = sub - s;
	return (len);
}

char	*inner_loop(const char *s, va_list *ptr, char *ans, int *len)
{
	char	*temp;
	char	*temp2;

	temp = ft_strdup(ans);
	temp2 = NULL;
	if (*s != '%')
	{
		*len = cal_len(s);
		temp2 = ft_substr(s, 0, *len);
	}
	else
	{
		if (ft_strchr("cspdiuxX%", s[1]))
			temp2 = check_type(s[1], ptr);
		*len = 2;
	}
	free(ans);
	ans = ft_strjoin(temp, temp2);
	free(temp2);
	free(temp);
	return (ans);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	char	*ans;
	va_list	ptr;

	len = 0;
	va_start(ptr, s);
	ans = ft_strdup("");
	while (*s)
	{
		ans = inner_loop(s, &ptr, ans, &len);
		s += len;
	}
	va_end(ptr);
	ft_p_str(ans);
	len = ft_strlen(ans);
	free(ans);
	return (len);
}
