#include "header.h"

void createEmpty(stack *S)
{
    (*S).top = NULL;
}

int isEmpty(stack S)
{
    int hasil = 0;
    if (S.top == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S)
{

    int hasil = 0;

    if (S.top != NULL)
    {
        /* stack tidak kosong */

        elemen *bantu;

        /* inisialisasi */
        bantu = S.top;
        while (bantu != NULL)
        {
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(char nim[], int nilai, stack *S)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nim);
    baru->kontainer.harga = nilai;
    if ((*S).top == NULL)
    {
        // jika stack kosong
        baru->next = NULL;
    }
    else
    {
        // jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S)
{
    if ((*S).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;
        if (countElement(*S) == 1)
        {
            (*S).top = NULL;
        }
        else
        {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("stack kosong");
    }
}

void popS(stack *S1, stack *S2)
{
    if ((*S1).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S1).top;
        if (countElement(*S1) == 1)
        {
            (*S1).top = NULL;
        }
        else
        {
            (*S1).top = (*S1).top->next;
        }
        hapus->next = NULL;

        if ((*S2).top == NULL)
        {
            // jika stack kosong
            hapus->next = NULL;
        }
        else
        {
            // jika stack tidak kosong
            hapus->next = (*S2).top;
        }
        (*S2).top = hapus;
        hapus = NULL;
    }
    else
    {
        printf("stack kosong");
    }
}

void printStack(stack S)
{
    if (S.top != NULL)
    {
        elemen *bantu = S.top;

        int i = 1;
        while (bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.nama);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("- Stack Kosong\n");
    }
}