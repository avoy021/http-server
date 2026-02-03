#include <iostream>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    WORD version = MAKEWORD(2,2);
    
    int wsOk = WSAStartup(version, &wsaData);
    if(wsOk != 0) {
        std::cout << "run" << std::endl;
        std::cout << "Winsock failed to start. Error: " << wsOk << std::endl;
        return 1;
    }

    std::cout << "Winsock started successfully!" << std::endl;

    WSACleanup();

    return 0;
}
