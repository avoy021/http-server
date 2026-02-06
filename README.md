# Winsock TCP/HTTP Server in C++

A low-level TCP server built from scratch using **Winsock (Windows Sockets API)** in **C++**, compiled with **MSVC**.
This project demonstrates how HTTP/TCP servers actually work under the hood without using any frameworks or libraries.

> No frameworks. Only raw Winsock.

---

## 🚀 What this project shows

This project demonstrates:

* How to initialize and use **Winsock 2.2**
* Creating and binding a **TCP socket**
* Listening for incoming connections
* Accepting client connections
* Extracting client IP and port using `getnameinfo`
* Receiving raw bytes from client using `recv`
* Sending data back using `send`
* Proper cleanup using `closesocket` and `WSACleanup`

This is the foundation on which real HTTP servers like **nginx**, **Apache**, and **Node.js** networking are built.

---

## 🧠 Concepts Covered

* TCP Socket Programming
* Client–Server Architecture
* IPv4 Addressing
* Port Binding
* Blocking I/O model
* Byte stream communication
* Echo server mechanism
* DNS/IP resolution
* Winsock lifecycle management

---

## 🛠️ Tech Stack

* C++
* Winsock2 (`ws2_32.lib`)
* MSVC Compiler
* Windows OS

---

## 📂 How it Works (Flow)

1. Initialize Winsock using `WSAStartup`
2. Create a TCP socket using `socket()`
3. Bind the socket to `0.0.0.0:8080`
4. Listen for connections using `listen()`
5. Accept a client using `accept()`
6. Print client IP and port
7. Receive data from client using `recv()`
8. Send the same data back using `send()` (Echo)
9. Close sockets and cleanup Winsock

---

## ▶️ How to Run

### Requirements

* Windows OS
* MSVC (Visual Studio / VS Code with C++ extension)

### Build

The linker must include the Winsock library:

```
ws2_32.lib
```

Or via pragma (already added in code):

```cpp
#pragma comment(lib, "ws2_32.lib")
```

### Compile & Run

Using MSVC Developer Command Prompt:

```
cl server.cpp
server.exe
```

Without MSVC:

g++ server.cpp -o server.exe -lws2_32

---

## 🧪 Testing the Server

Open another terminal and run:

```
telnet localhost 8080
```

Or use:

```
curl localhost:8080
```

Type anything — the server will echo the same bytes back.

---

## 📸 What happens when you connect?

When a client connects:

* Server prints client IP and port
* Waits for data
* Prints received data
* Sends the same data back
* Handles client disconnect

---

## ⚠️ Limitations (Intentional for learning)

This server:

* Handles only **one client**
* Uses **blocking I/O**
* Does not parse HTTP requests yet
* Does not support concurrency

These are left as future improvements.

---

## 🔮 Future Improvements

* Parse HTTP request headers
* Handle multiple clients 
* Serve static HTML files
* Implement basic HTTP response format
* Add logging
* Convert into a mini HTTP server

---



