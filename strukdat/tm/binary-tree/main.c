/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include "header.h"

int main() {
    Tree T;
    char cIn;
    scanf(" %c", &cIn);
    makeTree(cIn, &T);
 
    scanf(" %c", &cIn);
    addRight(cIn, T.root);
 
    scanf(" %c", &cIn);
    addLeft(cIn, T.root);
 
    scanf(" %c", &cIn);
    addLeft(cIn, T.root->right);
 
    scanf(" %c", &cIn);
    addRight(cIn, T.root->left);
 
    scanf(" %c", &cIn);
    addRight(cIn, T.root->right);
 
    scanf(" %c", &cIn);
    addLeft(cIn, T.root->left->right);
 
    scanf(" %c", &cIn);
    addRight(cIn, T.root->right->left);
 
    scanf(" %c", &cIn);
    addRight(cIn, T.root->left->right);
 
    scanf(" %c", &cIn);
    addRight(cIn, T.root->right->right);
 
    scanf(" %c", &cIn);
    addLeft(cIn, T.root->right->right);
 
    scanf(" %c", &cIn);
    addLeft(cIn, T.root->left->right->left);
 
    scanf(" %c", &cIn);
    addLeft(cIn, T.root->right->left->right);
 
    scanf(" %c", &cIn);
    addRight(cIn, T.root->right->left->right);
 
    printf("Pre Order:\n");
    printTreePreOrder(T.root);
    printf("\n");
 
    delLeft(T.root->left->right->left);
    printf("In Order:\n");
    printTreeInOrder(T.root);
    printf("\n");
 
    delRight(T.root->right->right);
    printf("Post Order:\n");
    printTreePostOrder(T.root);
    printf("\n");
 
    return 0;
}