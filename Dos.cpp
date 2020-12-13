//#include "Dos_Implementations.cpp"
#include "Dos_Header.h"

int main()
{
    int checkExit = 0;
    int selection = 0;
    int insDone = 0;
    char tmpID[MAX_CHAR], tmpUpID[MAX_CHAR];
    Node* root = newNode((char*)"DARYLL");
    //struct Node* root = newNode(1);
    //root->left = newNode(2);
    //root->right = newNode(3);
    //root->left->left = newNode(4);
    //root->left->right = newNode(5);
    //root->right->left = newNode(6);
    //root->right->right = newNode(7);
    //root->left->left->left = newNode(8);
    //root->left->left->right = newNode(9);
    //root->left->right->left = newNode(10);
    //root->left->right->right = newNode(11);
    //root->right->left->left = newNode(12);
    //root->right->left->right = newNode(13);
    //root->right->right->left = newNode(14);
    //root->right->right->right = newNode(15);

    //print2D(root);

   do {

       printf("\n -- DOS Membership System --\nPlease select a choice: \n");
       printf("[1] - Add a new downline\n[2] - Compute and Update Commissions\n[3] - Display list of downlines\n[4] - Display Dos Network Tree\n[5] - Exit\n");
       printf("\nSelection: ");
       scanf_s("%d", &selection);


       switch (selection) {

       case 1:/* if (root->left == NULL && root->right == NULL) {
               Node* tmpNode = newNode(1);
               root->left = tmpNode;*/
       //}
         //    else {
       {
           printf("Please enter your NAME: ");
           //scanf_s("%s", &tmpID);
           getchar();
           fgets(tmpID, 90, stdin);
           strtok(tmpID, "\n");
           printf("\nPlease enter your UPLINE's NAME: ");
           //scanf_s("%s", &tmpUpID);
           fgets(tmpUpID, 90, stdin);
           strtok(tmpUpID, "\n");
           getchar();



           Node* tmpHolder = search(root, tmpUpID);
           printf("\nNode found in: %p", tmpHolder);
           if (tmpHolder == NULL) {
               //tmpHolder = newNode(tmpID);
               strcpy_s(tmpHolder->data, tmpID);
               insDone = 1;
           }
           if (insDone != 1 && tmpHolder->left == NULL) {
               //tmpHolder->left = newNode(tmpID);
               tmpHolder->left = newNode(tmpID);
              // strcpy_s(tmpHolder->left->data, tmpID);
               insDone = 1;
           }
           if (insDone != 1 && tmpHolder->right == NULL) {
               //tmpHolder->right = newNode(tmpID);
               tmpHolder->right = newNode(tmpID);
              // strcpy_s(tmpHolder->right->data, tmpID);
               insDone = 1;
           }
          
           insDone = 0;
       }
               break;
       case 4: print2D(root);
               break;

       }

       selection = '\0';
    } while (checkExit != 1);


    return 0;
}