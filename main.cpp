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
    
    WSACleanup();
    
}
