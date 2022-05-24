*app1*
```c
HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
HAL_Delay(500);
```

*app2*
```c
#include <stdio.h>
```

```c
int __io_putchar(int ch)
{
	if (ch == '\n') {
		HAL_UART_Transmit(&huart2, (uint8_t *)"\r", 1, 0xFFFF);
	}
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

	return ch;
}

uint32_t curr_time;

HAL_Delay(100);
curr_time = HAL_GetTick();
printf("curr_time = %d\n", curr_time);
```   

*app3*
```c
#include <stdio.h>
```

```c
int __io_getchar(void)
{
	uint8_t ch = 0;

	__HAL_UART_CLEAR_OREFLAG(&huart2);

	HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

	return ch;
}

uint32_t in[3];

setvbuf(stdin, NULL, _IONBF, 0);
scanf("%d %d %d",&in[0], &in[1], &in[2]);
printf("in[0] = %d, in[1] = %d, in[2] = %d\n", in[0], in[1], in[2]);
```

*app4*
```c
if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET){
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}
else {
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}
```

*app5*
```c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_13)
    {
    	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    }
}
```
