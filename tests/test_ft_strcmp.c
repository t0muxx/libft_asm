/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:20:08 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 08:10:13 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strcmp_5(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	printf(" [*]strcmp segfault \n");
}

void	test_ft_strcmp_4(void)
{
	char str1[10];
	char str2[10];
	int  ret1;
	int	ret2;

	strcpy(str1, "");
	strcpy(str2, "");
	printf(" [*] test on : %s\n", __FUNCTION__);
	ret1 = strcmp(str1, str2);
	ret2 =  ft_strcmp(str1, str2);
	assert(ret1 == ret2);
}

void	test_ft_strcmp_3(void)
{
	char str1[10];
	char str2[10];
	int  ret1;
	int	ret2;

	strcpy(str1, "testtest");
	strcpy(str2, "teoxtest");
	printf(" [*] test on : %s\n", __FUNCTION__);
	ret1 = strcmp(str1, str2);
	ret2 =  ft_strcmp(str1, str2);
	assert(ret1 == ret2);
}

void	test_ft_strcmp_2(void)
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
	ret1 = strcmp(str1, str2);
	ret2 = ft_strcmp(str1, str2);
	printf("strcmp : %d\n", ret1);
	printf("ft_strcmp : %d\n", ret2);
	printf("strcmp : %d\n", strcmp(str1, str2));
	printf("ft_strcmp : %d\n", ft_strcmp(str1, str2));
	assert(ret1 == ret2);
}

void	test_ft_strcmp_1(void)
{
	char str1[10];
	char str2[10];

	strcpy(str1, "testtest");
	strcpy(str2, "testtest");
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(strcmp(str1, str2) == ft_strcmp(str1, str2));
}
