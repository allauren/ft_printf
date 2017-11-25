/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 03:21:03 by allauren          #+#    #+#             */
/*   Updated: 2017/11/24 11:33:13 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft/libft.h"

static void	ft_recursive(char *str, unsigned long long jack,
			unsigned long long base, unsigned long long i)
{
	if (i >= base)
	{
		if ((jack / i) < 10)
			*str = jack / i + '0';
		else
			*str = jack / i - 10 + 'A';
		ft_recursive((str + 1), (jack % i), base, (i / base));
		return ;
	}
	if (jack / i < 10)
		*str = jack / i + '0';
	else
		*str = jack / i - 10 + 'A';
}

char		*ft_itoa_base(unsigned long long jack, int base)
{
	unsigned long long	i;
	unsigned long long	test;
	char				*str;
	unsigned long long	count;
	unsigned int		j;

	j = 0;
	i = 1;
	count = 0;
	test = jack;
	while ((test = test / base))
		count++;
	count++;
	while (j++ < (count - 1))
		i = i * base;
	if (base < 2 || !(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	if (jack == 0)
		str[0] = '0';
	else
		ft_recursive(str, jack, base, i);
	return (str);
}
