/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:24:29 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/13 15:28:04 by tmaraval         ###   ########.fr       */
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
	void	(*tests[54])(void);
	tests[0] = &test_ft_cat;
	tests[1] = &test_ft_cat_closed_fd;
	tests[2] = &test_ft_cat_closed_0;
	tests[3] = 0;
	/*
	tests[0] = &test_ft_bzero_1_ok;
	tests[1] = &test_ft_bzero_2_ok;
	tests[2] = &test_ft_bzero_3_len_0;
	tests[3] = &test_ft_bzero_4_len_inf;
	tests[4] = &test_ft_strcat_1_ok;
	tests[5] = &test_ft_strcat_2_ko;
	tests[6] = &test_ft_strcat_3_ko;
	tests[7] = &test_ft_strcat_random;
	tests[8] = &test_ft_isalpha_1_true;
	tests[9] = &test_ft_isalpha_2_false;
	tests[10] = &test_ft_isdigit_1_true;
	tests[11] = &test_ft_isdigit_2_false;
	tests[12] = &test_ft_isalnum_1_true;
	tests[13] = &test_ft_isalnum_2_false;
	tests[14] = &test_ft_isascii_1_true;
	tests[15] = &test_ft_isascii_2_false;
	tests[16] = &test_ft_isprint_1_true;
	tests[17] = &test_ft_isprint_2_false;
	tests[18] = &test_ft_toupper_all;
	tests[19] = &test_ft_tolower_all;
	tests[20] = &test_ft_puts_ok;
	tests[21] = &test_ft_puts_emtpy;
	tests[22] = &test_ft_puts_null;
	tests[23] = &test_ft_puts_fd_ok;
	tests[24] = &test_ft_puts_fd_file;
	tests[25] = &test_ft_puts_fd_null;
	tests[26] = &test_ft_strlen_1;
	tests[27] = &test_ft_strlen_2_empty;
	tests[28] = &test_ft_strlen_3_null;
	tests[29] = &test_ft_memset_1;
	tests[30] = &test_ft_memset_2;
	tests[31] = &test_ft_memset_len_0;
	tests[32] = &test_ft_memcpy_1;
	tests[33] = &test_ft_memcpy_2;
	tests[34] = &test_ft_strdup_1;
	tests[35] = &test_ft_strdup_2;
	tests[36] = &test_ft_cat;
	tests[37] = &test_ft_cat_closed_fd;
	tests[38] = &test_ft_cat_closed_0;
	tests[39] = &test_ft_strcmp_1;
	tests[40] = &test_ft_strcmp_2;
	tests[41] = &test_ft_strcmp_3;
	tests[42] = &test_ft_strcmp_4;
	tests[43] = &test_ft_strcmp_5;
	tests[44] = &test_ft_strncmp_1;
	tests[45] = &test_ft_strncmp_2;
	tests[46] = &test_ft_strncmp_3;
	tests[47] = &test_ft_strncmp_4;
	tests[48] = &test_ft_strncmp_5; 
	tests[49] = &test_ft_atoi_1;
	tests[50] = &test_ft_atoi_2_max;
	tests[51] = &test_ft_strsub_1;
	tests[52] = &test_ft_shellcode; 
	tests[53] = 0; */
	run_tests(tests);
	return (0);
}
