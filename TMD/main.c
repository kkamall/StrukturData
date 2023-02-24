/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Tugas Masa Depan - Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    tree T;
    dataMie mie[100];

    /*
        (1) banyaMie = banyak inputan
        (2) deepest = maximum depth
        (3) inputMie = inputnya full
        (4) parent = parent node
        (5) hargaMinimum = harga minimum
    */
    int banyakMie, deepest = 0;
    scanf("%d", &banyakMie);

    char inputMie[201], parent[201], hargaMinimum[10];
    simpul *node;

    // Proses inputan
    for(int i = 0; i < banyakMie; i++)
    {
        scanf("%s", &inputMie);

        // Memisahkan inputan
        pemisah(inputMie, &mie[i].mie, &parent, &mie[i].harga, &mie[i].banyakKomponen);

        // Input komponen
        for(int j = 0; j < mie[i].banyakKomponen; j++)
        {
            scanf("%s", &mie[i].inputKomponen[j]);
        }
        
        // Pembuatan tree
        if(i == 0)
        {
            mie[i].depth = 0;
            // Inisialisasi Tree
            makeTree(mie[i].mie, mie[i].harga, mie[i].inputKomponen, mie[i].banyakKomponen, mie[i].depth, "NULL", &T);
        }
        else
        {
            // Cari maximum depth
            for(int k = 0; k < i; k++)
            {
                if(strcmp(parent, mie[k].mie) == 0)
                {
                    mie[i].depth = mie[k].depth + 1;
                    if(deepest < mie[i].depth)
                    {
                        deepest = mie[i].depth;
                    }
                }
            }
            node = findSimpul(parent, T.root);
            // Tambah Anak
            addChild(mie[i].mie, mie[i].harga, mie[i].inputKomponen, mie[i].banyakKomponen, mie[i].depth, parent, node);
        }
    }
    scanf("%s", &hargaMinimum);

    int stringTerpanjang[deepest];
    for(int i = 0; i <= deepest; i++)
    {
        stringTerpanjang[i] = 0;
    }
    // Cari string terpanjang
    cariStringTerpanjang(mie, banyakMie, deepest, &stringTerpanjang);
    // Mengeluarkan output Tree yang belum dihapus
    printTreePreOrder(T.root, stringTerpanjang, deepest, 0, T.root);
    // Hapus mie dengan harga di bawah harga minimum
    hapusMie(mie, banyakMie, hargaMinimum, T.root);
    // Cari node terakhir
    simpul *terakhir = cariNodeAkhir(T.root);
    // Mengeluarkan output Tree yang sudah dihapus
    printTreePreOrder(T.root, stringTerpanjang, deepest, 1, terakhir);

    return 0;
}