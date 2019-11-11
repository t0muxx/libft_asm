/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:20:08 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 10:55:48 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strncmp_5(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	printf(" [*]strncmp segfault \n");
}

void	test_ft_strncmp_4(void)
{
	char str1[10];
	char str2[10];
	int  ret1;
	int	ret2;
	char *save;

	strcpy(str1, "");
	strcpy(str2, "");
	save = str2;
	printf(" [*] test on : %s\n", __FUNCTION__);
	ret1 = strncmp(str1, str2, 0);
	ret2 =  ft_strncmp(str1, str2, 0);
	printf("ret1 = %d\n", ret1);
	printf("ret1 = %d\n", ret2);
	assert(save == str2);
	assert(ret1 == ret2);
}

void	test_ft_strncmp_3(void)
{
	char str1[10];
	char str2[10];
	int  ret1;
	int	ret2;

	strcpy(str1, "testtest");
	strcpy(str2, "teoxtest");
	printf(" [*] test on : %s\n", __FUNCTION__);
	ret1 = strncmp(str1, str2, 2);
	ret2 =  ft_strncmp(str1, str2, 2);
	assert(ret1 == ret2);
	ret1 = strncmp(str1, str2, 10);
	ret2 =  ft_strncmp(str1, str2, 10);
	assert(ret1 == ret2);
}

void	test_ft_strncmp_2(void)
{
	char str1[10];
	char str2[10];
	int ret1;
	int ret2;

	ret1 = 0;
	ret2 = 0;
	strcpy(str1, "testtest");
	strcpy(str2, "testxf");
	printf(" [*] test on : %s\n", __FUNCTION__);
	ret1 = strncmp(str1, str2, 2);
	ret2 = ft_strncmp(str1, str2, 2);
	assert(ret1 == ret2);
	ret1 = strncmp(str1, str2, 8);
	ret2 = ft_strncmp(str1, str2, 8);
	assert(ret1 == ret2);
}

void	test_ft_strncmp_1(void)
{
	char str1[10];
	char str2[10];
	int	ret1;
	int ret2;

	strcpy(str1, "testtest");
	strcpy(str2, "testtest");
	printf(" [*] test on : %s\n", __FUNCTION__);
	ret1 = strncmp(str1, str2, 6);
	ret2 = ft_strncmp(str1, str2, 6);
	assert(ret1 == ret2);
}
