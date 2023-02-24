/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS Graph - (GJTL22) Struktur Data C1 2021
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
// Mencari banyak jalur langsung dan tidak langsung
void cariJalur2(simpul *awal, char (*path)[][100], int *i, int *j, int *iterasi, int *flag, char tAwal, char tAkhir);