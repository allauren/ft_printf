/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:46:04 by allauren          #+#    #+#             */
/*   Updated: 2017/11/25 18:51:34 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int		ft_printf(const char* format, ...)
{
	int		i;
	int		j;
	int		ret;
	va_list				ap;

	i = 0;
	j = 0;
	ret = 0;
	va_start(ap, format);
	while(format[i])
	{
		if(format[i] == '%')
		{
			if (j - i++ != 0)
			{
			printf_to_limit((char*)&format[j], (i - j) - 1);
			ret += (i - j - 1);
			}
			i += ft_parse(&format[i], ap, &ret);
			j = i;
		}
		else
			i++;
	}
	if(format[j])
	{
	ret += (i - j);
	ft_putstr(&format[j]);
	}
	//printf("\n%d la valeur de sortie est\n", ret);
	va_end(ap);
	return(ret);
}



/*
int main(void)
{
	int i = 0;
	//ft_printf("%d et le string est %s", 2147483648,"les oiseaux");
	//i = printf("%d et le string est %s",-2147483648, "les oiseaux");
	printf("\n%d alors que la vraie est\n", i);
	return 0;
}
*/
