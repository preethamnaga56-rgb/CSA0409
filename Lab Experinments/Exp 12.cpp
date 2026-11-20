#include <stdio.h>
#include <windows.h>

#define N 5

HANDLE chopstick[N];
HANDLE room;

DWORD WINAPI philosopher(LPVOID arg)
{
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % N;
    int k;

    for (k = 0; k < 2; k++)
    {
        printf("Philosopher %d is thinking.\n", id + 1);

        WaitForSingleObject(room, INFINITE);
        WaitForSingleObject(chopstick[left], INFINITE);
        WaitForSingleObject(chopstick[right], INFINITE);

        printf("Philosopher %d is eating.\n", id + 1);
        Sleep(200);

        ReleaseSemaphore(chopstick[right], 1, NULL);
        ReleaseSemaphore(chopstick[left], 1, NULL);
        ReleaseSemaphore(room, 1, NULL);
    }

    return 0;
}

int main()
{
    HANDLE threads[N];
    int ids[N];
    int i;

    room = CreateSemaphore(NULL, 4, 4, NULL);

    for (i = 0; i < N; i++)
        chopstick[i] = CreateSemaphore(NULL, 1, 1, NULL);

    for (i = 0; i < N; i++)
    {
        ids[i] = i;
        threads[i] = CreateThread(
            NULL, 0, philosopher, &ids[i], 0, NULL);
    }

    WaitForMultipleObjects(N, threads, TRUE, INFINITE);

    for (i = 0; i < N; i++)
    {
        CloseHandle(threads[i]);
        CloseHandle(chopstick[i]);
    }

    CloseHandle(room);
    return 0;
}
