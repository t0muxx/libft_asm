/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:38:46 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 10:16:44 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_isalpha_2_false(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(ft_isalpha('\n') == isalpha('\n'));
	assert(ft_isalpha('\0') == isalpha('\0'));
	assert(ft_isalpha('[') == isalpha('['));
	assert(ft_isalpha('.') == isalpha('.'));
}

void	test_ft_isalpha_1_true(void)
{
	int i;

	i = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	while (i < 255)
	{
		if (isalpha(i) != 0)
			assert(ft_isalpha(i) != 0);
		else
			assert(ft_isalpha(i) == 0);
		i++;
	}
}
