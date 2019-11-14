/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:20:08 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 10:47:18 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strcmp(void)
{
	char *s1;
	char *s2;
	int i;
	int size;
	int retft;
	int retstrcmp;

	printf(" [*] test on : %s\n", __FUNCTION__);
	s1 = strdup("12345678");
	s2 = strdup("12345678");
	retft = ft_strcmp(s1, s2);
	retstrcmp = strcmp(s1, s2);
	assert(retft == retstrcmp);
	i = 0;
	free(s1);
	free(s2);
	while (i < NTEST)
	{
		size = rand() % 1000;
		if (size < 0)
			size = size * -1;
		s1 = random_str(size);
		s2 = random_str(size);
		retft = ft_strcmp(s1, s2);
		retstrcmp = strcmp(s1, s2);
		assert(retft == retstrcmp);
		i++;
		free(s1);
		free(s2);
	}
	s1 = strdup("");
	s2 = strdup("");
	retft = ft_strcmp(s1, s2);
	retstrcmp = strcmp(s1, s2);
	assert(retft == retstrcmp);
	free(s1);
	free(s2);
}
