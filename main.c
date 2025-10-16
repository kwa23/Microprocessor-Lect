#include "stm32f1xx_hal.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
  HAL_Init();                 // Inisialisasi HAL
  SystemClock_Config();      // Konfigurasi clock
  MX_GPIO_Init();            // Inisialisasi GPIO

  while (1)
  {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);  // Toggle LED di PA1
    HAL_Delay(500);                         // Delay 500ms
  }
}

void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();             // Aktifkan clock GPIOA

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // Output push-pull
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
