/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strsub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:10:25 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 17:11:14 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strsub_1(void)
{
	char *str = "test_other_1234567";
	char *ret;

	printf(" [*] test on : %s\n", __FUNCTION__);
	ret = ft_strsub(str, 4, 14);
	printf("ret ===> |%s|\n", ret);
	assert(strcmp(ret, "_other_1234567") == 0);
	free(ret);
	ret = ft_strsub(str, 0, 4);
	printf("ret ===> |%s|\n", ret);
	assert(strcmp(ret, "test") == 0);
	free(ret);
	ret = ft_strsub(str, 0, 0);
	printf("ret ===> |%s|\n", ret);
	assert(strcmp(ret, "") == 0);
	free(ret);
	ret = ft_strsub(NULL, 0, 0);
	assert(ret == 0);
}
