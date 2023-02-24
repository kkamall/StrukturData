/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM3 Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    list L;

    char namaH[7][100];
    char tanggalH[7][12];
    int jumlahH[7];

    int i;
    for (i = 0; i < 7; i++)
    {
        scanf("%s %s %d", &namaH[i], &tanggalH[i], &jumlahH[i]);
    }

    printf("Data Kebun Binatang\n");

    createList(&L);
    addFirst(namaH[0], tanggalH[0], jumlahH[0], &L);
    addLast(namaH[1], tanggalH[1], jumlahH[1], &L);
    addAfter(L.first, namaH[2], tanggalH[2], jumlahH[2], &L);
    printElement(L);

    delAfter(L.data[L.first].next, &L);
    addAfter(L.first, namaH[3], tanggalH[3], jumlahH[3], &L);
    addAfter(L.data[L.tail].prev, namaH[4], tanggalH[4], jumlahH[4], &L);
    delFirst(&L);
    printElement(L);

    addFirst(namaH[5], tanggalH[5], jumlahH[5], &L);
    addAfter(L.data[L.first].next, namaH[6], tanggalH[6], jumlahH[6], &L);
    delLast(&L);
    printElementR(L);

    delAll(&L);
    printf("===================\n");
    printElement(L);

    return 0;
}