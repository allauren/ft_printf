/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:32:27 by allauren          #+#    #+#             */
/*   Updated: 2017/11/30 15:12:27 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
int		main(void)
{
	setlocale(LC_ALL,"");
	wchar_t	s[4];

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2]= 0x81000;
	s[3] = '\0';
	int i = ft_printf(NULL);
	int j = 0;
	//int j = printf("%9.6ls %S", s, (wchar_t *)'a');
	printf("%d compare a la valeur %d", i, j);
	return 0;
}
/*ft_connect_stdout(pfd, &save_stdout);
 *	data.r1 = ft_printf("toto %##.0xet %#.X%###.1x", 0, 0, 0);
 into_all_04(void)
 ft_printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
 {
 data.r1 = ft_printf("%.x", 12);
 t_datadata;
 intpfd[2];
 intret							;
 intsave_stdout;
 test%#.4o et %02o %0#14.0o!!
 ft_connect_stdout(pfd, &save_stdout);
 data.r1 =		 ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
 data.s1 = ft_get_stdout(pfd, &save_stdout);
 ft_connect_stdout(pfd, &save_stdout);
 data.r2 = printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
 data.s2 = ft_get_stdout(pfd, &save_stdout);
 ret = 0;
 if (data.r1 != data.r2)
 ret = -1;
 if (ft_strcmp(data.s1, data.s2))
 ret = -1;
 ft_strdel(&data.s1);
 ft_strdel(&data.s2);
 return (ret);
 }*/
/*
   "%#X", 0xff7744)*
   static void test_chinese(t_test *test)
   {
// test->debug = 1;
assert_printf("%C", L'猫');
}

data.r1 = ft_printf("coco et %-#-#--24O titi%#012o", 12, -874);
data.s1 = ft_get_stdout(pfd, &save_stdout);
ft_connect_stdout(pfd, &save_stdout);
data.r2 = printf("coco et %-#-#--24O titi%#012o", 12, -874);
data.s2 = ft_get_stdout(pfd, &save_stdout);
ret = 0;
if (data.r1 != data.r2)
ret = -1;
if (ft_strcmp(data.s1, data.s2))
ret = -1;
ft_strdel(&data.s1);
ft_strdel(&data.s2);
return (ret);
static void test_greek(t_test *test)
{
// test->debug = 1;
assert_printf("%C", L'δ');
}


static void test_korean(t_test *test)
{
// test->debug = 1;
assert_printf("%C", L'요');
}

static void test_japanese(t_test *test)
{
// test->debug = 1;
assert_printf("%C", L'莨');
}

static void test_arabic(t_test *test)
{
// test->debug = 1;
assert_printf("%C", L'ي');
}

static void test_nullChar(t_test *test)
{
// test->debug = 1;
assert_printf("%C", 0);
}

*/
