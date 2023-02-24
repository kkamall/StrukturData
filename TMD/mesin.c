/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal Tugas Masa Depan - Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Buat tree
void makeTree(char mie[], char harga[], char komponen[][201], int banyakKomponen, int depth, char parent[], tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));

    // Memasukkan nilai ke kontainer
    strcpy(node->kontainer.nama, mie);
    strcpy(node->kontainer.harga, harga);
    strcpy(node->kontainer.parent, parent);
    for (int i = 0; i < banyakKomponen; i++)
    {
        strcpy(node->kontainer.komponen[i], komponen[i]);
    }
    node->kontainer.banyakKomponen = banyakKomponen;
    node->kontainer.depth = depth;

    // Setup
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

// Menambahkan anak
void addChild(char mie[], char harga[], char komponen[][201], int banyakKomponen, int depth, char parent[], simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak */

        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));

        // Memasukkan nilai ke kontainer
        strcpy(baru->kontainer.nama, mie);
        strcpy(baru->kontainer.harga, harga);
        strcpy(baru->kontainer.parent, parent);
        for (int i = 0; i < banyakKomponen; i++)
        {
            strcpy(baru->kontainer.komponen[i], komponen[i]);
        }
        baru->kontainer.banyakKomponen = banyakKomponen;
        baru->kontainer.depth = depth;
        baru->child = NULL;

        if (root->child == NULL)
        {
            /* jika simpul root belum
            memiliki simpul anak maka simpul baru
            menjadi anak pertama */

            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                /* jika simpul root memiliki
                anak yang belum memiliki saudara, maka
                simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
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

// Menghapus tree
void delAll(simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong */
        if (root->child != NULL)
        {
            if (root->child->sibling == NULL)
            {
                /* jika hanya memiliki satu simpul anak */
                delAll(root->child);
            }
            else
            {
                /* jika hanya memiliki > satu simpul anak */
                simpul *bantu;
                simpul *proses;
                bantu = root->child;
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

// Menghapus anak
void delChild(char c[], simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {
                /*jika hanya mempunyai satu anak*/
                if (strcmp(root->child->kontainer.nama, c) == 0)
                {
                    delAll(root->child);
                    root->child = NULL;
                }
            }
            else
            {
                /*jika memiliki lebih dari satu simpul anak*/
                simpul *prev = NULL;
                /*mencari simpul yang akan dihapus*/
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if (strcmp(hapus->kontainer.nama, c) == 0)
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                /*memproses simpul anak terakhir karena
                belum terproses dalam pengulangan*/
                if ((ketemu == 0) && (strcmp(hapus->kontainer.nama, c) == 0))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk
                    membantu proses atau pemeriksaan jika yang
                    dihapus nantinya anak terakhir */
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {
                        /*jika simpul yang dihapus
                        anak pertama*/
                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            /*jika hanya ada dua anak*/
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            /* jika memiliki simpul anak
                            lebih dari dua simpul */
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (hapus == last))
                        {
                            /* jika hanya ada dua simpul
                            anak dan yang dihapus adalah simpul
                            anak kedua */
                            root->child->sibling = NULL;
                        }
                        else
                        {
                            /* jika yang dihapus bukan
                            simpul anak pertama dan simpul root
                            memiliki simpul anak lebih dari dua
                            simpul */
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus);
                }
            }
        }
    }
}

// Mencari node
simpul *findSimpul(char c[], simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        // Cek kesamaan
        if (strcmp(root->kontainer.nama, c) == 0)
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    // Cek kesamaan
                    if (strcmp(bantu->kontainer.nama, c) == 0)
                    {
                        hasil = bantu;
                    }
                    else
                    {
                        hasil = findSimpul(c, bantu);
                    }
                }
                else
                {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        // Cek kesamaan
                        if (strcmp(bantu->kontainer.nama, c) == 0)
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
                    /*memproses simpul anak terakhir karena
                    belum terproses dalam pengulangan*/
                    if (ketemu == 0)
                    {
                        if (strcmp(bantu->kontainer.nama, c) == 0)
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

// Mengeluarkan output secara pre-order
void printTreePreOrder(simpul *root, int stringTerpanjang[], int deepest, int flag, simpul *terakhir)
{
    if (root != NULL)
    {
        // Print spasi sebelum print nama mie
        for (int x = 0; x < root->kontainer.depth; x++)
        {
            for (int spasi = 0; spasi < stringTerpanjang[x] + 2; spasi++)
            {
                printf(" ");
            }
        }
        // Print nama mie dan harga
        printf("|%s - %s\n", root->kontainer.nama, root->kontainer.harga);
        // Print komponen^2 mie
        for (int z = 0; z < root->kontainer.banyakKomponen; z++)
        {
            // Print spasi sebelum komponen mie
            for (int x = 0; x < root->kontainer.depth; x++)
            {
                for (int spasi = 0; spasi < stringTerpanjang[x] + 2; spasi++)
                {
                    printf(" ");
                }
            }
            printf(" - %s\n", root->kontainer.komponen[z]);
        }
        if(flag != 1 || root != terakhir)
        {
            printf("\n");
        }

        // Rekursif + Itrasi
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu, stringTerpanjang, deepest, flag, terakhir);
            }
            else
            {
                /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu, stringTerpanjang, deepest, flag, terakhir);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak
                terakhir karena belum terproses
                dalam pengulangan*/
                printTreePreOrder(bantu, stringTerpanjang, deepest, flag, terakhir);
            }
        }
    }
}

// Memisahkan inputan user
void pemisah(char inputMie[], char (*mie)[], char (*parent)[], char (*harga)[], int *banyakKomponen)
{
    int j = 0, k = 1;
    for (int i = 0; i < strlen(inputMie); i++)
    {
        if (inputMie[i] != '#')
        {
            // Memisahkan nama mie
            if (k == 1)
            {
                (*mie)[j] = inputMie[i];
                if (inputMie[i + 1] == '#')
                {
                    (*mie)[j + 1] = '\0';
                }
            }
            // Memisahkan parent mie
            else if (k == 2)
            {
                (*parent)[j] = inputMie[i];
                if (inputMie[i + 1] == '#')
                {
                    (*parent)[j + 1] = '\0';
                }
            }
            // Memisahkan harga mie
            else if (k == 3)
            {
                (*harga)[j] = inputMie[i];
                if (inputMie[i + 1] == '#')
                {
                    (*harga)[j + 1] = '\0';
                }
            }
            // Memisahkan banyak komponen mie
            else
            {
                *banyakKomponen = inputMie[i] - 48;
            }
            j++;
        }
        else
        {
            j = 0;
            k++;
        }
    }
}

// Mencari string terpanjang di tiap depth
void cariStringTerpanjang(dataMie mie[], int banyakMie, int deepest, int (*stringTerpanjang)[])
{
    for (int j = 0; j < deepest; j++)
    {
        int flag = 0;
        for (int i = 0; i < banyakMie; i++)
        {
            // Mie memiliki depth yang sama
            if (j == mie[i].depth)
            {
                // Cari string terpanjang berdasarkan mie dan harga
                if ((*stringTerpanjang)[j] < strlen(mie[i].mie) + strlen(mie[i].harga) + 3)
                {
                    (*stringTerpanjang)[j] = strlen(mie[i].mie) + strlen(mie[i].harga) + 3;
                }
                // Cari string terpanjang berdasarkan komponen
                for (int k = 0; k < mie[i].banyakKomponen; k++)
                {
                    if ((*stringTerpanjang)[j] < strlen(mie[i].inputKomponen[k]) + 2)
                    {
                        (*stringTerpanjang)[j] = strlen(mie[i].inputKomponen[k]) + 2;
                    }
                }
            }
        }
    }
}

// Menghapus mie dengan di bawah harga minimum
void hapusMie(dataMie mie[], int banyakMie, char hargaMinimum[], simpul *root2)
{
    simpul *node1;
    simpul *node2;
    for(int i = 0; i < banyakMie; i++)
    {
        int flag = 0;
        // Pengecekan harga lebih kecil -> panjang string current harga mie lebih sedikit dibanding harga minimum
        if(strlen(mie[i].harga) < strlen(hargaMinimum))
        {
            node1 = findSimpul(mie[i].mie, root2);
            node2 = findSimpul(node1->kontainer.parent, root2);
            delChild(node1->kontainer.nama, node2);
        }
        // Pengecekan harga lebih kecil -> panjang string current harga mie sama dengan harga minimum
        else if(strlen(mie[i].harga) == strlen(hargaMinimum))
        {
            for(int j = 0; j < strlen(mie[i].harga); j++)
            {
                // Ascii Current character harga mie lebih kecil dari pada current character harga minimum
                if(mie[i].harga[j] < hargaMinimum[j] && flag == 0)
                {
                    node1 = findSimpul(mie[i].mie, root2);
                    if(node1 != NULL)
                    {
                        node2 = findSimpul(node1->kontainer.parent, root2);
                        delChild(node1->kontainer.nama, node2);
                    }
                }
                // Ascii Current character harga mie lebih besar dari pada current character harga minimum
                else if(mie[i].harga[j] > hargaMinimum[j])
                {
                    flag = 1;
                }
            }
        }
    }
}

// Mencari node paling bawah di pre-order
simpul *cariNodeAkhir(simpul *root)
{
    int flag = 0;
    simpul *bantu1 = root;
    simpul *bantu2 = root;

    while(flag == 0)
    {
        // Proses mencari node terakhir
        while(bantu1->sibling != NULL && bantu1->sibling != bantu2->child)
        {
            bantu1 = bantu1->sibling;
        }
        // node  paling bawah di pre-order
        if(bantu1->child == NULL)
        {
            flag = 1;
            return bantu1;
        }
        // Iterasi
        else
        {
            bantu2 = bantu1;
            bantu1 = bantu1->child;
        }
    }
}