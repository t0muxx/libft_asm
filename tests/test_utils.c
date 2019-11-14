/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 07:46:54 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/14 08:03:09 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*random_junk(size_t size)
{
	char	*str;
	int		fd;
	
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	if ((fd = open("/dev/urandom", O_RDONLY)) < 0)
	{
		free(str);
		return (NULL);
	}
	read(fd, str, size -1);
	str[size] = 0;
	close(fd);
	return (str);
}

char	*random_str(size_t size)
{
	char *str;
	char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_+-()";
	size_t i;

	i = 0;
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		str[i] = charset[rand() % sizeof(charset)];
		i++;
	}
	str[size] = 0;
	return (str);
}

char	 *random_str_nb(size_t size)
{
	char	*str;
	char	charset[] = "0123456789";
	int		sign;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	sign = rand() % 3;
	if (sign == 0)
	{
		str[i] = '-';
		i++;
	}
	else if (sign == 1)
	{
		str[i] = '+';
		i++;
	}
	else if (sign == 2)
	{
		str[i] = ' ';
		i++;
	}
	while (i < size)
	{
		str[i] = charset[rand() % sizeof(charset)];
		i++;
	}
	str[size] = 0;
	return (str);
}
