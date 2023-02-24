/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz 1 Nomor 1 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int banyak1, banyak2;
    char jenis1[100][20];
    char makanan1[100][100];
    int harga1[100];
    char jenis2[100][20];
    char makanan2[100][100];
    int harga2[100];
    char perusahaan[100];
    char jenis3[20];

    list P1;
    list P2;

    createList(&P1);
    createList(&P2);

    int i;
    scanf("%d", &banyak1);
    for (i = 0; i < banyak1; i++)
    {
        scanf("%s %s %d", &jenis1[i], &makanan1[i], &harga1[i]);
        addLast(jenis1[i], makanan1[i], harga1[i], &P1);
    }
    scanf("%d", &banyak2);
    for (i = 0; i < banyak2; i++)
    {
        scanf("%s %s %d", &jenis2[i], &makanan2[i], &harga2[i]);
        addLast(jenis2[i], makanan2[i], harga2[i], &P2);
    }
    scanf("%s %s", &perusahaan, &jenis3);

    tukar(perusahaan, jenis3, &P1, &P2);
    // printElement(P2);
    // printElement(P1);

    return 0;
}