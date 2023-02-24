/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal UTS Struktur Data C1 2021
    dalam mata Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    int n;
    int m[100];
    int i, j;
    char kodeP[100][20];
    char namaP[100][50];
    char kodeOP[100][20];
    char namaO[100][50];
    int bulanO[100];
    int tahunO[100];
    char jenisO[100][7];
    int bulan;
    int tahun;
    /*
        (1) n = banyak perusahaan
        (2) m = banyak obat
        (3) i, j = buat looping
        (4) kodeP, kodeOP = kode perusahaan
        (5) namaP = Nama perusahaan
        (6) namaO = nama obat
        (7) bulanO, tahunO = tanggal obat
        (8) jenisO = jenis Obat
        (9) bulan, tahun = tanggal dari perusahaan berwenang
    */

    // Pembuatan list
    list L;
    createList(&L);
    // Pointer penunjuk baris yang akan terakhir dimasukkan
    eBaris *pointerB;

    // Proses pemintaan input dan pemasukkan ke list
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %d", &kodeP[i], &namaP[i], &m[i]);
        addLastB(kodeP[i], namaP[i], &L);
        if (i == 0)
        {
            pointerB = L.first;
        }
        else
        {
            pointerB = pointerB->next;
        }
        for (j = 0; j < m[i]; j++)
        {
            scanf("%s %s %d %d %s", &kodeOP[i], &namaO[i], &bulanO[i], &tahunO[i], &jenisO[i]);
            addLastK(kodeOP[i], namaO[i], bulanO[i], tahunO[i], jenisO[i], pointerB);
        }
    }
    scanf("%d %d", &bulan, &tahun);
    addLastB("org", "OrganisasiBerwenang", &L);

    // Proses penghapusan atau pemindahan obat
    erasing(&L, tahun, bulan);
    // Proses pengeluaran output
    printElement(L);

    return 0;
}