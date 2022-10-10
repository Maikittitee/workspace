#include <stdio.h>


static char maze[10][10];

void	show_maze()
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			printf(" %d ",maze[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
int	can_go(x,y)
{
	return (x < 10 && y < 10 && maze[x][y] == 0);
}
int	ft_flushfill(int x, int y)
{
	if (x == 9 && y == 9)
		return (1);

	if (can_go(x,y))
	{
		if (ft_flushfill(x + 1, y))
			return (1);
		if (ft_flushfill(x, y + 1))
			return (1);
	}
	return (0);
}

int	main()
{
	int	size_x = 4, size_y = 4;

	// maze[1][1] = 1;
	// maze[0][1] = 1;
	// maze[0][4] = 1;
	// maze[0][5] = 1;

	// maze[1][8] = 1;
	// maze[8][1] = 1;
	// maze[4][3] = 1;
	// maze[7][5] = 1;

	show_maze();
	if (ft_flushfill(0,0))
		printf("can go\n");
	else
		printf("cannot go");
}
