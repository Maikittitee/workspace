#include <stdio.h>

#define CLOCK_SPEED 150000000

int	main()
{
	long long	i;

	i = 0;
	while (1)
	{
		if (i % CLOCK_SPEED == 0)
			printf("sec : %lld\n",i);
		i++;
		//i %= CLOCK_SPEED;
	}
}
