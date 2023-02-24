/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM2 Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
}

int countElement(list L)
{
    int hasil = 0;

    if (L.first != NULL)
    {
        elemen *tunjuk;
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            hasil++;
            tunjuk = tunjuk->next;
        }
    }

    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nim);
    strcpy(baru->kontainer.jenis_kelamin, nama);
    strcpy(baru->kontainer.asal_buku, nilai);

    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *prev, char nim[], char nama[], char nilai[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nim);
    strcpy(baru->kontainer.jenis_kelamin, nama);
    strcpy(baru->kontainer.asal_buku, nilai);

    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addLast(char nim[], char nama[], char nilai[], list *L)
{
    if ((*L).first == NULL)
    {
        addFirst(nim, nama, nilai, L);
    }
    else
    {
        elemen *prev = (*L).first;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        addAfter(prev, nim, nama, nilai, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen *prev, list *L)
{
    elemen *hapus = prev->next;
    if (hapus != NULL)
    {
        if (hapus->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            elemen *last = (*L).first;
            elemen *prev;

            while (last->next != NULL)
            {
                prev = last;
                last = last->next;
            }
            delAfter(prev, L);
        }
    }
}

void printElement(list L)
{
    if (L.first == NULL)
    {
        printf("--------------------\n");
        printf("List Kosong.\n");
    }
    else
    {
        elemen *tunjuk = L.first;
        printf("--------------------\n");
        while (tunjuk != NULL)
        {
            printf("%s - %s - %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.jenis_kelamin, tunjuk->kontainer.asal_buku);

            tunjuk = tunjuk->next;
        }
    }
}

void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i > 0; i--)
    {
        delLast(L);
    }
}