
#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;

int main()
{
    const char* message = "Hello, shared memory!";

    // Create a shared memory area
    HANDLE hMapFile = CreateFileMappingA(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "Local\\MySharedMemory"
    );

    if (hMapFile == NULL)
    {
        cout << "Error creating shared memory." << endl;
        return 1;
    }

    // Access the shared memory
    char* shm_ptr = (char*)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        1024
    );

    if (shm_ptr == NULL)
    {
        cout << "Error accessing shared memory." << endl;
        CloseHandle(hMapFile);
        return 1;
    }

    // Write data into shared memory
    strcpy(shm_ptr, message);

    // Display the stored data
    cout << "Data written to shared memory: "
         << shm_ptr << endl;

    // Release the shared memory view
    UnmapViewOfFile(shm_ptr);

    // Close the shared memory handle
    CloseHandle(hMapFile);

    return 0;
}

