#include "header.h"

int main()
{
    int i, tanda = 0, banyak = 0;
    char huruf[15];
    for(i = 0; i<14; i++)
    {
        scanf(" %c", &huruf[i]);
    }

    tree T;
    makeTree(huruf[0], &T);
    addLeft(huruf[1], T.root);
    addRight(huruf[2], T.root);
    addLeft(huruf[3], T.root->right);
    addRight(huruf[4], T.root->left);
    addRight(huruf[5], T.root->right);
    addLeft(huruf[6], T.root->left->right);
    addRight(huruf[7], T.root->right->left);
    addRight(huruf[8], T.root->left->right);
    addRight(huruf[9], T.root->right->right);
    addLeft(huruf[10], T.root->right->right);
    addLeft(huruf[11], T.root->left->right->left);
    addLeft(huruf[12], T.root->right->left->right);
    addRight(huruf[13], T.root->right->left->right);

    hitungNode(T.root, &banyak);

    printf("Pre Order:\n");
    printTreePreOrder(T.root, &tanda, banyak);

    tanda = 0;
    delLeft(T.root->left->right->left);
    printf("\nIn Order:\n");
    printTreeInOrder(T.root, &tanda, banyak);

    tanda = 0;
    delRight(T.root->right->right);
    printf("\nPost Order:\n");
    printTreePostOrder(T.root, &tanda);
    printf("\n");

    return 0;
}