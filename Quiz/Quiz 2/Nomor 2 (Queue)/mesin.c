/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz 2 - (qubea22) Struktur Data C1 2021
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
void add(char nim[], int nilai, int bantuan, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    // Proses pengisian kontainer
    strcpy(baru->kontainer.nama, nim);
    baru->kontainer.antrian = nilai;
    baru->kontainer.semester = bantuan;
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
void del(queue *Q)
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
        free(hapus);
    }
}

// Pengeluaran output
void printQueue1(queue Q, queue Q2)
{
    // Queue tidak kosong
    if (Q.first != NULL)
    {
        elemen *bantu = Q2.first;
        printf("sudah mendapat beasiswa:\n");

        // Print semua elemen queue Q2
        while(bantu != NULL)
        {
            printf("%s %d %d\n", bantu->kontainer.nama, bantu->kontainer.antrian, bantu->kontainer.semester);
            bantu = bantu->next;
        }

        bantu = Q.first;
        printf("\nbelum mendapat beasiswa:\n");

        // Print semua elemen queue Q1
        while (bantu != NULL)
        {
            printf("%s %d %d\n", bantu->kontainer.nama, bantu->kontainer.antrian, bantu->kontainer.semester);
            bantu = bantu->next;
        }
    }
}

// Penambahan elemen dengan priority
void addP(char nim[], int priority, int bantuan, queue *Q)
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
    baru->kontainer.antrian = priority;
    baru->kontainer.semester = bantuan;
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
        if ((*Q).first == NULL)
        {
            (*Q).first = baru;
        }
        else if (priority > countElement(*Q))
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

// Menggerakkan elemen mahasiswa yang sudah mendapat beasiswa
void move(queue *Q, queue *Q2, int m)
{
    int i;
    elemen *bantu;

    // Proses pemindahan elemen Q1 ke Q2 sebanyak m
    for(i=0; i<m; i++)
    {
        bantu = (*Q).first;
        add(bantu->kontainer.nama, bantu->kontainer.antrian, bantu->kontainer.semester, Q2);
        del(Q);
    }
}