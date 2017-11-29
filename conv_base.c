/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 21:36:31 by allauren          #+#    #+#             */
/*   Updated: 2017/11/29 22:31:55 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		printf_hexm(va_list ap, t_option *s, t_size *l)
{
	int					len;
	unsigned long long	num;
	char				*str;

	num = ft_parseu_size(ap, l);
	len = 0;
	str = ft_itoa_base(num, 16);
	if (s->pre != -1 || s->zero != 0)
		str = iszeroh(str, s, 0, 16);
	if (s->hash)
		str = ft_ishash(str);
	len = ft_strlen(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		printf_hex(va_list ap, t_option *s, t_size *l)
{
	int					len;
	unsigned long long	num;
	char				*str;

	num = ft_parseu_size(ap, l);
	len = 0;
	str = ft_itoa_base(num, 16);
	if (s->pre != -1 || s->zero != 0)
		str = iszeroh(str, s, 0, 16);
	if (str && s->hash)
		str = ft_ishash(str);
	len = ft_strlen(str);
	ft_strtolower(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		printf_octm(va_list ap, t_option *s, t_size *l)
{
	int					len;
	unsigned long long	num;
	char				*str;

	num = ft_parseul_size(ap, l);
	len = 0;
	str = ft_itoa_base(num, 8);
	if (s->pre > 0 || (s->pre != -1 && !s->hash) || s->zero != 0)
		str = iszeroo(str, s, 0);
	if (s->hash && ft_atoi(str))
		str = ft_ishasho(str);
	len = ft_strlen(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		printf_oct(va_list ap, t_option *s, t_size *l)
{
	int					len;
	unsigned long long	num;
	char				*str;

	num = ft_parseu_size(ap, l);
	len = 0;
	str = ft_itoa_base(num, 8);
	if (s->pre > 0 || (s->pre != -1 && !s->hash) || s->zero != 0)
		str = iszeroo(str, s, 0);
	if (s->hash && ft_atoi(str))
		str = ft_ishasho(str);
	len = ft_strlen(str);
	ft_strtolower(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		printf_p(va_list ap, t_option *s, t_size *l)
{
	int					len;
	unsigned long long	num;
	char				*str;

	(void)l;
	num = va_arg(ap, unsigned long long);
	len = 0;
	str = ft_itoa_base(num, 16);
	if (s->pre != -1 || s->zero != 0)
		str = iszero(str, s, 0, 16);
	str = ft_isp(str);
	len = ft_strlen(str);
	ft_strtolower(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}
