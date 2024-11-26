/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:53:59 by asdebele          #+#    #+#             */
/*   Updated: 2024/11/01 10:35:14 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error_msg(void)
{
	printf (GREEN"Please execute as follows:\n \t./philo X1 X2 X3 X4 [X5]");
	printf("\n where:\n\t X1 - Number of Philosopher \n");
	printf("\t X2 - time to die \n\t X3 - time to eat \n\t X4 - time to sleep");
	printf("\n \t X5 - optional Number of must eat\n"RST);
}

void	exit_error_msg(char *str)
{
	printf (RED" %s\n"RST, str);
	print_error_msg();
}
