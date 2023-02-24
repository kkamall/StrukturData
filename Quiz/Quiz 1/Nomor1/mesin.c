/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz 1 Nomor 1 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
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

void addFirst(char nim[], char nama[], int nilai, list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.jenis, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = nilai;

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

void addAfter(elemen *prev, char nim[], char nama[], int nilai, list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.jenis, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = nilai;

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

void addLast(char nim[], char nama[], int nilai, list *L)
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
        printf("Data kosong!!!\n");
    }
    else
    {
        elemen *tunjuk = L.first;

        while (tunjuk != NULL)
        {
            printf("%s %s %d\n", tunjuk->kontainer.jenis, tunjuk->kontainer.nama, tunjuk->kontainer.harga);
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

void tukar(char perusahaan[], char jenis3[], list *P1, list *P2)
{
    int i = 0;
    elemen *flag;
    elemen *flag2;
    elemen *ayam = (*P1).first;
    elemen *tunjuk2 = (*P2).first;
    flag = ayam;
    if (strcmp(perusahaan, "pertama") == 0)
    {
        while (ayam != NULL)
        {
            if (strcmp(ayam->kontainer.jenis, jenis3) != 0)
            {
                addFirst(ayam->kontainer.jenis, ayam->kontainer.nama, ayam->kontainer.harga, P2);
                if (i == 0)
                {
                    delFirst(P1);
                    ayam = ayam->next;
                }
                else
                {
                    delAfter(flag, P1);
                    ayam = ayam->next;
                    flag = flag->next;
                }
                i++;
            }
            else
            {
                flag = flag->next;
                ayam = ayam->next;
                i++;
            }
        }
        flag2 = tunjuk2;
        i = 0;
        while (tunjuk2 != NULL)
        {
            if (strcmp(tunjuk2->kontainer.jenis, jenis3) == 0)
            {
                addFirst(tunjuk2->kontainer.jenis, tunjuk2->kontainer.nama, tunjuk2->kontainer.harga, P1);
                if (i == 0)
                {
                    delFirst(P2);
                    tunjuk2 = tunjuk2->next;
                }
                else
                {
                    delAfter(flag2, P2);
                    flag2 = flag2->next;
                    tunjuk2 = tunjuk2->next;
                }
                i++;
            }
            else
            {
                if (i == 0)
                {
                    tunjuk2 = tunjuk2->next;
                }
                else
                {
                    flag2 = flag2->next;
                    tunjuk2 = tunjuk2->next;
                }
                i++;
            }
        }
        printf("\n");
        printElement(*P1);
        printf("\n");
        printElement(*P2);
    }
    // else
    // {
    //     flag = ayam;
    //     while (tunjuk1 != NULL)
    //     {
    //         if (strcmp(tunjuk1->kontainer.jenis, jenis3) == 0)
    //         {
    //             addFirst(tunjuk1->kontainer.jenis, tunjuk1->kontainer.nama, tunjuk1->kontainer.harga, P2);
    //             if (i == 0)
    //             {
    //                 delFirst(P1);
    //                 tunjuk1 = tunjuk1->next;
    //             }
    //             else
    //             {
    //                 delAfter(flag, P1);
    //                 flag = flag->next;
    //                 tunjuk1 = tunjuk1->next;
    //             }
    //             i++;
    //         }
    //         else
    //         {
    //             if (i == 0)
    //             {
    //                 tunjuk1 = tunjuk1->next;
    //             }
    //             else
    //             {
    //                 flag = flag->next;
    //                 tunjuk1 = tunjuk1->next;
    //             }
    //             i++;
    //         }
    //     }
    //     flag = tunjuk2;
    //     i = 0;
    //     while (tunjuk2 != NULL)
    //     {
    //         if (strcmp(tunjuk2->kontainer.jenis, jenis3) != 0)
    //         {
    //             addFirst(tunjuk2->kontainer.jenis, tunjuk2->kontainer.nama, tunjuk2->kontainer.harga, P1);
    //             if (i == 0)
    //             {
    //                 delFirst(P2);
    //                 tunjuk2 = tunjuk2->next;
    //             }
    //             else
    //             {
    //                 delAfter(flag, P2);
    //                 flag = flag->next;
    //                 tunjuk2 = tunjuk2->next;
    //             }
    //             i++;
    //         }
    //         else
    //         {
    //             if (i == 0)
    //             {
    //                 tunjuk2 = tunjuk2->next;
    //             }
    //             else
    //             {
    //                 flag = flag->next;
    //                 tunjuk2 = tunjuk2->next;
    //             }
    //             i++;
    //         }
    //     }
    // }
}