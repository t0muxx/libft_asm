/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:01:26 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 14:31:23 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_memset_len_0(void)
{
	char s1[50];
	char s2[50];
	int i;

	printf(" [*] test on : %s\n", __FUNCTION__);
	i = 0;
	memset(s1, 0, 50);
	memset(s2, 0, 50);
	assert(ft_memset(s1, 1, 0) == s1);
	while (i < 50)
	{
		assert(s1[i] == s2[i]);
		i++;
	}
}

void	test_ft_memset_2(void)
{
	char s1[50];
	char s2[50];
	int i;

	printf(" [*] test on : %s\n", __FUNCTION__);
	i = 0;
	memset(s1, 0, 50);
	memset(s2, 0, 50);
	assert(ft_memset(s1, 257, 30) == s1);
	assert(memset(s2, 257, 30) == s2);
	while (i < 30)
	{
		assert(s1[i] == s2[i]);
		i++;
	}
	while (i < 50)
	{
		assert(s1[i] == s2[i]);
		i++;
	}
}


void	test_ft_memset_1(void)
{
	char s1[50];
	char s2[50];
	int i;

	printf(" [*] test on : %s\n", __FUNCTION__);
	i = 0;
	memset(s1, 0, 50);
	memset(s2, 0, 50);
	assert(ft_memset(s1, 1, 50) == s1);
	assert(memset(s2, 1, 50) == s2);
	while (i < 50)
	{
		assert(s1[i] == s2[i]);
		i++;
	}
}
