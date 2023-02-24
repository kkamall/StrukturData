/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz 2 - (stfil22) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    /*
        (1) n = jumlah elemen
        (2) m = jumlah stack wilayah
        (3) i = looping
        (4) kota 2 = array wilayah
        (5) stack S = stack besar
    */
    int n, m, i;
    char nama[50][20], kounter[50][5], kota[50][20], kota2[20];
    stack S;

    // Set up stack
    createEmpty(&S);

    // Input
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s %s %s", &nama[i], &kounter[i], &kota[i]);
    }
    // Pemasukan nilai ke stack
    for(i=n-1; i>=0; i--)
    {
        push(nama[i], kounter[i], kota[i], &S, 0);
    }


    // Input
    scanf("%d", &m);
    // (6) S2 = Stack wilayah
    stack S2[m];
    for(i=0; i<m; i++)
    {
        // Set up stack
        createEmpty(&S2[i]);
        scanf("%s", &kota2);
        // Pemindahan elemen ke stack wilayah sesuai dengan wilayahnya 
        move(&S, &S2[i], m, n, kota2);
    }
    // Output
    printStackA(S2, m);
    // Mengeluarkan semua elemen stack
    popAll(&S);

    return 0;
}