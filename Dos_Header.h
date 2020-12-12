#ifndef dos_h
#define dos_h
#define COUNT 2
#include <conio.h>
#include <stdio.h>
#include <stdlib.h> 
struct Node
{
    char data;
    struct Node* left, * right;
};



struct Node* newNode(int data);
void print2DUtil(Node* root, int space);
void print2D(Node* root);
Node* search(Node* root, int data);
	
#endif // !dos_h
