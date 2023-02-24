/*
    Saya Muhammad Kamal Robbani [2102313] mengerjakan
    soal N-Ary Tree - (BPRA1) Struktur Data C1 2021
    dalam mata kuliah Struktur Data
    untuk keberkahanNya maka saya tidak melakukan kecurangan
    seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main()
{
    /*
        (1) i = flag query
        (2) banyak = depth node
        (3) input1, input2 = parent and/or anak
    */
    int i = 0, banyak = 0;
    char query[15], input1[101], input2[101];
    tree T;
    simpul *node;

    // Proses peng-input-an user
    while(strcmp(query, "DONE;") != 0)
    {
        banyak = 0;
        scanf("%s", &query);

        // Query pembuatan tree
        if(i == 0)
        {
            scanf("%s", &input1);

            // Penghapusan ";"
            input1[strlen(input1)-1] = '\0';
            makeTree(input1, &T);
            i++;
        }
        else
        {
            // Cek query bukan "Preorder;"/"Done;"
            if(strcmp(query, "PREORDER;") != 0 && strcmp(query, "DONE;") != 0)
            {
                scanf("%s %s", &input1, &input2);
            }

            // Penghapusan ";"
            input2[strlen(input2)-1] = '\0';

            // Jika query CHILD
            if(strcmp(query, "CHILD") == 0)
            {
                node = findSimpul(input2, T.root);
                addChild(input1, node);
            }
            // Jika query DELLCHILD
            else if(strcmp(query, "DELLCHILD") == 0)
            {
                node = findSimpul(input2, T.root);
                delChild(input1, node);   
            }
            // Jika query PREORDER
            else if(strcmp(query, "PREORDER;") == 0)
            {
                printf("Output %d:\n=========\n", i);
                i++;
                printTreePreOrder(T.root, &banyak);
            }
        }
    }
    printf("=========\n");

    return 0;
}