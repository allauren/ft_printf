/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:26:21 by allauren          #+#    #+#             */
/*   Updated: 2017/11/29 22:33:37 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_null(char *str)
{
	char	*new;

	if (!(new = ft_memalloc(6)))
		return (NULL);
	new[0] = '(';
	new[1] = 'n';
	new[2] = 'u';
	new[3] = 'l';
	new[4] = 'l';
	new[5] = ')';
	new[6] = '\0';
	free(str);
	return (new);
}

int		printf_string(va_list ap, t_option *s, t_size *l)
{
	char	*str;
	int		len;

	(void)l;
	str = va_arg(ap, char*);
	if (!str)
		str = ft_null(str);
	str = ft_strdup(str);
	if (s->pre != -1)
		len = (((int)ft_strlen(str)) < s->pre) ? ft_strlen(str) : s->pre;
	else
		len = ft_strlen(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		printf_pourcent(va_list ap, t_option *s, t_size *l)
{
	char	*str;
	int		len;

	(void)l;
	(void)ap;
	if (!(str = ft_memalloc(sizeof(char) * 2)))
		exit(-1);
	str[0] = '%';
	str[1] = '\0';
	if (s->zero != 0)
		str = iszero(str, s, 0, 10);
	len = ft_strlen(str);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}

int		printf_char(va_list ap, t_option *s, t_size *l)
{
	wchar_t		c;
	wchar_t		*str;
	int			len;

	(void)l;
	c = (char)va_arg(ap, int);
	if (!(str = ft_memalloc(2 * sizeof(wchar_t))))
		return (-1);
	str[0] = c;
	str[1] = '\0';
	if (!str)
		str = (wchar_t*)ft_null((char*)str);
	len = 1;
	print_padding(s, (char*)str, len);
	return ((s->length > len) ? s->length : len);
}
