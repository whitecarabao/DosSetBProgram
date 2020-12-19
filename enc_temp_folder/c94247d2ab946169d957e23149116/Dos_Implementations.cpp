#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Dos_Header.h"
#include <string.h>


struct Node* newNode(char* data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    //node->data = data;
    strcpy_s(node->data, data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void padding(char ch, int n) {
    int i;

    for (i = 0; i < n; i++)
        putchar(ch);
}

void showTree(Node* root, int level) {
    int i;

    if (root == NULL) {
        padding('\t', level);
        puts("-->");
    }
    else {
        showTree(root->right, level + 1);
        padding('\t', level);
        printf("%s - [PHP %d] \n", root->data, root->commission);
        showTree(root->left, level + 1);
    }
}




Node* search(Node* root, char* data)
{

    if (root == NULL)
        return NULL;
    else if ((strcmp(root->data, data)==0))
        return root;
    else {
        Node* left = search(root->left, data);
        return left ? left : search(root->right, data);
    }
}

int compensateUpline(Node* root, char* data) {
    /* Recursion termination condition */
    if (root == NULL)
        return FALSE;

    if ((strcmp(root->data, data)) == 0)
        return TRUE;

    if (compensateUpline(root->left, data) ||
        compensateUpline(root->right, data)) {
        /* If num is present is any any of the two sub tree
         of root, then root is an ancestor of num */
        root->commission += 500;



        printf("\n\nUPLINE - [%s] COMPENSATED\nNEW BALANCE: PHP %d ", root->data, root->commission);
        
        return TRUE;
    }
    else {
        /* If none of the sub tree of root contains num,
        then root is not an ancestor of num */
        return FALSE;
    }
}

void downline(Node* root, char* tmpUpID, char* tmpID) {

    int insDone = 0;

    Node* tmpHolder = search(root, tmpUpID);
    printf("\nNode found in: %p", tmpHolder);


    if (tmpHolder == NULL) {

        printf("\nERROR - UPLINE NOT FOUND!");
        insDone = 1;
    }
    if (insDone != 1 && tmpHolder->left == NULL) {
        tmpHolder->left = newNode(tmpID);
        tmpHolder->left->commission = 0;
        //  tmpHolder->commission += 500;
        insDone = 1;
    }
    if (insDone != 1 && tmpHolder->right == NULL) {
        tmpHolder->right = newNode(tmpID);
        tmpHolder->right->commission = 0;

        compensateUpline(root, tmpHolder->right->data);
        _getch(); //preview compensated uplines
        insDone = 1;
    }

    insDone = 0;
}

