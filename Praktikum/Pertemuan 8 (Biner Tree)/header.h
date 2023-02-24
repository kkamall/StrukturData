/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Binary Tree - (BT22C1) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp{
    char kontainer;
    alamatsimpul right;
    alamatsimpul left;
}simpul;

typedef struct{
    simpul* root;
}tree;

void makeTree(char c, tree *T);
void addRight(char c, simpul *root);
void addLeft(char c, simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root, int *tanda, int banyak);
void printTreeInOrder(simpul *root, int *tanda, int banyak);
// void printTreePostOrder(simpul *root);
void printTreePostOrder(simpul *root, int *tanda);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
int depthTree(simpul *root);
void printTreeLevelOrder(simpul *root, int level);
void hitungNode(simpul *root, int *total);