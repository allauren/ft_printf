/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:46:04 by allauren          #+#    #+#             */
/*   Updated: 2017/11/25 05:24:58 by allauren         ###   ########.fr       */
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
	while(format[++i])
	{
		if(format[i] == '%')
		{	
			printf_to_limit((char*)&format[j], (i - j));
			ret += (i - j);
			i++;
			i += ft_parse(&format[i], ap, &ret);
			j = i;
		}
	}
	ret += (i - j);
	ft_putstr(&format[j]);
//	printf("%d la valeur de sortie est\n", ret);
	va_end(ap);
	return(ret);
}



/*
int main(void)
{
	int i = 0;
	ft_printf("je suis la %+.0d#  je suis ici %-100s# \n",9 , "et je danse le mia");
	i = printf("je suis la %+.0d#  je suis ici %-100s# \n",9 , "et je danse le mia");
	printf("\n%d alors que la vraie est", i);
	return 0;
}*/
