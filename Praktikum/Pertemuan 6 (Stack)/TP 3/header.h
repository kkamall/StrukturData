/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP3 Struktur Data C1 2021
    dalam mata kuliah Stuktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Typedef struct data makanan
typedef struct
{
    int harga;
    char nama[50];
    int kalori;
} makanan;

// Typedef struct kontainer dan next elemen
typedef struct elmt *alamatelmt;
typedef struct elmt
{
    makanan kontainer;
    alamatelmt next;
} elemen;

// Kontainer stack (kumpulan elemen + top)
typedef struct
{
    elemen *top;
} stack;

// Setting stack
void createEmpty(stack *S);
// Cek stack kosong atau tidak
int isEmpty(stack S);
// Menghitung banyak elemen pada stack
int countElement(stack S);
// Push elemen baru
void push(int harga, char nama[], int kalori, stack *S);
// Push elemen baru sesuai nilai Ascii
void push2(int harga, char nama[], int kalori, stack *S1, stack *S2);
// Print isi setiap elemen
void printStack(stack S1, stack S2);