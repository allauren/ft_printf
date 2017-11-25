/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:10:47 by allauren          #+#    #+#             */
/*   Updated: 2017/11/25 04:49:49 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
t_convert	set_struct	(char c, int (*f)(va_list ap, t_option *s, t_size *l))
{
	t_convert s;
	s.c = c;
	s.f = f;
	return (s);
}

int		set_function(va_list ap, char c, t_option *s, t_size *l,int *ret)
{
	t_convert	tab[14];
	int			i;

	i = 0;
	tab[0] = set_struct('s' , printf_string);
	tab[1] = set_struct('d' , printf_numbers);
	tab[2] = set_struct('s' , printf_string);
	tab[3] = set_struct('s' , printf_string);
	tab[4] = set_struct('s' , printf_string);
	tab[5] = set_struct('s' , printf_string);
	tab[6] = set_struct('s' , printf_string);
	tab[7] = set_struct('s' , printf_string);
	tab[8] = set_struct('s' , printf_string);
	tab[9] = set_struct('s' , printf_string);
	tab[10] = set_struct('s' , printf_string);
	tab[11] = set_struct('s' , printf_string);
	tab[12] = set_struct('s' , printf_string);
	tab[13] = set_struct('\0' , NULL);
	while(tab[i].c != c)
		i++;
	*ret += tab[i].f(ap, s, l);
	return(1);

}

int		ft_parse(const char* format, va_list ap, int *ret)
{
	int		i = 0;
	char			*option;
	int				len;
	t_option		s;
	t_size			l;


	(void)ap;
	ft_bzero(&s, sizeof(t_option));
	ft_bzero(&l, sizeof(t_size));
	s.precision = -1;
	len = ft_stritostr(format, TYPE);
	option = ft_strsub(&format[i], i, len); 
	i += ft_setoption(option, &s , &l);
	set_function(ap, format[len], &s, &l, ret);
	free(option);
//	printf("\nhash ==>^%d^\nplus ==>^%d^\nmoins ==>^%d^\nspace ==>^%d^\nzero ==>^%d^\nquote ==>^%d^\nlenght ==>^%d^\n",s.hash,s.plus,s.moins,s.space,s.zero,s.quote,s.length);
//	printf("la precision est ^%d^\n", s.precision);
	return(i + 1);
}
