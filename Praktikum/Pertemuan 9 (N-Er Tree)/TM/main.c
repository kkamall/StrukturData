#include "header.h"

int main()
{
    data mahasiswa[100];
    char cariNama[100][20];
    int i, banyak, tanda = 0;

    for(i=0; i<9; i++)
    {
        scanf("%s %d", &mahasiswa[i].nama, &mahasiswa[i].nilai);
    }
    scanf("%s", &cariNama[0]);

    printf("Step 1:\n================\n");
    tree T;
    makeTree(mahasiswa[0], &T);
    addChild(mahasiswa[1], T.root);
    addChild(mahasiswa[2], T.root);
    addChild(mahasiswa[3], T.root);
    addChild(mahasiswa[4], T.root->child);
    addChild(mahasiswa[5], T.root->child);

    banyak = 0;
    banyakNode(T.root, &banyak);
    printTreePreOrder(T.root, &tanda, banyak);
    tanda = 0;
    printf("\n");
    printTreePostOrder(T.root, &tanda, banyak);
    tanda = 0;
    printf("\n");

    delChild(T.root->child->child->sibling->kontainer.nama, T.root->child->child->sibling->kontainer.nilai, T.root->child);

    banyak = 0;
    banyakNode(T.root, &banyak);
    printTreePreOrder(T.root, &tanda, banyak);
    tanda = 0;
    printf("\n");
    printTreePostOrder(T.root, &tanda, banyak);
    tanda = 0;
    printf("\n");

    addChild(mahasiswa[6], T.root->child->sibling);
    addChild(mahasiswa[7], T.root->child->sibling);
    addChild(mahasiswa[8], T.root->child->sibling->sibling);
    banyak = 0;
    banyakNode(T.root, &banyak);
    printTreePreOrder(T.root, &tanda, banyak);
    printf("\n");

    printf("Step 2:\n================\n");
    tree T2;
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1)
    {
        printf("Sama\n");
    }
    else
    {
        printf("Tidak sama\n");
    }

    printf("Step 3:\n================\n");
    simpul *simpan = NULL;
    simpan = findSimpul(cariNama[0], T.root->child->child);
    if(simpan != NULL)
    {
        printf("%s ditemukan\n", cariNama[0]);
    }
    else
    {
        printf("%s tidak ditemukan\n", cariNama[0]);
    }
    simpan = NULL;
    simpan = findSimpul(cariNama[0], T.root->child->sibling);
    if(simpan != NULL)
    {
        printf("%s ditemukan\n", cariNama[0]);
    }
    else
    {
        printf("%s tidak ditemukan\n", cariNama[0]);
    }
    simpan = NULL;
    simpan = findSimpul(cariNama[0], T.root);
    if(simpan != NULL)
    {
        printf("%s ditemukan\n", cariNama[0]);
    }
    else
    {
        printf("%s tidak ditemukan\n", cariNama[0]);
    }

    return 0;
}