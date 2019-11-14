/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:54:24 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 08:19:57 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_bzero(void)
{
	char *test1;
	char *testbzero;
	char *rd;
	int i;
	int size;

	i = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	while (i < NTEST)
	{
		size = rand() % 1000;
	//	printf("size == %d\n", size);
		if (!(test1 = (char *)malloc(size + 1)))
			return ;
		if (!(testbzero = (char *)malloc(size + 1)))
			return ;
		memset(test1, 1, size);
		memset(testbzero, 1, size);
		rd = random_junk(size);
		memcpy(test1, rd, size);
		memcpy(testbzero, rd, size);
	//	printf("testing with value |%s|, |%d|\n", test1, size);
		ft_bzero(test1, size);
		bzero(testbzero, size);
		assert(memcmp(test1, testbzero, size) == 0);
		free(test1);
		free(testbzero);
		free(rd);
		i++;
	}
}
