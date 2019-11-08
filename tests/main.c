/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:24:29 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 09:08:48 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		run_tests(void (*tests[])(void))
{
	int i;

	i = 0;
	while (tests[i])
	{
		(*tests[i])();
		printf(" [*] Ok !\n");
		i++;
	}
	return (0);
}


int		main(void)
{
	void	(*tests[20])(void);

	tests[0] = &test_ft_bzero_1_ok;
	tests[1] = &test_ft_bzero_2_ok;
	tests[2] = &test_ft_bzero_3_len_0;
	tests[3] = &test_ft_bzero_4_len_inf;
	tests[4] = &test_ft_strcat_1_ok;
	tests[5] = &test_ft_strcat_2_ko;
	tests[6] = &test_ft_strcat_3_ko;
	tests[7] = &test_ft_isalpha_1_true;
	tests[8] = &test_ft_isalpha_2_false;
	tests[9] = &test_ft_isdigit_1_true;
	tests[10] = &test_ft_isdigit_2_false;
	tests[11] = &test_ft_isalnum_1_true;
	tests[12] = &test_ft_isalnum_2_false;
	tests[13] = &test_ft_isascii_1_true;
	tests[14] = &test_ft_isascii_2_false;
	tests[15] = &test_ft_isprint_1_true;
	tests[16] = &test_ft_isprint_2_false;
	tests[17] = &test_ft_toupper_all;
	tests[18] = &test_ft_tolower_all;
	tests[19] = 0;
	run_tests(tests);
	return (0);
}
