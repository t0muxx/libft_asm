/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strsub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:10:25 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 16:55:19 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strsub_1(void)
{
	char *str = "test_other_1234567";
	char *ret;

	ret = ft_strsub(str, 4, 14);
	printf("ret ===> |%s|\n", ret);
	assert(strcmp(ret, "_other_1234567") == 0);

}
