/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal N-Ary Tree - (BPRA1) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Pembuatan Tree
void makeTree(char nama[], tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));

    // Setup Tree
    strcpy(node->kontainer, nama);
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

// Penambahan anak
void addChild(char child[], simpul *root)
{
    // Kondisi root tidak kosong
    if (root != NULL)
    {
        /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak */

        simpul *baru;
        
        // Setup Node
        baru = (simpul *)malloc(sizeof(simpul));
        strcpy(baru->kontainer, child);
        baru->child = NULL;

        // Kondisi root tidak memiliki anak
        if (root->child == NULL)
        {
            baru->sibling = NULL;
            root->child = baru;
        }
        // Kondisi root memiliki anak
        else
        {
            // Kondisi anaknya 1
            if (root->child->sibling == NULL)
            {
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            // Kondisi anakanya > 1
            else
            {
                simpul *last = root->child;
                /* mencari simpul anak terakhir
                karena akan dikaitkan dengan simpul
                baru sebagai simpul anak terakhir yang
                baru, simpul anak terakhir adalah yang
                memiliki sibling simpul anak pertama,
                maka selama belum sampai pada simpul
                anak terakhir, penunjuk last akan
                berjalan ke simpul anak berikutnya */
                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

// Penghapusan node
void delAll(simpul *root)
{
    // Kondisi root tidak kosong
    if (root != NULL)
    {
        // Kondisi root punya anak
        if (root->child != NULL)
        {
            // Kondisi root hanya memiliki 1 anak
            if (root->child->sibling == NULL)
            {
                delAll(root->child);
            }
            // Kondisi root hanya memiliki > 1 anak
            else
            {
                simpul *bantu;
                simpul *proses;
                bantu = root->child;

                // Looping untuk melakukan proses penghapusan
                while (bantu->sibling != root->child)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(proses);
                }
                // Tambahan
                delAll(bantu);
            }
            free(root);
        }
        else
        {
            free(root);
        }
    }
}

// Penghapusan anak pada sebuah node
void delChild(char c[], simpul *root)
{
    // Kondisi root tidak kosong
    if (root != NULL)
    {
        simpul *hapus = root->child;

        // Kondisi simpul hapus tidak kosong
        if (hapus != NULL)
        {
            // Kondisi simpul hapus tidak punya saudara
            if (hapus->sibling == NULL)
            {
                // Kondisi nilai anaknya sama dengan yang dicari
                if (strcmp(root->child->kontainer, c) == 0)
                {
                    // Proses penghapusan
                    delAll(root->child);
                    root->child = NULL;
                }
                // Kondisi anaknya tidak ada yang memiliki nilai yang dicari
                else
                {
                    printf("%s tidak ditemukan\n", c);
                }
            }
            // Kondisi simpul hapus punya saudara
            else
            {
                simpul *prev = NULL;
                int ketemu = 0;

                // Looping untuk mencari simpul yang akan dihapus
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    // Kondisi nilai yang ada pada simpul hapus sama dengan nilai yang dicari
                    if (strcmp(hapus->kontainer, c) == 0)
                    {
                        ketemu = 1;
                    }
                    // Iterasi
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }

                // Memproses simpul anak terakhir karena belum terproses dalam pengulangan
                if ((ketemu == 0) && (strcmp(hapus->kontainer, c) == 0))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;

                    //  mencari simpul anak terakhir untuk membantu proses atau pemeriksaan jika yang dihapus nantinya anak terakhir
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }

                    // Kondisi simpul yang akan dihapus merupakan anak pertama
                    if (prev == NULL)
                    {
                        // jika hanya ada dua anak
                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            root->child = last;
                            last->sibling = NULL;
                        }
                        // jika memiliki simpul anak lebih dari dua simpul
                        else
                        {
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        // jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua
                        if ((prev == root->child) && (hapus == last))
                        {
                            root->child->sibling = NULL;
                        }
                        // jika yang dihapus bukan simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul
                        else
                        {
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus);
                }
                else
                {
                    printf("%s tidak ditemukan\n", c);
                }
            }
        }
    }
}

// Pencarian sebuah node
simpul *findSimpul(char c[], simpul *root)
{
    simpul *hasil = NULL;

    // Kondisi simpul root tidak kosong
    if (root != NULL)
    {
        // Kondisi nilai yang ada pada simpul root sama seperti yang dicari
        if (strcmp(root->kontainer, c) == 0)
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;

            // Kondisi simpul bantu tidak kosong
            if (bantu != NULL)
            {
                // Jika memiliki satu simpul anak
                if (bantu->sibling == NULL)
                {
                    // Kondisi nilai yang ada pada simpul root sama seperti yang dicari
                    if (strcmp(bantu->kontainer, c) == 0)
                    {
                        hasil = bantu;
                    }
                    else
                    {
                        hasil = findSimpul(c, bantu);
                    }
                }
                // Jika memiliki banyak simpul anak
                else
                {
                    int ketemu = 0;

                    // Pencarian simpul
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        // Kondisi nilai yang ada pada simpul root sama seperti yang dicari
                        if (strcmp(bantu->kontainer, c) == 0)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findSimpul(c, bantu);
                            bantu = bantu->sibling;
                            if(hasil != NULL)
                            {
                                ketemu = 1;
                            }
                        }
                    }
                    // Memproses simpul anak terakhir karena belum terproses dalam pengulangan
                    if (ketemu == 0)
                    {
                        if (strcmp(bantu->kontainer, c) == 0)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil = findSimpul(c, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

// Output preorder
void printTreePreOrder(simpul *root, int *banyak)
{
    int i;
    // Kondisi simpul root tidak kosong
    if (root != NULL)
    {
        // Print "->" sebanyak nilai depth simpul
        for(i = 0; i < *banyak; i++)
        {
            printf("->");
        }
        printf("%s\n", root->kontainer);
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            // Kondisi memiliki satu simpul anak
            if (bantu->sibling == NULL)
            {
                *banyak += 1;
                printTreePreOrder(bantu, banyak);
            }
            // Kondisi memiliki > satu simpul anak
            else
            {
                *banyak += 1;
                // Mencetak simpul anak
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu, banyak);
                    bantu = bantu->sibling;
                }
                // Memproses simpul anak terakhir karena belum terproses dalam pengulangan
                printTreePreOrder(bantu, banyak);
            }
            *banyak -= 1;
        }
    }
}