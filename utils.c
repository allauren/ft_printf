/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:19:47 by allauren          #+#    #+#             */
/*   Updated: 2017/11/29 07:04:26 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_sizenum(t_ull nb, int base)
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
		exit (-1);
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
		exit (-1);
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
			exit (-1);
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
			exit (-1);
		new[0] = '0';
		ft_strcat(new, str);
		free(str);
		return (new);
	return (str);
}

void	ft_strtolower(char *str)
{
	unsigned int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i])
			str[i] = ft_tolower(str[i]);
}
char	*set_zero(t_option *s, char *str, int len, int i)
{
	char	*new;

	if (!(new = ft_memalloc(s->length + 2 - s->plus)))
		exit (-1);
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
	if (s->precision > (int)ft_strlen(str))
	{
		if (!(new = ft_memalloc(s->precision + 1)))
			exit (-1);
		new[s->precision - (int)ft_strlen(str)] = '\0';
		ft_memset(new, '0', s->precision - (int)ft_strlen(str));
	}
	else if (s->precision == -1 && s->length > (int)ft_strlen(str))
		new = set_zero(s, str, len, i);
	if (new)
	{
		ft_strcat(new, str);
		ft_memdel((void**)&str);
		return (new);
	}
	if (s->precision == 0 && ft_atoi_base(str, base) == 0)
	{
		return (new = ft_memalloc(1));
	}
	return (str);
}


char	*set_zeroh(t_option *s, char *str, int len, int i)
{
	char	*new;

	if (!(new = ft_memalloc(s->length + 5 - s->plus)))
		exit (-1);
	if (i != 0 || s->plus || (s->hash && ft_atoi_base(str, 16)))
		len = s->length - s->plus - (int)ft_strlen(str) - s->hash * 2;
	else
		len = s->length - s->plus - (int)ft_strlen(str) - i;
//	printf("len vaut %d %d %d %s\n", ft_atoi_base(str, 16),i,s->plus, str);
	new[len] = '\0';
	ft_memset(new, '0', len);
	if (s->space && !s->plus)
	{
		new[0] = ' ';
		s->space = 0;
	}
	return (new);
}

char	*iszeroh(char *str, t_option *s, int i, int base)
{
	char	*new;
	int		len;

	len = 0;
	new = NULL;
	if (s->precision > (int)ft_strlen(str))
	{
		if (!(new = ft_memalloc(s->precision + 5)))
			exit (-1);
		new[s->precision - (int)ft_strlen(str)] = '\0';
		ft_memset(new, '0', s->precision - (int)ft_strlen(str));
	}
	else if (s->precision == -1 && s->length > (int)ft_strlen(str))
		new = set_zeroh(s, str, len, i);
	if (new)
	{
		ft_strcat(new, str);
		ft_memdel((void**)&str);
		return (new);
	}
	if (s->precision == 0 && ft_atoi_base(str, base) == 0)
	{
		if(!(new = ft_memalloc(sizeof(char) * 1)))
			exit (-1);
		free(str);
		return (new);
	}
	return (str);
}

char	*set_zeroo(t_option *s, char *str, int len, int i)
{
	char	*new;

	if (!(new = ft_memalloc(s->length + 1 - s->plus)))
		exit (-1);
	if (i != 1 || s->plus || s->hash)
	len = s->length - s->plus - (int)ft_strlen(str) - s->hash;
	else
		len = s->length - s->plus - (int)ft_strlen(str) - i;
	new[len] = '\0';
	ft_memset(new, '0', len);
	if (s->space && !s->plus)
	{
		new[0] = ' ';
		s->space = 0;
	}
	if(len)
		s->hash = 0;
	return (new);
}

char	*iszeroo(char *str, t_option *s, int i)
{
	char	*new;
	int		len;

	len = 0;
	new = NULL;
	if (s->precision > (int)ft_strlen(str))
	{
		if (!(new = ft_memalloc(s->precision + 1)))
			exit (-1);
		new[s->precision - (int)ft_strlen(str)] = '\0';
		ft_memset(new, '0', s->precision - (int)ft_strlen(str));
		s->hash = 0;
	}
	else if (s->precision == -1 && s->length > (int)ft_strlen(str))
		new = set_zeroo(s, str, len, i);
	if (new)
	{
		ft_strcat(new, str);
		ft_memdel((void**)&str);
		return (new);
	}
	if (s->precision == 0 && ft_atoi(str) == 0)
	{
		return (new = ft_memalloc(1));
	}
	return (str);
}
