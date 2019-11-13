/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:03 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/13 14:10:59 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_strcat_random(void)
{
	char	ft_s1[200];
	char	s1[200];
	char	s2[200];
	char	*ret;

	printf(" [*] test on : %s\n", __FUNCTION__);
	memset(ft_s1, 1, 200);
	memset(s1, 1, 200);
	memset(s2, 1, 200);
	strcpy(s1, "s)8G_DGkms");
	strcpy(ft_s1, "s)8G_DGkms");
	strcpy(s2, "-5(wqDvFGAg3lIlZxmw3ofnec(83+-KWdigai");
	ret = ft_strcat(ft_s1, s2);
	strcat(s1, s2);
	assert(ret != 0);
	printf("strcat : |%s| vs ft_strcat : |%s|\n", s1, ft_s1);
	assert(memcmp(ft_s1, s1, 200) == 0);
	
}

void	test_ft_strcat_3_ko(void)
{
	char	s1[16];
	char	s2[8];
	char	*ret;

	printf(" [*] test on : %s\n", __FUNCTION__);
	strcpy(s1, "12345678");
	strcpy(s2, "abcdef");
	ret = ft_strcat(0, s2);
	assert(ret == 0);
}

void	test_ft_strcat_2_ko(void)
{
	char	s1[16];
	char	s2[8];
	char	*ret;

	printf(" [*] test on : %s\n", __FUNCTION__);
	strcpy(s1, "12345678");
	strcpy(s2, "abcdef");
	ret = ft_strcat(s1, 0);
	assert(strcmp(s1, "12345678") == 0);
	assert(ret == s1);
}

void	test_ft_strcat_1_ok(void)
{
	char	s1[16];
	char	s2[8];
	char	*ret;

	printf(" [*] test on : %s\n", __FUNCTION__);
	strcpy(s1, "12345678");
	strcpy(s2, "abcdef");
	ret = ft_strcat(s1, s2);
	assert(strcmp(s1, "12345678abcdef") == 0);
	assert(ret == s1);
}
