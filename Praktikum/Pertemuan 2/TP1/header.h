/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP1 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Struct buat nyimpen data musik
typedef struct
{
    char judul[100];
    char artis[100];
    int urutan;
} lagu;

// Struct elemen
typedef struct elmt *alamatelmt;
typedef struct elmt
{
    lagu kontainer;
    alamatelmt next;
} elemen;

// Struck list
typedef struct
{
    elemen *first;
} list;

// Buat list
void createList(list *L);
// Menghitung banyak elemen di list
int countElement(list L);
// Menambahkan elemen baru di depan
void addFirst(char nim[], char nama[], int nilai, list *L);
// Menambahkan elemen baru di tengah atau di akhir
void addAfter(elemen *prev, char nim[], char nama[], int nilai, list *L);
// Menambahkan elemen baru di akhir
void addLast(char nim[], char nama[], int nilai, list *L);
// Nge-print isi list
void printElement(list L);
// Nuker elemen sesuai urutan yang diinginkan user
void tukar(list *L, char dasar[], char jenis[], int jumlah);