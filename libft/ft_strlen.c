/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 00:59:38 by allauren          #+#    #+#             */
/*   Updated: 2017/11/26 01:02:05 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
