/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UAS Binary Tree - (PBBA22) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp{
    int nilai;
    alamatsimpul right;
    alamatsimpul left;
}simpul;

typedef struct{
    simpul* root;
}tree;

// Membuat tree
void makeTree(int nilai, tree *T);
// Menambah anak di kanan
void addRight(int nilai, simpul *root);
// Menambah anak di kiri
void addLeft(int nilai, simpul *root);
// Mengeluarkan output dengan teknik in order
void printTreeInOrder(simpul *root, int banyak, int *i);
// Menambah child node
void prosesTree(simpul *root, int *flag, int nParent, int nPembagi);
// Menghitung banyak simpul
int banyakSimpul(simpul *root);