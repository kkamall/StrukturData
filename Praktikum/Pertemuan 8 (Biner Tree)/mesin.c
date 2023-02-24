#include "header.h"

void makeTree(char c, tree *T)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

void addRight(char c, simpul *root)
{
    if (root->right == NULL)
    {
        /*jika sub pohon kanan kosong*/
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->right = NULL;
        baru->left = NULL;
        root->right = baru;
    }
    else
    {
        printf("sub pohon kanan telah terisi \n");
    }
}

void addLeft(char c, simpul *root)
{
    if (root->left == NULL)
    {
        /*jika sub pohon kiri kosong*/
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->right = NULL;
        baru->left = NULL;
        root->left = baru;
    }
    else
    {
        printf("sub pohon kiri telah terisi \n");
    }
}

void delAll(simpul *root)
{

    if (root != NULL)
    {
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(simpul *root)
{
    if (root != NULL)
    {
        if (root->right != NULL)
        {
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(simpul *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void hitungNode(simpul *root, int *total)
{
    if(root->left != NULL)
    {
        *total += 1;
        hitungNode(root->left, total);
    }
    if(root->right != NULL)
    {
        *total += 1;
        hitungNode(root->right, total);
    }
}

void printTreePreOrder(simpul *root, int *tanda, int banyak)
{
    if (root != NULL)
    {
        printf("%c", root->kontainer);
        if(*tanda < banyak)
        {
            printf(" - ");
        }
        if(root->left != NULL)
        {
            *tanda += 1;
            printTreePreOrder(root->left, tanda, banyak);
        }
        if(root->right != NULL)
        {
            *tanda += 1;
            printTreePreOrder(root->right, tanda, banyak);
        }
    }
}

void printTreeInOrder(simpul *root, int *tanda, int banyak)
{
    if (root != NULL)
    {
        if(root->left != NULL)
        {
            *tanda += 1;
            printTreeInOrder(root->left, tanda, banyak);
        }
        printf("%c", root->kontainer);
        if(*tanda < banyak-1)
        {
            printf(" - ");
        }
        if(root->right != NULL)
        {
            *tanda += 1;
            printTreeInOrder(root->right, tanda, banyak);
        }
    }
}

void printTreePostOrder(simpul *root, int *tanda)
{
    if (root != NULL)
    {
        *tanda += 1;
        printTreePostOrder(root->left, tanda);
        printTreePostOrder(root->right, tanda);
        printf("%c", root->kontainer);
        *tanda -= 1;
        if(*tanda > 0)
        {
            printf(" - ");
        }
    }
}

void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        if (root1->left != NULL)
        {
            copyTree(root1->left, &(*root2)->left);
        }
        if (root1->right != NULL)
        {
            copyTree(root1->right, &(*root2)->right);
        }
    }
}

int isEqual(simpul *root1, simpul *root2)
{
    int hasil = 1;

    if ((root1 != NULL) && (root2 != NULL))
    {
        /* jika simpul pohon 1 dan pohon 2 sama sama
        tidak NULL */
        if (root1->kontainer != root2->kontainer)
        {
            /* jika isi kontainer simpul pohon 1 dan pohon
            2 tidak sama */
            hasil = 0;
        }
        else
        {
            /* jika isi kontainer simpul pohon 1 dan simpul
            pohon 2 sama, maka telusuri simpul selanjutnya */
            isEqual(root1->left, root2->left);
            isEqual(root1->right, root2->right);
        }
    }
    else
    {
        if ((root1 != NULL) || (root2 != NULL))
        {
            /* jika salah satu simpul ada yang NULL */
            hasil = 0;
        }
    }

    return hasil;
}

int depthTree(simpul *root) 
{
    int max = 0;
    if (root != NULL) {
        int leftRoot = depthTree(root->left);
        int rightRoot = depthTree(root->right);
        if (leftRoot > rightRoot) {
            max = leftRoot + 1;
            return max;
        } else {
            max = rightRoot + 1;
            return max;
        }
    }
}

void printTreeLevelOrder(simpul *root, int level) 
{
    if (root != NULL) {
        if (level == 1) {
            printf(" %c ", root->kontainer);
        } else if (level > 1) {
            printTreeLevelOrder(root->left, level - 1);
            printTreeLevelOrder(root->right, level - 1);
        }
    }
}