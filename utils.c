/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:19:47 by allauren          #+#    #+#             */
/*   Updated: 2017/11/29 22:30:04 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*set_zero(t_option *s, char *str, int len, int i)
{
	char	*new;

	if (!(new = ft_memalloc(s->length + 2 - s->plus)))
		exit(-1);
	if (i != 1 || s->plus || (s->hash && ft_atoi_base(str, 16)))
		len = s->length - s->plus - (int)ft_strlen(str);
	else
		len = s->length - s->plus - (int)ft_strlen(str) - i;
	new[len] = '\0';
	ft_memset(new, '0', len);
	if (s->space && !s->plus)
	{
		new[0] = ' ';
		s->space = 0;
	}
	return (new);
}

char	*iszero(char *str, t_option *s, int i, int base)
{
	char	*new;
	int		len;

	len = 0;
	new = NULL;
	if (s->pre > (int)ft_strlen(str))
	{
		if (!(new = ft_memalloc(s->pre + 1)))
			exit(-1);
		new[s->pre - (int)ft_strlen(str)] = '\0';
		ft_memset(new, '0', s->pre - (int)ft_strlen(str));
	}
	else if (s->pre == -1 && s->length > (int)ft_strlen(str))
		new = set_zero(s, str, len, i);
	if (new)
	{
		ft_strcat(new, str);
		ft_memdel((void**)&str);
		return (new);
	}
	if (s->pre == 0 && ft_atoi_base(str, base) == 0)
	{
		return (new = ft_memalloc(1));
	}
	return (str);
}
