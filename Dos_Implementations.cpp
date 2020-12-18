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

void compUpline(Node* root, char* data) //work in progress
{
    int test = 0;
    // base case
  

    // return true if given node is found
    if ((strcmp(root->data, data) == 0));
    test = 1;
    printf("\n -- all uplines compensated --");
       // return true;

    // search node in left subtree
    compUpline(root->left, data);
    test = 0;
    // search node in right subtree
    //bool right = false;
    if (test == 0)
        compUpline(root->right, data);

    // if given node is found in either left or right subtree,
    // current node is an ancestor of given node
    if (test == 0)
        root->commission +=500;

    // return true if node is found
  
}
