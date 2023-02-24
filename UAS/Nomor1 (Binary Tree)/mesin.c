#include "header.h"

// Membuat tree
void makeTree(int nilai, tree *T)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    // Pmeasukkan nilai ke kontainer
    baru->nilai = nilai;
    // Setup tree
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

// Menambah anak di kanan
void addRight(int nilai, simpul *root)
{
    if (root->right == NULL)
    {
        /*jika sub pohon kanan kosong*/
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        // Pemasukan nilai ke kontainer
        baru->nilai = nilai;
        // Setup node
        baru->right = NULL;
        baru->left = NULL;
        root->right = baru;
    }
    else
    {
        printf("sub pohon kanan telah terisi \n");
    }
}

// Menambah anak di kiri
void addLeft(int nilai, simpul *root)
{
    if (root->left == NULL)
    {
        /*jika sub pohon kiri kosong*/
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        // Pemasukkan nilai ke kontainer
        baru->nilai = nilai;
        // Setup node
        baru->right = NULL;
        baru->left = NULL;
        root->left = baru;
    }
    else
    {
        printf("sub pohon kiri telah terisi \n");
    }
}

// Menghitung banyak node
int banyakSimpul(simpul *root)
{
    int i=0;
    simpul *begin = root;
    // Proses perhitungan
    while(begin != NULL)
    {
        i++;
        // Iterasi tree
        if(begin->right == NULL)
        {
            begin = begin->left;
        }
        else
        {
            begin = begin->right;
        }
    }

    return i;
}

// Mengeluarkan output dengan teknik inorder
void printTreeInOrder(simpul *root, int banyak, int *i)
{
    if (root != NULL)
    {
        // Rekursif
        printTreeInOrder(root->left, banyak, i);
        // Proses pengeluaran output
        printf("%d", root->nilai);
        // Proses print spasi (agar di akhir tidak ada spasi)
        if(*i < banyak-1)
        {
            printf(" ");
            *i += 1;
        }
        // Rekursif
        printTreeInOrder(root->right, banyak, i);
    }
}

// Menambah node child
void prosesTree(simpul *root, int *flag, int nParent, int nPembagi)
{
    // Hitung nilai root
    int nilai = nParent / nPembagi;
    simpul *bantu = root;
    // Nilai akhir root (setelah dibagi) di atas 1 
    if(nilai >= 1)
    {
        // Nilai genap
        if(nilai % 2 == 0)
        {
            addRight(nilai, root);
            bantu = root->right;
        }
        // Nilai ganjil
        else
        {
            addLeft(nilai, root);
            bantu = root->left;
        }
    }
    else
    // Nilai akhir root (setelah dibagi) di bawah 1 
    {
        *flag = 1;
    }

    // Rekursif
    if(*flag != 1)
    {
        prosesTree(bantu, flag, nilai, nPembagi);   
    }
}