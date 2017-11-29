/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:17:38 by allauren          #+#    #+#             */
/*   Updated: 2017/11/29 22:30:46 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long	ft_is_negative(long long nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

char				*ft_isp(char *str)
{
	char	*new;

	if (!(new = ft_memalloc(ft_strlen(str) + 3)))
		exit(-1);
	new[0] = '0';
	new[1] = 'X';
	ft_strcat(new, str);
	free(str);
	return (new);
	return (str);
}

char	*isplus(char *str, int *nb, t_option *s)
{
	char	*new;

	if (!(new = ft_memalloc(ft_strlen(str) - s->zero + 1)))
		exit(-1);
	if (*nb == 1)
		new[0] = '-';
	else if (s->space)
		new[0] = ' ';
	else if ((*nb = 1))
		new[0] = '+';
	ft_strcat(new, str);
	free(str);
	return (new);
}

char	*ft_ishash(char *str)
{
	char	*new;

	if (ft_atoi_base(str, 16))
	{
		if (!(new = ft_memalloc(ft_strlen(str) + 3)))
			exit(-1);
		new[0] = '0';
		new[1] = 'X';
		ft_strcat(new, str);
		free(str);
		return (new);
	}
	return (str);
}

char	*ft_ishasho(char *str)
{
	char	*new;

	if (!(new = ft_memalloc(ft_strlen(str) + 2)))
		exit(-1);
	new[0] = '0';
	ft_strcat(new, str);
	free(str);
	return (new);
	return (str);
}
