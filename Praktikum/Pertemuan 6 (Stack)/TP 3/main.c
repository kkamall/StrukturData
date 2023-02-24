/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal TP3 Struktur Data C1 2021
    dalam mata kuliah Stuktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    /*
        (1) n = banyak inputan
        (2) hargaM, kaloriM, namaM = harga, kalori, dan nama makanan
        (3) i, j = buat looping
        (4) makananS = stack berisi semua data inputan
        (5) makananP = stack berisi inputan yang sesuai dengan constraint makanan pedas
        (6) makananM = stack berisi inputan yang sesuai dengan constraint makanan manis
    */
    int n, hargaM[10], kaloriM[10], i, j;
    char namaM[10][100];
    stack makananS;
    stack makananP;
    stack makananM;
    createEmpty(&makananS);
    createEmpty(&makananP);
    createEmpty(&makananM);

    // Meminta inputan
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %s %d", &hargaM[i], &namaM[i], &kaloriM[i]);
    }

    // Memasukkan elemen ke stack
    for(i = n-1; i>= 0; i--)
    {
        // Memasukkan semua elemen ke stack makananS
        push(hargaM[i], namaM[i], kaloriM[i], &makananS);
        // Memasukkan semua elemen sesuai dengan sifatnya (pedas/manis)
        push2(hargaM[i], namaM[i], kaloriM[i], &makananP, &makananM);
    }

    // Mengeluarkan output
    printStack(makananP, makananM);

    return 0;
}