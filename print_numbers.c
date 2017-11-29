/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:50:39 by allauren          #+#    #+#             */
/*   Updated: 2017/11/29 22:30:23 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_padding(t_option *s, char *str, int len)
{
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
}

int		printf_numbers(va_list ap, t_option *s, t_size *l)
{
	int			len;
	long long	num;
	int			i;
	char		*str;

	num = ft_parse_size(ap, l);
	i = 0;
	len = 0;
	if (ft_is_negative(num) && (i = 1))
		num = absolute_value(num);
	else
		i = 2;
	str = ft_itoa_base(num, 10);
	if (s->pre != -1 || s->zero != 0)
		str = iszero(str, s, i, 10);
	if (s->plus || i == 1 || s->space)
		str = isplus(str, &i, s);
	len = ft_strlen(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		printf_dnumbers(va_list ap, t_option *s, t_size *l)
{
	int			len;
	long long	num;
	int			i;
	char		*str;

	num = ft_parsel_size(ap, l);
	i = 0;
	len = 0;
	if (ft_is_negative(num) && (i = 1))
		num = absolute_value(num);
	else
		i = 2;
	str = ft_itoa_base(num, 10);
	if (s->pre != -1 || s->zero != 0)
		str = iszero(str, s, i, 10);
	if (s->plus || i == 1 || s->space)
		str = isplus(str, &i, s);
	len = ft_strlen(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		printf_unumbers(va_list ap, t_option *s, t_size *l)
{
	int			len;
	long long	num;
	char		*str;

	num = ft_parseu_size(ap, l);
	len = 0;
	str = ft_itoa_base(num, 10);
	if (s->pre != -1 || s->zero != 0)
		str = iszero(str, s, 0, 10);
	len = ft_strlen(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		printf_umnumbers(va_list ap, t_option *s, t_size *l)
{
	int			len;
	long long	num;
	char		*str;

	num = ft_parseul_size(ap, l);
	len = 0;
	str = ft_itoa_base(num, 10);
	if (s->pre != -1 || s->zero != 0)
		str = iszeroh(str, s, 0, 10);
	len = ft_strlen(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}
