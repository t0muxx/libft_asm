/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:24:17 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/08 09:08:05 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void	_ft_bzero(void *mem, size_t n);
void	test_ft_bzero_1_ok(void);
void	test_ft_bzero_2_ok(void);
void	test_ft_bzero_3_len_0(void);
void	test_ft_bzero_4_len_inf(void);

char	*_ft_strcat(const char *s1, const char *s2);
void	test_ft_strcat_1_ok(void);
void	test_ft_strcat_2_ko(void);
void	test_ft_strcat_3_ko(void);

int		_ft_isalpha(int c);
void	test_ft_isalpha_1_true(void);
void	test_ft_isalpha_2_false(void);

int		_ft_isdigit(int c);
void	test_ft_isdigit_1_true(void);
void	test_ft_isdigit_2_false(void);

int		_ft_isalnum(int c);
void	test_ft_isalnum_1_true(void);
void	test_ft_isalnum_2_false(void);

int		_ft_isascii(int c);
void	test_ft_isascii_1_true(void);
void	test_ft_isascii_2_false(void);

int		_ft_isprint(int c);
void	test_ft_isprint_1_true(void);
void	test_ft_isprint_2_false(void);

int		_ft_toupper(int c);
void	test_ft_toupper_all(void);

int		_ft_tolower(int c);
void	test_ft_tolower_all(void);
