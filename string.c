/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:42:50 by allauren          #+#    #+#             */
/*   Updated: 2017/11/29 06:35:28 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

void	ft_putwchar_fd(wchar_t chr, int fd)
{
	if (chr <= 0x7F)
		ft_putchar_fd(chr, fd);
	else if (chr <= 0x7FF)
	{
		ft_putchar_fd((chr >> 6) + 0xC0, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar_fd((chr >> 12) + 0xE0, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar_fd((chr >> 18) + 0xF0, fd);
		ft_putchar_fd(((chr >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
}
void	printf_to_limit(char *str , int i)
{
	write(1, str, i);
}

void	printfw_to_limit(wchar_t *str , int i)
{
	int j;

	j = -1;
	while(++j <= (i - 1))
		ft_putwchar_fd(str[j], 1);
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

char*	ft_NULL(char *str)
{
	char *new;

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
		str = ft_NULL(str);
	str = ft_strdup(str);
	if (s->precision != -1)
		len = (((int)ft_strlen(str)) < s->precision) ? ft_strlen(str) : s->precision;
	else
		len = ft_strlen(str);
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
	ft_memdel((void**)&str);
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
	if(s->zero != 0)
		str = iszero(str, s, 0, 10);
	len = ft_strlen(str);
	//	printf("\nje passe ici et je vaus %s et len est %d et la precision est de %d\n", str, len, s->precision);
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
	ft_memdel((void**)&str);
	return ((s->length > len) ? s->length : len);
}

int		printf_char(va_list ap, t_option *s, t_size *l)
{
	wchar_t		c;
	wchar_t		*str;
	int		len;

	(void)l;
	c = (char)va_arg(ap, int);
	if (!(str = ft_memalloc(2 * sizeof(wchar_t))))
		return (-1);
	str[0] = c;
	str[1] = '\0';
	if (!str)
		str = (wchar_t*)ft_NULL((char*)str);
	len = 1;
	//	printf("\nje passe ici et je vaus %s et len est %d et la precision est de %d\n", str, len, s->precision);
	if (s->moins)
	{
		printfw_to_limit(str, 1);
		if (s->length - len > 0)
			printf_carac((s->length - len), ' ');
	}
	else
	{
		if (s->length - len > 0)
			printf_carac((s->length - len), ' ');
		printfw_to_limit(str, 1);
	}
	ft_memdel((void**)&str);
	return ((s->length > len) ? s->length : len);
}
