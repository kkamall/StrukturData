/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP1 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    // Manggil struct list
    list musik;
    // Buat list
    createList(&musik);

    /*
        (1) judulL = lagu
        (2) artisL = musisi
        (3) urutanL = urutan lagunya
        (4) dasar = urut berdasarkan apa
        (5) jenis = asc/dsc
        (6) tanda = nge-stop minta inputan (masukkin '-')
    */
    char judulL[100][100];
    char artisL[100][100];
    int urutanL[100];
    char dasar[6];
    char jenis[5];
    int tanda = 0;

    // Var buat looping
    int i = 0, j;
    // While untuk minta inputan user
    while (tanda == 0)
    {
        scanf("%s", &judulL[i]);
        // Pengecekan '-' (sudah selesai masukin input)
        if (strcmp(judulL[i], "-") != 0)
        {
            scanf("%s", &artisL[i]);
            scanf("%d", &urutanL[i]);
            i++;
        }
        else
        {
            tanda = 1;
        }
    }
    scanf("%s", &dasar);
    scanf("%s", &jenis);

    // For untuk nambahin data inputan user ke list
    for (j = 0; j < i; j++)
    {
        addLast(judulL[j], artisL[j], urutanL[j], &musik);
    }

    // Menukar sesuai urutan yang diinginkan user
    tukar(&musik, dasar, jenis, i);
    // Nge-print isi list
    printElement(musik);

    return 0;
}