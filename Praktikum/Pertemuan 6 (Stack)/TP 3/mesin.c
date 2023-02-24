/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP3 Struktur Data C1 2021
    dalam mata kuliah Stuktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Set up stack
void createEmpty(stack *S)
{
    (*S).top = NULL;
}

// Mengecek apakah stack tidak punya elemen
int isEmpty(stack S)
{
    // Flag => 0 (stack kosong) | 1 (stack memiliki elemen)
    int hasil = 0;
    // Pengecekan ada elemen atau tidak
    if (S.top == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

// Menghitung banyak elemen
int countElement(stack S)
{
    // Variabel berupa banyak elemen
    int hasil = 0;

    // Cek apakah stack kosong
    if (S.top != NULL)
    {
        /* stack tidak kosong */

        elemen *bantu;

        /* inisialisasi */
        bantu = S.top;
        while (bantu != NULL)
        {
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

// Memasukkan elemen baru ke stack makananS
void push(int harga, char nama[], int kalori, stack *S)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    // Memasukkan nilai pada kontainer elemen bantu
    baru->kontainer.harga = harga;
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.kalori = kalori;

    // jika stack kosong
    if ((*S).top == NULL)
    {
        baru->next = NULL;
    }
    // jika stack tidak kosong
    else
    {
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

// Memasukkan elemen baru ke stack makananP/makananM
void push2(int harga, char nama[], int kalori, stack *S1, stack *S2)
{
    /*
        (1) i = untuk looping
        (2) totalA = total ASCII suatu string (nama makanan)
    */
    int i, totalA = 0;

    // Looping penjumlahan ASCII tiap kata dalam string
    for (i = 0; i < strlen(nama); i++)
    {
        totalA += nama[i];
    }

    // Jika total ASCII genap
    if (totalA % 2 == 0)
    {
        push(harga, nama, kalori, S1);
    }
    // Jika total ASCII ganjil
    else
    {
        push(harga, nama, kalori, S2);
    }
}

// Mene-print nilai tiap elemen
void printStack(stack S1, stack S2)
{
    printf("Wishlist Makanan Pedas:\n===================\n");
    // jika stack makananP tidak kosong
    if (S1.top != NULL)
    {
        elemen *bantu = S1.top;

        int i = 1;
        // Proses pengeluaran output hingga mencapai akhir stack
        while (bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    // Jika stack makananP kosong
    else
    {
        /* proses jika stack kosong */
        printf("LEMAH!\n");
    }

    printf("\nWishlist Makanan Manis:\n===================\n");
    // jika stack makananM tidak kosong
    if (S2.top != NULL)
    {
        elemen *bantu = S2.top;

        int i = 1;
        // Proses pengeluaran output hingga mencapai akhir stack
        while (bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    // Jika stack makananM kosong
    else
    {
        /* proses jika stack kosong */
        printf("NDAK SEHAT!\n");
    }
}