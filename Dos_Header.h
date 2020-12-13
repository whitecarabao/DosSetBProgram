#ifndef dos_h
#define dos_h
#define COUNT 4
#define MAX_CHAR 100
#pragma warning(disable:4996)


#include <conio.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <Windows.h>
struct Node
{
    char data[MAX_CHAR];
    struct Node* left, * right;
};



struct Node* newNode(char* data);
void print2DUtil(Node* root, int space);
void print2D(Node* root);
Node* search(Node* root, char* data);
	
#endif // !dos_h
