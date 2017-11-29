/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcharc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 01:07:15 by allauren          #+#    #+#             */
/*   Updated: 2017/11/28 01:08:25 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <wchar.h>
#include "printf.h"
int pf_ft_putwchar_in_char(wchar_t wchar, char *fresh, int i)
{
	int				size;

	size = pf_ft_wcharlen(wchar);
	if (size == 1)
		fresh[i++] = wchar;
	else if (size == 2)
	{
		fresh[i++] = (wchar >> 6) + 0xC0;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		fresh[i++] = (wchar >> 12) + 0xE0;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		fresh[i++] = (wchar >> 18) + 0xF0;
		fresh[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	return (i);
}

/*
 * **Transforme les wchar en char
 * */

char	*pf_ft_transform_wchar_in_char(wchar_t *ws)
{
	char*fresh;
	inti;
	intk;
	intlen;

	if							 (!ws)
		return (0);
	i = 0;
	k = 0;
	len = pf_ft_wbytelen(ws);
	fresh = (char*)malloc(sizeof(char) * len);
	fresh[len] = '\0';
	while (ws[k])
	{
		i = pf_ft_putwchar_in_char(ws[k], fresh, i);
		k++;
	}
	return (fresh);
}
