/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:35:55 by asdebele          #+#    #+#             */
/*   Updated: 2024/07/15 19:17:37 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_line(int fd, char *buf, char *lchr)
{
	int		len;
	char	*temp;

	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0 && !lchr)
			return (NULL);
		if (!lchr)
			lchr = ft_strdup("");
		temp = lchr;
		if (!len)
			break ;
		buf[len] = '\0';
		lchr = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n') || ft_strchr(buf, 0))
		{
			return (lchr);
			break ;
		}
	}
	return (temp);
}

char	*set_lchr(char *buf, char **lchr)
{
	int		i;
	char	*tmp;

	i = 0;
	if (buf == NULL)
	{
		return (NULL);
	}
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
	{
		*lchr = NULL;
		return (buf);
	}
	else
	{
		if (i + 1 != ft_strlen(buf))
			*lchr = ft_substr(buf, i + 1, ft_strlen(buf));
		else
			*lchr = NULL;
	}
	tmp = ft_substr(buf, 0, i + 1);
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*lchr;
	char		*fnl;
	char		*buf;
	char		*tmp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		(void)lchr;
		free(buf);
		return (NULL);
	}
	else
		tmp = fill_line(fd, buf, lchr);
	fnl = set_lchr(tmp, &lchr);
	free(buf);
	return (fnl);
}
