/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM5 Struktur Data C1 2021
    dalam mata Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int n;
    char label[5][50];
    char kode[5][5];
    char barang[5][4][50];
    int i, j;
    list L;
    createList(&L);

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %s", &label[i], &kode[i]);
        for (j = 0; j < 4; j++)
        {
            scanf("%s", &barang[i][j]);
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        addFirstB(label[i], kode[i], &L);
        for (j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                addFirstK(barang[i][j], L.first);
            }
            else if (j == 1)
            {
                addLastK(barang[i][j], L.first);
            }
            else if (j == 2)
            {
                addAfterK(L.first->col->next_kol, barang[i][j]);
            }
            else
            {
                addFirstK(barang[i][j], L.first);
            }
        }
    }

    delAfterK(L.first->next->col->next_kol);
    delFirstB(&L);
    delFirstK(L.first);
    printElement(L);

    for (i = 0; i < n - 1; i++)
    {
        delAllK(L.first);
        delFirstB(&L);
    }
    printElement(L);

    return 0;
}