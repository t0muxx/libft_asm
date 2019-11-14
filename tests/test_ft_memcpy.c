/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:43:36 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 10:35:14 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_memcpy(void)
{
	char *src;
	char *destft;
	char *destmemcpy;
	int i;
	int size;


	size = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	i = 0;
	while (i < NTEST)
	{
		size = rand() % 1000;
		if (size < 0)
			size = size * -1;
		if (!(destft = malloc(size)))
			return ;
		if (!(destmemcpy = malloc(size)))
			return ;
		memset(destft, 0, size);
		memset(destmemcpy, 0, size);
		src = random_junk(size);
		memcpy(destmemcpy, src, size);	
		memcpy(destft, src, size);	
		assert(memcmp(destft, destmemcpy, size) == 0);
		free(src);
		free(destmemcpy);
		free(destft);
		i++;
	}
}
