#include <stdio.h>
#include <string.h>

#define USERS 10
#define FILES 10

char users[USERS][30];
char files[USERS][FILES][40];
int fileCount[USERS] = {0};
int userCount = 0;

int findUser(char name[])
{
    int i;

    for (i = 0; i < userCount; i++)
        if (strcmp(users[i], name) == 0)
            return i;

    return -1;
}

int main()
{
    char user[30], file[40];
    int choice, u, i, found;

    while (1)
    {
        printf("\n1. Create user directory\n");
        printf("2. Create file\n3. List files\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (userCount == USERS)
            {
                printf("Maximum users reached.\n");
                continue;
            }

            printf("Enter username: ");
            scanf("%29s", user);

            if (findUser(user) != -1)
                printf("User already exists.\n");
            else
            {
                strcpy(users[userCount], user);
                fileCount[userCount] = 0;
                userCount++;
                printf("User directory created.\n");
            }
        }
        else if (choice == 2)
        {
            printf("Enter username: ");
            scanf("%29s", user);
            u = findUser(user);

            if (u == -1)
            {
                printf("User not found.\n");
                continue;
            }

            if (fileCount[u] == FILES)
            {
                printf("Directory is full.\n");
                continue;
            }

            printf("Enter filename: ");
            scanf("%39s", file);

            found = 0;
            for (i = 0; i < fileCount[u]; i++)
                if (strcmp(files[u][i], file) == 0)
                    found = 1;

            if (found)
                printf("File already exists.\n");
            else
            {
                strcpy(files[u][fileCount[u]++], file);
                printf("File created successfully.\n");
            }
        }
        else if (choice == 3)
        {
            printf("Enter username: ");
            scanf("%29s", user);
            u = findUser(user);

            if (u == -1)
                printf("User not found.\n");
            else
            {
                printf("Files belonging to %s:\n", user);
                for (i = 0; i < fileCount[u]; i++)
                    printf("%s\n", files[u][i]);

                if (fileCount[u] == 0)
                    printf("No files found.\n");
            }
        }
        else if (choice == 4)
            break;
        else
            printf("Invalid choice.\n");
    }

    return 0;
}
