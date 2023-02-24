/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM 7 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char nama[50];
    int rating;
}nilaiMatkul;

typedef struct elm *alamatelmt;
typedef struct elm
{
    nilaiMatkul kontainer;
    alamatelmt next;
}elemen;

typedef struct
{
    elemen *first;
    elemen *last;
}queue;

// Set up queue
void createEmpty(queue *Q);
// Cek queue kosong atau tidak
int isEmpty(queue Q);
// Menghitung banyak elemen
int countElement(queue Q);
// Menambah elemen
void add(char nim[], int nilai, queue *Q);
// Menghapus elemen
void del(queue *Q, queue *Q2);
// Memberi output berupa nilai di kontainer elemen
void printQueue1(queue Q, int i);
// Menambah elemen dengan priority
void addP(char nim[], int nilai, queue *Q, int priority);