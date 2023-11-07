#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

extern void shrt_int();
extern int8_t len;
extern int16_t va, vb, mas[10];
extern int32_t res;

void clean_stream()
{
    while (fgetc(stdin) != '\n')
        ;
}

int main()
{
    len = 10;
    printf("a: ");
    scanf("%hu", &va);
    printf("b: ");
    scanf("%hu", &vb);
    printf("mas with size 10: ");
    clean_stream();
    char mas_[10];
    gets(mas_);
    for (int i = 0; i < 10; i++)
    {
        mas[i] = mas_[i] - '0';
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
    printf("%hu <= mas[i] <= %hu\n", va, vb);
    printf("---shrt_int---\ncresult: %hu\n\n", sum);
    printf("result: %hu\n\n", res);
}