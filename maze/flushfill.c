#include <stdio.h>
//TODO : Segmentation fault has occurred by can_go() >> FIXED!

int size_x;
int size_y;

void	show_maze(int maze[size_y + 1][size_x + 1])
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
int	can_go(int x,int y, int maze[size_y + 1][size_x + 1])
{
	if (x >= 0 && y >= 0 && x <= size_x - 1 && y <= size_y - 1 && maze[y][x] == 0)
		return (1);
	else
		return (0);
}

int	ft_flushfill(int x, int y, int maze[size_y + 1][size_x + 1])
{
	if (x == size_x - 1 && y == size_y - 1)
		return (1);

	if (can_go(x,y, maze))
	{
		if (ft_flushfill(x, y + 1,maze))
			return (1);
		if (ft_flushfill(x + 1, y, maze))
			return (1);
		// if (ft_flushfill(x, y - 1,maze))
		//  	return (1);
		// if (ft_flushfill(x - 1,y , maze))
		// 	return (1);
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
	//add frame of maze (prevent segmentation fault from some case)
	for (int c = 0; c <= size_y; c++)
	{
		for (int d = 0; d <= size_x; d++)
		{
			if (d == size_x || c == size_y)
				maze[c][d] = 1;
		}
	}
	//show maze for making sure that maze was correct;
	//show_maze(maze);

	//check result from flushfill function
	if (ft_flushfill(0,0,maze))
		printf("YESSSS\n");
	else
		printf("NO!\n");
}
