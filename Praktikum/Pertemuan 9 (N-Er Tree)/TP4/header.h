/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal N-Ary Tree - (BPRA1) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library:
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct smp *alamatsimpul;
typedef struct smp{
    char kontainer[101];
    alamatsimpul sibling;
    alamatsimpul child;
}simpul;

typedef struct{
    simpul *root;
}tree;

// Pembuatan tree
void makeTree(char nama[], tree *T);
// Penambahan anak
void addChild(char child[], simpul *root);
// Penghapusan node
void delAll(simpul *root);
// Penghapusan anak pada sebuah parent
void delChild(char c[], simpul *root);
// Pencarian sebuah node
simpul *findSimpul(char c[], simpul *root);
// Output preorder
void printTreePreOrder(simpul *root, int *banyak);