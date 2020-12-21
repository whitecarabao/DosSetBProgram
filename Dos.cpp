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
		selection = menu();
		switch (selection) {

		case '0': terminate(selection); checkExit = 1; sleep(2);
			break;
		case '1': n(2);
			s(5); printf("Enter your NAME: ");
			getchar();
			fgets(tmpID, 90, stdin);
			getchar();
			strtok(tmpID, "\n");
			s(5); printf("Enter your UPLINE's NAME: ");
			fgets(tmpUpID, 90, stdin);
			strtok(tmpUpID, "\n");
			getchar();
			downline(root, tmpUpID, tmpID);
			insDone = 0;
			break;
		case '2': char tmpSearch[MAX_CHAR];
			cls(); getchar();
			strtok(tmpSearch, "\n");
			n(2); s(51); printf(" DOS [NETWORK TREE] ");
			n(1); s(49); printf(" (Downline Search Mode) ");
			n(1); s(45); printf(" * CASE AND SPACE SENSITIVE! * "); n(2);
			n(1); printf(" -- Enter name of upline: ");
			fgets(tmpSearch, 90, stdin);
			strtok(tmpSearch, "\n");
			displayDownlines(root, tmpSearch);
			break;
		case '3': cls(); n(2);
			s(51); printf(" DOS [NETWORK TREE] "); n(1);
			s(37); printf(" HIGHEST <---------------------------> LOWEST "); n(3);
			showTree(root, 0); prompt(1); _getch();
			break;


		

		}
		cls(); selection = '\0';
	} while (checkExit != 1);
	return 0;
}