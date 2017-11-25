/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stritostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:38:07 by allauren          #+#    #+#             */
/*   Updated: 2017/11/23 16:46:47 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_stritostr(const char *str1, const char *str2)
{
	int i;
	int j;

	i = 0;
	while (str1[i])
	{
	j = -1;
		while(str2[++j])
		{
			if (str1[i] == str2[j])
				return (i);
		}
			i++;
	}
	return (0);
}

