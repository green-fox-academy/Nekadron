/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "stm32f7xx_hal_adc.h"
#include "stm32f7xx_hal_adc_ex.h"

struct row_and_col {
	GPIO_TypeDef * letter;
	uint16_t number;
};

struct row_and_col data[] = {
		//sorok sorrendben
	{GPIOG, GPIO_PIN_7},
	{GPIOH, GPIO_PIN_6},
	{GPIOB, GPIO_PIN_4},
	{GPIOI, GPIO_PIN_0},
	{GPIOG, GPIO_PIN_6},
	{GPIOC, GPIO_PIN_7},
	{GPIOC, GPIO_PIN_6},
	//oszlopok balról jobbra
	{GPIOI, GPIO_PIN_2},
	{GPIOB, GPIO_PIN_15},
	{GPIOA, GPIO_PIN_8},
	{GPIOI, GPIO_PIN_3},
	{GPIOA, GPIO_PIN_15},
};
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

osMessageQId StorageEvent;
/* Create Storage Message Queue */
 osMessageQDef(osqueue, 1, uint16_t);

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_ch_conf;
GPIO_InitTypeDef led_matr;
uint16_t ref;

//void adc_init();
//uint16_t adc_measure();
// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);

// Mutex global variable
osMutexId led_matrix_mutex_id;

/* Private function prototypes -----------------------------------------------*/
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);
/* Private functions ---------------------------------------------------------*/

void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{
	// 1 A0 PA0 ADC3_IN0
	__HAL_RCC_ADC3_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Pin = GPIO_PIN_0;
	GPIO_Init.Speed = GPIO_SPEED_FAST;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOA, &GPIO_Init);
}

uint16_t adc_measure()
{
	HAL_ADC_Start(&adc_handle);
	HAL_ADC_PollForConversion(&adc_handle, HAL_MAX_DELAY);
	return HAL_ADC_GetValue(&adc_handle);
}
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
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);	// pin D0 - 7-es sor

	led_matr.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOC, &led_matr);
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);	// pin D1 - 2-es sor

	led_matr.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOG, &led_matr);
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);	// pin D2 - 1-es sor

	led_matr.Pin = GPIO_PIN_4;
	HAL_GPIO_Init(GPIOB, &led_matr);
	//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);	// pin D3 - 8-as sor

	led_matr.Pin = GPIO_PIN_7;
	HAL_GPIO_Init(GPIOG, &led_matr);
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);	// pin D4 - 9-es sor

	led_matr.Pin = GPIO_PIN_0;
	HAL_GPIO_Init(GPIOI, &led_matr);
	//HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0, GPIO_PIN_RESET);	// pin D5 - 12-es sor

	led_matr.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOH, &led_matr);
	//HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET);	// pin D6 - 14-es sor

	led_matr.Pin = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOI, &led_matr);
	//HAL_GPIO_WritePin(GPIOI, GPIO_PIN_3, GPIO_PIN_RESET);	// pin D7 - 10-es oszlop

	led_matr.Pin = GPIO_PIN_2;
	HAL_GPIO_Init(GPIOI, &led_matr);
	//HAL_GPIO_WritePin(GPIOI, GPIO_PIN_2, GPIO_PIN_RESET);	// pin D8 - 13-as oszlop

	led_matr.Pin = GPIO_PIN_15;
	HAL_GPIO_Init(GPIOA, &led_matr);
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);	// pin D9 - 6-os oszlop

	led_matr.Pin = GPIO_PIN_8;
	HAL_GPIO_Init(GPIOA, &led_matr);
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);	// pin D10 - 4-es oszlop

	led_matr.Pin = GPIO_PIN_15;
	HAL_GPIO_Init(GPIOB, &led_matr);
	//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);	// pin D11 - 3-as oszlop

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF
	led_matrix_mutex_id = osMutexCreate (osMutex(LED_MATRIX_MUTEX_DEF));
	LCD_UsrLog("led_matrix - initialized\n");

	for (int c = 0; c < LED_MATRIX_ROWS; c++) {
		HAL_GPIO_WritePin (data[c].letter, data[c].number, GPIO_PIN_SET);
	}

	// Infinite loop
	while (1) {
		/*GPIO_PinState led_matrix_state2[7][5] = {
		           {1, 1, 1, 1, 1} ,
		           {1, 0, 1, 1, 1} ,
		           {1, 0, 1, 1, 0} ,
		           {1, 0, 1, 1, 1} ,
		           {1, 0, 1, 1, 0} ,
		           {1, 0, 1, 1, 1} ,
		           {1, 1, 1, 1, 1}
		        };
		        memcpy(&led_matrix_state, &led_matrix_state2, sizeof(led_matrix_state2));*/
		// TODO:
		// Implement the led matrix updater functionality
		// Step 1:
		// Iterate through every column or row
		for (int i = 7; i < LED_MATRIX_COLS + 7; i++) {


			// Step 2:
			// Wait for the mutex
			osMutexWait(led_matrix_mutex_id, osWaitForever);

			// Step 3:
			// Turn on the column or row
			HAL_GPIO_WritePin (data[i].letter, data[i].number, GPIO_PIN_SET);	//elsõ oszlop

			// Step 4:
			// Turn on the leds in that column or row
			for (int j = 0; j < LED_MATRIX_ROWS; j++) {
				HAL_GPIO_WritePin (data[j].letter, data[j].number, GPIO_PIN_RESET);
				osDelay(5);
				HAL_GPIO_WritePin (data[j].letter, data[j].number, GPIO_PIN_SET);
			}
			/*HAL_GPIO_WritePin(data[0].letter, data[0].number, led_matrix_state[0][i]);
			HAL_GPIO_WritePin(data[1].letter, data[1].number, led_matrix_state[1][i]);
			HAL_GPIO_WritePin(data[2].letter, data[2].number, led_matrix_state[2][i]);
			HAL_GPIO_WritePin(data[3].letter, data[3].number, led_matrix_state[3][i]);
			HAL_GPIO_WritePin(data[4].letter, data[4].number, led_matrix_state[4][i]);
			HAL_GPIO_WritePin(data[5].letter, data[5].number, led_matrix_state[5][i]);
			HAL_GPIO_WritePin(data[6].letter, data[6].number, led_matrix_state[6][i]);*/

			// Step 5:
			// Release the mutex
			osMutexRelease(led_matrix_mutex_id);

			// Step 6:
			// Delay
			osDelay(5);

			// Step 7:
			// Turn off the column or row
			HAL_GPIO_WritePin (data[i].letter, data[i].number, GPIO_PIN_RESET);	//elsõ oszlop
		}
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
	}
}

void ADC_Init_thread(void const *argument)
{
	HAL_ADC_MspInit(&adc_handle);

	adc_handle.State = HAL_ADC_STATE_RESET;
	adc_handle.Instance = ADC3;
	adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	adc_handle.Init.Resolution = ADC_RESOLUTION_12B;
	adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
	adc_handle.Init.DMAContinuousRequests = DISABLE;
	adc_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	adc_handle.Init.ContinuousConvMode = DISABLE;
	adc_handle.Init.DiscontinuousConvMode = DISABLE;
	adc_handle.Init.ScanConvMode = DISABLE;
	HAL_ADC_Init(&adc_handle);

	adc_ch_conf.Channel = ADC_CHANNEL_0;
	adc_ch_conf.Offset = 0;
	adc_ch_conf.Rank = 1;
	adc_ch_conf.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_ch_conf);

	//adc_measure();

	while (1) {
		ref = adc_measure() / 50;
		printf("Led Speed: %d\n", ref);
		StorageEvent = osMessageCreate (osMessageQ(osqueue), NULL);
		if (osMessagePut(StorageEvent, ref, osWaitForever) != 0)
			printf("Macilaci\n");
		osDelay(30);
	}
}

// This thread is a waterfall type animation
void led_matrix_waterfall_thread(void const *argument)
{
	osEvent event;
	while (1) {
		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
				event = osMessageGet(StorageEvent, osWaitForever);
				printf("event.value.v");
				led_matrix_set(r, c, 1);
				osDelay(500);
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
