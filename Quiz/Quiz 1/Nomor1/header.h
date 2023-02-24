/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz 1 Nomor 1 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char jenis[20];
    char nama[100];
    int harga;
} nilaiMatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaiMatkul kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char nim[], char nama[], int nilai, list *L);
void addAfter(elemen *prev, char nim[], char nama[], int nilai, list *L);
void addLast(char nim[], char nama[], int nilai, list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void printElement(list L1);
void delAll(list *L);
void tukar(char perusahaan[], char jenis3[], list *P1, list *P2);