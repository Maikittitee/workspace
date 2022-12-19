#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

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

    score = 0;

    while (fgets(line, sizeof(line), fptr))
    { 
        s1 = line;
        s2 = line + (strlen(line) / 2);
        printf("s1 = %s",s1);
        printf("s2 = %s",s2);
        i = 0;
        while (i < strlen(line) / 2)
        {
            if (strchr (s2,s1[i]))
            {
                score += getpi(s1[i]);
                break;
                //printf("common is %c\n",common);
            }
            i++;
        }
    }
    printf("\nmy score = %d\n",score);


}
