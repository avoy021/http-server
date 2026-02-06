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

    // check client info: getnameinfo() for dns(or ip),port
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    ZeroMemory(host, NI_MAXHOST);
    ZeroMemory(service, NI_MAXSERV);

    if(getnameinfo((sockaddr *)&client, clientSize, host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        cout << host << " port: " << service << endl;
    }
    else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " port: " << ntohs(client.sin_port) << endl;
    }

    // close listening socket
    closesocket(listening);

    // Echo Server: receive data from client and send it back
    char buf[4096];
    while(true) {
        ZeroMemory(buf, 4096);
        // wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if(bytesReceived == SOCKET_ERROR) {
            cerr << "Error in recv(): Quitting" << endl;
            break;
        }

        if(bytesReceived == 0) {
            cout << "Client disconnected" << endl;
            break;
        }
        // print the data
        cout << "Received: " << string(buf, 0, bytesReceived) << endl;
        // send message to client
        send(clientSocket, buf, bytesReceived+1, 0);
    }

    // close socket
    closesocket(clientSocket);

    //cleanup winsock
    WSACleanup();

    return 0;
}
