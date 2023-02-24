/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz Nomor 2 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

void createList(list *L)
{

    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for (i = 0; i < 7; i++)
    {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        int bantu;
        bantu = L.first;
        while (bantu != -1)
        {
            hasil = hasil + 1;
            bantu = L.data[bantu].next;
        }
    }
    return hasil;
}

int emptyElement(list L)
{
    int hasil = -1;
    if (countElement(L) < 7)
    {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 7))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return hasil;
}

void addFirst(char nim[], char nama[], int nilai, list *L)
{
    if (countElement(*L) < 200)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nama, nim);
        strcpy((*L).data[baru].kontainer.bagian, nama);
        (*L).data[baru].kontainer.id = nilai;

        if ((*L).first == -1)
        {
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }

        else
        {
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }
        (*L).first = baru;
    }
    else
    {
        printf("sudah tidak dapat ditambah\n");
    }
}

void addAfter(int before, char nim[], char nama[], int nilai, list *L)
{
    if (countElement(*L) < 200)
    {
        int baru = emptyElement(*L);

        strcpy((*L).data[baru].kontainer.nama, nim);
        strcpy((*L).data[baru].kontainer.bagian, nama);
        (*L).data[baru].kontainer.id = nilai;

        if ((*L).data[before].next != -1)
        {
            (*L).data[baru].prev = before;
            (*L).data[baru].next = (*L).data[before].next;
            (*L).data[before].next = baru;
            (*L).data[(*L).data[baru].next].prev = baru;
        }
        else
        {
            (*L).data[baru].prev = before;
            (*L).data[before].next = baru;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
    }
    else
    {
        printf("sudah tidak dapat ditambah\n");
    }
}

void addLast(char nim[], char nama[], int nilai, list *L)
{
    if ((*L).first == -1)
    {
        addFirst(nim, nama, nilai, L);
    }
    else
    {
        addAfter((*L).tail, nim, nama, nilai, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != -1)
    {
        int hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = -1;
            (*L).tail = -1;
        }
        else
        {
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = -1;
        }
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
    else
    {
        printf("list kosong\n");
    }
}

void delAfter(int before, list *L)
{
    int hapus = (*L).data[before].next;
    if (hapus != -1)
    {
        if ((*L).data[hapus].next == -1)
        {
            (*L).tail = before;
            (*L).data[before].next = -1;
        }
        else
        {
            (*L).data[before].next = (*L).data[hapus].next;
            (*L).data[(*L).data[hapus].next].prev = before;
        }
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
        // printf("JAJAJA\n");
    }
}

void delLast(list *L)
{

    if ((*L).first != -1)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            delAfter((*L).data[(*L).tail].prev, L);
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

void printElement(list L)
{
    if (L.first != -1)
    {
        int bantu = L.first;

        while (bantu != -1)
        {
            printf("%d %s %s\n", L.data[bantu].kontainer.id, L.data[bantu].kontainer.nama, L.data[bantu].kontainer.bagian);
            bantu = L.data[bantu].next;
        }
    }
    else
    {
        printf("List Kosong.\n");
    }
}

void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
    {
        delLast(L);
    }
}

void tukar(int banyak, list *P1, list *P2)
{
    int i;
    int tuker1 = (*P1).first;
    int tuker2 = (*P2).tail;
    for (i = 0; i < banyak; i++)
    {
        tuker2 = (*P2).data[tuker2].prev;
    }
    for (i = 1; i < banyak; i++)
    {
        tuker1 = (*P1).data[tuker1].next;
    }
    for (i = 0; i < banyak; i++)
    {
        addFirst((*P2).data[tuker2].kontainer.nama, (*P2).data[tuker2].kontainer.bagian, (*P2).data[tuker2].kontainer.id, P1);
        tuker2 = (*P2).data[tuker2].next;
        addLast((*P1).data[tuker1].kontainer.nama, (*P1).data[tuker1].kontainer.bagian, (*P1).data[tuker1].kontainer.id, P2);
        tuker1 = (*P1).data[tuker1].prev;
    }
}