/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:01:26 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 09:28:37 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_memset(void)
{
	char *destft;
	char *destmemset;
	int i;
	int size;
	char rchr;

	rchr = 0;
	size = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	i = 0;
	while (i < NTEST)
	{
		size = rand() % 1000;
		rchr = rand() % 240;
		if (size < 0)
			size = size * -1;
		if (rchr < 0)
			rchr = rchr * -1;
		if (!(destft = (char *)malloc(size)))
			return ;
		if (!(destmemset = (char *)malloc(size)))
			return ;
		memset(destmemset, rchr, size);
		ft_memset(destft, rchr, size);
		free(destmemset);
		free(destft);
		i++;
	}
}
