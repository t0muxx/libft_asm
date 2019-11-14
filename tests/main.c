/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:24:29 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 11:00:19 by tmaraval         ###   ########.fr       */
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
	void	(*tests[31])(void);
	
	tests[0] = &test_ft_bzero;
	tests[1] = &test_ft_strcat;
	tests[2] = &test_ft_isalpha_1_true;
	tests[3] = &test_ft_isalpha_2_false;
	tests[4] = &test_ft_isdigit_1_true;
	tests[5] = &test_ft_isdigit_2_false;
	tests[6] = &test_ft_isalnum_1_true;
	tests[7] = &test_ft_isalnum_2_false;
	tests[8] = &test_ft_isascii_1_true;
	tests[9] = &test_ft_isascii_2_false;
	tests[10] = &test_ft_isprint_1_true;
	tests[11] = &test_ft_isprint_2_false;
	tests[12] = &test_ft_toupper_all;
	tests[13] = &test_ft_tolower_all;
	tests[14] = &test_ft_puts_ok;
	tests[15] = &test_ft_puts_emtpy;
	tests[16] = &test_ft_puts_null;
	tests[17] = &test_ft_puts_fd_ok;
	tests[18] = &test_ft_puts_fd_file;
	tests[19] = &test_ft_puts_fd_null;
	tests[20] = &test_ft_strlen;
	tests[21] = &test_ft_memset;
	tests[22] = &test_ft_memcpy;
	tests[23] = &test_ft_strdup;
	tests[24] = &test_ft_cat;
	tests[25] = &test_ft_cat_closed_fd;
	tests[26] = &test_ft_cat_closed_0;
	tests[27] = &test_ft_strcmp;
	tests[28] = &test_ft_strncmp;
	tests[29] = &test_ft_atoi;
	tests[30] = 0;
	/*
	tests[49] = &test_ft_atoi_1;
	tests[50] = &test_ft_atoi_2_max;
	tests[51] = &test_ft_strsub_1;
	tests[52] = &test_ft_shellcode; 
	tests[53] = 0; */
	srand(time(NULL));
	run_tests(tests);
	return (0);
}
