#include <stdio.h>
//Segment fault occured by can_go

int size_x;
int size_y;

//int	size_x, size_y;

void	show_maze(int maze[size_y][size_x])
{
	for (int b = 0; b <= size_y; b++)
	{
		for (int c = 0; c <= size_x; c++)
		{
			printf(" %d ",maze[b][c]);
		}
		printf("\n");
	}
}
int	can_go(int x,int y, int maze[size_y][size_x])
{
	if (x >= 0 && y >= 0 && x < size_x && y < size_y && maze[y][x] == 0)
		return (1);
	else
		return (0);
}

int	ft_flushfill(int x, int y, int maze[size_y][size_x])
{
	if (x == size_x - 1 && y == size_y - 1 && can_go(x,y,maze))
		return (1);

	if (can_go(x,y, maze)/* && maze[x][y]*/)
	{
		if (y < size_y - 1 && ft_flushfill(x, y + 1,maze))
			return (1);
		if (x < size_x -1 && ft_flushfill(x + 1, y, maze))
			return (1);
		if (y > 0 && ft_flushfill(x, y - 1,maze))
		 	return (1);
		if (x > 0 && ft_flushfill(x - 1,y , maze))
			return (1);
	}
	return (0);
}
int	main()
{

	printf("Enter Size of MAZE (row colum)> ");
	scanf("%d %d", &size_y, &size_x);

	int maze[size_y + 1][size_x + 1];

	for(int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			scanf("%d",&maze[i][j]);
		}
	}
	printf("after input show -----\n");
	for (int c = 0; c <= size_y; c++)
	{
		for (int d = 0; d <= size_x; d++)
		{
			printf(" %d ",maze[c][d]);
			if (d == size_x || c == size_y)
				maze[c][d] = 8;
		}
		printf("\n");
	}
	printf("function show ----- \n");
	show_maze(maze);
	if (ft_flushfill(0,0,maze))
		printf("YESSSS\n");
	else
		printf("NO!\n");
}
