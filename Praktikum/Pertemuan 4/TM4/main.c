/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM4 Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    char namaS[7][50];
    char nimS[7][10];
    char goldarS[7][3];

    int i;
    for (i = 0; i < 7; i++)
    {
        scanf("%s %s %s", &namaS[i], &nimS[i], &goldarS[i]);
    }

    printf("Data Golongan Darah\n");

    list L;
    createList(&L);
    addLast(nimS[0], namaS[0], goldarS[0], &L);
    addFirst(nimS[1], namaS[1], goldarS[1], &L);
    addBefore(L.first->next, nimS[2], namaS[2], goldarS[2], &L);
    printElement(L);

    addAfter(L.first->next, nimS[3], namaS[3], goldarS[3], &L);
    delAfter(L.first, &L);
    addAfter(L.first, nimS[4], namaS[4], goldarS[4], &L);
    addBefore(L.tail, nimS[5], namaS[5], goldarS[5], &L);
    delFirst(&L);
    printElement(L);

    delLast(&L);
    delAfter(L.first, &L);
    addLast(nimS[6], namaS[6], goldarS[6], &L);
    printElementR(L);

    delAll(&L);
    printElement(L);

    return 0;
}