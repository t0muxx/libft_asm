/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:03 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 09:15:37 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strcat(void)
{
	char *src;
	char *destft;
	char *destcat;
	char *rd;
	int i;
	int size;

	i = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	while (i < NTEST)
	{
		size = rand() % 800;
		if (size < 0)
			size = size * -1;
		src = random_str(size);
		rd = random_str(size / 2);
		if (!(destft = (char *)malloc(size + (size / 2) + 1)))
			return ;
		if (!(destcat = (char *)malloc(size + (size / 2) + 1)))
			return ;
		memset(destft, 0, size + (size / 2) + 1);
		memset(destcat, 0, size + (size / 2) + 1);
		memcpy(destft, rd, size/2);
		memcpy(destcat, rd, size/2);
		assert(memcmp(destft, destcat, size/2) == 0);
		printf("testing with |%s| |%s|\n", rd, src);
		ft_strcat(destft, src);
		strcat(destcat, src);
		assert(memcmp(destft, destcat, size + (size / 2) + 1) == 0);
		free(rd);
		free(destft);
		free(destcat);
		free(src);
		i++;
	}
}
