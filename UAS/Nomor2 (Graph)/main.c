/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS Graph - (GJTL22) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    /*
        (1) banyakJalur = banyak jalur inputan user
        (2) i, j = untuk index array dan looping
        (3) flag = proses pencarian jalur
        (4) jalur = tempat menyimpan jalur^2
    */
    int banyakJalur, i, j, iterasi = 0, flag = 0;
    scanf("%d", &banyakJalur);
    char jalur[banyakJalur + 10][banyakJalur + 10];

    graph G;
    simpul *begin;
    simpul *end;
    createEmpty(&G);

    char awal, akhir;
    for (i = 0; i < banyakJalur; i++)
    {
        // Input node dan jalur
        scanf(" %c %c", &awal, &akhir);

        // Proses memasukkan node ke graph
        if (findSimpul(awal, G) == NULL)
        {
            addSimpul(awal, &G);
        }
        if (findSimpul(akhir, G) == NULL)
        {
            addSimpul(akhir, &G);
        }

        // Proses memasukkan jalur node
        begin = findSimpul(awal, G);
        end = findSimpul(akhir, G);
        addJalur(begin, end, 0);
    }
    // Input node awal dan akhir yang dicari jalurnya
    scanf(" %c %c", &awal, &akhir);

    i = 0;
    j = -1;
    begin = findSimpul(awal, G);

    // Pencarian jalur langsung dan tidak langsung
    cariJalur2(begin, &jalur, &i, &j, &iterasi, &flag, awal, akhir);

    return 0;
}