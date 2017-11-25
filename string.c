/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:42:50 by allauren          #+#    #+#             */
/*   Updated: 2017/11/24 23:50:52 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

void	printf_to_limit(char *str , int i)
{
	write(1, str, i);
}

void printf_carac(int len, char c)
{
	char *str;

	str = ft_strnew(len + 1);
	str[len] = '\0';
	ft_memset(str, c, len);
	write(1, str, len);
	free(str);
}

int		printf_string(va_list ap, t_option *s, t_size *l)
{
	char	*str;
	int		len;

	(void)l;
	str = va_arg(ap, char*);
	if (s->precision != -1)
		len = (((int)ft_strlen(str)) < s->precision) ? ft_strlen(str) : s->precision;
	else
		len = ft_strlen(str);
	//printf("\nje passe ici et je vaus %s et len est %d et la precision est de %d\n", str, len, s->precision);
	if (s->moins)
	{
		printf_to_limit(str, len);
		if (s->length - len > 0)
			printf_carac((s->length - len), ' ');
	}
	else
	{
		if (s->length - len > 0)
			printf_carac((s->length - len), ' ');
		printf_to_limit(str, len);
	}
	return((s->length > len) ? s->length : len);
}
