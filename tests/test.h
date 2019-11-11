/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:24:17 by tmaraval          #+#    #+#             */
/*   Updated: 2019/11/11 10:36:10 by tmaraval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_bzero(void *mem, size_t n);
void	test_ft_bzero_1_ok(void);
void	test_ft_bzero_2_ok(void);
void	test_ft_bzero_3_len_0(void);
void	test_ft_bzero_4_len_inf(void);

char	*ft_strcat(const char *s1, const char *s2);
void	test_ft_strcat_1_ok(void);
void	test_ft_strcat_2_ko(void);
void	test_ft_strcat_3_ko(void);

int		ft_isalpha(int c);
void	test_ft_isalpha_1_true(void);
void	test_ft_isalpha_2_false(void);

int		ft_isdigit(int c);
void	test_ft_isdigit_1_true(void);
void	test_ft_isdigit_2_false(void);

int		ft_isalnum(int c);
void	test_ft_isalnum_1_true(void);
void	test_ft_isalnum_2_false(void);

int		ft_isascii(int c);
void	test_ft_isascii_1_true(void);
void	test_ft_isascii_2_false(void);

int		ft_isprint(int c);
void	test_ft_isprint_1_true(void);
void	test_ft_isprint_2_false(void);

int		ft_toupper(int c);
void	test_ft_toupper_all(void);

int		ft_tolower(int c);
void	test_ft_tolower_all(void);

int		ft_puts(const char *s);
void	test_ft_puts_ok(void);
void	test_ft_puts_emtpy(void);
void	test_ft_puts_null(void);

size_t	ft_strlen(const char *s);
void	test_ft_strlen_1(void);
void	test_ft_strlen_2_empty(void);
void	test_ft_strlen_3_null(void);

void	*ft_memset(void *s, int c, size_t n);
void	test_ft_memset_1(void);
void	test_ft_memset_2(void);
void	test_ft_memset_len_0(void);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	test_ft_memcpy_1(void);
void	test_ft_memcpy_2(void);

char	*ft_strdup(const char *s);
void	test_ft_strdup_1(void);
void	test_ft_strdup_2(void);

void	ft_cat(int fd);
void	test_ft_cat(void);
void	test_ft_cat_closed_fd(void);
void	test_ft_cat_closed_0(void);

int		ft_strcmp(const char *s1, const char *s2);
void	test_ft_strcmp_1(void);
void	test_ft_strcmp_2(void);
void	test_ft_strcmp_3(void);
void	test_ft_strcmp_4(void);
void	test_ft_strcmp_5(void);
