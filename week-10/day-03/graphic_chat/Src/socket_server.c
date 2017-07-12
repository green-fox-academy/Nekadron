/* Includes ------------------------------------------------------------------*/
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>

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
	// Server address structure initialization
		struct sockaddr_in addr_in;                                 // Inet address structure definition
		addr_in.sin_family = AF_INET;                               // This address is an internet address
		addr_in.sin_port = htons(54545);                      // Server port
		addr_in.sin_addr.s_addr = INADDR_ANY;             // Server IP
		struct sockaddr *addr = (struct sockaddr *)&addr_in;        // Make a struct sockaddr pointer, which points to the address stucture

		// Creating the socket
		int master_sock = socket(AF_INET, SOCK_STREAM, 0);
		// Check if socket is ok
		if (master_sock < 0)
			LCD_ErrLog("socket() ");

		// Start binding the socket to the previously set address
		int flag = bind(master_sock, addr, sizeof(*addr));
		// Check if the binding is ok
		if (flag < 0)
			LCD_ErrLog("bind() ");

		// Start listening on with the set socket with a predefined queue size
		flag = listen(master_sock, 100);

		// Check is listening is ok
		if (flag < 0)
			LCD_ErrLog("listen() ");

		// Create variables which will be used in the while loop
		struct sockaddr client_addr;    // Client address structure
		int slave_sock;              // Slave socket definition, this will be used to store the incoming socket
		//char buff[DATA_BUFFER_SIZE];                // Buffer for incoming and outgoing data
		//int cntr = 1;                   // Counter for incoming connections
		while (1) {
			// Accept the connection and save the incoming socket
			slave_sock = accept(master_sock, &client_addr, NULL);

			// Check if the socket is valid
			if (slave_sock < 0)
				LCD_ErrLog("accept()");

			LCD_UsrLog("connection accepted\n");

			// Receive the data sent by the client
			int received_bytes;
			BSP_LCD_Clear(LCD_COLOR_BLUE);
			TS_StateTypeDef touch_scr;
			do {
				received_bytes = recv(slave_sock, &touch_scr, sizeof(TS_StateTypeDef), 0);
				if (received_bytes > 0) {
					BSP_LCD_SetTextColor(0xFFFFFFFF);
					BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 10);
					osDelay(5);
					/*if (BSP_PB_GetState(BUTTON_KEY) == 1)
						BSP_LCD_Clear(LCD_COLOR_BLUE);*/

				} else if (received_bytes < 0) {
					LCD_UsrLog("Something went wrong with the client socket, trying to close it...\n");
					break;
				}
			} while (received_bytes > 0);

			closesocket(slave_sock);
			LCD_UsrLog("client socket closed\n\n");
		}
		//ButtonMode_TypeDef(LCD)
		// Cleaning up used memory
		LCD_UsrLog("Closing server socket\n");
		closesocket(master_sock);
		LCD_UsrLog("Cleaning up WSA\n");
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
