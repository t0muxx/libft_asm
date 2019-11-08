/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:20:08 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 13:42:34 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strlen_3_null(void)
{

	printf(" [*] test on : %s\n", __FUNCTION__);
	printf(" [*] strlen segfault so no need to test\n");

}

void	test_ft_strlen_2_empty(void)
{
	char str[10];

	strcpy(str, "");
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(strlen(str) == ft_strlen(str));

}

void	test_ft_strlen_1(void)
{
	char str[10];

	strcpy(str, "testtest");
	printf(" [*] test on : %s\n", __FUNCTION__);
	assert(strlen(str) == ft_strlen(str));

}
