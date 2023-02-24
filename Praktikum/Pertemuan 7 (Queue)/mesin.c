/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM 7 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Set up queue
void createEmpty(queue *Q)
{
    (*Q).first = NULL;
    (*Q).last = NULL;
}

// Cek queue kosong atau tidak
int isEmpty(queue Q)
{
    int hasil = 0;

    // If dengan kondisi queue kosong
    if (Q.first == NULL)
    {
        hasil = 1;
    }

    return hasil;
}

// Menghitung banyak elemen
int countElement(queue Q)
{
    int hasil = 0;
    // If dengan kondisi queue tidak kosong
    if (Q.first != NULL)
    {
        elemen *bantu;
        bantu = Q.first;

        // While untuk menghitung
        while (bantu != NULL)
        {
            hasil++;
            bantu = bantu->next;
        }
    }

    return hasil;
}

// Menambah elemen
void add(char nim[], int nilai, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    // Proses pengisian kontainer
    strcpy(baru->kontainer.nama, nim);
    baru->kontainer.rating = nilai;
    baru->next = NULL;

    // Proses penambahan elemen
    // Queue kosong
    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
    }
    // Queue tidak kosong
    else
    {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

// Penghapusan elemen
void del(queue *Q, queue *Q2)
{
    // If dengan kondisi queue tidak kosong
    if ((*Q).first != NULL)
    {
        elemen *hapus = (*Q).first;

        // Proses penghapusan
        // If dengan kondisi elemennya hanya 1
        if (countElement(*Q) == 1)
        {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        // If dengan kondisi elemennya > 1
        else
        {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        // Penambahan eleme ke queue 2
        add(hapus->kontainer.nama, hapus->kontainer.rating, Q2);
        free(hapus);
    }
}

// Pengeluaran output
void printQueue1(queue Q, int i)
{
    // Queue tidak kosong
    if (Q.first != NULL)
    {
        printf("******************\n");
        printf("Queue %d\n", i);

        elemen *bantu = Q.first;
        // While untuk pengeluaran output
        while (bantu != NULL)
        {
            printf("%s %d\n", bantu->kontainer.nama, bantu->kontainer.rating);
            bantu = bantu->next;
        }
    }
}

// Penambahan elemen dengan priority
void addP(char nim[], int nilai, queue *Q, int priority)
{
    elemen *baru;
    elemen *bantu = (*Q).first;
    int i = 0;

    // Set up pointer bantu hingga menunjuk elemen sebelum elemen yang akan digeser
    while((i < priority - 2) && (bantu != NULL))
    {
        bantu = bantu->next;
        i++;
    }

    baru = (elemen *)malloc(sizeof(elemen));
    // Pemasukan nilai ke kontainer
    strcpy(baru->kontainer.nama, nim);
    baru->kontainer.rating = nilai;
    baru->next = NULL;

    // Penambahan elemen di awal
    if (priority == 1)
    {
        // Queue kosong
        if ((*Q).first == NULL)
        {
            (*Q).first = baru;
        }
        // Queue tidak kosong
        else
        {
            baru->next = bantu;
            (*Q).first = baru;
        }
    }
    // Penambahan elemen di tengah atau akhir
    else
    {
        // Angka priority di atas banyak elemen (penambahan di akhir)
        if (priority > countElement(*Q))
        {
            (*Q).last->next = baru;
        }
        // Penambahan di tengah
        else
        {
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
    // elemen baru merupakan elemen terakhir
    if (baru->next == NULL)
    {
        (*Q).last = baru;
    }
    baru = NULL;
}