/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:32:46 by allauren          #+#    #+#             */
/*   Updated: 2017/11/25 21:35:14 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
unsigned long long ft_parse_size(va_list ap, t_size *l)
{
	long long n;

	if (l->h == 2)
		n = (long long)((char)va_arg(ap,int));
	else if (l->h== 1)
		n = (long long)((short)va_arg(ap,int));
	else if (l->l == 1 || l->z == 1 || l->j == 1)
		n = (long long)va_arg(ap,long);
	else if (l->l == 2)
		n = (long long)va_arg(ap, long long);
	else
		n = (long long)va_arg(ap, int);
	return(n);
}

unsigned long long ft_parseu_size(va_list ap, t_size *l)
{
	unsigned long long n;

	if (l->h == 2)
		n = (unsigned long long)(va_arg(ap, unsigned int) % 256);
	else if (l->h== 1)
		n = (unsigned long long)(va_arg(ap, unsigned int) % 65536);
	else if (l->l == 1 || l->z == 1 || l->j == 1)
		n = (unsigned long long)va_arg(ap, unsigned long);
	else if (l->l == 2)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else
		n = (unsigned long long)va_arg(ap, unsigned int);
	return(n);
}
