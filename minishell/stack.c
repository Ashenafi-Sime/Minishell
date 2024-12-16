/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:18:24 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/11 20:24:45 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	push(t_stack **head, char *var)
{
	t_stack	*new_st;

	new_st = malloc(sizeof(t_stack));
	new_st->var = ft_strdup(var);
	new_st->next = NULL;
	if (is_empty(*head))
		new_st->prev = NULL;
	else
	{
		new_st->prev = *head;
		(*head)->next = new_st;
	}
	*head = new_st;
	if (!is_empty((*head)->prev))
	{
		(*head)->id = (*head)->prev->id + 1;
	}
	else
		(*head)->id = 0;
}
/*
t_stack	*find_in_stack(t_stack **st, char *key)
{
	char	*temp;

	if (is_empty(*st))
		return (*st);
	while (is_empty((*st)->prev))
	{
		temp = ft_strkey((*st)->var, '=');
		if (!ft_strcmp(key, temp))
		{
			free(temp);
			return (*st);
		}
		free(temp);
		*st = (*st)->prev;
	}
	return ((*st)->prev);
}*/

t_stack	*end_stack(t_stack **st)
{
	if (is_empty((*st)))
		return (*st);
	while (!is_empty((*st)->next))
		*st = (*st)->next;
	return (*st);
}

/*
void	pop(t_stack **head, char *key)
{
	t_stack	*cur;

	if (is_empty(*head))
		return ;
	cur = find_in_stack(head, key);
	if(is_empty(cur))
	{
		cur = end_stack(head);
		return ;
	}
	printf("Stack.c : %s, \n====next stack= %i===\n \n", cur->var, !is_empty(cur->prev));
	if (!is_empty(cur->prev) && !is_empty(cur->next))
	{
		(*head) = cur-> next;
		(*head)->prev = cur-> prev;
		free(cur->var);
		free(cur);
	}
	else if (is_empty(cur->prev) && !is_empty(cur->next))
	{
		(*head) = cur->next;
		(*head)->prev = NULL;
		free (cur->var);
		free (cur);
	}
	else if (!is_empty(cur->prev) && is_empty(cur->next))
	{
		(*head) = cur->prev;
		(*head)->next = NULL;
		free (cur->var);
		free (cur);
	}
	cur = end_stack(head);
	printf("Stack.c : %s \n====next stack= %i===\n \n", cur->var, !is_empty(cur->next));
}*/





void	remove_stack(t_stack **head, t_stack	*cur)
{
	ft_printf("remove\n");
	if (!is_empty(cur->prev) && !is_empty(cur->next))
	{
		(*head) = cur-> next;
		(*head)->prev = cur-> prev;
	}
	else if (is_empty(cur->prev) && !is_empty(cur->next))
	{
		(*head) = cur->next;
		(*head)->prev = NULL;
	}
	else if (!is_empty(cur->prev) && is_empty(cur->next))
	{
		(*head) = cur->prev;
		(*head)->next = NULL;
	}
	else if (is_empty(cur->prev) && is_empty(cur->next))
	{
		(*head) = NULL;
	}
	free (cur->var);
	free (cur);
	ft_printf("remove2 \n");
}

void	find_n_remove(t_stack **st, char *key)
{
	char	*temp;
	t_stack	*cur;

	cur = *st;
	if (is_empty(cur))
		return ;
	while (1)
	{
		temp = ft_strkey((cur)->var, '=');
		if (!ft_strcmp(key, temp))
		{
			free(temp);
			remove_stack(st, cur);
			end_stack(st);
			return ;
		}
		free(temp);
		if (is_empty((cur)->prev))
			break ;
		cur = (cur)->prev;
	}
	end_stack(st);
}



int	is_empty(t_stack *check)
{
	return (check == NULL);
}

int	st_len(t_stack *st)
{
	if (is_empty(st))
		return (0);
	return (1 + st_len(st->next));
}

int	not_sorted(t_stack **st)
{
	t_stack	*cur;

	cur = *st;
	while (!is_empty((cur)))
	{
		if (!is_empty(cur->next))
		{
			if (ft_strcmp(cur->var, (cur->next)->var) > 0)
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}

