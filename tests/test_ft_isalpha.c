/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:38:46 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/07 15:43:25 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_isalpha_2_false(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(_ft_isalpha('\n') == 0);
	assert(_ft_isalpha('\0') == 0);
	assert(_ft_isalpha('[') == 0);
	assert(_ft_isalpha('.') == 0);
}

void	test_ft_isalpha_1_true(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(_ft_isalpha('B') == 1);
	assert(_ft_isalpha('c') == 1);
	assert(_ft_isalpha('o') == 1);
	assert(_ft_isalpha('Z') == 1);
	assert(_ft_isalpha('a') == 1);
	assert(_ft_isalpha('z') == 1);
	assert(_ft_isalpha('K') == 1);
	assert(_ft_isalpha('n') == 1);

}
