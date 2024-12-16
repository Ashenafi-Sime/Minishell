/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:41:11 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/11 20:08:49 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(t_stack **st, char *envp[])
{
	int	i;

	i = -1;
	while (envp[++i])
		push(st, envp[i]);
}

void	add_env(t_stack **st, char *var)
{
	char	*key;

	key = ft_strkey(var, '=');
	find_n_remove(st, key);
	push(st, var);
}

void	print_env(t_stack *st)
{
	t_stack	*cur;

	cur = st;
	if (is_empty(cur))
	{
		ft_printf("\n");
	}
	while (!is_empty((cur)))
	{
		ft_printf("%d - %s \n", cur->id, cur->var);
		cur = cur->prev;
	}

}

