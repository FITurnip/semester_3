#pragma once
 
// Struktur data n-er tree
#define Container TShirt
typedef struct {
    char name[101], t_size[4];
} TShirt;
 
typedef struct nodeStruct* nodeAddress;
typedef struct nodeStruct {
    Container container;
    nodeAddress sibling, child;
} Node;
 
typedef struct {
    Node* root;
} Tree;
 
// Memmbuat node & tree
Node *makeNode(Container container);
void makeTree(Container container, Tree *tree);
void addChild(Container container, Node *root);
 
// Menghapus tree
void delAll(Node *root);
void delChild(Container container, Node *root);
 
// Mencari node
Node *findNode(Container container, Node *root);
 
// Print element
void printTreePreOrder(Node *root, int isFirstPrintedNode);
void printTreePostOrder(Node *root, int isFirstPrintedNode);
 
// Menyalin tree
void copyTree(Node *src, Node **dst);
 
// Membandingkan tree
int isEqual(Node *a, Node *b);
