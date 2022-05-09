#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

uint32_t mem;

#define set_nibble(mem, index, value) (mem |= (value) << ((index) * 4)) 
#define get_nibble(mem, index) ((mem >> (index * 4)) & 0xF)

void init_random(void)
{
    int32_t table[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    srandom(time(NULL));

    for (int x, i = 0; i < 3; i++) {
        do {
            x = random() % 10;
        } while (table[x] == -1);

        set_nibble(mem, i, table[x]);
        table[x] = -1;
    }
}

void input_num(void)
{
    int n[3];
    scanf("%d %d %d", &n[0], &n[1], &n[2]);

    for (int x, i = 0; i < 3; i++) {
        set_nibble(mem, 3+i, n[i]);
    }
}

void display_mem(void)
{
    for(int i = 0; i < 6; ++i) {
        printf("%d ", get_nibble(mem, i));
    }
    printf("\n");
}

int main()
{    
    init_random();
    input_num();
    display_mem();
    
    return 0;
}