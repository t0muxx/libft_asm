/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:54:24 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/07 10:57:40 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_bzero_2_ok(void)
{
	char test[4];

	printf(" [*] test on : %s\n", __FUNCTION__);
	test[0] = 'A';
	test[1] = 'b';
	test[2] = 'c';
	_ft_bzero((void *)test, 2);
	assert(test[0] == 0);
	assert(test[1] == 0);
	assert(test[2] == 'c');
}

void	test_ft_bzero_1_ok(void)
{
	char test[4];

	printf(" [*] test on : %s\n", __FUNCTION__);
	test[0] = 'A';
	test[1] = 'b';
	test[2] = 'c';
	_ft_bzero((void *)test, 3);
	assert(test[0] == 0);
	assert(test[1] == 0);
	assert(test[2] == 0);
}
