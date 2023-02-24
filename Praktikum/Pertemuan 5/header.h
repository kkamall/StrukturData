/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM5 Struktur Data C1 2021
    dalam mata Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char label[50];
    char kode[5];
} box;

typedef struct
{
    char barang[50];
} barang;

typedef struct eklm *alamatekolom;
typedef struct eklm
{
    barang kontainer_kol;
    alamatekolom next_kol;
} eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr
{
    box kontainer;
    eKolom *col;
    alamatebaris next;
} eBaris;

typedef struct
{
    eBaris *first;
} list;

void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(char nim[], char nama[], list *L);
void addFirstK(char kode[], eBaris *L);
void addAfterB(eBaris *prev, char nim[], char nama[]);
void addAfterK(eKolom *prev, char kode[]);
void addLastB(char nim[], char nama[], list *L);
void addLastK(char kode[], eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);