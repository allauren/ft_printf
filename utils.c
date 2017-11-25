/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:19:47 by allauren          #+#    #+#             */
/*   Updated: 2017/11/25 18:38:08 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int		ft_sizenum(t_ull nb, int base)
{
	int		i;

	i = 0;
	while((nb = nb / base))
		i++;
	i++;
	return(i);
}

unsigned long long absolute_value(long long i)
{
	return ((~0 ^ (unsigned long long)i) + 1);
}

unsigned long long ft_is_negative(long long nb)
{
	if (nb < 0)
	{
		absolute_value(nb);
		return (1);
	}
	return(0);
}

char	*isplus(char *str, int *nb, t_option *s)
{
	char	*new;

	if(!(new = ft_memalloc(ft_strlen(str) - s->zero+ 1)))
		return (NULL);
	if(*nb == 1)
		new[0] = '-';
	else if(s->space)
		new[0] = ' ';
	else if((*nb = 1))
		new[0] = '+';
	ft_strcat(new, str);
	free(str);
	return (new);
}
/*char	*ft_nul(char *str, t_option *s)
  {
  char	*new;

  new = NULL;
  return(str);

  }*/

char	*iszero(char *str, t_option *s, int i)
{
	char	*new;
	int		len;

	len = 0;
	new = NULL;
	if(s->precision > (int)ft_strlen(str))
	{
		if(!(new = ft_memalloc(s->precision + 1)))
			return NULL;
		new[s->precision - (int)ft_strlen(str)] = '\0';
		ft_memset(new, '0', s->precision - (int)ft_strlen(str));
	}
	else if(s->precision == -1 && s->length > (int)ft_strlen(str))
	{
		if(!(new = ft_memalloc(s->length + 1 - s->plus)))
			return NULL;
		if(i != 1 || s->plus)
		len = s->length - s->plus - (int)ft_strlen(str);
		else
		len = s->length - s->plus - (int)ft_strlen(str) - i;
		new[len] = '\0';
		ft_memset(new, '0', len);
		if(s->space && !s->plus)
			new[0] = ' ';
	}
	if(new)
	{
		ft_strcat(new, str);
		free(str);
		return (new);
	}
	if(s->precision == 0 && ft_atoi(str) == 0)
	{
		return(new = ft_memalloc(1));
	}
	return(str);
}

