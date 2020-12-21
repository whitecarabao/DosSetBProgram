//#include "Dos_Implementations.cpp"
#include "Dos_Header.h"

int main()
{
    int checkExit = 0;
    char selection = 0;
    int insDone = 0;
    char tmpID[MAX_CHAR], tmpUpID[MAX_CHAR];
    Node* root = newNode((char*)"DARYLL");
    root->commission = 0;


   do {
      
       printf("\n -- DOS Membership System --\nPlease select a choice: \n");
       printf("[1] - Add a new downline\n[2] - Display list of downlines\n[3] - Display Dos Network Tree\n[5] - Exit\n");
       printf("\nSelection: ");
       scanf_s(" %c", &selection);
          
       
       switch (selection) {

       case '1':
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
       
       case '2': 

           char tmpSearch[MAX_CHAR];
           //Node* tmpRoot = search(root, tmpSearch);
           system("cls");
           getchar();
           strtok(tmpSearch, "\n");
           printf("\n  ------------- DOS NETWORK TREE ------------- ");
           printf("\n  ----------- DOWNLINE SEARCH MODE ----------- ");
           printf("\n       -- [CASE AND SPACE SENSITIVE!] --\n\n");
           printf("\n -- Enter name of upline: ");
           fgets(tmpSearch, 90, stdin);
           strtok(tmpSearch, "\n");
           displayDownlines(root, tmpSearch);
           break;

       case '3': 
           system("cls");
           printf(" ------------- DOS NETWORK TREE ------------- \n");
           printf(" HIGHEST <---------------------------> LOWEST \n\n\n");
           showTree(root, 0);
           printf("\n\n      -- Press any key to continue -- ");
           _getch();
               break;
        case '5':
               exit(0);
               break;
       }
       system("cls");
       selection = '\0';
    } while (checkExit == 5);


    return 0;
}
