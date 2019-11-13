#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../test.h"

int	main(int argc, char **argv)
{
	int	fd = 0;

	if (argc == 1)
		ft_cat(fd);
	else
	{
		argv++;
		while (*argv)
		{
			if ((fd = open(*argv, O_RDONLY)) < 0)
			{
				printf("Error: Canot open %s\n", *argv);
				return (EXIT_FAILURE);
			}
			printf("test with |%s| fd == %d\n", *argv, fd);
			ft_cat(fd);
			argv++;
		}
	}
	return (EXIT_SUCCESS);
}
