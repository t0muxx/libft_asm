/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:20:08 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 11:15:34 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strncmp(void)
{
	char *s1;
	char *s2;
	int i;
	int size;
	int size_2;
	int retft;
	int retstrncmp;

	printf(" [*] test on : %s\n", __FUNCTION__);
	s1 = strdup("12345678");
	s2 = strdup("12345678");
	retft = ft_strncmp(s1, s2, 2);
	retstrncmp = strncmp(s1, s2, 2);
	assert(retft == retstrncmp);
	i = 0;
	free(s1);
	free(s2);
	while (i < NTEST)
	{
		size = rand() % 1000;
		if (size < 0)
			size = size * -1;
		if (size != 0)
			size_2 = rand() % size;
		else
			size_2 = 0;
		if (size_2 < 0)
			size_2 = size_2 * -1;
		s1 = random_str(size);
		s2 = random_str(size);
		printf("testing with |%s| |%s| |%d|\n", s1, s2, size_2);
		retft = ft_strncmp(s1, s2, size_2);
		retstrncmp = strncmp(s1, s2, size_2);
		assert(retft == retstrncmp);
		i++;
		free(s1);
		free(s2);
	}
	s1 = strdup("123456789");
	s2 = strdup("123456");
	retft = ft_strncmp(s1, s2, 8);
	retstrncmp = strncmp(s1, s2, 8);
	assert(retft == retstrncmp);
	free(s1);
	free(s2);
}
