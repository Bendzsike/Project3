#include "binarySearchTree.h"

Node *newNode(int item) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->key);
        inorder(root->right);
    }
}

Node *insertBST(Node *node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insertBST(node->left, key);
    else
        node->right = insertBST(node->right, key);

    return node;
}

void fillingUp(Node **node, int *array, int length) {
    for (int i = 0; i < length; ++i) {
        (*node) = insertBST((*node), array[i]);
    }
}

void preorder(Node* root)
{
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        inorder(root->right);
    }

}

void postorder(Node* root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

Node* minValueNode(Node* node){
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

bool searchNode(Node* node, int key){
    if (node == NULL)
        return false;

    if (node->key == key)
        return true;

    bool res1 = searchNode(node->left, key);
    if(res1) return true;
    bool res2 = searchNode(node->right, key);

    return res2;
}

int minNode(Node* root){
    if (root == NULL)
        return INT_MAX;

    int res = root->key;
    int lres = minNode(root->left);
    int rres = minNode(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}

int maxNode(Node* root){
    if (root == NULL)
        return INT_MIN;

    int res = root->key;
    int lres = maxNode(root->left);
    int rres = maxNode(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}