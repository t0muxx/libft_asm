/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_shellcode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:19:19 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 17:21:52 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_shellcode(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	printf(" --> Don't forget to close the shell \n");
	ft_shellcode();
}
