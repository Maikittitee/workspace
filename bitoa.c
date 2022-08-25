#include<stdio.h>

void	convert(char *str)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	j = 0;
	sum = 0;
	while (str[i])
	{
		sum = sum * 2 + (str[i] - '0');
		i++;
		if (j == 7)
		{
			printf("%c",sum);
			sum = 0;
			j = -1;
		}
		j++;

	}
}


int	main(int argc, char **argv)
{
	char	str[121];

	printf("ENTER BINARY : ");
	scanf("%s",str);
	printf(" str is %s\n",str);
	convert(str);
}
