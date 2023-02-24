/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UTS Struktur Data C1 2021
    dalam mata Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur membuat list
void createList(list *L)
{
    (*L).first = NULL;
}

// Fungsi menghitung elemen baris
int countElementB(list L)
{
    int hasil = 0;
    // if dengan kondisi list tidak kosong
    if (L.first != NULL)
    {
        eBaris *bantu;

        bantu = L.first;
        // While untuk menghitung banyaknya elemen baris
        while (bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
}

// Fungsi menghitung elemen kolom
int countElementK(eBaris L)
{
    int hasil = 0;
    // If dengan kondisi elemen colom tidak kosong
    if (L.col != NULL)
    {
        eKolom *bantu;
        bantu = L.col;
        // while untuk proses perhitungan
        while (bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

// Prosedur menambah elemen baris menjadi first elemen
void addFirstB(char nim[], char nama[], list *L)
{
    eBaris *baru;

    // Proses pemasukkan nilai ke elemen baru
    baru = (eBaris *)malloc(sizeof(eBaris));
    strcpy(baru->kontainer.kode, nim);
    strcpy(baru->kontainer.nama, nama);

    // Proses memasukkan elemen baru ke list
    baru->col = NULL;
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

// Prosedur menambah elemen kolom menjadi first elemen
void addFirstK(char kode[], char nama[], int bulan, int tahun, char jenis[], eBaris *L)
{
    eKolom *baru;

    // Proses pemasukkan nilai ke elemen baru
    baru = (eKolom *)malloc(sizeof(eKolom));
    strcpy(baru->kontainer_kol.kode, kode);
    strcpy(baru->kontainer_kol.nama, nama);
    baru->kontainer_kol.bulan = bulan;
    baru->kontainer_kol.tahun = tahun;
    strcpy(baru->kontainer_kol.jenis, jenis);

    // Rposes pemasukkan elemen baru ke list
    if ((*L).col == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

// Prosedur menambah elemen baris setelah yang ditentukan
void addAfterB(eBaris *prev, char nim[], char nama[])
{
    eBaris *baru;
    // Proses pemasukkan nilai ke elemen baru
    baru = (eBaris *)malloc(sizeof(eBaris));
    strcpy(baru->kontainer.kode, nim);
    strcpy(baru->kontainer.nama, nama);

    // Proses pemasukkan elemen baru ke list
    baru->col = NULL;
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

// Prosedur menambah elemen kolom setelah yang ditentukan
void addAfterK(eKolom *prev, char kode[], char nama[], int bulan, int tahun, char jenis[])
{
    eKolom *baru;

    // Proses pemasukkan nilai ke elemen baru
    baru = (eKolom *)malloc(sizeof(eKolom));
    strcpy(baru->kontainer_kol.kode, kode);
    strcpy(baru->kontainer_kol.nama, nama);
    baru->kontainer_kol.bulan = bulan;
    baru->kontainer_kol.tahun = tahun;
    strcpy(baru->kontainer_kol.jenis, jenis);

    // Proses pemasukkan elemen baru ke list
    if (prev->next_kol == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL;
}

// Prosedur menambah elemen baris di akhir
void addLastB(char nim[], char nama[], list *L)
{
    // If dengan kondisi list kosong
    if ((*L).first == NULL)
    {
        addFirstB(nim, nama, L);
    }
    // Else dengan kondisi list tidak kosong
    else
    {
        eBaris *last = (*L).first;
        while (last->next != NULL)
        {
            last = last->next;
        }
        addAfterB(last, nim, nama);
    }
}

// Prosedur menambah elemen kolom di akhir
void addLastK(char kode[], char nama[], int bulan, int tahun, char jenis[], eBaris *L)
{
    // If dengan kondisi elemen kolom kosong
    if ((*L).col == NULL)
    {
        addFirstK(kode, nama, bulan, tahun, jenis, L);
    }
    // Else dengan kondisi elemen kolom tidak kosong
    else
    {
        eKolom *last = (*L).col;
        while (last->next_kol != NULL)
        {
            last = last->next_kol;
        }
        addAfterK(last, kode, nama, bulan, tahun, jenis);
    }
}

// Prosedur menghapus elemen kolom pertama
void delFirstK(eBaris *L)
{
    // If dengan kondisis elemen kolom kosong
    if ((*L).col != NULL)
    {
        // Proses penghapusan
        eKolom *hapus = (*L).col;
        if (countElementK(*L) == 1)
        {
            (*L).col = NULL;
        }
        else
        {
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

// Prosedur menghapus elemen kolom setelah yang ditentukan
void delAfterK(eKolom *prev)
{
    eKolom *hapus = prev->next_kol;
    // If dengan kondsisi elemen kolom tidak kosong
    if (hapus != NULL)
    {
        // Proses penghapusan
        if (hapus->next_kol == NULL)
        {
            prev->next_kol = NULL;
        }
        else
        {
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

// Prosedur menghapus elemen kolom terakhir
void delLastK(eBaris *L)
{
    // If dengan kondisi elemen kolom tidak kosong
    if ((*L).col != NULL)
    {
        // If dengan kondisi elemen kolom hanya 1
        if (countElementK(*L) == 1)
        {
            delFirstK(L);
        }
        // Else dengan kondisi elemen kolom > 1
        else
        {
            eKolom *last = (*L).col;
            eKolom *before_last;

            // While untuk membuat pointer last berada di akhir
            while (last->next_kol != NULL)
            {
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

// Prosedur menghapus semua elemen kolom
void delAllK(eBaris *L)
{
    // If dengan kondisi elemen kolom tidak kosong
    if (countElementK(*L) != 0)
    {
        int i;
        // Proses penghapusan
        for (i = countElementK(*L); i >= 1; i--)
        {
            delLastK(L);
        }
    }
}

// Prosedur menghapus elemen baris pertama
void delFirstB(list *L)
{
    // If dengan kondisi list tidak kosong
    if ((*L).first != NULL)
    {
        // Proses penghapusan
        eBaris *hapus = (*L).first;

        if (hapus->col != NULL)
        {
            delAllK(hapus);
        }
        // If dengan kondsisi jumlah elemen baris 1
        if (countElementB(*L) == 1)
        {
            (*L).first = NULL;
        }
        // Else dengan kondsisi jumlah elemen baris > 1
        else
        {
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    // Else dengan kondsisi list kosong
    else
    {
        printf("List Kosong.");
    }
}

// Prosedur menghapus elemen bari setelah yang ditentukan
void delAfterB(eBaris *prev)
{
    if (prev != NULL)
    {
        eBaris *hapus = prev->next;
        // Proses penghapusan
        if (hapus != NULL)
        {
            if (hapus->col != NULL)
            {
                delAllK(hapus);
            }
            if (hapus->next == NULL)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

// Prosedur menghapus elemen baris terakhir
void delLastB(list *L)
{
    // If dengan kondisi list tidak kosong
    if ((*L).first != NULL)
    {
        // If dengan kondisi jumlah elemen baris 1
        if (countElementB(*L) == 1)
        {
            delFirstB(L);
        }
        // Else dengan kondisi jumlah elemn baris > 1
        else
        {
            eBaris *last = (*L).first;
            eBaris *before_last;
            // While untuk membuat pointer last di akhir
            while (last->next != NULL)
            {
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

// Prosedur menghapus semua elemen baris
void delAllB(list *L)
{
    // If dengan kondisi jumlah elemen tidak kosong
    if (countElementB(*L) != 0)
    {
        int i;
        // Proses penghapusan
        for (i = countElementB(*L); i >= 1; i--)
        {
            delLastB(L);
        }
    }
}

// Prosedur mengeluarkan output berupa nilai elemen
void printElement(list L)
{
    // If dengan kondisi list tidak kosong
    if (L.first != NULL)
    {
        eBaris *bantu = L.first;

        // Proses pengeluaran output berupa nilai elemen baris
        while (bantu != NULL)
        {
            printf("%s %s\n", bantu->kontainer.kode, bantu->kontainer.nama);
            eKolom *eCol = bantu->col;
            // Proses pengeluaran output berupa nilai elemen kolom
            while (eCol != NULL)
            {
                printf("- %s %s %d %d %s\n", eCol->kontainer_kol.kode, eCol->kontainer_kol.nama, eCol->kontainer_kol.bulan, eCol->kontainer_kol.tahun, eCol->kontainer_kol.jenis);
                eCol = eCol->next_kol;
            }
            bantu = bantu->next;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

// Prosedur penghapusan/perpindahan obat
void erasing(list *L, int tahun, int bulan)
{
    int flag = 0;
    eBaris *pointer = (*L).first;
    eBaris *pointerOrg = (*L).first;
    eKolom *pointerSekarang;
    eKolom *pointerSebelum;
    // While untuk membuat pointerOrg menunjuk elemen terakhir
    while (pointerOrg->next != NULL)
    {
        pointerOrg = pointerOrg->next;
    }
    eKolom *pointerKOrg;

    // While dengan kondisi pointer bukan elemen akhir
    while (pointer != pointerOrg)
    {
        pointerSekarang = pointer->col;
        pointerSebelum = pointer->col;
        // While dengan kondisi pointerSekarang bukan null
        while (pointerSekarang != NULL)
        {
            flag = 0;
            // If dengan kondisi jenisnya sirup
            if (strcmp(pointerSekarang->kontainer_kol.jenis, "sirup") == 0)
            {
                // If dengan kondisi tanggal obat > tanggal pihak berwenang
                if (((pointerSekarang->kontainer_kol.tahun >= tahun) && (pointerSekarang->kontainer_kol.bulan >= bulan)) || (pointerSekarang->kontainer_kol.tahun > tahun))
                {
                    // Proses penghapusan
                    if (pointerSekarang == pointerSebelum)
                    {
                        if (pointerOrg->col == NULL)
                        {
                            pointer->col = pointerSebelum->next_kol;
                            pointerOrg->col = pointerSebelum;
                            pointerSekarang = pointerSekarang->next_kol;
                            pointerSebelum->next_kol = NULL;
                        }
                        else
                        {
                            pointer->col = pointerSebelum->next_kol;
                            pointerKOrg->next_kol = pointerSebelum;
                            pointerSekarang = pointerSekarang->next_kol;
                            pointerSebelum->next_kol = NULL;
                        }
                        flag = 1;
                        pointerSebelum = pointerSekarang;
                    }
                    else
                    {
                        if (pointerOrg->col == NULL)
                        {
                            pointerSebelum->next_kol = pointerSekarang->next_kol;
                            pointerOrg->col = pointerSekarang;
                            pointerSekarang->next_kol = NULL;
                        }
                        else
                        {
                            pointerSebelum->next_kol = pointerSekarang->next_kol;
                            pointerKOrg->next_kol = pointerSekarang;
                            pointerSekarang->next_kol = NULL;
                        }
                        flag = 1;
                        pointerKOrg = pointerSekarang;
                        pointerSekarang = pointerSebelum->next_kol;
                    }
                    pointerKOrg = pointerOrg->col;
                    while (pointerKOrg->next_kol != NULL)
                    {
                        pointerKOrg = pointerKOrg->next_kol;
                    }
                }
            }
            // Proses iterasi
            if (flag != 1)
            {
                if (pointerSekarang != pointerSebelum)
                {
                    pointerSebelum = pointerSekarang;
                }
                pointerSekarang = pointerSekarang->next_kol;
            }
        }
        // Proses iterasi
        pointer = pointer->next;
    }
}