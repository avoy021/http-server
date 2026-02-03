#include <iostream>
#include <ws2tcpip.h>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

void main() {
    WSADATA wsaData;
    WORD version = MAKEWORD(2,2);
    
    int wsOk = WSAStartup(version, &wsaData);
    if(wsOk != 0) {
        cout << "Winsock failed to start. Error: " << wsOk << endl;
        return;
    }

    //create a socket
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if(listening == INVALID_SOCKET) {
        cerr << "Invalid Socket!" << endl;
        return;
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
        return;
    }
    
    WSACleanup();

}
