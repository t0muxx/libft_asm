/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:43:36 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 14:45:54 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_memcpy_1(void)
{
	char s1[50];
	char s2[50];
	int i;

	printf(" [*] test on : %s\n", __FUNCTION__);
	i = 0;
	memset(s1, 0, 50);
	memset(s2, 0, 50);
	assert(ft_memcpy(s1, "abcdefg", 7) == s1);
	assert(memcpy(s2, "abcdefg", 7) == s2);
	while (i < 50)
	{
		assert(s1[i] == s2[i]);
		i++;
	}
}