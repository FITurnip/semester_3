/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"
#include <stdio.h>
#include <malloc.h>
 
int isFirstPrintedNode;
 
Node *makeNode(Container container) {
    // mengalokasikan memori sebesar Node untuk dipakai
    Node *new = (Node *) malloc (sizeof (Node));
    new->container = container;
    new->right = NULL;
    new->left = NULL;
    return new;
}
 
void makeTree(Container container, Tree *tree) {
    // memberikan alokasi bagi root untuk menyimpan container
    Node *new = makeNode(container);
    (*tree).root = new;
    new = NULL;
}
 
void addRight(Container container, Node *root) {
    if(root->right == NULL) {
        // memberikan alokasi bagi right untuk menyimpan container
        Node *new = makeNode(container);
        (*root).right = new;
        new = NULL;
    } else {
        printf("sudah pernah terisi\n");
    }
}
 
void addLeft(Container container, Node *root) {
    if(root->left == NULL) {
        // memberikan alokasi bagi left untuk menyimpan container
        Node *new = makeNode(container);
        (*root).left = new;
        new = NULL;
    } else {
        printf("sudah pernah terisi\n");
    }
}
 
void delAll(Node *root) {
    if(root != NULL) {
        // menghapus terlebih dahulu child dari parent/root
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}
 
void delRight(Node *root) {
    if(root != NULL) {
        if(root->right != NULL) {
            // hapus seluruh tree bagian right dari root
            delAll(root->right);
            root->right = NULL;
        }
    }
}
 
void delLeft(Node *root) {
    if(root != NULL) {
        if(root->left != NULL) {
            // hapus seluruh tree bagian left dari root
            delAll(root->left);
            root->left = NULL;
        }
    }
}
 
void __printTreePreOrder(Node *root) {
    if(root != NULL) {
        // preOrder mencetak terlebih dahulu kemudian mengunjungi node kiri hingga habis, dilanjut kanan
        if(isFirstPrintedNode == 0) printf(" = ");
        else isFirstPrintedNode = 0;
        printf("%c", root->container);
        __printTreePreOrder(root->left);
        __printTreePreOrder(root->right);
    }
}
 
void printTreePreOrder(Node *root) {
    isFirstPrintedNode = 1;
    __printTreePreOrder(root);
}
 
void __printTreeInOrder(Node *root) {
    if(root != NULL) {
        // inOrder mengunjungi kiri hingga habis, mencetak, dilanjutkan kanan
        __printTreeInOrder(root->left);
        if(isFirstPrintedNode == 0) printf(" = ");
        else isFirstPrintedNode = 0;
        printf("%c", root->container);
        __printTreeInOrder(root->right);
    }
}
 
void printTreeInOrder(Node *root) {
    isFirstPrintedNode = 1;
    __printTreeInOrder(root);
}
 
void __printTreePostOrder(Node *root) {
    if(root != NULL) {
        // postOrder mengunjungi terlebih dahulu dari kiri hingga habis, dilanjut kanan, baru dicetak
        __printTreePostOrder(root->left);
        __printTreePostOrder(root->right);
        if(isFirstPrintedNode == 0) printf(" = ");
        else isFirstPrintedNode = 0;
        printf("%c", root->container);
    }
}
 
void printTreePostOrder(Node *root) {
    isFirstPrintedNode = 1;
    __printTreePostOrder(root);
}
 
void copyTree(Node *src, Node **dst) {
    if(src != NULL) {
        // meng-copy tree src node per node
        (*dst) = (Node *) malloc (sizeof (Node));
        (*dst)->container = src->container;
        if(src->left != NULL) copyTree(src->left, &(*dst)->left);
        if(src->right != NULL) copyTree(src->right, &(*dst)->right);
    }
}
 
int isEqual(Node *a, Node *b) {
    // pengecekan dilakukan secara preOrder
    int equalCond = 1;
    if(a != NULL && b != NULL) {
        if(a->container != b->container) {
            equalCond = 0;
        } else {
            equalCond = isEqual(a->left, b->left);
            if(equalCond == 1) equalCond = isEqual(a->right, b->right);
        }
    } else {
        if(a != NULL || b != NULL) equalCond = 0;
    }
 
    return equalCond;
}
 