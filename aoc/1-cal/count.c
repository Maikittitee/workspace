#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main()
{
    FILE *fptr = fopen("case","r");

    char    line[100];
    static int sum[256];

    int i = 0;

    while (fgets(line, sizeof(line), fptr))
    {
        sum[i] += atoi(line);
        
        if (line[0] == '\n')
            i++;
        

    }
    //printf("first sum = %d",sum[255]);

    int max = sum[0];
    i = 0;

    while (i <= 254)
    {
        if (sum[i] > max)
            max = sum[i];
        i++;
    }
    printf("max value is %d\n",max);


}
