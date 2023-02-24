/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal N-Ary Tree - (NT22C1) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nama[20];
    int nilai;
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

void makeTree(data c, tree *T);
void addChild(data c, simpul *root);
void delAll(simpul *root);
void delChild(char c[], int nilai, simpul *root);
simpul *findSimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root, int *tanda, int banyak);
void printTreePostOrder(simpul *root, int *tanda, int banyak);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
void banyakNode(simpul *root, int *banyak);