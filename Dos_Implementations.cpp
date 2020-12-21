#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dos_Header.h"

void cls() {
    system("CLS");
}

void n(int number) {
    for (int x = 0; x < number; x++)
        printf("\n");
}

void s(int number) {
    for (int x = 0; x < number; x++)
        printf(" ");
}

void sleep(int number) {
    number *= 1000;
    _sleep(number);
}

void prompt(int choice) {
    sleep(1);
    switch (choice) {
    case 1: n(2); s(42); printf(" -- Press any key to continue -- ");
        break;
    case 2: n(2); s(42); printf(" -- Returning to menu... -- "); sleep(1);
        break;
    case 3: n(2); s(42); printf(" -- Exiting... -- "); sleep(1);
        break;
    }
}

void terminate(char answer) {
    n(2); s(5); printf("Program terminated."); n(2);
}

char menu() {
    char x; n(2);
    s(45); printf("DOS Membership System [MENU]"); n(2);
    s(25); printf("Choose an operation to be executed:");
    s(1); printf("[1] Add a new downline"); n(1);
    s(61); printf("[2] Display list of downlines"); n(1);
    s(61); printf("[3] Display Dos Network Tree"); n(1);
    s(61); printf("[0] EXIT"); n(1);
    s(33); printf("Input corresponding number: "); scanf_s("%c", &x);
    cls();
    return x;
}

struct Node* newNode(char* data)
{
    struct Node* node = (Node*)malloc(sizeof(Node));
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
    else if ((strcmp(root->data, data) == 0))
        return root;
    else {
        Node* left = search(root->left, data);
        return left ? left : search(root->right, data);
    }
}

void displayDownlines(Node* root, char* data) {
    Node* tmpRoot = search(root, data);
    cls();
    n(1); printf(" -- [Downlines and Commission Tree of Upline: %s]", tmpRoot->data); n(2);
    showTree(tmpRoot, 0); prompt(1);
    _getch();
}

int compensateUpline(Node* nodeToCheck, char* data) {
    //stops the recursive function
    if (nodeToCheck == NULL)
        return FALSE;
    if ((strcmp(nodeToCheck->data, data)) == 0)
        return TRUE;
    if (compensateUpline(nodeToCheck->left, data) ||
        compensateUpline(nodeToCheck->right, data)) {
       //basically if the node is found in either left or right nodes, it is an ancestor.

        nodeToCheck->commission += 500; //compensate PHP500 to upline for successful pair

        n(2); s(5); printf("UPLINE - [%s] COMPENSATED", nodeToCheck->data);
        n(1); s(5); printf("NEW BALANCE: PHP %d ", nodeToCheck->commission);

        return TRUE;
    }
    else {
      
        return FALSE;
    }
}

void downline(Node* root, char* tmpUpID, char* tmpID) {

    cls(); int insDone = 0;
    n(2); s(51); printf(" DOS NETWORKING CORP "); n(1);
    n(1); s(5); printf("UPLINE NAME: %s", tmpUpID);
    n(1); s(5); printf("NEW MEMBER:  %s", tmpID);
    n(1); s(5); printf("COMMISSION EARNED: ");

    if (checkDupe(root, tmpID) != 1) { //check if dupe
        Node* tmpHolder = search(root, tmpUpID);
        //printf("\nNode found in: %p", tmpHolder); //diagnostics 
        if (tmpHolder->left != NULL && tmpHolder->right != NULL) {
            printf(" PHP ZERO!\n\n   -- ERROR, THIS UPLINE IS ALREADY FULL! -- \n   -- FIND ANOTHER UPLINE AND TRY AGAIN -- \n");
        }
        if (tmpHolder == NULL) {
            n(1); s(5); printf("NULL - UPLINE NOT FOUND!");
            n(1); s(5); printf("ERROR - UPLINE NOT FOUND!");
            insDone = 1;
        }
        if (insDone != 1 && tmpHolder->left == NULL) {
            tmpHolder->left = newNode(tmpID);
            tmpHolder->left->commission = 0;
            printf("PHP 0");
            n(1); s(5); printf("STATUS: REGISTERED, NOT ELIGIBLE FOR COMMISSION!"); n(1); sleep(1);
            n(1); s(5); printf("One more downline, %s and you'll get PHP500 commission!", tmpHolder->data); n(2);
            insDone = 1;
        }
        if (insDone != 1 && tmpHolder->right == NULL) {
            printf("PHP 500");
            tmpHolder->right = newNode(tmpID);
            tmpHolder->right->commission = 0;
            n(1); s(5); printf("STATUS: REGISTERED, ELIGIBLE FOR COMMISSION!"); n(1);
            n(1); s(37); printf(" ---------- UPLINE COMPENSATION TABLE ----------- "); n(1);

            compensateUpline(root, tmpHolder->right->data);
            _getch(); //preview compensated uplines

            insDone = 1;
        }
        _getch();
    }
    else {
        prompt(2); prompt(1);
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
        cls();
        n(1); printf(" -- This downline already exists! -- "); n(1);
        prompt(3);
        return 1;
    }
}