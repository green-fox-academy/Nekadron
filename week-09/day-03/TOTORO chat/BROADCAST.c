#define _WIN32_WINNT 0x0501
#define QUEUE_SIZE 1
#define BROADCAST_IP           "255.255.255.255"
#define BROADCAST_PORT         12345
#define BROADCAST_MSG_LEN    1024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#include "server.h"
#include "BROADCAST.h"

void handle_error2(const char *error_string)
{
	printf("Error: %s\nError code: %d\n", error_string, WSAGetLastError());
	WSACleanup();
	printf("Press any key to exit from the program...");
	while (!kbhit());
	exit(EXIT_FAILURE);
}

int send_broadcast_msg(char *msg, uint16_t dest_port)
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		printf("WSAStartup failed with error: %d\n", iResult);

	}

    // Creating the UDP socket
	SOCKET broadcast_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	// Check if socket is ok
	if (broadcast_socket < 0)
		handle_error("socket() ");

     //// Set the socket as broadcasting socket
    int set_ud = setsockopt(broadcast_socket, SOL_SOCKET, SO_BROADCAST, "1", 1);
    if (set_ud == SOCKET_ERROR) {
        printf("ERROR%u\n");
    }

	// Server address structure initialization
	struct sockaddr_in broadcast_addr;                                 // Inet address structure definition
	broadcast_addr.sin_family = AF_INET;                               // This address is an internet address
	broadcast_addr.sin_port = htons(BROADCAST_PORT);                      // Server port
	broadcast_addr.sin_addr.s_addr = inet_addr(BROADCAST_IP);             // Server IP
	//struct sockaddr *addr = (struct sockaddr *)&broadcast_addr;        // Make a struct sockaddr pointer, which points to the address stucture

	// Send broadcast message
	int sender = sendto(broadcast_socket, msg, strlen(msg), 0,
                        (SOCKADDR*)&broadcast_addr,
                        sizeof(broadcast_addr));
	if (sender < strlen(msg)) {
        printf("Error: send_broadcast_msg - sendto()\n");
        return -3;
	}

	// Close the broadcast socket
    closesocket(broadcast_socket);
    return 0;
}

void broadcast_listener()
{
	// Create listener socket
    SOCKET listen_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (listen_socket < 0) {
        printf("Error: broadcast_listener - socket()\n");
        return;
    }

	int set_ud = setsockopt(listen_socket, SOL_SOCKET, SO_BROADCAST, "1", 1);
    if (set_ud == SOCKET_ERROR) {
        printf("ERROR%u\n");
    }

	// Server recv address structure initialization
	struct sockaddr_in listen_addr;
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = INADDR_ANY;
	listen_addr.sin_port = htons(BROADCAST_PORT);

	// Start binding
	if (bind(listen_socket, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) < 0) {
        printf("Error: broadcast_listener - bind()\n");
        return;
	}

    struct sockaddr_in client_addr;

    while (1) {

        // recvfrom needs a pointer to the address size -.-
        int client_addr_len = sizeof(client_addr);

        // Define buffer for incoming message
        char buff[BROADCAST_MSG_LEN];

        // Receive broadcast data
        int received_bytes = recvfrom(listen_socket,
                                      buff,
                                      BROADCAST_MSG_LEN,
                                      0,
                                      (struct sockaddr*)&client_addr,
                                      &client_addr_len);

        // Check for error
        if (received_bytes < 0) {
            printf("Error: broadcast_listener - recfrom()\n");
        } else {
            // Close the string
            buff[received_bytes] = '\0';

            // Get client IP
            uint32_t client_ip = client_addr.sin_addr.s_addr;

            // Get data
            char unique_str[BROADCAST_UNIQUE_STR_LEN];
            unique_str[0] = '\0';
            int port;

            if (sscanf(buff, "%s %d", unique_str, &port) < 2) {
                printf("Error: broadcast_listener - sscanf()\n");
            } else if (strstr(BROADCAST_UNIQUE_STR, unique_str) == NULL) {
                printf("Error: broadcast_listener - unique string not found\n");
            } else {
                // Send our name and our message listening port
                //char buff[TCP_MSG_LEN];
                //printf(buff, "%s %u", my_usr_data.name, my_usr_data.port);
                //send_tcp_msg(buff, client_ip, port);
            }
        }
    }
}
