#include <stdio.h>
#include <string.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee e;
    int choice, id;

    fp = fopen("employee.dat", "rb+");

    if (fp == NULL)
        fp = fopen("employee.dat", "wb+");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    while (1)
    {
        printf("\n1. Add employee\n");
        printf("2. Search employee by ID\n");
        printf("3. Display all employees\n");
        printf("4. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter ID, name and salary: ");
            scanf("%d %29s %f", &e.id, e.name, &e.salary);

            fseek(fp, 0, SEEK_SET);

            while (fread(&e, sizeof(e), 1, fp) == 1)
            {
                /* Scan existing records for duplicate IDs. */
                if (e.id == id)
                    break;
            }

            /* Read input again because e was used while scanning. */
            printf("Enter employee ID, name and salary again: ");
            scanf("%d %29s %f", &e.id, e.name, &e.salary);

            fseek(fp, 0, SEEK_END);
            fwrite(&e, sizeof(e), 1, fp);
            fflush(fp);

            printf("Employee record saved.\n");
        }
        else if (choice == 2)
        {
            printf("Enter employee ID: ");
            scanf("%d", &id);

            fseek(fp, 0, SEEK_SET);

            while (fread(&e, sizeof(e), 1, fp) == 1)
            {
                if (e.id == id)
                    break;
            }

            if (feof(fp))
                printf("Employee not found.\n");
            else
                printf("ID: %d Name: %s Salary: %.2f\n",
                       e.id, e.name, e.salary);
        }
        else if (choice == 3)
        {
            fseek(fp, 0, SEEK_SET);

            printf("\nID\tName\tSalary\n");

            while (fread(&e, sizeof(e), 1, fp) == 1)
                printf("%d\t%s\t%.2f\n",
                       e.id, e.name, e.salary);
        }
        else if (choice == 4)
            break;
        else
            printf("Invalid choice.\n");
    }

    fclose(fp);
    return 0;
}
