/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP2 Struktur Data C1 2021
    dalam mata kuliah Stuktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur membuat list
void createList(list *L)
{
    // Di-NULL kan (belum ada elemen)
    (*L).first = NULL;
    (*L).tail = NULL;
}

// Fungsi menghitung banyak elemn
int countElement(list L)
{
    // (1) hasil = banyak elemen
    int hasil = 0;
    // If dengan kondisi ada elemen
    if (L.first != NULL)
    {
        // (1) bantu = penunjuk current elemen
        elemen *bantu;

        // Nge-set bantu di awal
        bantu = L.first;
        // While untuk menghitung elemen hingga NULL (abis)
        while (bantu != NULL)
        {
            // hasil bertambah 1
            hasil = hasil + 1;
            // Iterasi
            bantu = bantu->next;
        }
    }
    // Mengembalikan nilai hasil
    return hasil;
}

// Prosedur menambahkan elemen di awal
void addFirst(char nim[], int nama, int nilai, list *L)
{
    // (1) baru = pointer untuk nunjuk elemen baru
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    // Proses memasukkan inputan user ke elemen baru
    strcpy(baru->kontainer.nama, nim);
    baru->kontainer.tanggal = nama;
    baru->kontainer.kode = nilai;
    // Proses penambahan elemen
    // If dengan kondisi list tidak memiliki elemen
    if ((*L).first == NULL)
    {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    }
    // Else dengan kondisi list memiliki elemen
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

// Prosedur untuk menghapus elemen paling awal
void delFirst(list *L)
{
    // If dengan kondisi list tidak memiliki elemen
    if ((*L).first != NULL)
    {
        // (1) hapus = menunjuk elemen yang akan dihapus
        elemen *hapus = (*L).first;
        // Proses penghapusan
        // If dengan kondisi jumlah elemennya 1
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        // Else dengan kondisi jumlah elemennya > 1
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

// Prosedur menghapus elemen setelah elemen yang diinginkan user
void delAfter(elemen *before, list *L)
{
    // If dengan kondisi ada elemen yang ingin dihapus
    if (before != NULL)
    {
        // (1) hapus = penunjuk elemen yang ingin dihapus
        elemen *hapus = before->next;
        // If dengan kondisi elemen yang ingin dihapus ada
        if (hapus != NULL)
        {
            // Proses penghapusan
            // If dengan kondisi elemen yang ingin dihapus diakhir
            if (hapus->next == NULL)
            {
                (*L).tail = before;
                before->next = NULL;
            }
            // Else dengna kondisi elemen yang ingin dihapus ditengah
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

// Prosedur memberikan output berupa elemen secara reverse
void printElementR(list L)
{
    printf("==== List Barang ====\n");
    // If dengan kondisi ada elemen
    if (L.first != NULL)
    {
        // (1) bantu = penunjuk current elemen
        elemen *bantu = L.tail;
        // while dengna kondisi bantu bukan NULL (habis)
        while (bantu != NULL)
        {
            // Memberikan output
            printf("%d %s\n", bantu->kontainer.kode, bantu->kontainer.nama);
            // Iterasi
            bantu = bantu->prev;
        }
    }
    // Else dengan kondisi gak ada elemen
    else
    {
        printf("Listnya kosong nihh..\n");
    }
    printf("=====================\n");
}

// Prosedur sorting kode secara ascending
void sortingAscKode(list *L)
{
    /*
        (1) flag = penanda adanya pertukaran atau tidak
        (2) tunjuk1, tunjuk2 = nunjuk elemen yang ingin ditukar
        (3) temp = buat nyimpen nilai sementara
    */
    int flag = 1;
    elemen *tunjuk1;
    elemen *tunjuk2;
    elemen *temp;

    // Proses pertuakan
    // While dengan kondisi ada pertuakaran
    while (flag == 1)
    {
        // Set up awal
        flag = 0;
        tunjuk1 = (*L).first;
        tunjuk2 = tunjuk1->next;
        // While dengan kondisi tunjuk2-nya bukan NULL (habis)
        while (tunjuk2 != NULL)
        {
            // If dengan kondisi kode yang ditunjuk pointer tunjuk1 > nilainya dibanding kode yang ditunjuk pointer tunjuk2
            if (tunjuk1->kontainer.kode > tunjuk2->kontainer.kode)
            {
                // If dengan kondisi elemen yang ingin ditukar merupakan elemen pertama
                if (tunjuk1->prev == NULL)
                {
                    (*L).first = tunjuk2;
                }
                // Else dengan kondisi elemen yang ingin ditukar bukan merupakan elemen pertama
                else
                {
                    tunjuk1->prev->next = tunjuk2;
                }
                // If dengan kondisi elemen yang ingin ditukan merupakan elemen terakhir
                if (tunjuk2->next == NULL)
                {
                    (*L).tail = tunjuk1;
                }
                // Else dengan kondisi elemen yang ingin ditukan bukan merupakan elemen terakhir
                else
                {
                    tunjuk2->next->prev = tunjuk1;
                }
                // Proses pertukaran
                tunjuk1->next = tunjuk2->next;
                tunjuk2->next = tunjuk2->prev;
                temp = tunjuk1->prev;
                tunjuk1->prev = tunjuk2;
                tunjuk2->prev = temp;
                // Set flag = 1 (ada pertukaran)
                flag = 1;
                // Keluar dari looping while
                break;
            }
            // Iterasi
            tunjuk1 = tunjuk1->next;
            tunjuk2 = tunjuk2->next;
        }
    }
}

// Prosedur menghapus elemen yang tanggal-nya merupakan keliapatan 5
void hapus(list *L)
{
    // (1) bantu = penunjuk current elemen
    elemen *bantu = (*L).first;
    // Looping while dengan kondisi bantu != NULL (habis)
    while (bantu != NULL)
    {
        // If dengan kondisi tanggal merupakan kelipatan 5
        if (bantu->kontainer.tanggal % 5 == 0)
        {
            // Memberikan output
            printf("%d telah dihapus.\n", bantu->kontainer.kode);
            // Proses penghapusan
            // If dengan kondisi elemen yang ingin dihapus merupakan elemen pertama
            if (bantu->prev == NULL)
            {
                bantu = bantu->next;
                delFirst(L);
            }
            // Else dengan kondisi elemen yang ingin dihapus bukan merupakan elemen pertama
            else
            {
                bantu = bantu->prev;
                delAfter(bantu, L);
            }
        }
        // Else dengan kondisi tanggal bukan merupakan kelipatan 5
        else
        {
            bantu = bantu->next;
        }
    }
}

// Prosedur sorting tanggal secara ascending
void sortingAscTanggal(list *L)
{
    /*
        (1) flag = penanda adanya pertukaran atau tidak
        (2) tunjuk1, tunjuk2 = nunjuk elemen yang ingin ditukar
        (3) temp = buat nyimpen nilai sementara
    */
    int flag = 1;
    elemen *tunjuk1;
    elemen *tunjuk2;
    elemen *temp;
    // If dengan kondisi ada elemen
    if ((*L).first != NULL)
    {
        // Proses pertuakan
        // While dengan kondisi ada pertuakaran
        while (flag == 1)
        {
            // Set up awal
            flag = 0;
            tunjuk1 = (*L).first;
            tunjuk2 = tunjuk1->next;
            // While dengan kondisi tunjuk2-nya bukan NULL (habis)
            while (tunjuk2 != NULL)
            {
                // If dengan kondisi tanggal yang ditunjuk pointer tunjuk1 > nilainya dibanding tanggal yang ditunjuk pointer tunjuk2
                if (tunjuk1->kontainer.tanggal > tunjuk2->kontainer.tanggal)
                {
                    // If dengan kondisi elemen yang ingin ditukar merupakan elemen pertama
                    if (tunjuk1->prev == NULL)
                    {
                        (*L).first = tunjuk2;
                    }
                    // Else dengan kondisi elemen yang ingin ditukar bukan merupakan elemen pertama
                    else
                    {
                        tunjuk1->prev->next = tunjuk2;
                    }
                    // If dengan kondisi elemen yang ingin ditukan merupakan elemen terakhir
                    if (tunjuk2->next == NULL)
                    {
                        (*L).tail = tunjuk1;
                    }
                    // Else dengan kondisi elemen yang ingin ditukan bukan merupakan elemen terakhir
                    else
                    {
                        tunjuk2->next->prev = tunjuk1;
                    }
                    // Proses pertukaran
                    tunjuk1->next = tunjuk2->next;
                    tunjuk2->next = tunjuk2->prev;
                    temp = tunjuk1->prev;
                    tunjuk1->prev = tunjuk2;
                    tunjuk2->prev = temp;
                    // Set flag = 1 (ada pertukaran)
                    flag = 1;
                    // Keluar dari looping while
                    break;
                }
                // Iterasi
                tunjuk1 = tunjuk1->next;
                tunjuk2 = tunjuk2->next;
            }
        }
    }
}