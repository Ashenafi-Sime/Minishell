/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:35:33 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/15 19:26:45 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_checker(char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	return (0);
}

int	count_word(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_checker(str[i + 1], c) == 1
			&& char_checker(str[i], c) == 0)
			words++;
		i++;
	}
	return (words);
}

int	count_size(char const *s, char c, int *delimiter)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	*delimiter = 0;
	while (s[i] == c)
	{
		i += 1;
		*delimiter += 1;
	}
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
		{
			return (count);
		}
		count++;
		i++;
	}
	return (count);
}

void	check_free_address1(int i, char **ans)
{
	if (ans[i] == NULL)
	{
		while (i >= 0)
		{
			free (ans[i]);
			i--;
		}
		free (ans);
	}
}

char	**ft_split(char const *s, char c)
{
	int		word;
	int		len;
	int		delimiter;
	int		i;
	char	**ans;

	i = 0;
	word = count_word(s, c);
	ans = (char **)ft_calloc(sizeof(char *), word + 1);
	if (ans == NULL)
		return (NULL);
	while (i < word)
	{
		len = count_size(s, c, &delimiter);
		ans[i] = ft_substr(s, delimiter, len);
		check_free_address1(i, ans);
		if (ans[i] == NULL)
			return (NULL);
		s += len + delimiter;
		i++;
	}
	return (ans);
}
