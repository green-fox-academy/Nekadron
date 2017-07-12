/* Includes ------------------------------------------------------------------*/

#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "string.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

// TODO:
// Implement this function!
void socket_server_thread(void const *argument)
{
	// Creating client TCP IP socket
		int server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);
		if (server_socket < 0) {
	        printf("Error: send_tcp_msg - socket()\n");

		}

		// Creating server address
		struct sockaddr_in server_addr;
		server_addr.sin_family = AF_INET;
		server_addr.sin_port = htons(54545);
		server_addr.sin_addr.s_addr = inet_addr("10.27.6.61");

		// Connecting the client socket to the server
		int connect_retval = connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
		if (connect_retval < 0) {
	        printf("Error: send_tcp_msg - connect()\n");

		}

	    // Send the message to the servers
		char msg[100];
		int sent_bytes = send(server_socket, msg, strlen(msg), 0);
		if (sent_bytes < strlen(msg)) {
	        printf("Error: send_tcp_msg - send()\n");

		}

		// Close socket
		closesocket(server_socket);

		// Create listener socket
		    int listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
		    if (listen_socket < 0) {
		        printf("Error: msg_listener - socket()\n");
		        return;
		    }

		    // Server listen address structure initialization
			struct sockaddr_in listen_addr;
			listen_addr.sin_family = AF_INET;
			listen_addr.sin_addr.s_addr = inet_addr("10.27.6.61");
			listen_addr.sin_port = htons(54545);

			// Bind the listen address to the socket
			if (bind(listen_socket, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) < 0) {
		        printf("Error: msg_listener - bind()\n");
		        return;
			}

		    // Start listening on with the set socket with a predefined queue size
			if (listen(listen_socket, 100) < 0) {
		        printf("Error: msg_listener - listen()\n");
		        return;
			}

		    // printf("msg_listener initialized\n");

		    struct sockaddr_in client_addr;
		    int client_addr_len = sizeof(client_addr);
		    int client_socket;
		    while (1) {
		        //printf("msg_listener - Waiting for connection...\n");
		        // Accept incoming connections
		         client_socket = accept(listen_socket, (struct sockaddr*)&client_addr, NULL);
		         //slave_sock = accept(master_sock, &client_addr, NULL);
		        if (client_socket == 0) {
		            printf("Error: msg_listener - accept()\n");
		        } else {
		            // Define buffer for incoming message
		            char buff[4095];
		            // Receive broadcast data
		            int received_bytes = recv(client_socket, buff, 4095, 0);
		            // Check for error
		            if (received_bytes < 0) {
		                printf("Error: msg_listener - recv()\n");
		            } else {
		                // Close the string
		                buff[received_bytes] = '\0';

		                // Get client IP
		                uint32_t client_ip = client_addr.sin_addr.s_addr;

		                // Print client name
		                //printf("%d: ", get_usr_name(client_ip));
		                // Print the message
		                printf("%s\n", buff);
		            }
		            closesocket(client_socket);
		        }
		    }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
