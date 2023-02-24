#include "header.h"

int main()
{
    char nama[6][50];
    int harga[6];
    stack S1;
    stack S2;
    createEmpty(&S1);
    createEmpty(&S2);

    int i;
    for (i = 0; i < 6; i++)
    {
        scanf("%s %d", &nama[i], &harga[i]);
    }

    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    push(nama[0], harga[0], &S1);
    push(nama[1], harga[1], &S2);
    push(nama[2], harga[2], &S2);

    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    pop(&S1);
    popS(&S2, &S1);
    push(nama[3], harga[3], &S1);
    push(nama[4], harga[4], &S2);
    push(nama[5], harga[5], &S1);
    pop(&S2);
    popS(&S1, &S2);

    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    return 0;
}