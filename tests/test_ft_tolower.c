/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:01:50 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 10:25:42 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_tolower_all(void)
{
	int	i;

	i = -1;
	printf(" [*] test on : %s\n", __FUNCTION__);
	while (i < 260)
	{
		assert(ft_tolower(i) == tolower(i));
		i++;
	}

}
