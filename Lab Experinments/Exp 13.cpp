#include <stdio.h>

int main()
{
    int block[20], process[20], allocation[20];
    int m, n, i, j, choice, best, size;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    if (m < 1 || m > 20)
        return 1;

    printf("Enter block sizes:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
        return 1;

    printf("Enter process sizes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    for (i = 0; i < n; i++)
    {
        best = -1;

        for (j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (choice == 1)
                {
                    best = j;
                    break;
                }
                else if (choice == 2)
                {
                    if (best == -1 || block[j] < block[best])
                        best = j;
                }
                else if (choice == 3)
                {
                    if (best == -1 || block[j] > block[best])
                        best = j;
                }
            }
        }

        if (best != -1)
        {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t", i + 1, process[i]);

        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not allocated\n");
    }

    return 0;
}
