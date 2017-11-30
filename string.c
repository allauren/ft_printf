/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:42:50 by allauren          #+#    #+#             */
/*   Updated: 2017/11/30 02:13:25 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printf_to_limit(char *str, int i)
{
	write(1, str, i);
}

void	printf_carac(int len, char c)
{
	char *str;

	str = ft_strnew(len + 1);
	str[len] = '\0';
	ft_memset(str, c, len);
	write(1, str, len);
	free(str);
}
