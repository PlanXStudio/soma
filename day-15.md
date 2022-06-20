## 1. MOS

```c
const char *mos_table[] = { /* A ~ Z */
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
```
```c
void mos(char ch, int dot /*ms*/) 
{
	const char *mos_str_p = mos_table[ch - 'A'];

	int len = strlen(mos_str_p);
	for (int i = 0; i < len; i++) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		if (mos_str_p[i] == '.') HAL_Delay(dot);
		else HAL_Delay(dot * 3)
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);		
		HAL_Delay(dot);
}
```
```c
mos('S', 200);
mos('O', 200);
mos('S', 200);
```

## 2. Software PWM

```c
float hz50 = 1/50;

for (int i = 0; i < 50*2+1; i++) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_Delay(int(hz50/2));
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);	
	HAL_Delay(int(hz50/2));
```

## 3. Hardware PWM
- TIM3
  - Clock Source: Internal Clock
  - Channel1: PWM Generation CH1 --> PA6
  - Counter Settings
    - Prescaler: 72-1
    - Counter Period: 1000-1
  - PWM Generation Channel 1
    - Pulse: 0
- Cabling
  - A5 <--- Jumpter Cable ---> A6

```c
HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

while(1)
{
    for (int i = 0; i < 1000; i+=10) {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, i);
	HAL_Delay(10);
    }
    for (int i = 1000-1; i > -1; i-=10) {
        htim3.Instance->CCR1 = i;
	HAL_Delay(10);
    }
    ...
}
```
