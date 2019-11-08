/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_cat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:24:03 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 16:26:22 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_cat(void)
{
	int fd;

	fd = 0;
	printf(" [*] test on : %s\n", __FUNCTION__);
	fd = open("./test_ft_cat.c", O_RDONLY);
	ft_cat(fd);
	close(fd);
}
