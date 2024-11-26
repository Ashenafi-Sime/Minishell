/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:10:29 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/16 16:10:32 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp_lst;

	temp_lst = lst;
	count = 0;
	while (temp_lst)
	{
		temp_lst = temp_lst->next;
		count++;
	}
	return (count);
}
