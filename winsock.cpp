#include <winsock2.h>
#include <iostream>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

int main() {
    WSADATA wsaData;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cout << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    std::cout << "Winsock initialized successfully. Status: " << wsaData.szSystemStatus << std::endl;

    // In a real application, you would create sockets, connect, send/receive data here.

    // Cleanup Winsock
    WSACleanup();
    std::cout << "Winsock cleaned up." << std::endl;

    return 0;
}
