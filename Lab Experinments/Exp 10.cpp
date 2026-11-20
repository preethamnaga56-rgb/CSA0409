
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> messageQueue;
    string message = "Hello, message queue!";

    // Producer: Send a message
    messageQueue.push(message);

    cout << "Producer: Data sent to message queue: "
         << message << endl;

    // Consumer: Receive a message
    if (!messageQueue.empty())
    {
        string receivedMessage = messageQueue.front();
        messageQueue.pop();

        cout << "Consumer: Data received from message queue: "
             << receivedMessage << endl;
    }

    return 0;
}

