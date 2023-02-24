/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

#define TOTAL 5

typedef struct
{
    char nama[100];
    char level[10];
    char game[100];
} games;

typedef struct
{
    games kontainer;
    int next;
} elemen;

typedef struct
{
    int first;
    elemen data[TOTAL];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], char level[], char game[], list *L);
void addAfter(int prev, char nama[], char level[], char game[], list *L);
void addLast(char nama[], char level[], char game[], list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);