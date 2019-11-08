/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:38:46 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 10:26:29 by tmaraval         ###   ########.fr       */
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
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(ft_isdigit('0') == 1);
	assert(ft_isdigit('1') == 1);
	assert(ft_isdigit('2') == 1);
	assert(ft_isdigit('3') == 1);
	assert(ft_isdigit('4') == 1);
	assert(ft_isdigit('5') == 1);
	assert(ft_isdigit('6') == 1);
	assert(ft_isdigit('7') == 1);
	assert(ft_isdigit('8') == 1);
	assert(ft_isdigit('9') == 1);

}
