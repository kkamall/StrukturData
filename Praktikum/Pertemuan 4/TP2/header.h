/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP2 Struktur Data C1 2021
    dalam mata kuliah Stuktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Typedef struct buat barang
typedef struct
{
    char nama[50];
    int tanggal;
    int kode;
} barang;

// Typedef struct buat elemen
typedef struct elmt *alamatelmt;
typedef struct elmt
{
    barang kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

// Typedef struct buat elemen + first + tail
typedef struct
{
    elemen *first;
    elemen *tail;
} list;

// Prosedur membuat list
void createList(list *L);
// Fungsi menghitung banyak elemen
int countElement(list L);
// Prosedur menambah elemen di awal
void addFirst(char nim[], int nama, int nilai, list *L);
// Prosedur menghapus elemen pertama
void delFirst(list *L);
// Prosedur menghapus elemen setelah elemen yang di input user
void delAfter(elemen *before, list *L);
// Prosedur menampilkan elemen
void printElementR(list L);
// Prosedur sorting ascending kode
void sortingAscKode(list *L);
// Prosedur hapus elemen dengan tanggal kelipatan lima
void hapus(list *L);
// Prosedur soring ascending tanggal
void sortingAscTanggal(list *L);