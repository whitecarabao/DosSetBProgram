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
        puts("--> [OPEN]");
    }
    else {
        showTree(root->right, level + 1);
        padding('\t', level);
        printf("--> %s - [PHP %d] \n", root->data, root->commission);
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



void displayDownlines(Node* root, char* data) {
    //Node* tmpDisp = search(root, data);
    Node* tmpRoot = search(root, data);
    system("cls");
    printf("\n -- [Downlines and Commission Tree of Upline: %s]\n\n", tmpRoot->data);
    showTree(tmpRoot, 0);
    printf("\n -- Press any key to return to menu --");
    _getch();
}



int compensateUpline(Node* nodeToCheck, char* data) {
    /* Recursion termination condition */
    if (nodeToCheck == NULL)
        return FALSE;

    if ((strcmp(nodeToCheck->data, data)) == 0)
        return TRUE;

    if (compensateUpline(nodeToCheck->left, data) ||
        compensateUpline(nodeToCheck->right, data)) {
        /* If num is present is any any of the two sub tree
         of root, then root is an ancestor of num */

        nodeToCheck->commission += 500; //compensate PHP500 to upline for successful pair



        printf("\n\nUPLINE - [%s] COMPENSATED\nNEW BALANCE: PHP %d ", nodeToCheck->data, nodeToCheck->commission);
        
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
    system("cls");
    printf(" -------------- DOS NETWORKING CORP --------------- \n");
    printf("\n -- UPLINE NAME: %s", tmpUpID);
    printf("\n -- NEW MEMBER:  %s", tmpID);
    printf("\n -- COMMISSION EARNED: ");
    
    if (checkDupe(root, tmpID)!= 1) { //check if dupe
        Node* tmpHolder = search(root, tmpUpID);
        //printf("\nNode found in: %p", tmpHolder); //diagnostics 


        if (tmpHolder == NULL) {
            printf(" NULL - UPLINE NOT FOUND!");
            printf("\nERROR - UPLINE NOT FOUND!");
            insDone = 1;
        }
        if (insDone != 1 && tmpHolder->left == NULL) {
            tmpHolder->left = newNode(tmpID);
            tmpHolder->left->commission = 0;
            printf("PHP 0");
            printf("\n -- STATUS: REGISTERED, NOT ELIGIBLE FOR COMMISSION!\n");
            printf("\nOne more downline, %s and you'll get PHP500 commission!\n\n", tmpHolder->data);
            //  tmpHolder->commission += 500;
            insDone = 1;
        }
        if (insDone != 1 && tmpHolder->right == NULL) {
            printf("PHP 500");
            tmpHolder->right = newNode(tmpID);
            tmpHolder->right->commission = 0;
            printf("\n -- STATUS: REGISTERED, ELIGIBLE FOR COMMISSION!\n");
            printf("\n ---------- UPLINE COMPENSATION TABLE ----------- \n ");
            
            compensateUpline(root, tmpHolder->right->data);
            _getch(); //preview compensated uplines

            insDone = 1;
        }
        _getch();
    }
    else {
        printf("\n -- Returning to menu... --\n -- Press any key to continue --\n");
        _getch();
    }
    insDone = 0;
}

int checkDupe(Node* root, char* name) {
    Node* tmpNode = search(root, name);
    if (tmpNode == NULL) {
        return 0;
    }
    else {
        system("cls");
        printf("\n -- This downline already exists! --\n -- Exiting... --\n");
        return 1;
    }

}