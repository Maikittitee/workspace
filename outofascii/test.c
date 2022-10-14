#include<stdio.h>

int	main()
{
	char a;
	char	b,c;

	c = '\177';
	a = '\200';
	b = '\201';

	printf("c = /177 %d\n",c);
	printf("a = /200 %d\n",a);
	printf("p = /201 %d\n",b);
}

