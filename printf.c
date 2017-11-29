/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:46:04 by allauren          #+#    #+#             */
/*   Updated: 2017/11/29 22:38:26 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		ret;
	va_list	ap;

	i = 0;
	j = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (j - i++ != 0)
			{
				printf_to_limit((char*)&format[j], (i - j) - 1);
				ret += (i - j - 1);
			}
			i += ft_parse(&format[i], ap, &ret);
			if (ret == -1)
				return (-1);
			j = i;
		}
		else
			i++;
	}
	if (format[j] && format[j] != '%')
	{
		ret += (i - j);
		ft_putstr(&format[j]);
	}
	va_end(ap);
	return (ret);
}
