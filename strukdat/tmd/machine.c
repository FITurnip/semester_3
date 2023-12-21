#include "header.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
/**
 * Single List
*/
// Set up list
void createList(List *list) {
    (*list).first = NULL; // menandakan list belum terkait ke element manapun
}

// Menghitung banyaknya element pada list
int countElement(List list) {
    int counter = 0; // inisiasi banyak element yang telah dihitung
    if (list.first != NULL) {
        Element *pointer = list.first; // tunjuk element pertama
        while (pointer != NULL) { // selama belum mencapai ujung list, hitung
            counter++;
            pointer = pointer->next; // tunjuk element selanjutnya
        }
    }

    return counter;
}

// Menambahkan element pada list
void addListElementFirst(ListContainer datas, List *list) {
    //  set element
    Element *new = (Element *)malloc(sizeof(Element));
    new->container = datas;

    // kaitkan element pertama ke element selanjutnya
    if ((*list).first == NULL)
        new->next = NULL;
    else
        new->next = (*list).first;
    (*list).first = new; // tunjuk ke element baru
    new = NULL;          // hilangkan kaitan new
}

void addListElementAfter(Element *prev, ListContainer datas) {
    // set element
    Element *new = (Element *)malloc(sizeof(Element));
    new->container = datas;

    // kaitkan element sebelumnya ke element selanjutnya
    if (prev != NULL) {
        if (prev->next == NULL)
            new->next = NULL;
        else
            new->next = prev->next;
        prev->next = new; // tunjuk ke element baru
        new = NULL;       // hilangkan kaitan new
    }
}

void addListElementLast(ListContainer datas, List *list) {
    if ((*list).first == NULL) {
        addListElementFirst(datas, list); // kondisi kosong, masukan ke element pertama
    } else {
        // cari element paling terakhir
        Element *prev = (*list).first;
        while (prev->next != NULL)
            prev = prev->next;

        addListElementAfter(prev, datas); // tambahkan ke element paling terakhir
    }
}

// Menghapus element pada list
void delListElementFirst(List *list) {
    if ((*list).first != NULL) { // pastikan element bisa dihapus
        Element *del = (*list).first;
        if (countElement(*list) == 1)
            (*list).first = NULL; // jika hanya satu element, langsung null
        else
            (*list).first = (*list).first->next; // jika tidak, tunjuk element selanjutnya
        free(del);                               // hapus data
    }
}

void delListElementAfter(Element *prev, List *list) {
    Element *del = prev->next; // tunjuk element
    if (del != NULL) { // pastikan tidak null
        if (del->next == NULL) {
            prev->next = NULL; // langsung null
        } else {
            prev->next = del->next; // tunjuk element selanjutnya
            del->next = NULL;       // langsung null
        }
        free(del); // hapus data
    }
}

void delListElementLast(List *list) {
    if ((*list).first != NULL) { // pastikan tidak kosong
        if (countElement(*list) == 1) { // jika hanya satu, hapus element pertama
            delFirst(list);
        } else { // jika tidak, cari element paling ujung dan hapus
            Element *last = (*list).first;
            Element *prev;
            while (last->next != NULL) {
                prev = last;
                last = last->next;
            }

            delAfter(prev, list);
        }
    }
}

void delListElementAll(List *list) {
    // pastikan tidak kosong
    int elementCounter = countElement(*list);
    if (elementCounter != 0) {
        // hapus dari paling terakhir
        for (int i = elementCounter; i >= 1; i--)
            delLast(list);
    }
}

// menampilkan data
void printListElement(ListContainer container) {
    printf("- %s\n", container.name);
}

void printList(List list) {
    if (list.first != NULL) { // kondisi list tidak kosong
        Element *pointer = list.first;
        int itr = 1; // inisiasi element pertama
        while (pointer != NULL) {
            printListElement(pointer->container);
            pointer = pointer->next;
            itr++;
        }
    }
}

/**
 * N-er Tree
*/
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
    if(strcmp(container1.name_key, container2.name_key) == 0) isEqual = 1;
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
        if(isContainerEqual(root->container, container) == 1) {
            result = root;
        } else {
            Node *pointer = root->child;
            if(pointer != NULL) {
                if(pointer->sibling == NULL) {
                    if(isContainerEqual(pointer->container, container) == 1) {
                        result = pointer;
                    }
                    else result = findNode(container, pointer);
                } else {
                    while(pointer->sibling != root->child && result == NULL) {
                        if(isContainerEqual(pointer->container, container) == 1) {
                            result = pointer;
                        } else {
                            result = findNode(container, pointer);
                            pointer = pointer->sibling;
                        }
                    }
 
                    if(result == NULL) {
                        if(isContainerEqual(pointer->container, container) == 1) {
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
    printf("|%s - %d digit\n", container.name_key, container.salary); // ini ubah jadi digit
    printf("- %d\n", container.salary);
    printf("- %d tahun\n", container.exp);
    // print list
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
