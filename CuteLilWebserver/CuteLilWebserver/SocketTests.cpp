//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <stdio.h>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//#pragma comment(lib, "Ws2_32.lib")
//
//#define DEFAULT_PORT "27015"
//
//
//int serverInit(SOCKET &ClientSocket) {
//
//	WSADATA wsaData;
//
//	int iResult;
//
//	// Initialize Winsock
//	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (iResult != 0) {
//		printf("WSAStartup failed: %d\n", iResult);
//		return 1;
//	}
//
//#define DEFAULT_PORT "27015"
//
//	struct addrinfo *result = NULL, *ptr = NULL, hints;
//
//	ZeroMemory(&hints, sizeof (hints));
//	hints.ai_family = AF_INET;
//	hints.ai_socktype = SOCK_STREAM;
//	hints.ai_protocol = IPPROTO_TCP;
//	hints.ai_flags = AI_PASSIVE;
//
//	// Resolve the local address and port to be used by the server
//	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
//	if (iResult != 0) {
//		printf("getaddrinfo failed: %d\n", iResult);
//		WSACleanup();
//		return 1;
//	}
//
//	SOCKET ListenSocket = INVALID_SOCKET;
//	// Create a SOCKET for the server to listen for client connections
//	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
//
//	if (ListenSocket == INVALID_SOCKET) {
//		printf("Error at socket(): %ld\n", WSAGetLastError());
//		freeaddrinfo(result);
//		WSACleanup();
//		return 1;
//	}
//
//	// Setup the TCP listening socket
//	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
//	if (iResult == SOCKET_ERROR) {
//		printf("bind failed with error: %d\n", WSAGetLastError());
//		freeaddrinfo(result);
//		closesocket(ListenSocket);
//		WSACleanup();
//		return 1;
//	}
//	freeaddrinfo(result);
//
//	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
//		printf("Listen failed with error: %ld\n", WSAGetLastError());
//		closesocket(ListenSocket);
//		WSACleanup();
//		return 1;
//	}
//
//
//	//ClientSocket = INVALID_SOCKET;
//	// Accept a client socket
//	ClientSocket = accept(ListenSocket, NULL, NULL);
//	if (ClientSocket == INVALID_SOCKET) {
//		printf("accept failed: %d\n", WSAGetLastError());
//		closesocket(ListenSocket);
//		WSACleanup();
//		return 1;
//	}
//
//	return 0;
//}
//
//int serverConnection(SOCKET &ClientSocket) {
//#define DEFAULT_BUFLEN 512
//
//	char recvbuf[DEFAULT_BUFLEN];
//	int iResult, iSendResult;
//	int recvbuflen = DEFAULT_BUFLEN;
//
//	// Receive until the peer shuts down the connection
//	do {
//
//		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
//		if (iResult > 0) {
//			printf("Bytes received: %d\n", iResult);
//
//			// Echo the buffer back to the sender
//			iSendResult = send(ClientSocket, recvbuf, iResult, 0);
//			if (iSendResult == SOCKET_ERROR) {
//				printf("send failed: %d\n", WSAGetLastError());
//				closesocket(ClientSocket);
//				WSACleanup();
//				return 1;
//			}
//			printf("Bytes sent: %d\n", iSendResult);
//
//			//TODO this exits the loop
//			iResult = -1;
//		}
//		else if (iResult == 0)
//			printf("Connection closing...\n");
//		else {
//			printf("recv failed: %d\n", WSAGetLastError());
//			closesocket(ClientSocket);
//			WSACleanup();
//			return 1;
//		}
//
//	} while (iResult > 0);
//}
//
//int serverCloseConnection(SOCKET &ClientSocket) {
//	// shutdown the send half of the connection since no more data will be sent
//	int iResult = shutdown(ClientSocket, SD_SEND);
//	if (iResult == SOCKET_ERROR) {
//		printf("shutdown failed: %d\n", WSAGetLastError());
//		closesocket(ClientSocket);
//		WSACleanup();
//		return 1;
//	}
//
//	// cleanup
//	closesocket(ClientSocket);
//	WSACleanup();
//
//	return 0;
//}
//
//int NOmain() {
//	string s;
//	int error = 0;
//
//	SOCKET ClientSocket;
//	ClientSocket = INVALID_SOCKET;
//
//	error = serverInit(ClientSocket);
//	//if (error != 0)
//	//	return error;
//
//	error = serverConnection(ClientSocket);
//	//if (error != 0)
//	//	return error;
//
//	error = serverCloseConnection(ClientSocket);
//
//
//	cout << "DONE";
//
//	cin >> s ;
//	
//	return error;
//}