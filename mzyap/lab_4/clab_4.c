#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

extern void shrt_int();
extern int8_t len;
extern int16_t va, vb, mas[10];
extern int32_t res;

int main()
{
    len = 10;
    printf("a: ");
    scanf("%hd", &va);
    printf("b: ");
    scanf("%hd", &vb);
    printf("mas size 10: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%hd", &mas[i]);
    }
    // short mas[] = {12, 2, 7, 3, 2, 0, 21, -9, 0, 8};
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (mas[i] >= va && mas[i] <= vb)
        {
            sum += mas[i];
        }
    }

    shrt_int();
    printf("%hd <= mas[i] <= %hd\n\n", va, vb);
    printf("---shrt_int---\ncresult: %hd\n\n", sum);
    printf("result: %hd\n\n", res);
}