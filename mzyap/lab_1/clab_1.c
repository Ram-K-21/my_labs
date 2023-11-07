#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

extern void unch();
extern void snch();
extern void unint();
extern int16_t va, vb, vd;
extern int32_t res, divd, divr;
int main()
{
    printf("(2*d-96/a)/(34/b-a+1)\n");
    printf("a: ");
    scanf("%hd", &va);
    printf("b: ");
    scanf("%hd", &vb);
    printf("d: ");
    scanf("%hd", &vd);

    //(2*d-96/a)/(34/b-a+1)

    unch();
    uint8_t a = va, b = vb, d = vd;
    printf("---unch---\n");
    if (a != 0 && b != 0 && (int16_t)(34 / b - a + 1) != 0)
    {
        printf("numerator: %hd\n", (int16_t)(2 * d - 96 / a));
        printf("denominator: %hd\n", (int16_t)(34 / b - a + 1));
        printf("cresult: %hd\n\n", (int16_t)(2 * d - 96 / a) / (uint16_t)(34 / b - a + 1));
    }
    else
        printf("cresult: division by zero\n\n");
    printf("numerator: %hd\n", divd);
    printf("denominator: %hd\n", divr);
    printf("result: %hd\n\n", res);

    snch();
    printf("---snch---\n");
    if (va != 0 && vb != 0 && (int16_t)(34 / vb - va + 1) != 0)
    {
        printf("numerator: %hd\n", (int16_t)(2 * vd - 96 / va));
        printf("denominator: %hd\n", (int16_t)(34 / vb - va + 1));
        printf("cresult: %hd\n\n", (int16_t)(2 * vd - 96 / va) / (int16_t)(34 / vb - va + 1));
    }
    else
        printf("cresult: division by zero\n\n");
    printf("numerator: %hd\n", divd);
    printf("denominator: %hd\n", divr);
    printf("result: %hd\n\n", res);

    unint();
    uint16_t wa = va, wb = vb, wd = vd;
    printf("---unint---\n");
    if (wa != 0 && wb != 0 && (int32_t)(34 / wb - wa + 1) != 0)
    {
        printf("numerator: %d\n", (int32_t)(2 * wd - 96 / wa));
        printf("denominator: %d\n", (int32_t)(34 / wb - wa + 1));
        printf("cresult: %d\n\n", (int32_t)(2 * wd - 96 / wa) / (int32_t)(34 / wb - wa + 1));
    }
    else
        printf("cresult: division by zero\n\n");
    printf("numerator: %d\n", divd);
    printf("denominator: %d\n", divr);
    printf("result: %d\n\n", res);
}