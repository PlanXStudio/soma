/*
1. init P_n (n=3) with random
int P[3];

#include <stdlib.h>
#include <time.h>

srandom(time(NULL));
int table[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
for(int x, i = 0; i < 3; i++) {
    do {
        x = random() % 10;
    } while (table[x] == -1);
    P[i] = table[x];
    table[x] = -1;
}

2. input U_n (n=3)
int U[3];

scanf("%d %d %d", &U[0], &U[1], &U[2])

3. compare P, U
int s = b

3-0. s = b = 0
s = b = 0;

3-1. if P_n == U_n then s++
3-2. if P_n == U_m then b++
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (i == j) {
            if (P[i] == U[i]) s++;        
        }
        else {
            if (P[i] == U[j]) b++;
        }
    }
}
4. print s, b
printf("s = %d, b = %d", s, b);

5. if s !=3 then goto 2.
do { /*2. 3. 4.*/ } while(s != 3);
*/

/*
P, U, s, b

1. P 생성. void init(void)
   do {
2. U 대입. void input(void)
3. PU 비교. void compare(void)
4. s, b 출력. void show(void)
   }while (s != 3);
*/
