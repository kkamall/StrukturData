/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Tugas Masa Depan - Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char mie[201];
    char harga[10];
    char inputKomponen[100][201];
    int banyakKomponen;
    int depth;
}dataMie;

typedef struct{
    char nama[201];
    char harga[10];
    char komponen[100][201];
    char parent[201];
    int banyakKomponen;
    int depth;
}data;

typedef struct smp *alamatsimpul;
typedef struct smp{
    data kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
}simpul;

typedef struct{
    simpul *root;
}tree;

// Membuat Tree
void makeTree(char mie[], char harga[], char komponen[][201], int banyakKomponen, int depth, char parent[], tree *T);
// Menambah child
void addChild(char mie[], char harga[], char komponen[][201], int banyakKomponen, int depth, char parent[], simpul *root);
// Menghapus tree
void delAll(simpul *root);
// Menghapus child
void delChild(char c[], simpul *root);
// Mencari node
simpul *findSimpul(char c[], simpul *root);
// Mengeluarkan output secara preorder
void printTreePreOrder(simpul *root, int stringTerpanjang[], int deepest, int flag, simpul *terakhir);
// Memisahkan inputan user
void pemisah(char inputMie[], char (*mie)[], char (*parent)[], char (*harga)[], int *banyakKomponen);
// Mencari string terpanjang di tiap depth
void cariStringTerpanjang(dataMie mie[], int banyakMie, int deepest, int (*stringTerpanjang)[]);
// Menghapus mie dengan di bawah harga minimum
void hapusMie(dataMie mie[], int banyakMie, char hargaMinimum[], simpul *root2);
// Mencari node paling bawah di pre-order
simpul *cariNodeAkhir(simpul *root);