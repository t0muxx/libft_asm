/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:20:08 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 09:22:34 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strlen(void)
{
	char *str;
	size_t retft;
	size_t retstrlen;
	int i;
	size_t size;
	
	size = 0;
	i = 0;
	retft = 0;
	retstrlen = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	while (i < NTEST)
	{
		size = rand() % 1000;
		str = random_str(size);
		printf("testing with |%s|\n", str);
		retft = ft_strlen(str);
		retstrlen = strlen(str);
		assert(retft == retstrlen);
		i++;
		free(str);
	}
}
