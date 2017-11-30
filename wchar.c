/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 00:12:55 by allauren          #+#    #+#             */
/*   Updated: 2017/11/30 14:31:53 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int		wcharlen(unsigned int c)
{
	if(c <= 0x7f)
		return (1);
	if(c <= 0x7ff)
		return (2);
	if(c <= 0xffff)
		return (3);
	else
		return (4);
}

char		*fill_tab(char	*str, wint_t c)
{
	if(!(str = ft_memalloc(sizeof(char) * 5)))
		exit(-1);
	str[wcharlen(c)] = '\0';
	if(c <= 0x7f)
	{
		str[0] = c;
	}
	else if(c <= 0x7ff)
	{
		str[0] = 0b11000000 | ((c >> 6) & 0b00011111);
		str[1] = 0b10000000 | (c & 0b00111111);
	}
	else if(c <= 0xffff)
	{
		str[0] = 0b11100000 | ((c >> 12) & 0b00001111);
		str[1] = 0b10000000 | ((c >> 6) & 0b00111111);
		str[2] = 0b10000000 | (c & 0b00111111);
	}
	else
	{
		str[0] = 0b11110000 | ((c >> 18) & 0b00000111);
		str[1] = 0b10000000 | ((c >> 12) & 0b00111111);
		str[2] = 0b10000000 | ((c >> 6) & 0b00111111);
		str[3] = 0b10000000 | (c & 0b00111111);
	}
	return (str);
}
/*
 ** does the comparison on the fitting byte to calcul unicode
 */
int		ft_is_valid(wchar_t c)
{
	if ((MB_CUR_MAX == 1 && c > 127) || (MB_CUR_MAX == 2 && c > 2047)
			|| (MB_CUR_MAX == 3 && c > 65535) || (MB_CUR_MAX == 4 && c > 2097151) ||
			c > 0x10fff)
		return (0);
	return (1);
}

int		printf_wchar(va_list ap, t_option *s, t_size *l)
{
	wchar_t		c;
	char		*str;
	int			len;

	(void)l;
	c = va_arg(ap, wchar_t);
	str = fill_tab(NULL, c);
	if (!str)
		str = ft_null(str);
	len = wcharlen(c);
	if(!ft_is_valid(c))
		return(-1);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}
int		ft_wstrlen(wchar_t *str)
{
	int		j;
	int		i;
	int		len;

	j = 0;
	i = -1;
	while(str[++i])
	{
		j += (len = wcharlen(str[i]));
		if(!ft_is_valid(str[i]))
			return(-1);
	}
	return(j);
}

int		ft_lenwstr(wchar_t *ptr, char *str, t_option *s)
{
	int		i;
	int		j;
	int		z;
	int		ret;

	i = 0;
	j = 0;
	z = 0;
	ret = 0;
	while(s->pre != -1 && s->pre < (int)ft_strlen(str) && str[i])
	{
		j += wcharlen(ptr[z]);
		while(i < j && i < s->pre && str[i])
			i++;
		if(i == j)
			ret = i;
		if (i == s->pre || !str[i])
			return(ret);
		z++;
	}
	return (ft_strlen(str));
}




int		printf_wstr(va_list ap, t_option *s, t_size *l)
{
	wchar_t		*ptr;
	char		*str;
	int			len;
	int			i;

	(void)l;
	i = -1;
	if(!(ptr = va_arg(ap, wchar_t*)))
		ptr = L"(null)";
	if((len = ft_wstrlen(ptr)) == -1)
		return(-1);
	if (!(str = ft_memalloc(sizeof(char) * (len + 1))))
		exit(-1);
	while(ptr[++i])
	{
		char *prov = fill_tab(NULL, ptr[i]);
		ft_strcat(str, prov);
		free(prov);
	}
	len = ft_lenwstr(ptr, str, s);
	print_padding(s, str, len);
	return ((s->length > len) ? s->length : len);
}
