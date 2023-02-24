/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz 2 - (qubea22) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

// Library
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Data mahasiswa
typedef struct
{
    char nama[50];
    int antrian;
    int semester;
}mahasiswa;

// Elemen
typedef struct elm *alamatelmt;
typedef struct elm
{
    mahasiswa kontainer;
    alamatelmt next;
}elemen;

// Queue
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
void add(char nim[], int nilai, int bantuan, queue *Q);
// Menghapus elemen
void del(queue *Q);
// Memberi output berupa nilai di kontainer elemen
void printQueue1(queue Q, queue Q2);
// Menambah elemen dengan priority
void addP(char nim[], int priority, int bantuan, queue *Q);
// Menggerakkan elemen mahasiswa yang sudah mendapat beasiswa
void move(queue *Q, queue *Q2, int m);