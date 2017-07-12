/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef led_matr;
// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);

// Mutex global variable
osMutexId led_matrix_mutex_id;

/* Private function prototypes -----------------------------------------------*/
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);
/* Private functions ---------------------------------------------------------*/

// TODO:
// Write this function!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state) {
	// TODO:
	// Wait for the mutex
	osMutexWait(led_matrix_mutex_id, osWaitForever);

	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!
	if (state) {
		led_matrix_state[row][col] = GPIO_PIN_RESET;	// Ez a lehúzó = 0.
	} else {
		led_matrix_state[row][col] = GPIO_PIN_SET;	// Ez a felhúzó = 1.
	}

	// TODO:
	// Release the mutex
	osMutexRelease(led_matrix_mutex_id);
}

// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();

	led_matr.Pin = GPIO_PIN_7;
	led_matr.Mode = GPIO_MODE_OUTPUT_PP;
	led_matr.Pull = GPIO_NOPULL;
	led_matr.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &led_matr);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);	// pin D0 - 7-es sor

	led_matr.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOC, &led_matr);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);	// pin D1 - 2-es sor

	led_matr.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOG, &led_matr);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);	// pin D2 - 1-es sor

	led_matr.Pin = GPIO_PIN_4;
	HAL_GPIO_Init(GPIOB, &led_matr);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);	// pin D3 - 8-as sor

	led_matr.Pin = GPIO_PIN_7;
	HAL_GPIO_Init(GPIOG, &led_matr);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);	// pin D4 - 9-es oszlop

	led_matr.Pin = GPIO_PIN_0;
	HAL_GPIO_Init(GPIOI, &led_matr);
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);	// pin D5 - 12-es sor

	led_matr.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOH, &led_matr);
	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);	// pin D6 - 14-es sor

	led_matr.Pin = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOI, &led_matr);
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_RESET);	// pin D7 - 10-es oszlop

	led_matr.Pin = GPIO_PIN_2;
	HAL_GPIO_Init(GPIOA, &led_matr);
	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_RESET);	// pin D8 - 13-as oszlop

	led_matr.Pin = GPIO_PIN_15;
	HAL_GPIO_Init(GPIOA, &led_matr);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);	// pin D9 - 6-os oszlop

	led_matr.Pin = GPIO_PIN_8;
	HAL_GPIO_Init(GPIOA, &led_matr);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);	// pin D10 - 4-es oszlop

	led_matr.Pin = GPIO_PIN_15;
	HAL_GPIO_Init(GPIOB, &led_matr);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);	// pin D11 - 3-as oszlop

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF
	led_matrix_mutex_id = osMutexCreate (osMutex(LED_MATRIX_MUTEX_DEF));
	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);	// pin D11 - 3-as oszlop
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_SET);	// pin D4 - 9-es oszlop
		HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET);	// pin D6 - 14-es sor
		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_SET);	// pin D5 - 12-es sor
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);	// pin D2 - 1-es sor
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);	// pin D0 - 7-es sor
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);	// pin D1 - 2-es sor



		// Step 1:
		// Iterate through every column or row
		for (int i = 0; i < LED_MATRIX_COLS; i++) {

			// Step 2:
			// Wait for the mutex
		osMutexWait(led_matrix_mutex_id, osWaitForever);

			// Step 3:
			// Turn on the column or row


			// Step 4:
			// Turn on the leds in that column or row
		for (int j = 0; j < LED_MATRIX_ROWS; j++) {

		}

			// Step 5:
			// Release the mutex


			// Step 6:
			// Delay


			// Step 7:
			// Turn off the column or row
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
	}
}

// This thread is a waterfall type animation
void led_matrix_waterfall_thread(void const *argument)
{
	while (1) {
		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
				led_matrix_set(r, c, 1);
				osDelay(50);
				led_matrix_set(r, c, 0);
			}
		}
	}

	while (1) {
		LCD_ErrLog("led_matrix_waterfall - terminating...\n");
		osThreadTerminate(NULL);
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
