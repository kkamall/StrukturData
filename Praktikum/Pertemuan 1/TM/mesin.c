/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TM Struktur Data C1 2021
    dalam mata kuliah Algoritma dan Pemrograman 2
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

void createList(list *L)
{
    (*L).first = -1;
    int i;

    for (i = 0; i < TOTAL; i++)
    {
        (*L).data[i].next = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;

    if (L.first != -1)
    {
        int hitung;

        hitung = L.first;

        while (hitung != -1)
        {
            hasil++;
            hitung = L.data[hitung].next;
        }
    }

    return hasil;
}

int emptyElement(list L)
{
    int hasil = -1;

    if (countElement(L) < TOTAL)
    {
        int ketemu = 0, i = 0;
        while ((ketemu == 0) && (i < TOTAL))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i++;
            }
        }
    }

    return hasil;
}

void addFirst(char nama[], char level[], char game[], list *L)
{
    if (countElement(*L) < TOTAL)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.level, level);
        strcpy((*L).data[baru].kontainer.game, game);

        if ((*L).first == -1)
        {
            (*L).data[baru].next = -1;
        }
        else
        {
            (*L).data[baru].next = (*L).first;
        }

        (*L).first = baru;
    }
    else
    {
        printf("Data penuh!!!\n");
    }
}

void addAfter(int prev, char nama[], char level[], char game[], list *L)
{
    if (countElement(*L) < TOTAL)
    {
        int baru = emptyElement(*L);

        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.level, level);
        strcpy((*L).data[baru].kontainer.game, game);

        if ((*L).data[prev].next == -1)
        {
            (*L).data[baru].next = -1;
        }
        else
        {
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    }
    else
    {
        printf("Data penuh!!!\n");
    }
}

void addLast(char nama[], char level[], char game[], list *L)
{
    if ((*L).first == -1)
    {
        addFirst(nama, level, game, L);
    }
    else
    {
        // printf("%d\n", countElement(*L));
        if (countElement(*L) < TOTAL)
        {
            int prev = (*L).first;
            while ((*L).data[prev].next != -1)
            {
                prev = (*L).data[prev].next;
            }
            addAfter(prev, nama, level, game, L);
        }
        else
        {
            printf("Data penuh!!!\n");
        }
    }
}

void delFirst(list *L)
{
    if ((*L).first == -1)
    {
        printf("List Kosong.\n");
    }
    else
    {
        int hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = -1;
        }
        else
        {
            (*L).first = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    }
}

void delAfter(int prev, list *L)
{
    int hapus = (*L).data[prev].next;

    if (hapus != -1)
    {
        if ((*L).data[hapus].next == -1)
        {
            (*L).data[prev].next = -1;
        }
        else
        {
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L)
{
    if ((*L).first == -1)
    {
        printf("Data kosong!!!/\n");
    }
    else
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            int hapus = (*L).first;
            int prev;

            while ((*L).data[hapus].next != -1)
            {
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }

            delAfter(prev, L);
        }
    }
}

void printElement(list L)
{
    if (L.first == -1)
    {
        printf("List Kosong.\n");
        printf("--------------------\n");
    }
    else
    {
        int tunjuk = L.first;

        while (tunjuk != -1)
        {
            printf("- %s %s %s\n", L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.level, L.data[tunjuk].kontainer.game);

            tunjuk = L.data[tunjuk].next;
        }
        printf("--------------------\n");
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