#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

#include <iostream>

// "Receiver" side

int main() {
	// set up WSA
	WSADATA WSA;
	// create a buffer
	char buffer[24];
	// initialize variable to store doubles received
	double value;
	// create a socket
	SOCKET Socket;
	// create the address which we want to receive packets from
	sockaddr_in serverAddress;

	int serverLen = sizeof(serverAddress);
	// initialize WSA
	if (WSAStartup(MAKEWORD(2, 2), &WSA) != 0) {
		cout << "STARTUP FAILED: " << endl;
	}
	// fill in the address attributes
	serverAddress.sin_family = AF_INET;
	InetPton(AF_INET, "8.8.8.8", &serverAddress.sin_addr.S_un.S_addr);
	serverAddress.sin_port = htons(25000);
	// set up the socket
	Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	// bind the socket to the address
	int bind = ::bind(Socket, (SOCKADDR*)& serverAddress, sizeof(serverAddress));
 
	while(true){
		// receive the packets into the buffer
		int receivefrom = ::recvfrom(Socket, buffer, 24, 0, (SOCKADDR*)& serverAddress, &serverLen);
		if (receivefrom == SOCKET_ERROR) {
			cout << "Receiving Data Failed & Error -> " << WSAGetLastError() << endl;
		}
		// convert the bytes to doubles 
		for (int i = 0; i < 24; i = i + 8) {
			memcpy(&value, &buffer[i], 8);
			cout << value << endl; 
		}
	}
	// close socket and clean up 
	int closeSocket = closesocket(Socket);
	int WSAcleanup = WSACleanup();
}