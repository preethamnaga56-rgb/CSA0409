#include <stdio.h>
#include <string.h>

#define MAX 20

int main()
{
    char files[MAX][50];
    char name[50];
    int count = 0, choice, i, found;

    while (1)
    {
        printf("\n1. Create file\n2. List files\n");
        printf("3. Delete file\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (count == MAX)
            {
                printf("Directory is full.\n");
                continue;
            }

            printf("Enter filename: ");
            scanf("%49s", name);

            found = 0;
            for (i = 0; i < count; i++)
                if (strcmp(files[i], name) == 0)
                    found = 1;

            if (found)
                printf("File already exists.\n");
            else
            {
                strcpy(files[count++], name);
                printf("File created successfully.\n");
            }
        }
        else if (choice == 2)
        {
            printf("Files in directory:\n");
            for (i = 0; i < count; i++)
                printf("%s\n", files[i]);

            if (count == 0)
                printf("Directory is empty.\n");
        }
        else if (choice == 3)
        {
            printf("Enter filename to delete: ");
            scanf("%49s", name);

            found = 0;
            for (i = 0; i < count; i++)
            {
                if (strcmp(files[i], name) == 0)
                {
                    int j;
                    for (j = i; j < count - 1; j++)
                        strcpy(files[j], files[j + 1]);

                    count--;
                    found = 1;
                    printf("File deleted successfully.\n");
                    break;
                }
            }

            if (!found)
                printf("File not found.\n");
        }
        else if (choice == 4)
            break;
        else
            printf("Invalid choice.\n");
    }

    return 0;
}
