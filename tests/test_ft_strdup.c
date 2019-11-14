/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:43:36 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 10:41:58 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strdup(void)
{
	char *src;
	char *destft;
	char *deststrdup;
	int i;
	int size;

	printf(" [*] test on : %s\n", __FUNCTION__);
	i = 0;
	while (i < NTEST)
	{
		size = rand() % 1000;
		if (size < 0)
			size = size * -1;
		src = random_str(size);
		destft = ft_strdup(src);
		deststrdup = strdup(src);
		assert(strcmp(destft, deststrdup) == 0);
		free(src);
		free(deststrdup);
		free(destft);
		i++;
	}
	destft = ft_strdup("");
	deststrdup = strdup("");
	assert(strcmp(destft, deststrdup) == 0);
}
