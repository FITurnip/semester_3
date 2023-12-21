#include "header.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
 
Node *makeNode(Container container) {
    // mengalokasikan memori sebesar Node untuk dipakai
    Node *node = (Node *) malloc (sizeof (Node));
    node->container = container;
    node->sibling = NULL;
    node->child = NULL;
 
    return node;
}
 
void makeTree(Container container, Tree *tree) {
    // memberikan alokasi bagi root untuk menyimpan container
    Node *node = makeNode(container);
    tree->root = node;
    node = NULL;
}
 
void addChild(Container container, Node *root) {
    if(root != NULL) {
        // membuat alokasi bagi node baru untuk menyimpan child dari root
        Node *new = makeNode(container);
 
        if(root->child == NULL) {
            root->child = new;
        } else {
            if(root->child->sibling == NULL) {
                new->sibling = root->child;
                root->child->sibling = new;
            } else {
                Node *last = root->child;
                while(last->sibling != root->child) last = last->sibling;
                new->sibling = root->child;
                last->sibling = new;
            }
        }
 
        new = NULL;
    }
}
 
void delAll(Node *root) {
    if(root != NULL) {
        if(root->child != NULL) {
            // hapus semua anak terlebih dahulu
            if(root->child->sibling == NULL) {
                delAll(root->child);
            } else {
                Node *pointer = root->child;
                Node *delNode;
                while(pointer->sibling != root->child) {
                    delNode = pointer;
                    pointer = pointer->sibling;
                    delAll(delNode);
                }
            }
        }
        // hapus parent
        free(root);
    }
}
 
int isContainerEqual(Container container1, Container container2) {
    int isEqual = 0;
    if(strcmp(container1.name, container2.name) == 0) {
        if(strcmp(container1.t_size, container2.t_size) == 0) {
            isEqual = 1;
        }
    }
 
    return isEqual;
}
 
void delChild(Container container, Node *root) {
    if(root != NULL) {
        Node *delNode = root->child;
        // hanya akan menghapus pada node yang mengadung container
        if(delNode != NULL) {
            if(delNode->sibling == NULL) {  // kondisi parent hanya memiliki satu anak
                if(isContainerEqual(root->child->container, container) == 1) {
                    delAll(root->child);    // hapus seluruh pohon dari node
                    root->child = NULL;
                } else {
                    printf("Node tidak ditemukan\n");
                }
            } else {                        // kondisi parent hanya memiliki lebih dari satu anak
                // temukan terlebih dahulu posisi node
                Node *prev = NULL;
                int found = 0;
 
                while(delNode->sibling != root->child && found == 0) {
                    if(isContainerEqual(delNode->container, container) == 1) {
                        found = 1;
                    } else {
                        prev = delNode;
                        delNode = delNode->sibling;
                    }
                }
                if(found == 0 && isContainerEqual(delNode->container, container) == 1) found = 1;
 
                if(found == 1) {
                    Node *last = root->child;
                    while(last->sibling != root->child) last = last->sibling;
 
                    // perbaiki posisi sibling antara prev dan next dari node yang dihapus
                    if(prev == NULL) {
                        if(delNode->sibling == last && last->sibling == root->child) {
                            root->child = last;
                            last->sibling = NULL;
                        } else {
                            root->child = delNode->sibling;
                            last->sibling = root->child;
                        }
                    } else {
                        if(prev == root->child && last->sibling == root->child) {
                            root->child->sibling = NULL;
                        } else {
                            prev->sibling = delNode->sibling;
                            delNode->sibling = NULL;
                        }
                    }
                    delAll(delNode);    // hapus seluruh pohon dari node
                } else {
                    printf("Node tidak ditemukan\n");
                }
            }
        }
    }
}
 
Node *findNode(Container container, Node *root) {
    // pengecekan dilakukan secara preOrder
    Node *result = NULL;
    if(root != NULL) {
        if(strcmp(root->container.name, container.name) == 0) {
            result = root;
        } else {
            Node *pointer = root->child;
            if(pointer != NULL) {
                if(pointer->sibling == NULL) {
                    if(strcmp(pointer->container.name, container.name) == 0) {
                        result = pointer;
                    }
                    else result = findNode(container, pointer);
                } else {
                    while(pointer->sibling != root->child && result == NULL) {
                        if(strcmp(pointer->container.name, container.name) == 0) {
                            result = pointer;
                        } else {
                            result = findNode(container, pointer);
                            pointer = pointer->sibling;
                        }
                    }
 
                    if(result == NULL) {
                        if(strcmp(pointer->container.name, container.name) == 0) {
                            result = pointer;
                        }
 
                        else result = findNode(container, pointer);
                    } else {
                    }
                }
            }
        }
    }
 
    return result; // akan mengembalikan NULL jika tidak temukan
}
 
void printContainer(Container container) {
    printf("%s %s", container.name, container.t_size);
}
 
void printTreePreOrder(Node *root, int isFirstPrintedNode) {
    if(root != NULL) {
        // preOrder mencetak terlebih dahulu kemudian mengunjungi node kiri hingga habis, dilanjut kanan
        if(isFirstPrintedNode == 0) printf("-");
        else isFirstPrintedNode = 0;
        printContainer(root->container);
        Node *pointer = root->child;
        if(pointer != NULL) {
            if(pointer->sibling != NULL) {
                while(pointer->sibling != root->child) {
                    printTreePreOrder(pointer, 0);
                    pointer = pointer->sibling;
                }
            }
            printTreePreOrder(pointer, 0);
        }
    }
}
 
void printTreePostOrder(Node *root, int isFirstPrintedNode) {
    if(root != NULL) {
        // postOrder mengunjungi terlebih dahulu dari kiri hingga habis, dilanjut kanan, baru dicetak
        Node *pointer = root->child;
        if(pointer != NULL) {
            if(pointer->sibling == NULL) {
                printTreePostOrder(pointer, 0);
            } else {
                while(pointer->sibling != root->child) {
                    printTreePostOrder(pointer, 0);
                    pointer = pointer->sibling;
                }
 
                printTreePostOrder(pointer, 0);
            }
        }
        printContainer(root->container);
        if(isFirstPrintedNode == 0) printf("-");
        else isFirstPrintedNode = 0;
    }
}
 
void copyTree(Node *src, Node **dst) {
    if(src != NULL) {
        // meng-copy tree src node per node
        (*dst) = makeNode(src->container);
 
        if(src->child != NULL) {
            if(src->child->sibling == NULL) {
                copyTree(src->child, &(*dst)->child);
            } else {
                Node *srcPointer = src->child, *dstPointer = (*dst)->child;
                while(srcPointer->sibling != src->child) {
                    copyTree(srcPointer, &dstPointer);
                    srcPointer = srcPointer->sibling;
                    dstPointer = dstPointer->sibling;
                }
 
                copyTree(srcPointer, &dstPointer);
            }
        }
    }
}
 
int isEqual(Node *a, Node *b) {
    // pengecekan dilakukan secara preOrder
    int equalCond = 1;
    if(a != NULL && b != NULL) {
        if(isContainerEqual(a->container, b->container) == 0) {
            equalCond = 0;
        } else {
            if(a->child != NULL && b->child != NULL) {
                if(a->child->sibling == NULL) {
                    equalCond = isEqual(a->child, b->child);
                } else {
                    Node *aPointer = a->child, *bPointer = b->child;
                    while(aPointer->sibling != a->child && equalCond == 1) {
                        if(aPointer != NULL && bPointer != NULL) {
                            equalCond = isEqual(aPointer, bPointer);
                            aPointer = aPointer->sibling;
                            bPointer = bPointer->sibling;
                        } else {
                            equalCond = 0;
                        }
                    }
 
                    equalCond = isEqual(aPointer, bPointer);
                }
            }
        }
    } else {
        if(a != NULL || b != NULL) {
            equalCond = 0;
        }
    }
 
    return equalCond;
}
