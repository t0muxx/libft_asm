/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:38:46 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 10:15:48 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_isalnum_2_false(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(ft_isalnum('\n') == isalnum('\n'));
	assert(ft_isalnum('\0') == isalnum('\0'));
	assert(ft_isalnum('[') == isalnum('['));
	assert(ft_isalnum('.') == isalnum('.'));
}

void	test_ft_isalnum_1_true(void)
{
	int i;

	i = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	while (i < 255)
	{
		if (isalnum(i) != 0)
			assert(ft_isalnum(i) != 0);
		else
			assert(ft_isalnum(i) == 0);
		i++;
	}
}
