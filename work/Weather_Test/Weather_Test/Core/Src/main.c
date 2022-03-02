/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bmp280.h"
#include "EPD_Test.h"
#include "EPD_2in9_V2.h"
#include<stdio.h>
#include<string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define PULSE_TIME_MS 100
#define SAMPLE_UPDATE_TICK (uint16_t)((0.3)*(1000/PULSE_TIME_MS))
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint16_t ADC_Value[100];
uint8_t i;
double ad1;
int flag = 0;
char buf[200], buffer[100], aRxBuffer[100] = "";
int buf_length, buffer_length, length;
char *dir = "DIR";

#define BUFFER_SIZE 100 // 缂撳啿鍖哄ぇ�??????????????????????
uint8_t Receive_Buffer[100]; // 涓插彛鎺ユ敹缂撳啿锟??????????????
volatile uint16_t recv_end_flag = 0; // 涓插彛鎺ユ敹瀹屾垚鐨勬爣�??????????????????????
volatile uint8_t rx_length = 0; // 涓插彛鎺ユ敹鐨勬暟鎹殑�????????垮害
uint8_t speed_flag = 0, rain_flag = 0;
int output_flag = 1;
int j = 1;

volatile uint32_t wind_count = 0;
volatile uint32_t last_wind_count = 0;
volatile uint32_t rain_count = 0;
volatile uint32_t last_rain_count = 0;
extern double bmp_280_temperature;
extern double bmp_280_atmospressure;
volatile double speed = 0;

volatile uint16_t sample_cnt = SAMPLE_UPDATE_TICK;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
UBYTE *BlackImage;
int EPD_init(void)
{
    if(DEV_Module_Init()!=0){
        return -1;
    }

    printf("e-Paper Init and Clear...\r\n");
	EPD_2IN9_V2_Init();
    EPD_2IN9_V2_Clear();

    //Create a new image cache
    UWORD Imagesize = ((EPD_2IN9_V2_WIDTH % 8 == 0)? (EPD_2IN9_V2_WIDTH / 8 ): (EPD_2IN9_V2_WIDTH / 8 + 1)) * EPD_2IN9_V2_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN9_V2_WIDTH, EPD_2IN9_V2_HEIGHT, 90, WHITE);
	Paint_Clear(WHITE);

    Paint_NewImage(BlackImage, EPD_2IN9_V2_WIDTH, EPD_2IN9_V2_HEIGHT, 90, WHITE);
    printf("show image for array\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    Paint_DrawBitMap(gImage_2in9);

    EPD_2IN9_V2_Display(BlackImage);
    DEV_Delay_ms(3000);
	Paint_NewImage(BlackImage, EPD_2IN9_V2_WIDTH, EPD_2IN9_V2_HEIGHT, 90, WHITE);
    printf("Drawing\r\n");
    return 0;
}


int EPD_write(float wind_speed,char* wind_direction, float rain_fall, float temp, float humi, float air_pressure)
{
    char tem[50];
    //1.Select Image
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    // 2.Drawing on the image
    printf("Drawing:BlackImage\r\n");


    Paint_DrawString_EN(0, 0,"windspeed(m/s):", &Font20, WHITE, BLACK);
    sprintf(tem,"%.2f",wind_speed);
    Paint_DrawString_EN(205, 0,tem, &Font20, WHITE, BLACK);

    Paint_DrawString_EN(0, 20, "wind direction:", &Font20, WHITE, BLACK);
    Paint_DrawString_EN(210, 20, wind_direction, &Font20, WHITE, BLACK);

    Paint_DrawString_EN(0, 40,"rainfall(mm):", &Font20, WHITE, BLACK);
    sprintf(tem,"%.2f",rain_fall);
    Paint_DrawString_EN(180, 40,tem, &Font20, WHITE, BLACK);

    Paint_DrawString_EN(0, 60, "temperature(c):", &Font20, WHITE, BLACK);
    sprintf(tem,"%.2f",temp);
    Paint_DrawString_EN(210, 60,tem, &Font20, WHITE, BLACK);

    Paint_DrawString_EN(0, 80,"humidity:", &Font20, WHITE, BLACK);
    sprintf(tem,"%.2f",humi);
    Paint_DrawString_EN(120, 80,tem, &Font20, WHITE, BLACK);

    Paint_DrawString_EN(0, 100, "air pres(hPa):", &Font20, WHITE, BLACK);
    sprintf(tem,"%.0f",air_pressure);
    Paint_DrawString_EN(200, 100,tem, &Font20, WHITE, BLACK);


    EPD_2IN9_V2_Display_Base(BlackImage);
    DEV_Delay_ms(3000);
    return 0;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

	__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE); // �??????????????????????鍚覆鍙ｇ┖闂蹭腑锟??????????????
	HAL_ADC_Start_DMA((ADC_HandleTypeDef*)&hadc1, (uint32_t*)ADC_Value, (uint32_t)10); //通道�??1
	bmp280_init();

	HAL_ADC_Start_DMA(&hadc1, &ADC_Value, 100);
	HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"AT+RST\r\n", 8);
	HAL_Delay(3);
	HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"AT+CWMODE=1\r\n", 13);
	HAL_Delay(3);
	HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"AT+CWJAP=\"zjn\",\"13536712286\"\r\n", 31);
	HAL_Delay(3);
	EPD_init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int i;
  while (1)
  {
    /* USER CODE END WHILE */
	  ad1 = 0;
    /* USER CODE BEGIN 3 */
	bmp280_getTemperature();
	bmp280_getAtmosPressure();
	for(i = 0; i < 100; i++)
		ad1 += ADC_Value[i];
	int tmp = (int)ad1/100;
	switch(tmp)
	{
	case 402:case 401:dir = "W"; break;
	case 199:case 400:dir = "WN"; break;
	case 398:dir = "N"; break;
	case 369:case 368:dir = "S"; break;
	case 295:case 296:case 297:case 298:dir = "E"; break;
	case 385:dir = "EN"; break;
	case 394:dir = "WS"; break;
	case 345:case 346:dir = "ES"; break;
	};
	if(wind_count - last_wind_count >= 0.000001)
	{
		speed = (wind_count - last_wind_count) * 0.34;
	}
	else
	{
		speed = 0;
	}
	buf_length = sprintf(buf, "temperature:%.2f 'C; QNH :%.2fhPa; Wind_Direction: %s; Wind_Speed: %.2f m/s; Rain_Count: %.2f mm; \r\n", bmp_280_temperature, bmp_280_atmospressure / 100,dir, speed, rain_count * 0.33);
	last_wind_count = wind_count;
	EPD_write(speed,dir,rain_count * 0.33,bmp_280_temperature, 0,bmp_280_atmospressure / 100);
	HAL_Delay(100);
	if(output_flag == 1)
	{
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"AT+CIPSTART=\"TCP\",\"quan.suning.com\",80\r\n", 40);
		HAL_Delay(100);
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"AT+CIPSEND=44\r\n", 15);
		HAL_Delay(100);
		HAL_UART_Receive_DMA(&huart1, Receive_Buffer, BUFFER_SIZE);
		HAL_Delay(1000);
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"GET http://quan.suning.com/getSysTime.do\r\n", 44);
		if(recv_end_flag == 1)
		{
			char* addr = strstr(Receive_Buffer, "\"sysTime1\"");
			if(addr != NULL)
			{
				for(int k = 0; k < strlen(addr); k++)
				{
					if(addr[k] == '}')
					{
						addr[k] = '\0';
						break;
					}
				}
				length = sprintf(aRxBuffer, "%s\r\n", addr);
			}
			else
			{
				length = 1;
			}
			for(int i = 0; i < rx_length ; i++) //清空接收缓存�??
							Receive_Buffer[i]=0;
		}


		HAL_Delay(500);
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"AT+CIPSTART=\"TCP\",\"192.168.43.47\",12345\r\n", 41);
		HAL_Delay(100);
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"AT+CWMODE=1\r\n", 13);
		HAL_Delay(100);
		buffer_length = sprintf(buffer, "AT+CIPSEND=%d\r\n", length);
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)buffer, buffer_length);
		HAL_Delay(1000);
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)aRxBuffer, length);
		HAL_Delay(1000);
		buffer_length = sprintf(buffer, "AT+CIPSEND=%d\r\n", buf_length);
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)buffer, buffer_length);
		HAL_Delay(1000);
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)buf, buf_length);
		HAL_Delay(1000);
		HAL_UART_Transmit_DMA(&huart1, (uint8_t*)"AT+CIPCLOSE\r\n", 13);
		HAL_Delay(100);
		output_flag = 0;
	}
	j--;
	if(j <= 0)
	{
		output_flag = 1;
		j = 1;
	}
	HAL_Delay(PULSE_TIME_MS);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO, RCC_MCO1SOURCE_PLLCLK, RCC_MCODIV_1);
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
