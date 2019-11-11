/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:54:24 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 10:10:27 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_bzero_4_len_inf(void)
{
	char test[4];

	printf(" [*] test on : %s\n", __FUNCTION__);
	test[0] = 'A';
	test[1] = 'b';
	test[2] = 'c';
	ft_bzero((void *)test, -1);
	assert(test[0] == 'A');
	assert(test[1] == 'b');
	assert(test[2] == 'c');
}

void	test_ft_bzero_3_len_0(void)
{
	char test1[4];
	char test2[4];
	int i;

	i = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	strcpy(test1, "AbC");
	strcpy(test2, "AbC");
	ft_bzero((void *)test1, 0);
	bzero((void *)test2, 0);
	while (i < 4)
	{
		assert(test1[i] == test2[i]);
		i++;
	}
}

void	test_ft_bzero_2_ok(void)
{
	char test1[4];
	char test2[4];
	int i;

	i = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	strcpy(test1, "AbC");
	strcpy(test2, "AbC");
	ft_bzero((void *)test1 + 1, 2);
	bzero((void *)test2 + 1, 2);
	while (i < 4)
	{
		assert(test1[i] == test2[i]);
		i++;
	}
}

void	test_ft_bzero_1_ok(void)
{
	char test1[4];
	char test2[4];
	int i;

	i = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	strcpy(test1, "AbC");
	strcpy(test2, "AbC");
	ft_bzero((void *)test1, ft_strlen(test1));
	bzero((void *)test2, strlen(test2));
	while (i < 4)
	{
		assert(test1[i] == test2[i]);
		i++;
	}
}
