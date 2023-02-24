/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Graph - (TCI122) Struktur Data C1 2021
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

// Menghapus jalur
void delJalur(char ctujuan, simpul *awal)
{
    jalur *hapus = awal->arc;
    // Proses penghapusan jalur
    if (hapus != NULL)
    {
        jalur *prev = NULL;
        /*mencari jalur yang akan dihapus*/
        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0))
        {
            if (hapus->tujuan->kontainer == ctujuan)
            {
                ketemu = 1;
            }
            else
            {
                prev = hapus;
                hapus = hapus->next_jalur;
            }
        }

        if (ketemu == 1)
        {
            if (prev == NULL)
            {
                /*hapus jalur pertama*/
                awal->arc = hapus->next_jalur;
                hapus->next_jalur = NULL;
            }
            else
            {
                if (hapus->next_jalur == NULL)
                {
                    /*hapus jalur terakhir*/
                    prev->next_jalur = NULL;
                }
                else
                {
                    /*hapus jalur di tengah*/
                    prev->next_jalur = hapus->next_jalur;
                    hapus->next_jalur = NULL;
                }
            }
            free(hapus);
        }
    }
}

// Menghapus graph
void delAll(simpul *awal)
{

    jalur *bantu;
    bantu = awal->arc;
    jalur *hapus;
    // Proses penghapusan graph
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next_jalur;
        awal->arc = bantu;
        hapus->next_jalur = NULL;
        free(hapus);
    }
}

// Menghapus simpul
void delSimpul(char c, graph *G)
{
    simpul *hapus = (*G).first;
    // Proses penghapusan simpul
    if (hapus != NULL)
    {
        simpul *prev = NULL;
        /*mencari simpul yang akan dihapus*/
        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0))
        {
            if (hapus->kontainer == c)
            {
                ketemu = 1;
            }
            else
            {
                prev = hapus;
                hapus = hapus->next;
            }
        }
        if (ketemu == 1)
        {
            /* jika simpul yang akan dihapus ada */
            /* hapus semua jalur dari simpul lain
           yang mengarah pada simpul yang dihapus */
            simpul *bantu;
            bantu = (*G).first;
            /* memeriksa semua simpul dalam graf */
            while (bantu != NULL)
            {
                /* jika simpul yang ditelusuri tidak sama
               dengan yang dihapus */
                if (bantu != hapus)
                {
                    /* hapus semua jalur yang mengarah pada
                   simpul yang dihapus */
                    delJalur(hapus->kontainer, bantu);
                }
                bantu = bantu->next;
            }
            /* hapus semua jalur */
            delAll(hapus);
            if (prev == NULL)
            {
                /*hapus simpul pertama*/
                (*G).first = hapus->next;
                hapus->next = NULL;
            }
            else
            {
                if (hapus->next == NULL)
                {
                    /*hapus simpul terakhir*/
                    prev->next = NULL;
                }
                else
                {
                    /*hapus simpul di tengah*/
                    prev->next = hapus->next;
                    hapus->next = NULL;
                }
            }
            free(hapus);
        }
    }
}

// Proses pengeluaran output nilai graph
void printGraph(graph G)
{
    simpul *bantu = G.first;
    if (bantu != NULL)
    {
        while (bantu != NULL)
        {
            // Output kontainer simpul
            printf("Node %c\n", bantu->kontainer);
            jalur *bantu_jalur = bantu->arc;
            // Output jalur simpul
            while (bantu_jalur != NULL)
            {
                printf("- Jalur %c ke %c\n", bantu->kontainer, bantu_jalur->tujuan->kontainer);
                bantu_jalur = bantu_jalur->next_jalur;
            }
            bantu = bantu->next;
        }
    }
    else
    {
        printf("graf kosong\n");
    }
}

// Mencari jalur
// void cariJalur(simpul *awal, char techi, char akhir, char (*path)[][100], int (*cost)[], int *a, int *b, int *flag)
// {
//     int i, j;
    
//     jalur *bantu_jalur = awal->arc;

//     // Inisialisasi awal
//     if (awal->kontainer == techi)
//     {
//         *a += 1;
//         (*path)[*a][*b] = techi;
//     }
//     // Penambahan cost jalur baru
//     if(awal->arc == NULL)
//     {
//         *flag += 1;
//         (*cost)[*flag] = (*cost)[*flag - 1];
//     }
//     // Proses pencarian jalur + perhitungan cost jalur
//     while (bantu_jalur != NULL)
//     {
//         simpul *bantu = bantu_jalur->tujuan;
//         *b += 1;
//         // Pemasukkan nilai
//         (*cost)[*flag] += bantu_jalur->kontainer_jalur;
//         (*path)[*a][*b] = bantu->kontainer;

//         // Rekursif
//         cariJalur(bantu, techi, akhir, path, cost, a, b, flag);
//         if (bantu_jalur->next_jalur != NULL)
//         {
//             // Meng-copy jalur baru
//             for (i = 0; i < strlen((*path)[*a]) - 1; i++)
//             {
//                 (*path)[*a + 1][i] = (*path)[*a][i];
//             }
//             *a += 1;
//         }
//         // Iterasi
//         (*cost)[*flag] -= bantu_jalur->kontainer_jalur;
//         bantu_jalur = bantu_jalur->next_jalur;
//         *b -= 1;
//     }
// }

void cariJalur2(simpul *awal, char (*path)[][100], int *i, int *j, int *iterasi, int *flag)
{
    if(*iterasi == 0)
    {
        *j += 1;
        (*path)[*i][*j] = awal->kontainer;
        *iterasi += 1;
    }
    jalur *bantu_jalur = awal->arc;
    while(bantu_jalur != NULL)
    {
        *j += 1;
        if(*flag == 1)
        {
            strcpy((*path)[*i+1], (*path)[*i]);
            *i += 1;
            *flag = 0;
        }
        (*path)[*i][*j] = bantu_jalur->tujuan->kontainer;
        cariJalur2(bantu_jalur->tujuan, path, i, j, iterasi, flag);
        if(*flag == 0)
        {
            (*path)[*i][*j+1] = '\0';
        }
        *j -= 1;
        bantu_jalur = bantu_jalur->next_jalur;
        *flag = 1;
    }
}