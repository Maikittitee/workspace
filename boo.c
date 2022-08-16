#include<stdlib.h>
#include<stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i <= atoi(argv[1]))
	{
		if (i)
			printf("%d is TRUE\n",i);
		else
			printf("%d is FALSE\n",i);
		i++;
	}
}
