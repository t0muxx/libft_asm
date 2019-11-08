/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:38:46 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 10:25:55 by tmaraval         ###   ########.fr       */
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
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(ft_isalnum('B') == 1);
	assert(ft_isalnum('c') == 1);
	assert(ft_isalnum('o') == 1);
	assert(ft_isalnum('Z') == 1);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('z') == 1);
	assert(ft_isalnum('K') == 1);
	assert(ft_isalnum('0') == 1);
	assert(ft_isalnum('2') == 1);
	assert(ft_isalnum('6') == 1);
	assert(ft_isalnum('9') == 1);

}
