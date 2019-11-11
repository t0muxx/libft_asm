/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:38:46 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 10:18:20 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_isdigit_2_false(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(ft_isdigit('\n') == isdigit('\n'));
	assert(ft_isdigit('\0') == isdigit('\0'));
	assert(ft_isdigit('[') == isdigit('['));
	assert(ft_isdigit('.') == isdigit('.'));
	assert(ft_isdigit('a') == isdigit('a'));
	assert(ft_isdigit('Z') == isdigit('Z'));
}

void	test_ft_isdigit_1_true(void)
{
	int i;

	i = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	while (i < 255)
	{
		if (isdigit(i) != 0)
			assert(ft_isdigit(i) != 0);
		else
			assert(ft_isdigit(i) == 0);
		i++;
	}
}
