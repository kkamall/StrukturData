/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM4 Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

void createList(list *L)
{

    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        elemen *bantu;

        bantu = L.first;
        while (bantu != NULL)
        {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.goldar, nilai);
    if ((*L).first == NULL)
    {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    }
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *before, char nim[], char nama[], char nilai[], list *L)
{
    if (before != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        strcpy(baru->kontainer.nim, nim);
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.goldar, nilai);
        if (before->next == NULL)
        {
            baru->next = NULL;
            (*L).tail = baru;
        }
        else
        {
            baru->next = before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addBefore(elemen *before, char nim[], char nama[], char nilai[], list *L)
{
    if (before != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        strcpy(baru->kontainer.nim, nim);
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.goldar, nilai);
        if (before->prev == NULL)
        {
            baru->prev = NULL;
            (*L).first = baru;
        }
        else
        {
            baru->prev = before->prev;
            baru->prev->next = baru;
        }
        baru->next = before;
        before->prev = baru;
        baru = NULL;
    }
}

void addLast(char nim[], char nama[], char nilai[], list *L)
{
    if ((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(nim, nama, nilai, L);
    }
    else
    {
        /*jika list tidak kosong*/
        addAfter((*L).tail, nim, nama, nilai, L);
    }
}

void delFirst(list *L)
{

    if ((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen *before, list *L)
{
    if (before != NULL)
    {
        elemen *hapus = before->next;
        if (hapus != NULL)
        {
            if (hapus->next == NULL)
            {
                (*L).tail = before;
                before->next = NULL;
            }
            else
            {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }
            hapus->prev = NULL;
            free(hapus);
        }
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
            delAfter((*L).tail->prev, L);
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

void printElement(list L)
{
    printf("===================\n");
    if (L.first != NULL)
    {
        elemen *bantu = L.first;

        while (bantu != NULL)
        {
            printf("%s %s %s\n", bantu->kontainer.nama, bantu->kontainer.nim, bantu->kontainer.goldar);
            bantu = bantu->next;
        }
    }
    else
    {
        printf("List Kosong\n");
    }
}

void printElementR(list L)
{
    printf("===================\n");
    if (L.first != NULL)
    {
        elemen *bantu = L.tail;

        while (bantu != NULL)
        {
            printf("%s %s %s\n", bantu->kontainer.nama, bantu->kontainer.nim, bantu->kontainer.goldar);
            bantu = bantu->prev;
        }
    }
    else
    {
        printf("List Kosong\n");
    }
}

void delAll(list *L)
{
    if (countElement(*L) != 0)
    {
        int i;
        for (i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
        }
    }
}