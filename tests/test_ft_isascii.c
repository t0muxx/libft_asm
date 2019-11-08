/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:38:46 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 08:45:13 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_isascii_2_false(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(_ft_isascii(-1) == isascii(-1));
	assert(_ft_isascii(128) == isascii(128));
	assert(_ft_isascii(-4) == isascii(-4));
	assert(_ft_isascii(200) == isascii(200));
}

void	test_ft_isascii_1_true(void)
{
	int i;

	i = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	while (i < 127)
	{
		assert(_ft_isascii(i) == 1);
		i++;
	}
}
