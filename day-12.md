# GPIO Loop back
* C8(OUT) <---Jumper Cable --> C6(IN)
* global
```c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if ( HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET ) {
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
  }
}
```
* main()
```c
  while (1)
  {
	  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) == GPIO_PIN_SET) {
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	  }
	  HAL_Delay(1);
  }
```
