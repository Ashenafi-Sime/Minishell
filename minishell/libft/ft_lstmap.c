/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:41:13 by asdebele          #+#    #+#             */
/*   Updated: 2024/03/17 15:41:23 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*n_temp;
	t_list	*new;

	if (!lst || !del || !f)
		return (NULL);
	new = NULL;
	temp = lst;
	while (temp)
	{
		n_temp = ft_lstnew(f(temp->content));
		if (!n_temp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, n_temp);
		temp = temp->next;
	}
	return (new);
}
