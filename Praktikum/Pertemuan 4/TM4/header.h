/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM4 Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nim[10];
    char nama[50];
    char goldar[5];
} golonganDarah;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    golonganDarah kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(elemen *before, char nim[], char nama[], char nilai[], list *L);
void addBefore(elemen *before, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void printElement(list L);
void printElementR(list L);
void delAll(list *L);