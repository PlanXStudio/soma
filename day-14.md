# Intermediate Arrange
```sh
----------------------------------------
UART2
A10: Output
B12: Input (Internal Pull-Up, EXTI Rising/Falling Edge)
TIM3: 7200, 10000 --> 1sec
----------------------------------------
```

```c
#define POLLING
```

```c
/* TIM3 1sec(7200, 10000) */
#ifndef POLLING
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{ 
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10); 
}
#endif
```
```c
/* B12 EXTI_15_10 Rising/Falling Edge */
#ifndef POLLING
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_pin)
{ 
	if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) == GPIO_PIN_RESET)
    		HAL_UART_Transmit(&huart2, (uint8_t *)"0\r\n", 3, 0xFFFF); 
	else
    		HAL_UART_Transmit(&huart2, (uint8_t *)"1\r\n", 3, 0xFFFF); 
}
#endif
```
```c
main() 
{
  ...
#ifndef POLLING //TIM Interrupt
	/* Start Timer Interrupt */
	HAL_TIM_Base_Start_IT(&htim3) 
#endif
	while(1) {
#ifdef POLLING  
		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) == GPIO_PIN_RESET)
		    HAL_UART_Transmit(&huart2, (uint8_t *)"0\r\n", 3, 0xFFFF); 
		else
		    HAL_UART_Transmit(&huart2, (uint8_t *)"1\r\n", 3, 0xFFFF); 
		
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10), HAL_Delay(1000);
#endif
  ...
```
