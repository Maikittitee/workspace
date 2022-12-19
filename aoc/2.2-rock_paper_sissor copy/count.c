#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


int compare(char en,char i)
{
    int p1;
    int p2;

    if (i == 'X') //lose
    {
        p2 = 0;
        if (en == 'A') //rock
            p1 = 3;
        if (en == 'B') //paper
            p1 = 1;
        if (en == 'C') //sissor
            p1 = 2;
    }
    if (i == 'Y') //draw
    {
        p2 = 3;
        if (en == 'A') //rock
            p1 = 1;
        if (en == 'B') //paper
            p1 = 2;
        if (en == 'C') //sissor
            p1 = 3;
    }
    if (i == 'Z') //win
    {
        p2 = 6;
        if (en == 'A') //rock
            p1 = 2;
        if (en == 'B') //paper
            p1 = 3;
        if (en == 'C') //sissor
            p1 = 1;
    }
    return (p1 + p2);
}


int	main()
{
    FILE *fptr = fopen("case","r");

    if (!fptr)
        printf("cant open file");

    char    line[100];
    int     score;

    score = 0;

    while (fgets(line, sizeof(line), fptr))
    {
        //printf("%c\n",line[2]);
        score += (compare(line[0],line[2]));
    }

    printf("my score = %d\n",score);

}
