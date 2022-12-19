#include <stdio.h>

int	return0()
{
	printf("in zero\n");
	return (0);
}

int	return1()
{
	printf("in one\n");
	return (1);
}

int	main(void)
{
	if (return0() && return1())	
		printf("ok");
	else
		printf("noting");
		
}
