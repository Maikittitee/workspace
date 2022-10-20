#include <stdio.h>
//COMMENT >> Segmentation fault has occurred by can_go() >> FIXED!
//TODO >> Fix go_up and go_left (Segmentation Fault) >> 

int size_x;
int size_y;

void	show_maze(int maze[size_y + 2][size_x + 2])
{
	for (int b = 0; b <= size_y + 1; b++)
	{
		for (int c = 0; c <= size_x + 1; c++)
		{
			//printf(" %d [%d,%d]",maze[b][c],b,c);
			printf(" %d ",maze[b][c]);
		}
		printf("\n");
	}
}
int	can_go(int x,int y, int maze[size_y + 2][size_x + 2])
{
	if (x > 0 && y > 0 && x <= size_x && y <= size_y && maze[y][x] == 0)
		return (1);
	else
		return (0);
}

int	ft_flushfill(size_t x, size_t y, int maze[size_y + 2][size_x + 2])
{
	if (x == size_x && y == size_y && can_go(x, y, maze))
		return (1);
	printf("x : %d, y : %d\n",x,y);
	if (can_go(x,y, maze))
	{
        maze[y][x] = 1;
		printf("x : %d, y : %d\n",x,y);
		if (ft_flushfill(x + 1, y, maze))
			return (1);
		if (ft_flushfill(x, y + 1, maze))
			return (1);
		if (ft_flushfill(x, y - 1,maze))
		 	return (1);
		if (ft_flushfill(x - 1,y , maze))
			return (1);
	}
	return (0);
}
int	main()
{

	printf("Enter Size of MAZE (row colum)> ");
	scanf("%d %d", &size_y, &size_x);

	int maze[size_y + 2][size_x + 2];
	
	for (int c = 0; c <= size_y + 1; c++)
	{
		for (int d = 0; d <= size_x + 1; d++)
		{
			if (d == 0 || c == 0)
				maze[c][d] = 1;
		}
	}

	for(int i = 1; i <= size_y; i++)
	{
		for (int j = 1; j <= size_x; j++)
		{
			scanf("%d",&maze[i][j]);
		}
	}
	//add frame of maze (prevent segmentation fault from some case)
	for (int c = 0; c <= size_y + 1; c++)
	{
		for (int d = 0; d <= size_x + 1; d++)
		{
			if (d == size_x + 1 || c == size_y + 1)
				maze[c][d] = 1;
		}
	}
	//show maze for making sure that maze was correct;
	//show_maze(maze);

	//check result from flushfill function
	if (ft_flushfill(1,1,maze))
		printf("YESSSS\n");
	else
		printf("NO!\n");
}
