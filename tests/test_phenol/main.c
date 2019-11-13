#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <time.h>

#include "../test.h"

#define MAX_SIZE (4096 * 2)
#define N_TEST	4096

char			*get_random(size_t size)
{
	char	*buffer;
	int		fd;

	if (!(buffer = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if ((fd = open("/dev/urandom", O_RDONLY)) < 0)
	{
		free(buffer);
		return (NULL);
	}
	read(fd, buffer, size - 1);
	buffer[size] = 0;
	close(fd);
	return (buffer);
}

char			*get_random_str(size_t size)
{
	char	*buffer;
	char	charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_+-()";
	size_t	i = 0;

	if (!(buffer = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		buffer[i] = charset[rand() % sizeof(charset)];
		i++;
	}
	buffer[size] = 0;
	return (buffer);
}

char			*get_random_nb(size_t size)
{
	char	*buffer;
	char	charset[] = "0123456789";
	int		sig;
	size_t	i = 0;

	if (!(buffer = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	sig = rand() % 3;
	if (sig == 0)
	{
		buffer[i] = '-';
		i++;
	} else if (sig == 1)
	{
		buffer[i] = '+';
		i++;
	}
	else if (sig == 2)
	{
		buffer[i] = ' ';
		i++;
	}
	while (i < size)
	{
		buffer[i] = charset[rand() % sizeof(charset)];
		i++;
	}
	buffer[size] = 0;
	return (buffer);
}

int		get_output(char *input, char *out, int (*fn)(const char *), size_t size)
{
	int		res;
	int		pfd[2];
	int		stout;

	stout = dup(1);
	pipe(pfd);
	dup2(pfd[1], 1);
	res = fn(input);
	memset(out, 0, size);
	read(pfd[0], out, size);
	dup2(stout, 1);
	close(pfd[0]);
	close(pfd[1]);
	close(stout);
	return (res);
}

int				test_puts(void)
{
	int		res0;
	int		res1;
	char	*input;
	char	my[4096];
	char	orig[4096];
	int		i = 0;

	printf("Testing ft_puts...\n");
	while (i < N_TEST)
	{
		if (!(input = get_random_str(rand() % 4095)))
			return (EXIT_FAILURE);
		res0 = get_output(input, my, &ft_puts, 4096);
		res1 = get_output(input, orig, &puts, 4096);
		if (res0 != res1)
		{
			printf("Error ft_puts: return value different %d != %d\nft_puts: %s\nputs: %s\n", res0, res1, my, orig);
			free(input);
			return (EXIT_FAILURE);
		}
		if (strcmp(my, orig))
		{
			printf("Error ft_puts: output different\nft_puts: %s\nputs: %s\n", my, orig);
			free(input);
			return (EXIT_FAILURE);
		}
		i++;
		free(input);
	}
	return (EXIT_SUCCESS);
}

int				test_atoi(void)
{
	int		res0;
	int		res1;
	char	*s;
	int		i = 0;

	printf("Testing ft_atoi...\n");
	while (i < N_TEST)
	{
		if (!(s = get_random_nb(rand() % 11)))
		{
			printf("Error OOM on test_atoi\n");
			return (EXIT_FAILURE);
		}
		res0 = ft_atoi(s);
		res1 = atoi(s);
		if (res0 != res1)
		{
			printf("Error ft_atoi: %d != %d (%s)\n", res0, res1, s);
			free(s);
			return (EXIT_FAILURE);
		}
		i++;
		free(s);
	}
	return (EXIT_SUCCESS);
}

int				test_strdup(void)
{
	char	*src;
	char	*d0;
	char	*d1;
	size_t	n;
	int		i;

	i = 0;
	printf("Testing ft_strdup...\n");
	while (i < N_TEST)
	{
		n = rand() % MAX_SIZE;
		if (!(src = get_random_str(n)))
			return (EXIT_FAILURE);
		if (!(d0 = ft_strdup(src)))
		{
			printf("Error ft_strdup returned NULL, problem or OOM?!\n");
			free(src);
			return (EXIT_FAILURE);
		}
		d1 = strdup(src);
		if (strncmp(d0, d1, n))
		{
			printf("Error ft_strdup: memory content differ\n");
			free(d0);
			free(d1);
			free(src);
			return (EXIT_FAILURE);
		}
		i++;
		free(d0);
		free(d1);
		free(src);
	}
	return (EXIT_SUCCESS);
}

int				test_bzero(void)
{
	char	*mess;
	size_t	size;
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	printf("Testing ft_bzero...\n");
	while (i < N_TEST)
	{
		size = rand() % MAX_SIZE;
		if (!(mess = get_random(size)))
			return (EXIT_FAILURE);
		ft_bzero(mess, size);
		while (j < size)
		{
			if (mess[j] != 0)
			{
				printf("Error ft_bzero: memory not properly zeroed\n");
				free(mess);
				return (EXIT_FAILURE);
			}
			j++;
		}
		j = 0;
		i++;
		free(mess);
	}
	return (EXIT_SUCCESS);
}

int				test_strcat(void)
{
	char	*s0_0;
	char	*s1_0;
	char	*tmp;
	char	*s0_1;
	char	*s1_1;
	size_t	size_s0;
	size_t	size_s1;
	char	*res0;
	int		i;

	i = 0;
	printf("Testing ft_strcat...\n");
	while (i < N_TEST)
	{
		size_s0 = rand() % MAX_SIZE;
		size_s1 = rand() % MAX_SIZE;
		s0_0 = get_random_str(size_s0);
		s1_0 = get_random_str(size_s1);
		if (!(tmp = (char *)malloc(sizeof(char) * (size_s0 + size_s1 + 1))))
		{
			free(s0_0);
			free(s1_0);
			return (EXIT_FAILURE);
		}
		memset(tmp, 0, size_s0 + size_s1 + 1);
		memcpy(tmp, s0_0, size_s0);
		free(s0_0);
		s0_0 = tmp;
		if (!(s0_1 = (char *)malloc(sizeof(char) * (size_s0 + size_s1 + 1))))
		{
			free(s0_0);
			free(s1_0);
			return (EXIT_FAILURE);
		}
		memset(s0_1, 0, size_s0 + size_s1 + 1);
		if (!(s1_1 = (char *)malloc(sizeof(char) * (size_s1 + 1))))
		{
			free(s0_0);
			free(s1_0);
			free(s0_1);
			return (EXIT_FAILURE);
		}
		memset(s1_1, 0, size_s1 + 1);
		memcpy(s1_1, s1_0, size_s1);
		memcpy(s0_1, s0_0, size_s0);
		res0 = ft_strcat(s0_0, s1_0);
		strcat(s0_1, s1_1);
		if (res0 != s0_0)
		{
			printf("Error ft_strcat: bad return value %p, expected: %p\n", res0, s0_0);
			free(s0_0);
			free(s1_0);
			free(s1_1);
			free(s0_1);
			return (EXIT_FAILURE);
		}
		if (memcmp(s0_0, s0_1, size_s0 + size_s1))
		{
			printf("Error ft_strcat: difference in memory content\n");
			printf("strcat: %s\nft_strcat: %s\n", s0_1, s0_0);
			free(s0_0);
			free(s1_0);
			free(s1_1);
			free(s0_1);
			return (EXIT_FAILURE);
		}
		i++;
		free(s0_0);
		free(s1_0);
		free(s1_1);
		free(s0_1);
	}
	return (EXIT_SUCCESS);
}

int				test_memset(void)
{
	char		*dst;
	char		*dst2;
	char		*res0;
	size_t		size;
	int			i;

	i = 0;
	printf("Testing ft_memset...\n");
	while (i < N_TEST)
	{
		size = rand() % MAX_SIZE;
		if (!(dst = (char *)malloc(sizeof(char) * size)))
			return (EXIT_FAILURE);
		if (!(dst2 = (char *)malloc(sizeof(char) * size)))
		{
			free(dst);
			return (EXIT_FAILURE);
		}
		res0 = ft_memset(dst, i, size);
		memset(dst2, i, size);
		if (res0 != dst)
		{
			printf("Error ft_memset: bad return value ft_memset() = %p, expected: %p\n", res0, dst);
			free(dst);
			free(dst2);
			return (EXIT_FAILURE);
		}
		if (memcmp(dst, dst2, size))
		{
			printf("Error ft_memset: difference in memory content\n");
			free(dst);
			free(dst2);
			return (EXIT_FAILURE);
		}
		i++;
		free(dst);
		free(dst2);
	}
	return (EXIT_SUCCESS);
}

int				test_memcpy(void)
{
	char	*src;
	char	*dst;
	char	*dst2;
	void	*res0;
	size_t	size;
	int		i;

	i = 0;
	printf("Testing ft_memcpy...\n");
	while (i < N_TEST)
	{
		size = rand() % MAX_SIZE;
		if (!(src = get_random(size)))
		{
			printf("Error getting random!\n");
			return (EXIT_FAILURE);
		}
		if (!(dst = (char *)malloc(sizeof(char) * size)))
		{
			free(src);
			return (EXIT_FAILURE);
		}
		memset(dst, 0, size);
		if (!(dst2 = (char *)malloc(sizeof(char) * size)))
		{
			free(src);
			free(dst);
			return (EXIT_FAILURE);
		}
		memset(dst2, 0, size);
		res0 = ft_memcpy(dst, src, size);
		memcpy(dst2, src, size);
		if (res0 != dst)
		{
			printf("Error ft_memcpy: bad return value ft_memcpy() = %p, expected: %p\n", res0, dst);
			free(src);
			free(dst);
			free(dst2);
			return (EXIT_FAILURE);
		}
		if (memcmp(dst, dst2, size))
		{
			printf("Error ft_memcpy: difference in copied memory\n");
			free(dst);
			free(dst2);
			free(src);
			return (EXIT_FAILURE);
		}
		i++;
		free(src);
		free(dst);
		free(dst2);
	}
	return (EXIT_SUCCESS);
}

int				test_strlen(void)
{
	char	*s;
	int		i;
	int		res0;
	int		res1;

	i = 0;
	printf("Testing ft_strlen...\n");
	while (i < N_TEST)
	{
		if (!(s = get_random(rand() % MAX_SIZE)))
		{
			printf("Error getting random!\n");
			return (EXIT_FAILURE);
		}
		res0 = ft_strlen(s);
		res1 = strlen(s);
		if (res0 != res1)
		{
			printf("Error ft_strlen\n");
			return (EXIT_FAILURE);
		}
		free(s);
		i++;
	}
	return (EXIT_SUCCESS);
}

int				test_isdigit(void)
{
	int	i;
	int	res0;
	int res1;

	i = 0;
	res0 = 0;
	res1 = 0;
	printf("Testing ft_isdigit...\n");
	while (i < N_TEST)
	{
		res0 = ft_isdigit(i);
		res1 = isdigit(i);
		if (res0 != res1)
		{
			printf("Error ft_isdigit(%d) = %d != isdigit(%d) = %d\n", i, res0, i, res1);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int				test_isprint(void)
{
	int	i;
	int	res0;
	int res1;

	i = 0;
	res0 = 0;
	res1 = 0;
	printf("Testing ft_isprint...\n");
	while (i < N_TEST)
	{
		res0 = ft_isprint(i);
		res1 = isprint(i);
		if (res0 != res1)
		{
			printf("Error ft_isprint(%d) = %d != isprint(%d) = %d\n", i, res0, i, res1);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int				test_isalnum(void)
{
	int	i;
	int	res0;
	int res1;

	i = 0;
	res0 = 0;
	res1 = 0;
	printf("Testing ft_isalnum...\n");
	while (i < N_TEST)
	{
		res0 = ft_isalnum(i);
		res1 = isalnum(i);
		if (res0 != res1)
		{
			printf("Error ft_isalnum(%d) = %d != isalnum(%d) = %d\n", i, res0, i, res1);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int				test_isalpha(void)
{
	int	i;
	int	res0;
	int res1;

	i = 0;
	res0 = 0;
	res1 = 0;
	printf("Testing ft_isalpha...\n");
	while (i < N_TEST)
	{
		res0 = ft_isalpha(i);
		res1 = isalpha(i);
		if (res0 != res1)
		{
			printf("Error ft_isalpha(%d) = %d != isalpha(%d) = %d\n", i, res0, i, res1);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int				test_isascii(void)
{
	int	i;
	int	res0;
	int res1;

	i = 0;
	res0 = 0;
	res1 = 0;
	printf("Testing ft_isascii...\n");
	while (i < N_TEST)
	{
		res0 = ft_isascii(i);
		res1 = isascii(i);
		if (res0 != res1)
		{
			printf("Error ft_isascii(%d) = %d != isascii(%d) = %d\n", i, res0, i, res1);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

#define N_FUNCS 13

int	(*test_func[N_FUNCS])(void) =
{
	&test_isdigit,
	&test_isprint,
	&test_isalnum,
	&test_isalpha,
	&test_isascii,
	&test_strlen,
	&test_memcpy,
	&test_memset,
	&test_strcat,
	&test_bzero,
	&test_strdup,
	&test_puts,
	&test_atoi,
	0
};

int				main(void)
{
	int n_func = 0;

	srand(time(NULL)); // Wrong way to init a PRNG, but this one sucks and we don't care here.
	while (n_func < N_FUNCS)
	{
		if (test_func[n_func]())
			return (EXIT_FAILURE);
		n_func++;
	}
	return (EXIT_SUCCESS);
}
