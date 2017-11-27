/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:32:27 by allauren          #+#    #+#             */
/*   Updated: 2017/11/27 22:24:57 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "printf.h"
int		ft_printf(const char* format, ...);

int main(void)
{
	int i = 0;
	int j = 0;

	j = ft_printf("% Zooo");
	printf("\n");
	i = printf("% Zooo");
	printf("\n%d alors que la vraie est %d\n",j,  i);
	return 0;
}

