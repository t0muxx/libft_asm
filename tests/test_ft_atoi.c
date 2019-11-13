/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:10:14 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/13 14:29:46 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_atoi_2_max(void)
{
	int ret1;
	int ret2;
	char *str;

	str = malloc(1000);
	sprintf(str, "%d", INT_MAX);
	ret1 = atoi(str);
	ret2 = ft_atoi(str);
	assert(ret1 == ret2);
	sprintf(str, "%d", INT_MIN);
	ret1 = atoi(str);
	ret2 = ft_atoi(str);
	assert(ret1 == ret2);
	str = malloc(1000);
	sprintf(str, "%ld", (long)INT_MAX + 2);
	ret1 = atoi(str);
	ret2 = ft_atoi(str);
	assert(ret1 == ret2);
	sprintf(str, "%ld", (long)INT_MIN - 3);
	ret1 = atoi(str);
	ret2 = ft_atoi(str);
}

void	test_ft_atoi_1(void)
{
	int ret1;
	int ret2;
	int i;
	char *str;
	int	j;

	printf(" [*] test on : %s\n", __FUNCTION__);
	j = 0;
	srand(time(NULL));
	i = 0;
	str = malloc(1000);
	sprintf(str, "");
	printf("testing with |%s|\n", str);
	ret1 = atoi(str);
	ret2 = ft_atoi(str);
	assert(ret1 == ret2);
	while (i < 200)
	{
		j = rand();
		ret1 = 0;
		ret2 = 0;
		if (i % 2 == 0)
			j = j * -1;
		sprintf(str, "%d", j);
		ret1 = atoi(str);
		ret2 = ft_atoi(str);
		assert(ret1 == ret2);
		i++;
	}
	free(str);
}
