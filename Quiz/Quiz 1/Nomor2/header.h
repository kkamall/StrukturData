/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz Nomor 2 Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char nama[50];
    char bagian[100];
} karyawan;

typedef struct
{
    karyawan kontainer;
    int prev;
    int next;
} elemen;

typedef struct
{
    int first;
    int tail;
    elemen data[100];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nim[], char nama[], int nilai, list *L);
void addAfter(int before, char nim[], char nama[], int nilai, list *L);
void addLast(char nim[], char nama[], int nilai, list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElement(list L);
void printElementR(list L);
void delAll(list *L);
void tukar(int banyak, list P1, list P2);