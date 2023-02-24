/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz 2 - (stfil22) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Set up stack
void createEmpty(stack *S)
{
    (*S).top = -1;
}

// Cek elemen stack kosong atau tidak
int isEmpty(stack S)
{
    int hasil = 0;
    // Stack kosong
    if (S.top == -1)
    {
        hasil = 1;
    }

    return hasil;
}

// Cek elemen stack penuh atau tidak
int isFull(stack S, int flag)
{
    int hasil = 0;

    // Stack penuh
    if (flag == 0)
    {
        // Total stack besar
        if (S.top == 50)
        {
            hasil = 1;
        }
    }
    else
    {
        // Total stack wilayah
        if (S.top == 10)
        {
            hasil = 1;
        }
    }
    return hasil;
}

// Memasukkan nilai ke stack
void push(char nim[], char nama[], char kota[], stack *S, int flag)
{
    // Stack penuh
    if (isFull(*S, flag) == 1)
    {
        printf("Stack Penuh!\n");
    }
    // Stack tidak penuh
    else
    {
        // Stack kosong
        if (isEmpty(*S) == 1)
        {
            (*S).top = 0;
            // Pemasukan nilai ke elemen stack
            strcpy((*S).data[(*S).top].nama, nim);
            strcpy((*S).data[(*S).top].kounter, nama);
            strcpy((*S).data[(*S).top].kota, kota);
        }
        // Stack tidak kosong
        else
        {
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            // Pemasukan nilai ke elemen stack
            strcpy((*S).data[(*S).top].nama, nim);
            strcpy((*S).data[(*S).top].kounter, nama);
            strcpy((*S).data[(*S).top].kota, kota);
        }
    }
}

// Mengeluarkan elemen dari stack
void pop(stack *S)
{
    // Stack tidak kosong
    if ((*S).top != -1)
    {
        (*S).top--;
    }
}

void popAll(stack *S)
{
    int i;
    for(i=(*S).top; i>=0; i--)
    {
        pop(S);
    }
}

// Output berupa nilai kontainer setiap elemen stack
void printStack(stack S)
{
    // Stack tidak kosong
    if (S.top != -1)
    {
        printf("--- Isi Stack ---\n");

        int i;
        // Print nilai
        for (i = S.top; i >= 0; i--)
        {
            printf("%s %s %s\n", S.data[i].nama, S.data[i].kounter, S.data[i].kota);
        }
        printf("---\n");
    }
    // Stack kosong
    else
    {
        printf("Stack kosong\n");
    }
}

// Output berupa nilai kontainer setiap elemen stack array
void printStackA(stack S[], int m)
{
    int j;
    for (j = 0; j < m; j++)
    {
        // Stack tidak kosong
        if (S[j].top != -1)
        {
            printf("stack %s\n", S[j].data[0].kota);

            int i;
            // Print nilai
            for (i = 0; i <= S[j].top; i++)
            {
                printf("- %s %s %s\n", S[j].data[i].nama, S[j].data[i].kounter, S[j].data[i].kota);
            }
            if (j < m - 1)
            {
                printf("\n");
            }
        }
        else
        {
            printf("Stack kosong\n");
        }
    }
}

// Pemindahan elemen sesuai dengan wilayah
void move(stack *S, stack *S2, int m, int n, char nama2[])
{
    int j, k;
    for (k = (*S).top; k >= 0; k--)
    {
        // Kotanya sama
        if (strcmp((*S).data[k].kota, nama2) == 0)
        {
            // Pemindahan elemen
            push((*S).data[k].nama, (*S).data[k].kounter, (*S).data[k].kota, S2, 1);
        }
    }
}