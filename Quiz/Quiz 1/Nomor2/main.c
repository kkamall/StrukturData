/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz Nomor 2 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int n;
    int id1[200];
    char nama1[200][50];
    char bagian1[200][100];
    int id2[200];
    char nama2[200][50];
    char bagian2[200][100];

    list P1;
    list P2;
    createList(&P1);
    createList(&P2);

    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d %s %s", &id1[i], &nama1[i], &bagian1[i]);
        addLast(nama1[i], bagian1[i], id1[i], &P1);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d %s %s", &id2[i], &nama2[i], &bagian2[i]);
        addLast(nama2[i], bagian2[i], id2[i], &P2);
    }

    tukar(n, P1, P2);
    printElement(P1);
    printElement(P2);

    return 0;
}