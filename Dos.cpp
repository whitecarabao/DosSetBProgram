//#include "Dos_Implementations.cpp"
#include "Dos_Header.h"

int main()
{
    int checkExit = 0;
    int selection = 0;
    int insDone = 0;
    char tmpID[MAX_CHAR], tmpUpID[MAX_CHAR];
    Node* root = newNode((char*)"DARYLL");
    root->commission = 0;


   do {

       printf("\n -- DOS Membership System --\nPlease select a choice: \n");
       printf("[1] - Add a new downline\n[2] - Display list of downlines\n[3] - Display Dos Network Tree\n[5] - Exit\n");
       printf("\nSelection: ");
       scanf_s("%d", &selection);


       switch (selection) {

       case 1:
       {
           printf("Please enter your NAME: ");
           //scanf_s("%s", &tmpID);
           getchar();
           fgets(tmpID, 90, stdin);
           getchar();
           strtok(tmpID, "\n");
           printf("\nPlease enter your UPLINE's NAME: ");
           //scanf_s("%s", &tmpUpID);
           fgets(tmpUpID, 90, stdin);
           strtok(tmpUpID, "\n");
           getchar();



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
               break;
       case 3: showTree(root, 0);
           printf("\n\n\n\n\n DOS Membership Tree \n -- Press any key to continue -- ");
           _getch();
               break;

       }
       system("cls");
       selection = '\0';
    } while (checkExit != 1);


    return 0;
}