/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_puts_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:26:05 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 11:33:13 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_ft_puts_fd_null(void)
{
	printf(" [*] test on : %s\n", __FUNCTION__);
	printf(" [*] puts segfault so no need to test\n");
//	assert(puts(str) < 0);
//	assert(_ft_puts_fd(str) < 0);
}

void	test_ft_puts_fd_file(void)
{
	char str[100];
	int fd;
	char buf[1024];

	fd = open("/tmp/ftputsfd", O_RDWR | O_CREAT | O_TRUNC, 0777);
	assert(fd > 0);
	printf(" [*] test on : %s\n", __FUNCTION__);
	strcpy(str, "1234567890");
	assert(ft_puts_fd(str, fd) >= 0);
	close(fd);
	memset(buf, 0, 1024);
	fd = open("/tmp/ftputsfd", O_RDONLY, 0777);
	assert(fd > 0);
	read(fd, buf, 1024);
	printf("buf == |%s|\n", buf);
	assert(strcmp(buf, "1234567890\n") == 0);
	close(fd);
}

void	test_ft_puts_fd_ok(void)
{
	char str[10];
	
	printf(" [*] test on : %s\n", __FUNCTION__);
	strcpy(str, "abcdefgh");
	assert(ft_puts_fd(str, 1) > 0);
}
