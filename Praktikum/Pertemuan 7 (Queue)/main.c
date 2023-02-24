/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM 7 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    // Inisialisasi
    char nama[6][50];
    int rating[6], i;
    queue Q1;
    queue Q2;

    // Set up queue
    createEmpty(&Q1);
    createEmpty(&Q2);

    // Meminta inputan
    for (i = 0; i < 6; i++)
    {
        scanf("%s %d", &nama[i], &rating[i]);
    }

    // Proses...
    add(nama[0], rating[0], &Q1);
    add(nama[1], rating[1], &Q1);
    addP(nama[2], rating[2], &Q1, 2);
    printQueue1(Q1, 1);
    del(&Q1, &Q2);
    printQueue1(Q1, 1);
    printQueue1(Q2, 2);
    addP(nama[3], rating[3], &Q1, 1);
    addP(nama[4], rating[4], &Q1, 99);
    printQueue1(Q1, 1);
    del(&Q1, &Q2);
    del(&Q1, &Q2);
    add(nama[5], rating[5], &Q1);
    printQueue1(Q1, 1);
    printQueue1(Q2, 2);
    printf("******************\n");

    return 0;
}