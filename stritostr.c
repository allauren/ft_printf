/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stritostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:38:07 by allauren          #+#    #+#             */
/*   Updated: 2017/11/30 02:15:57 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_stritostr(const char *str1, const char *str2)
{
	int i;
	int j;

	i = 0;
	while (str1[i])
	{
		j = -1;
		while (str2[++j])
		{
			if (str1[i] == str2[j])
				return (i);
		}
		i++;
	}
	return (-1);
}

int					ft_sizenum(t_ull nb, int base)
{
	int		i;

	i = 0;
	while ((nb = nb / base))
		i++;
	i++;
	return (i);
}

unsigned long long	absolute_value(long long i)
{
	return ((~0 ^ (unsigned long long)i) + 1);
}

void				ft_strtolower(char *str)
{
	unsigned int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i])
			str[i] = ft_tolower(str[i]);
}
