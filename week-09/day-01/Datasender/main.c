#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
// Create a Client Applications that send messages.

int main(int argc, char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char server_reply[2000];
    int recv_size;
    char buffer[1000];

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
        printf("Could not create socket : %d" , WSAGetLastError());

    printf("Socket created.\n");

    server.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(30000);

    //Connect to remote server
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("connect error\n");
        return 1;
    }
    puts("Connected\n");

    //Send some data
    gets(&buffer);
    if( send(s , buffer , strlen(buffer) , 0) < 0) {
        puts("Send failed\n");
        return 1;
    }
    puts("Data Send\n");

    //Receive a reply from the server
    if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR) {
        puts("recv failed\n");
    }

    puts("Reply received\n");

    //Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    puts(server_reply);

    closesocket(s);
    WSACleanup();

    return 0;
}

