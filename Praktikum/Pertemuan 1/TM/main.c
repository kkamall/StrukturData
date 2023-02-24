/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    list L;
    createList(&L);

    char namaCG[TOTAL][100];
    char levelG[TOTAL][10];
    char namaG[TOTAL][100];

    int i;
    for (i = 0; i < 5; i++)
    {
        scanf("%s %s %s", namaCG[i], levelG[i], namaG[i]);
    }

    addFirst(namaCG[0], levelG[0], namaG[0], &L);
    addFirst(namaCG[1], levelG[1], namaG[1], &L);
    addAfter(L.first, namaCG[2], levelG[2], namaG[2], &L);
    printElement(L);

    delLast(&L);
    addAfter(L.data[L.first].next, namaCG[3], levelG[3], namaG[3], &L);
    addLast(namaCG[4], levelG[4], namaG[4], &L);
    printElement(L);

    delAfter(L.data[L.first].next, &L);
    delFirst(&L);
    delLast(&L);
    printElement(L);

    delLast(&L);
    printElement(L);

    return 0;
}