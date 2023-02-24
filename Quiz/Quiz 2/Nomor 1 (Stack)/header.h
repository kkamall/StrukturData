/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz 2 - (stfil22) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library
#include <stdio.h>
#include <string.h>

// Data paket
typedef struct
{
    char nama[20];
    char kounter[5];
    char kota[20];
} paket;

// Stack
typedef struct
{
    int top;
    paket data[50];
} stack;

// Set up stack
void createEmpty(stack *S);
// Cek stack kosong atau tidak
int isEmpty(stack S);
// Cek stack penuh atau tidak
int isFull(stack S, int flag);
// Memasukkan elemen baru
void push(char nim[], char nama[], char kota[], stack *S, int flag);
// Mengeluarkan elemen
void pop(stack *S);
// Output berupa nilai kontainer tiap elemen stack
void printStack(stack S);
// Output berupa nilai kontainer tiap elemen stack array
void printStackA(stack S[], int m);
// Pemindahan elemen sesuai dengan wilayah 
void move(stack *S, stack *S2, int m, int n, char nama2[]);
// Mengeluarkan semua elemen
void popAll(stack *S);