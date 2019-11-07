/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:24:29 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/07 15:08:29 by tmaraval         ###   ########.fr       */
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
	void	(*tests[8])(void);

	tests[0] = &test_ft_bzero_1_ok;
	tests[1] = &test_ft_bzero_2_ok;
	tests[2] = &test_ft_bzero_3_len_0;
	tests[3] = &test_ft_bzero_4_len_inf;
	tests[4] = &test_ft_strcat_1_ok;
	tests[5] = &test_ft_strcat_2_ko;
	tests[6] = &test_ft_strcat_3_ko;
	tests[7] = 0;
	run_tests(tests);
	return (0);
}
