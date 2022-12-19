#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc(sizeof(char) * strlen(s1) + 1);
	if (!buffer)
		return (NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}


int getpi(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c - 38);
    return (c - 96);
}

int	main()
{
    FILE *fptr = fopen("case","r");

    if (!fptr)
        printf("cant open file");

    char    line[100];
    int     score;
    char    *s1;
    char    *s2;
    int     i = 0;
    char    *three_line[3];

    score = 0;
    int j;



    while (fgets(line, sizeof(line), fptr))
    {
        three_line[i] = ft_strdup(line);
        if (i == 2)
        {
            j = 0;
            while (three_line[0][j])
            {
                if (strchr(three_line[1],three_line[0][j]) && strchr(three_line[2],three_line[0][j]))
                {
                    score += getpi(three_line[0][j]);
                    break;
                }
                j++;
            }
        }
        i++; 
        i %= 3;
    }
    printf("\nmy score = %d\n",score);


}
