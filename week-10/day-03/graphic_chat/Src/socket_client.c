/* Includes ------------------------------------------------------------------*/
#include "socket_client.h"
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
void socket_client_thread(void const *argument)
{
	while (1) {
		if (BSP_PB_GetState(BUTTON_KEY) == 1) {
			BSP_LCD_Clear(LCD_COLOR_BLUE);
			osDelay(1000);
		}
		osDelay(100);
	}

	while (1) {
	    /* Delete the Init Thread */
	    osThreadTerminate(NULL);
    }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
