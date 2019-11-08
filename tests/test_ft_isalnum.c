/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:38:46 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 08:29:56 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_isalnum_2_false(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(_ft_isalnum('\n') == isalnum('\n'));
	assert(_ft_isalnum('\0') == isalnum('\0'));
	assert(_ft_isalnum('[') == isalnum('['));
	assert(_ft_isalnum('.') == isalnum('.'));
}

void	test_ft_isalnum_1_true(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(_ft_isalnum('B') == 1);
	assert(_ft_isalnum('c') == 1);
	assert(_ft_isalnum('o') == 1);
	assert(_ft_isalnum('Z') == 1);
	assert(_ft_isalnum('a') == 1);
	assert(_ft_isalnum('z') == 1);
	assert(_ft_isalnum('K') == 1);
	assert(_ft_isalnum('0') == 1);
	assert(_ft_isalnum('2') == 1);
	assert(_ft_isalnum('6') == 1);
	assert(_ft_isalnum('9') == 1);

}
