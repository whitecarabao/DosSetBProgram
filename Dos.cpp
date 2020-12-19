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
           getchar();
           fgets(tmpID, 90, stdin);
           getchar();
           strtok(tmpID, "\n");
           printf("\nPlease enter your UPLINE's NAME: ");
           fgets(tmpUpID, 90, stdin);
           strtok(tmpUpID, "\n");
           getchar();
           downline(root, tmpUpID, tmpID);
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