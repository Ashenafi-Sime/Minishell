/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asdebele <asdebele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:16:12 by asdebele          #+#    #+#             */
/*   Updated: 2024/12/07 13:39:19 by asdebele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(const char *mand, ...);
size_t		ft_strlen_p(const char *str);
char		*ft_itoa(int n);
char		set_value(int nb);
char		*ft_pitoa(size_t n);
void		ft_p_str(char *c);
char		*ft_chardup(char c);
#endif
