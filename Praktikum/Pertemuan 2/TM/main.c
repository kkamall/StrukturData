/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM2 Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    char namaZ[6][100];
    char jenis_kelaminZ[6][2];
    char asal_bukuZ[6][100];

    int i;
    for (i = 0; i < 6; i++)
    {
        scanf("%s %s %s", &namaZ[i], &jenis_kelaminZ[i], &asal_bukuZ[i]);
    }

    list L;
    createList(&L);
    addLast(namaZ[0], jenis_kelaminZ[0], asal_bukuZ[0], &L);
    addFirst(namaZ[1], jenis_kelaminZ[1], asal_bukuZ[1], &L);
    addAfter(L.first->next, namaZ[2], jenis_kelaminZ[2], asal_bukuZ[2], &L);
    printElement(L);

    delAfter(L.first->next, &L);
    delFirst(&L);
    printElement(L);

    addLast(namaZ[3], jenis_kelaminZ[3], asal_bukuZ[3], &L);
    addFirst(namaZ[4], jenis_kelaminZ[4], asal_bukuZ[4], &L);
    delLast(&L);
    printElement(L);

    delAll(&L);
    printElement(L);

    addLast(namaZ[5], jenis_kelaminZ[5], asal_bukuZ[5], &L);
    printElement(L);
    printf("--------------------\n");

    return 0;
}