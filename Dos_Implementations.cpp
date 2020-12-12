#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Dos_Header.h"



struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void print2DUtil(Node* root, int space)
{
    // Base case 
    if (root == NULL)
        return;

    // Increase distance between levels 
    space += COUNT;

    // Process right child first 
    print2DUtil(root->right, space);
    // Print current node after space 
    // count 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf("  ");
    printf("%d", root->data);

    // Process left child 
    print2DUtil(root->left, space);

}

// Wrapper over print2DUtil() 
void print2D(Node* root)
{
    // Pass initial space count as 0 
    print2DUtil(root, 0);
}

void printList(Node* root){
}



Node* search(Node* root, int data)
{
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->data == data)
        return root;

    // Key is greater than root's key 
    if (root->data < data)
        return search(root->right, data);

    // Key is smaller than root's key 
    return search(root->left, data);
}

//void newMember(Node* root) {
//    char tmpName[100];
//    int data;
//
//
//    printf(" -- Welcome to DOS! -- \n");
//    printf("\nID Number of customer: ");
//
//    fflush(stdin);
//    scanf("%d", &data);
//  //  fgets(tmpName, sizeof(tmpName), stdin);
//  //  printf("\n -- Press Enter to confirm -- \n");
//    getchar();
//    fflush(stdin);
//
//  // leaf/node creation sequence
//    if (root == NULL) {
//        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//        node->data = data;
//        node->left = NULL;
//        node->right = NULL;
//        root = node;
//    }
//    
//    printf("\n ID Number of UPLINE: ");
//   /* else {
//        if(root->left == NULL && root->right == NULL)
//        printf("\n You will be a downline for member: %d", root->data);
//        else {
//            while()
//        }
//
//    }*/
//}

//void insert(Node** p, int num)
//{
//    if ((*p) == NULL)
//    {
//        printf("Leaf node created.");
//        (*p) = (Node*)malloc(sizeof(Node));
//        (*p)->left = NULL;
//        (*p)->right = NULL;
//        (*p)->data = num;
//        return;
//    }
//    else
//    {
//        if (num == (*p)->data)
//        {
//            printf("\nREPEATED ENTRY ERROR VALUE REJECTED\n");
//            return;
//        }
//        if (num < (*p)->data)
//        {
//            printf("\nDirected to left link.\n");
//            insert(&((*p)->left), num);
//        }
//        else
//        {
//            printf("Directed to right link.\n");
//            insert(&((*p)->right), num);
//        }
//    }
//    return;
//}
//
//void inorder(Node* p)
//{
//    if (p != NULL)
//    {
//        inorder(p->left);
//        printf("\nData :%d", p->data);
//        inorder(p->right);
//    }
//    else
//        return;
//}
//
//void preorder(Node* p)
//{
//    if (p != NULL)
//    {
//        printf("\nData :%d", p->data);
//        preorder(p->left);
//        preorder(p->right);
//    }
//    else
//        return;
//}
//
//void postorder(Node* p)
//{
//    if (p != NULL)
//    {
//        postorder(p->left);
//        postorder(p->right);
//        printf("\nData :%d", p->data);
//    }
//    else
//        return;
//}