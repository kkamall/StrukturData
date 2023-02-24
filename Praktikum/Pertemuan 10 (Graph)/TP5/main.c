/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Graph - (TCI122) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    /*
        (1) i, j, k = index
        (2) banyak = banyak jalur
        (3) cost = harga total suatu jalur
        (4) nilai = harga satu jalur
        (5) input = masukkan jalur
        (6) TTechi = Titik techi
        (7) TTibu = Titik ibu techi
        (8) jalur = jalur dari TTechi -> TTibu
    */
    int i, j, k, banyak, cost[100] = {0}, nilai;
    scanf("%d", &banyak);
    char input[2], TTechi, TTibu, jalur[100][100];
    graph G;
    simpul *begin;
    simpul *end;

    // Inisialisasi graph
    createEmpty(&G);

    // Looping meminta inputan user dan memasukkan ke graph
    for(i = 0; i < banyak; i++)
    {
        scanf(" %c %c %d", &input[0], &input[1], &nilai);
        
        // Proses menambah simpul 
        if(i == 0)
        {
            addSimpul(input[0], &G);
        }
        simpul *flag = findSimpul(input[1], G);
        if(flag == NULL)
        {
            addSimpul(input[1], &G);
        }

        // Proses menambah jalur
        begin = findSimpul(input[0], G);
        end = findSimpul(input[1], G);
        addJalur(begin, end, nilai);
    }
    scanf(" %c %c", &TTechi, &TTibu);

    i = 0; j = -1;
    int flag = 0;
    int iterasi = 0;
    begin = findSimpul(TTechi, G);

    // Mencari jalur dari TTechi -> TTibu
    // cariJalur(begin, TTechi, TTibu, &jalur, &cost, &i, &j, &flag);
    cariJalur2(begin, &jalur, &i, &j, &iterasi, &flag);
    
    // Proses pengeluaran output
    for(j = 0; j < i+1; j++)
    {
            for(k = 0; k <strlen(jalur[j]); k++)
            {
                printf("%c ", jalur[j][k]);
            }
            printf("\n");
    }

    return 0;
}