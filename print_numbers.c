/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:50:39 by allauren          #+#    #+#             */
/*   Updated: 2017/11/27 06:15:56 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		printf_numbers(va_list ap, t_option *s, t_size *l)
{
	int len;
	long long num;
	int i;
	char	*str;

	num = ft_parse_size(ap, l) ;
	i = 0;
	len = 0;
	if (ft_is_negative(num) && (i = 1))
		num = absolute_value(num);
	else
		i = 2;
	str = ft_itoa_base(num, 10);
	if (s->precision != -1 || s->zero != 0)
		str = iszero(str, s, i);
	if (s->plus || i == 1 || s->space)
		str = isplus(str, &i, s);
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
	return ((s->length > len) ? s->length : len);
}
int		printf_p(va_list ap, t_option *s, t_size *l)
{
	int len;
	unsigned long long num;
	int i;
	char	*str;

	(void)l;
	num = va_arg(ap, unsigned long long);
	i = 0;
	len = 0;
	str = ft_itoa_base(num, 16);
	if (s->precision != -1 || s->zero != 0)
		str = iszero(str, s, i);
	str = ft_isp(str);
	len = ft_strlen(str);
	ft_strtolower(str);
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
	return ((s->length > len) ? s->length : len);
}
int		printf_dnumbers(va_list ap, t_option *s, t_size *l)
{
	int len;
	long long num;
	int i;
	char	*str;

	num = ft_parsel_size(ap, l) ;
	i = 0;
	len = 0;
	if (ft_is_negative(num) && (i = 1))
		num = absolute_value(num);
	else
		i = 2;
	str = ft_itoa_base(num, 10);
	if (s->precision != -1 || s->zero != 0)
		str = iszero(str, s, i);
	if (s->plus || i == 1 || s->space)
		str = isplus(str, &i, s);
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
	return ((s->length > len) ? s->length : len);
}


int		printf_unumbers(va_list ap, t_option *s, t_size *l)
{
	int len;
	long long num;
	int i;
	char	*str;

	num = ft_parseu_size(ap, l) ;
	i = 0;
	len = 0;
	str = ft_itoa_base(num, 10);
	if (s->precision != -1 || s->zero != 0)
		str = iszero(str, s, i);
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
	return ((s->length > len) ? s->length : len);
}

int		printf_Unumbers(va_list ap, t_option *s, t_size *l)
{
	int len;
	long long num;
	int i;
	char	*str;

	if (l->h)
		l->h = 0;
	num = ft_parseul_size(ap, l);
	i = 0;
	len = 0;
	str = ft_itoa_base(num, 10);
	if (s->precision != -1 || s->zero != 0)
		str = iszero(str, s, i);
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
	return ((s->length > len) ? s->length : len);
}

int		printf_HEX(va_list ap, t_option *s, t_size *l)
{
	int len;
	unsigned long long num;
	int i;
	char	*str;

	num = ft_parseu_size(ap, l) ;
	i = 0;
	len = 0;
	str = ft_itoa_base(num, 16);
	if (s->precision != -1 || s->zero != 0)
		str = iszero(str, s, i);
	if (s->hash)
		str = ft_ishash(str);
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
	return ((s->length > len) ? s->length : len);
}

int		printf_hex(va_list ap, t_option *s, t_size *l)
{
	int len;
	unsigned long long num;
	int i;
	char	*str;

	num = ft_parseu_size(ap, l) ;
	i = 0;
	len = 0;
	str = ft_itoa_base(num, 16);
	if (s->precision != -1 || s->zero != 0)
		str = iszero(str, s, i);
	if (s->hash)
		str = ft_ishash(str);
	len = ft_strlen(str);
	ft_strtolower(str);
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
	return ((s->length > len) ? s->length : len);
}
int		printf_OCT(va_list ap, t_option *s, t_size *l)
{
	int len;
	unsigned long long num;
	int i;
	char	*str;

	num = ft_parseul_size(ap, l) ;
	i = 0;
	len = 0;
	str = ft_itoa_base(num, 8);
	if (s->precision != -1 || s->zero != 0)
		str = iszero(str, s, i);
	if (s->hash)
		str = ft_ishasho(str);
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
	return ((s->length > len) ? s->length : len);
}

int		printf_oct(va_list ap, t_option *s, t_size *l)
{
	int len;
	unsigned long long num;
	int i;
	char	*str;

	num = ft_parse_size(ap, l) ;
	i = 0;
	len = 0;
	if (ft_is_negative(num) && (i = 1))
		num = absolute_value(num);
	else
		i = 2;
	str = ft_itoa_base(num, 8);
	if (s->precision != -1 || s->zero != 0)
		str = iszero(str, s, i);
	if (s->hash)
		str = ft_ishasho(str);
	len = ft_strlen(str);
	ft_strtolower(str);
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
	return ((s->length > len) ? s->length : len);
}
