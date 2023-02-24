#include "header.h"

int main()
{
    /*
        (1) kiri = simpul akar
        (2) kanan = pembagi
        (3) flag = tanda stop rekursif (lupa sebutannya)
    */
    int kiri, kanan, flag = 0;
    scanf("%d %d", &kiri, &kanan);

    tree T;
    // Membuat tree
    makeTree(kiri, &T);

    // Menambahkan child node
    prosesTree(T.root, &flag, kiri, kanan);
    // Menghitung banyak node
    int banyak = banyakSimpul(T.root);
    int i = 0;
    
    // Mengeluarkan output
    printTreeInOrder(T.root, banyak, &i);
    printf("\n");

    return 0;
}