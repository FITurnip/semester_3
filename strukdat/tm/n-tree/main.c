#include <stdio.h>
#include <string.h>
#include "header.h"

int main() {
    Tree T, T2;
    TShirt temp;
    scanf(" %s %s", temp.name, temp.t_size);
    makeTree(temp, &T);
    scanf(" %s %s", temp.name, temp.t_size);
    addChild(temp, T.root);
    scanf(" %s %s", temp.name, temp.t_size);
    addChild(temp, T.root);
    scanf(" %s %s", temp.name, temp.t_size);
    addChild(temp, T.root);
    scanf(" %s %s", temp.name, temp.t_size);
    addChild(temp, T.root->child->sibling);
    scanf(" %s %s", temp.name, temp.t_size);
    addChild(temp, T.root->child->sibling);
 
    printf("Pohon Data Merchandise:\n================================\n");
 
    printTreePreOrder(T.root, 1);
    printf("\n");
    printTreePostOrder(T.root, 1);
    printf("\n");
 
    delChild(T.root->child->sibling->child->sibling->container, T.root->child->sibling);
    printTreePreOrder(T.root, 1);
    printf("\n");
    printTreePostOrder(T.root, 1);
    printf("\n");
    scanf(" %s %s", temp.name, temp.t_size);
    addChild(temp, T.root->child);
    scanf(" %s %s", temp.name, temp.t_size);
    addChild(temp, T.root->child->sibling->sibling);
    scanf(" %s %s", temp.name, temp.t_size);
    addChild(temp, T.root->child);
    printTreePreOrder(T.root, 1);
    printf("\n");
 
    printf("\nArsip Pohon Data Merchandise :\n================================\n");
    printf("Salinan Pohon :\n");
    copyTree(T.root, &T2.root);
    printTreePreOrder(T.root, 1);
    printf("\n");
    if(isEqual(T.root, T2.root) == 1) printf("Sama\n");
 
    printf("\nData yang dicari:\n================================\n");
    scanf(" %s", temp.name);
    // strcpy(temp.t_size, "XS");
    printf("%s ", temp.name);
    if(findNode(temp, T.root->child->child) == NULL) printf("tidak ");
    // printf("\n");
    printf("ditemukan\n");
 
    printf("%s ", temp.name);
    if(findNode(temp, T.root->child->sibling) == NULL) printf("tidak ");
    // printf("\n");
    printf("ditemukan\n");
 
    printf("%s ", temp.name);
    if(findNode(temp, T.root) == NULL) printf("tidak ");
    // printf("\n");
    printf("ditemukan\n");
    return 0;
}