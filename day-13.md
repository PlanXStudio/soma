# 용어 정리
- AMBA (Advanced Microcontroller Bus Architecture)  
  - AHB (Advanced High Performance Bus)  
  - ASB (Advanced System Bus)  
  - APB (Advanced Peripheral Bus)  
- FSMC (Flexible static memory controller)  
- FLITF (Flash memory interface)
- SDIO (Secure digital input/output interface)  
- DMA (Direct Memory Access)
- GPIO (general-purpose input/output)  
- EXTI (External Interrupt)  
- USART (Universal Synchronous/Asynchronous Receiver Transmitter)   
- TIM (Timer/Counter)  
- PWM (Pulse Width Modulation)  
- ADC (Analog-to-digital converter)  
- I2C (Inter-Integrated Circuit)  
- SPI (Serial Peripheral Interface)
- CAN (Controller Area Network)

# 타이머
```text
*HSE*
72MHz
--------------------------------
*TIM3*
Clock Source: Internal Clock
Prescaler: 7200-1
Counter Period: 10000-1
--------------------------------
*NVIC*
TIM3: global interrupt 
</p>
--------------------------------
```
*코드*
```c
/* __weak */ void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

void main() 
{
  ...
  HAL_TIM_Base_Start_IT(&htim3)
  ...
    while() {
        ...
}
```
