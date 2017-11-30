/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:26:21 by allauren          #+#    #+#             */
/*   Updated: 2017/11/30 15:08:00 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_null()
{
	char	*new;

	if (!(new = ft_memalloc(sizeof(char) * 7)))
		return (NULL);
	new[0] = '(';
	new[1] = 'n';
	new[2] = 'u';
	new[3] = 'l';
	new[4] = 'l';
	new[5] = ')';
	new[6] = '\0';
	return (new);
}

int		printf_string(va_list ap, t_option *s, t_size *l)
{
	char	*str;
	int		len;
	char	*ptr;

	if (l->l)
		return (printf_wstr(ap, s, l));
	ptr = va_arg(ap, char*);
	if (!ptr)
		str = ft_null();
	else
		str = ft_strdup(ptr);
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
	char		c;
	char		*str;
	int			len;

	if (l->l)
		return(printf_wchar(ap, s, l));
	c = (char)va_arg(ap, unsigned int);
	if (!(str = ft_memalloc(2 * sizeof(wchar_t))))
		return (-1);
	str[0] = c;
	str[1] = '\0';
	if (!str)
		str = ft_null();
	if (s->zero != 0)
		str = iszero(str, s, 0, 10);
	len = 1;
	print_padding(s, (char*)str, len);
	return ((s->length > len) ? s->length : len);
}
