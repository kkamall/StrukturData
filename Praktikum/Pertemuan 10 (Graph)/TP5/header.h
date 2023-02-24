/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Graph - (TCI122) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp
{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;

typedef struct
{
    simpul *first;
} graph;

// Inisialisasi graph
void createEmpty(graph *G);
// Menbamah simpul
void addSimpul(char c, graph *G);
// Menambah jalur
void addJalur(simpul *awal, simpul *tujuan, int beban);
// Mencari simpul
simpul* findSimpul(char c, graph G);
// Menghapus jalur
void delJalur(char ctujuan, simpul *awal);
// Menhapus graph
void delAll(simpul *awal);
// Menghapus simpul
void delSimpul(char c, graph *G);
// Memberikan output nilai graph
void printGraph(graph G);
// Mencari jalur
// void cariJalur(simpul *awal, char techi, char akhir, char (*path)[][100], int (*cost)[], int *a, int *b, int *flag);
void cariJalur2(simpul *awal, char (*path)[][100], int *i, int *j, int *iterasi, int *flag);