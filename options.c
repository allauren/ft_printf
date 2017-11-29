/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:43:23 by allauren          #+#    #+#             */
/*   Updated: 2017/11/29 22:30:36 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		set_option(char *option, t_option *s)
{
	int i;

	i = 0;
	if (*option == '#' && (i = 1))
		s->hash = 1;
	else if (*option == ' ' && (i = 1))
		s->space = 1;
	else if (*option == '0' && (i = 1))
		s->zero = 1;
	else if (*option == '+' && (i = 1))
		s->plus = 1;
	else if (*option == '-' && (i = 1))
		s->moins = 1;
	return (i);
}

static int		set_taille(char *option, t_size *s)
{
	int i;

	i = 0;
	if (*option == 'h' && (i = 1))
		if (*(option + 1) == 'h' && (i = 2))
			s->h = i;
		else
			s->h = i;
	else if (*option == 'l' && (i = 1))
		if (*(option + 1) == 'l' && (i = 2))
			s->l = 2;
		else
			s->l = i;
	else if (*option == 'j' && (i = 1))
		s->j = 1;
	else if (*option == 'z' && (i = 1))
		s->z = 1;
	return (i);
}

int				ft_setoption(char *option, t_option *s, t_size *l)
{
	unsigned int i;

	i = 0;
	while (option[i])
	{
		while (option[i] && set_option(&option[i], s))
			i++;
		if (option[i] && ft_atoi(&option[i]))
			s->length = ft_atoi(&option[i]);
		while (option[i] && !set_taille(&option[i], l) && option[i] != '.')
			i++;
		if (option[i] == '.' && ((s->zero = 0) + 1))
			s->pre = ft_atoi(&option[++i]);
		while (option[i] && !set_taille(&option[i], l))
			i++;
		while (option[i] && set_taille(&option[i], l))
			i += set_taille(&option[i], l);
	}
	return (ft_strlen(option));
}
