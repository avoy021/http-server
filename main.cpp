#include <iostream>
#include <ws2tcpip.h>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    WORD version = MAKEWORD(2,2);
    
    int wsOk = WSAStartup(version, &wsaData);
    if(wsOk != 0) {
        cout << "Winsock failed to start. Error: " << wsOk << endl;
        return 1;
    }

    // create a socket
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if(listening == INVALID_SOCKET) {
        cerr << "Invalid Socket!" << endl;
        return 1;
    }

    // bind ip address and port to the socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;           // IPv4
    hint.sin_port = htons(8080);         // The Port (8080)
    hint.sin_addr.S_un.S_addr = INADDR_ANY; // Any IP address on this machine

    int bindResult = bind(listening, (sockaddr *)&hint, sizeof(hint));
    if(bindResult == SOCKET_ERROR) {
        cerr << "Bind failed! Error: " << WSAGetLastError() << endl;
        closesocket(listening);
        return 1;
    }

    // tell winsock the socket is for listening
    listen(listening, SOMAXCONN);
    
    // Wait for connections
    sockaddr_in client;
    int clientSize = sizeof(client);
    
    SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
    if(clientSocket == INVALID_SOCKET) {
        cerr << "Client Socket is Invalid" << endl;
    }
    
    WSACleanup();
    return 0;
}
