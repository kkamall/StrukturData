/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UTS Struktur Data C1 2021
    dalam mata Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// List Baris => Perusahaan
typedef struct
{
    char kode[20];
    char nama[50];
} perusahaan;

// List Kolom => Obat
typedef struct
{
    char kode[20];
    char nama[50];
    int bulan;
    int tahun;
    char jenis[7];
} obat;

// Eleme Kolom
typedef struct eklm *alamatekolom;
typedef struct eklm
{
    obat kontainer_kol;
    alamatekolom next_kol;
} eKolom;

// Elemen Baris
typedef struct ebr *alamatebaris;
typedef struct ebr
{
    perusahaan kontainer;
    eKolom *col;
    alamatebaris next;
} eBaris;

// List
typedef struct
{
    eBaris *first;
} list;

// Prosedur membuat list
void createList(list *L);
// Fungsi menghitung elemen baris
int countElementB(list L);
// Fungsi menghitung elemen kolom
int countElementK(eBaris L);
// Prosedur menambah elemen baris menjadi first elemen
void addFirstB(char nim[], char nama[], list *L);
// Prosedur menambah elemen kolom menjadi first elemen
void addFirstK(char kode[], char nama[], int bulan, int tahun, char jenis[], eBaris *L);
// Prosedur menambah elemen baris setelah yang ditentukan
void addAfterB(eBaris *prev, char nim[], char nama[]);
// Prosedur menambah elemen kolom setelah yang ditentukan
void addAfterK(eKolom *prev, char kode[], char nama[], int bulan, int tahun, char jenis[]);
// Prosedur menambah elemen baris di akhir
void addLastB(char nim[], char nama[], list *L);
// Prosedur menambah elemen kolom di akhir
void addLastK(char kode[], char nama[], int bulan, int tahun, char jenis[], eBaris *L);
// Prosedur menghapus elemen kolom pertama
void delFirstK(eBaris *L);
// Prosedur menghapus elemen kolom setelah yang ditentukan
void delAfterK(eKolom *prev);
// Prosedur menghapus elemen kolom terakhir
void delLastK(eBaris *L);
// Prosedur menghapus semua elemen kolom
void delAllK(eBaris *L);
// Prosedur menghapus elemen baris pertama
void delFirstB(list *L);
// Prosedur menghapus elemen baris setelah yang ditentukan
void delAfterB(eBaris *prev);
// Prosedur menghapus elemen bari terakhir
void delLastB(list *L);
// Prosedur menghapus semua elemen baris
void delAllB(list *L);
// Prosedur mengeluarkan output berupa nilai elemen
void printElement(list L);
// Prosedur penghapusan/perpindahan obat
void erasing(list *L, int tahun, int bulan);