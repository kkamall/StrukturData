/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS Graph - (GJTL22) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Inisialisasi graph
void createEmpty(graph *G)
{
    (*G).first = NULL;
}

// Menambah simpul
void addSimpul(char c, graph *G)
{
    simpul *baru;
    // Pemasukkan nilai baru
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->next = NULL;
    baru->arc = NULL;

    // Pemasangan nilai baru dengan ke graph
    if ((*G).first == NULL)
    {
        /*jika graf kosong*/
        (*G).first = baru;
    }
    else
    {
        /*menambahkan simpul baru pada akhir graph*/
        simpul *last = (*G).first;

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = baru;
    }
}

// Menambah jalur
void addJalur(simpul *awal, simpul *tujuan, int beban)
{
    jalur *baru;
    // Pemasukkan jalur baru
    baru = (jalur *)malloc(sizeof(jalur));
    baru->kontainer_jalur = beban;
    baru->next_jalur = NULL;
    baru->tujuan = tujuan;

    // Pemasangan jalur baru ke graph
    if (awal->arc == NULL)
    {
        /*jika list jalur kosong*/
        awal->arc = baru;
    }
    else
    {
        /*menambahkan jalur baru pada akhir list jalur*/
        jalur *last = awal->arc;

        while (last->next_jalur != NULL)
        {
            last = last->next_jalur;
        }

        last->next_jalur = baru;
    }
}

// Mencari simpul
simpul *findSimpul(char c, graph G)
{
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    int ketemu = 0;

    // Proses pencarian
    while ((bantu != NULL) && (ketemu == 0))
    {
        // Ketemu
        if (bantu->kontainer == c)
        {
            hasil = bantu;
            ketemu = 1;
        }
        // Iterasi
        else
        {
            bantu = bantu->next;
        }
    }

    return hasil;
}

// Proses mencaari jalur lansung dan tidak langsung
void cariJalur2(simpul *awal, char (*path)[][100], int *i, int *j, int *iterasi, int *flag, char tAwal, char tAkhir)
{
    // Kalau masih iterasi pertama
    if (*iterasi == 0)
    {
        // Set nilai awal path
        *j += 1;
        (*path)[*i][*j] = awal->kontainer;
        *iterasi += 1;
    }
    // Proses pencarian jalur
    jalur *bantu_jalur = awal->arc;
    while (bantu_jalur != NULL)
    {
        *j += 1;
        if (*flag == 1)
        {
            // Cari jalur selanjutnya
            strcpy((*path)[*i + 1], (*path)[*i]);
            *i += 1;
            *flag = 0;
        }
        // Menambah node tujuan
        (*path)[*i][*j] = bantu_jalur->tujuan->kontainer;
        // Rekursif
        cariJalur2(bantu_jalur->tujuan, path, i, j, iterasi, flag, tAwal, tAkhir);
        // Menjadikan string
        if (*flag == 0)
        {
            (*path)[*i][*j + 1] = '\0';
        }
        *j -= 1;
        // Iterasi
        bantu_jalur = bantu_jalur->next_jalur;
        *flag = 1;
    }

    // Proses pengeluaran output
    if (bantu_jalur == NULL && awal->kontainer == tAwal)
    {
        int banyak[2] = {0};
        for (int index = 0; index < *i + 1; index++)
        {
            // Proses identifikasi jalur
            if((*path)[index][strlen((*path)[index]) - 1] == tAkhir)
            {
                // Jalur lansung
                if((*path)[index][1] == tAkhir)
                {
                    banyak[1]++;
                }
                // Jalur tidak langsung
                else
                {
                    banyak[0]++;
                }
            }
        }

        // Mengeluarkan output
        printf("jumlah jalur: %d\n", banyak[0]+banyak[1]);
        printf("terdiri dari:\n");
        printf("- %d jalur langsung\n", banyak[1]);
        printf("- %d jalur tidak langsung\n", banyak[0]);
    }
}