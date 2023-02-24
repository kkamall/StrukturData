/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP2 Struktur Data C1 2021
    dalam mata kuliah Stuktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    /*
        (1) namaB = nama barang
        (2) tanggalB = tanggal masuk barang
        (3) kodeB = kode barang
    */
    char namaB[100][50];
    int tanggalB[100];
    int kodeB[100];
    list L;
    // Proses membuat list
    createList(&L);

    int i = 0;
    // Looping while untuk meminta inputan user hingga "--stop--" dan memasukannya ke list
    while (strcmp(namaB[i - 1], "--stop--") != 0)
    {
        if (i > 0)
        {
            scanf("%d %d", &tanggalB[i - 1], &kodeB[i - 1]);
            addFirst(namaB[i - 1], tanggalB[i - 1], kodeB[i - 1], &L);
        }
        scanf("%s", &namaB[i]);
        i++;
    }
    // Proses sorting kode ascending
    sortingAscKode(&L);
    // Proses menghapus elemen yang memiliki tanggal kelipatan lima
    hapus(&L);
    // Proses sorting tanggal ascending
    sortingAscTanggal(&L);
    // Proses memberi output elemen secara reverse
    printElementR(L);

    return 0;
}