# 용어 정리
- FSMC (Flexible static memory controller)  
- SDIO (Secure digital input/output interface)  
- AMBA (Advanced Microcontroller Bus Architecture)  
  - AHB (Advanced High Performance Bus)  
  - ASB (Advanced System Bus)  
  - APB (Advanced Peripheral Bus)  
- GPIO (general-purpose input/output)  
- EXTI (External Interrupt)  
- USART (Universal Synchronous/Asynchronous Receiver Transmitter)   
- TIM (Timer/Counter)  
- DMA (Direct Memory Access)
- FLITF (Flash memory interface)
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
