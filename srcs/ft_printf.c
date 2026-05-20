/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:00:29 by akdovlet          #+#    #+#             */
/*   Updated: 2026/05/20 08:11:13 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_flag	flags;
	int		wrote;
	int		i;

	i = 0;
	wrote = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			flag_parsing(str, &flags, &i);
			flag_precision(str, &flags, &i);
			if (flags.precision == -1 || flags.width == -1)
			{
				va_end(arg);
				return (-1);
			}
			wrote += ft_draft(str[i], &arg, flags);
		}
		else
			wrote += ft_put_n_count_char(str[i]);
		i++;
	}
	va_end(arg);
	return (wrote);
}
