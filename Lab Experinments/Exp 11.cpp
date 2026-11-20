#include <stdio.h>
#include <windows.h>

DWORD WINAPI threadFunction(LPVOID arg)
{
    int id = *(int *)arg;
    int i;

    for (i = 1; i <= 5; i++)
    {
        printf("Thread %d: Count = %d\n", id, i);
        Sleep(100);
    }

    return 0;
}

int main()
{
    HANDLE t1, t2;
    int id1 = 1, id2 = 2;

    t1 = CreateThread(NULL, 0, threadFunction, &id1, 0, NULL);
    t2 = CreateThread(NULL, 0, threadFunction, &id2, 0, NULL);

    if (t1 == NULL || t2 == NULL)
    {
        printf("Thread creation failed.\n");
        return 1;
    }

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);

    printf("Both threads completed.\n");
    return 0;
}
