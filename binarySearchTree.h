#ifndef PROJEKT2_BINARYSEARCHTREE_H
#define PROJEKT2_BINARYSEARCHTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
}Node;

Node* newNode(int );
void inorder(Node* );
void preorder(Node* );
void postorder(Node* );
Node* insert(Node* , int );
void fillingUp(Node** );
void push(Node** , int* , int first, int last);
Node* minValueNode(Node* );
Node* deleteNode(Node* , int );
int minNode(Node* );
int maxNode(Node* );
bool searchNode(Node* , int );

#endif //PROJEKT2_BINARYSEARCHTREE_H