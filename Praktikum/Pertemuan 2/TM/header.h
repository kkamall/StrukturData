/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM2 Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nama[100];
    char jenis_kelamin[2];
    char asal_buku[100];
} tokoh;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    tokoh kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(elemen *prev, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);