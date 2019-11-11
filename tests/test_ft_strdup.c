/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:43:36 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 07:47:02 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strdup_1(void)
{
	char s1[24];
	char *s2;
	char *s3;
	int i;

	printf(" [*] test on : %s\n", __FUNCTION__);
	i = 0;
	memset(s1, 0, 24);
	memcpy(s1, "1234567890qwertyu", 24);
	s2 = strdup(s1);
	s3 = ft_strdup(s1);
	assert(s2 != NULL);
	assert(s3 != NULL);
	while (i < 17)
	{
		assert(s2[i] == s3[i]);
		i++;
	}
	free(s2);
	free(s3);
}
