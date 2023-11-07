#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

extern void intt();
extern void unint();
extern int16_t va, vb;
extern int32_t res;
int main()
{
    printf("(b+a)/(a-1), a>b\n23, a=b\nb*b/8, a<b\n");
    printf("a: ");
    scanf("%hd", &va);
    printf("b: ");
    scanf("%hd", &vb);

    intt();
    printf("---intt---\n");
    if (va > vb && (int32_t)(va - 1) == 0)
        printf("cresult: division by zero\n\n");
    else if (va > vb)
        printf("cresult: %d\n\n", (int32_t)(vb + va) / (int32_t)(va - 1));
    else if (va == vb)
        printf("cresult: 23\n\n");
    else
        printf("cresult: %d\n\n", (int32_t)(vb * vb / 8));
    printf("result: %d\n\n", res);

    unint();
    uint16_t wa = va, wb = vb;
    printf("---unint---\n");
    if (wa > wb && (int32_t)(wa - 1) == 0)
        printf("cresult: division by zero\n\n");
    else if (wa > wb)
        printf("cresult: %d\n\n", (int32_t)(wb + wa) / (int32_t)(wa - 1));
    else if (wa == wb)
        printf("cresult: 23\n\n");
    else
        printf("cresult: %u\n\n", ((uint32_t)(wb * wb) / 8));
    printf("result: %u\n\n", res);
}