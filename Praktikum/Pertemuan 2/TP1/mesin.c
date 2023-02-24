/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP1 Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Buat list
void createList(list *L)
{
    // Pointer first belum dipake (di-NULL-in)
    (*L).first = NULL;
}

// Menghitung banyak elemen di list
int countElement(list L)
{
    // Var buat nyimpen jumlah elemen
    int hasil = 0;

    // Ngecek ada elemen atau enggak
    if (L.first != NULL)
    {
        // Pointer untuk nunjuk ke current elemen
        elemen *tunjuk;
        tunjuk = L.first;

        // While untuk ngitung sampai pointer tunjuk = NULL (mencapai akhir)
        while (tunjuk != NULL)
        {
            hasil++;
            tunjuk = tunjuk->next;
        }
    }

    return hasil;
}

// Menambahkan elemen baru di depan
void addFirst(char nim[], char nama[], int nilai, list *L)
{
    // Pointer elemen baru
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    // Ngisi inputan user ke kontainer baru
    strcpy(baru->kontainer.judul, nim);
    strcpy(baru->kontainer.artis, nama);
    baru->kontainer.urutan = nilai;

    // Ngecek apakah sudah ada elemen atau belum
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

// Menambahkan elemen baru di tengah atau di akhir
void addAfter(elemen *prev, char nim[], char nama[], int nilai, list *L)
{
    // Pointer elemen baru
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    // Ngsisi inputan user ke kontainer baru
    strcpy(baru->kontainer.judul, nim);
    strcpy(baru->kontainer.artis, nama);
    baru->kontainer.urutan = nilai;

    // Ngecek apakah elemen yang ingin ditambahkan di akhir atau di tengah
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

// Menambahkan elemen baru di akhir
void addLast(char nim[], char nama[], int nilai, list *L)
{
    // Ngecek elemennya udah ada atau belum
    if ((*L).first == NULL)
    {
        addFirst(nim, nama, nilai, L);
    }
    else
    {
        elemen *prev = (*L).first;
        // While agar pointer prev nunjuk elemen terakhir
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        addAfter(prev, nim, nama, nilai, L);
    }
}

// Nge-print isi list
void printElement(list L)
{
    // Ngecek apakah ada elemen atau enggak
    if (L.first == NULL)
    {
        printf("Data kosong!!!\n");
    }
    else
    {
        // Pointer buat nunjuk elemen yang ingin di-print
        elemen *tunjuk = L.first;
        // Var buat index
        int i = 1;

        // While untuk nge-print elemen (kontainer)
        while (tunjuk != NULL)
        {
            printf("%s - %s\n", tunjuk->kontainer.judul, tunjuk->kontainer.artis);
            // Lanjut ke elemen selanjutnya
            tunjuk = tunjuk->next;
            i++;
        }
    }
}

// Nuker elemen sesuai urutan yang diinginkan user
void tukar(list *L, char dasar[], char jenis[], int jumlah)
{
    /*
        (1) i, j = buat index looping
        (2) tanda = tanda ada perubaha atau enggak
        (3) ubah = tanda ada yang harus diubah atau enggak
        (4) temp = buat nyimpen nilai sementara
        (5) tunjuk1, tunjuk2, tunjuk3, tunjuk4 = nunjuk ke elemen yang ada kemungkinan ditukar
    */
    int i = 0, j, tanda = 1, ubah = 0;
    elemen *temp;
    elemen *tunjuk1;
    elemen *tunjuk2;
    elemen *tunjuk3;
    elemen *tunjuk4;

    // Ngecek user masukin list musik atau enggak
    if (strcmp((*L).first->kontainer.judul, "-") != 0)
    {
        // Ngecek elemennya ada 2 atau enggak (3 dengan '-')
        if (countElement(*L) >= 3)
        {
            tunjuk1 = (*L).first;
            tunjuk3 = (*L).first;
            tunjuk2 = (*L).first->next;
            tunjuk4 = (*L).first->next;

            // Selection Sort
            while (i < jumlah - 1)
            {
                // Ngecek ada perubaha atau enggak
                if (tanda == 0)
                {
                    tunjuk1 = tunjuk1->next;
                }
                // While untuk mindahin tunjuk3 sampai sebelum tunjuk1
                while ((tunjuk1 != tunjuk3->next) && (tunjuk3 != tunjuk1))
                {
                    tunjuk3 = tunjuk3->next;
                }
                tunjuk2 = tunjuk1->next;
                tunjuk4 = tunjuk1->next;
                // Reset
                tanda = 0;
                ubah = 0;

                // For untuk ngecek ada yang perlu ditukar atau enggak
                for (j = i + 1; j < jumlah; j++)
                {
                    // Ngecek urutannya berdasarkan apa? judul/angka
                    if (strcmp(dasar, "judul") == 0)
                    {
                        // Ngecek jenis urutannya
                        if (strcmp(jenis, "asc") == 0)
                        {
                            // Ngecek apakah judul yang ditunjuk "tunjuk1" > judul yang ditunjuk "tunjuk2"
                            if (strcmp(tunjuk1->kontainer.judul, tunjuk2->kontainer.judul) == 1)
                            {
                                // Set ubah = 1 (ada yang harus diubah)
                                ubah = 1;
                            }
                        }
                        else
                        {
                            // Ngecek apakah judul yang ditunjuk "tunjuk1" < judul yang ditunjuk "tunjuk2"
                            if (strcmp(tunjuk1->kontainer.judul, tunjuk2->kontainer.judul) == -1)
                            {
                                // Set ubah = 1 (ada yang harus diubah)
                                ubah = 1;
                            }
                        }
                    }
                    else
                    {
                        // Ngecek jenis urutannya
                        if (strcmp(jenis, "asc") == 0)
                        {
                            // Ngecek apakah angka yang ditunjuk "tunjuk1" > angka yang ditunjuk "tunjuk2"
                            if (tunjuk1->kontainer.urutan > tunjuk2->kontainer.urutan)
                            {
                                // Set ubah = 1 (ada yang harus diubah)
                                ubah = 1;
                            }
                        }
                        else
                        {
                            // Ngecek apakah angka yang ditunjuk "tunjuk1" < angka yang ditunjuk "tunjuk2"
                            if (tunjuk1->kontainer.urutan < tunjuk2->kontainer.urutan)
                            {
                                // Set ubah = 1 (ada yang harus diubah)
                                ubah = 1;
                            }
                        }
                    }
                    // Ngecek apakah ada yang harus diubah atau enggak
                    if (ubah == 1)
                    {
                        // Ngecek apakah elemen yang ditunjuk oleh "tunjuk1" bersampingan dengan elemen yang ditunjuk oleh "tunjuk2" atau enggak
                        if (tunjuk1->next == tunjuk2)
                        {
                            // Ngecek elemen yang ditunjuk oleh "tunjuk2" di akhir atau enggak
                            if (tunjuk2->next == NULL)
                            {
                                // Proses pertukaran
                                temp = tunjuk2->next;
                                tunjuk2->next = tunjuk1;
                                tunjuk1->next = temp;
                                if (tunjuk3 == tunjuk1)
                                {
                                    (*L).first = tunjuk2;
                                }
                                else
                                {
                                    tunjuk3->next = tunjuk2;
                                }
                                tanda = 1;
                            }
                            else
                            {
                                // Proses pertukaran
                                temp = tunjuk1;
                                tunjuk1->next = tunjuk2->next;
                                tunjuk2->next = temp;
                                if (tunjuk3 == tunjuk1)
                                {
                                    (*L).first = tunjuk2;
                                }
                                else
                                {
                                    tunjuk3->next = tunjuk2;
                                }
                                tanda = 1;
                            }
                        }
                        else
                        {
                            // Ngecek elemen yang ditunjuk oleh "tunjuk2" di akhir atau enggak
                            if (tunjuk2->next == NULL)
                            {
                                // Proses pertukaran
                                temp = tunjuk2->next;
                                tunjuk2->next = tunjuk1->next;
                                if (tunjuk3 == tunjuk1)
                                {
                                    (*L).first = tunjuk2;
                                }
                                else
                                {
                                    tunjuk3->next = tunjuk2;
                                }
                                tunjuk4->next = tunjuk1;
                                tunjuk1->next = temp;
                                tanda = 1;
                            }
                            else
                            {
                                // Proses pertukaran
                                temp = tunjuk1->next;
                                if (tunjuk3 == tunjuk1)
                                {
                                    (*L).first = tunjuk2;
                                }
                                else
                                {
                                    tunjuk3->next = tunjuk2;
                                }
                                tunjuk1->next = tunjuk2->next;
                                tunjuk4->next = tunjuk1;
                                tunjuk2->next = temp;
                                tanda = 1;
                            }
                        }
                    }
                    // Ngecek apakah ada perubahan atau enggak
                    if (tanda == 0)
                    {
                        // Ngecek apakah for looping sudah mencapai batas
                        if (j == jumlah - 1)
                        {
                            i++;
                        }
                        tunjuk2 = tunjuk2->next;
                        if (tunjuk4->next != tunjuk2)
                        {
                            tunjuk4 = tunjuk4->next;
                        }
                    }
                    else
                    {
                        tunjuk1 = tunjuk2;
                        tunjuk3 = (*L).first;
                        break;
                    }
                }
            }
        }
    }
}