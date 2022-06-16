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
