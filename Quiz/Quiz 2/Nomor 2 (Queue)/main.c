/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Quiz 2 - (qubea22) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    /*
        (1) n = banyak mahasiswa yang berhak menerima beasiswa
        (2) m = banyak mahasiswa yang telah menerima beasiswa
        (3) i = buat looping
        (4) Q1 = queue mahasiswa yang berhak menerima beasiswa
        (5) Q2 = queue mahasiswa yang telah menerima beasiswa
    */
    int n, m, antrian, semester, i;
    char nama[50];
    queue Q1;
    queue Q2;

    // Set up queue
    createEmpty(&Q1);
    createEmpty(&Q2);

    // Input
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s %d %d", &nama, &antrian, &semester);
        // Pemasukan semua data mahasiswa ke queue Q1
        addP(nama, antrian, semester, &Q1);
    }
    scanf("%d", &m);

    // Proses pemindahan mahasiswa yang telah menerima beasiswa ke queue Q2
    move(&Q1, &Q2, m);
    // Output
    printQueue1(Q1, Q2);

    return 0;
}