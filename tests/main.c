/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:24:29 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 08:09:04 by tmaraval         ###   ########.fr       */
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
	void	(*tests[37])(void);

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
	tests[19] = &test_ft_puts_ok;
	tests[20] = &test_ft_puts_emtpy;
	tests[21] = &test_ft_puts_null;
	tests[22] = &test_ft_strlen_1;
	tests[23] = &test_ft_strlen_2_empty;
	tests[24] = &test_ft_strlen_3_null;
	tests[25] = &test_ft_memset_1;
	tests[26] = &test_ft_memset_2;
	tests[27] = &test_ft_memset_len_0;
	tests[28] = &test_ft_memcpy_1;
	tests[29] = &test_ft_strdup_1;
	tests[30] = &test_ft_cat;
	tests[31] = &test_ft_strcmp_1;
	tests[32] = &test_ft_strcmp_2;
	tests[33] = &test_ft_strcmp_3;
	tests[34] = &test_ft_strcmp_4;
	tests[35] = &test_ft_strcmp_5;
	tests[36] = 0;
	run_tests(tests);
	return (0);
}
