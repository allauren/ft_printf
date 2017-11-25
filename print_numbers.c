/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:50:39 by allauren          #+#    #+#             */
/*   Updated: 2017/11/25 04:49:34 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		printf_numbers(va_list ap, t_option *s, t_size *l)
{
	int len;
	int num;
	int i;
	char	*str;

	(void)l;
	num = va_arg(ap, int);
	i = 0;
	len = 0;
	if(ft_is_negative(num) && (i = 1))
		num = absolute_value(num);
	else
		i = 2;
	str = ft_itoa_base(num, 10);
	if(s->precision != -1 || s->zero != -1)
		str = iszero(str, s);
	if(s->plus || i == 1)
		str = isplus(str, &i);
	//printf("je passe ici et ma string vaut %s et sa longueur est %d\n", str, len);
		len = ft_strlen(str);
	if (s->moins)
	{
		printf_to_limit(str, len);
		if (s->length - len > 0)
			printf_carac((s->length - len), ' ');
	}
	else
	{
		if (s->length > len)
			printf_carac((s->length - len), ' ');
		printf_to_limit(str, len);
	}
	free(str);
	return((s->length > len) ? s->length : len);
}
