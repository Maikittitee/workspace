#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[256], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
 
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

    // while (i <= 254)
    // {
    //     if (sum[i] > max)
    //         max = sum[i];
    //     i++;
    // }

    bubbleSort(sum,256);
    printf("max value is %d\n",sum[255]);
    printf("max value is %d\n",sum[254]);
    printf("max value is %d\n",sum[253]);
    printf("sum of 3 max value is %d\n",sum[253]+sum[254]+sum[255]);


}
