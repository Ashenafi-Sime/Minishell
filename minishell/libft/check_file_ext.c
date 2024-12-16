/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:18:40 by asdebele          #+#    #+#             */
/*   Updated: 2024/07/26 20:27:03 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_file_extension(char *filename)
{
	int		len;
	int		ret_val;
	char	*f_extension;

	len = ft_strlen(filename);
	f_extension = ft_substr(filename, len - 4, len);
	ret_val = ft_strncmp(f_extension, ".ber", 4);
	free(f_extension);
	return (ret_val);
}
