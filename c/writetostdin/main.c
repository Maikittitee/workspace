#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	write(0,"what_are_you_saying\n",20);
	//write(0,"Hello\n",6);
	write(1,stdin,20);
	return (0);
}
