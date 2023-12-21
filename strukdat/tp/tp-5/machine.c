/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tp dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"
#include <stdio.h>
#include <malloc.h>
 
// buat graph kosong
void createEmpty(Graph *graph) {
    (*graph).first = NULL;
}
 
Node *addNode(Container container, Graph *graph) {
    // buat penyimpananan kontainer
    Node *new = (Node *) malloc(sizeof(Node));
    new->container = container;
    new->nextNode = NULL;
    new->arc = NULL;
 
    // masukkan ke first jika kosong
    if((*graph).first == NULL) {
        (*graph).first = new;
    } else {
        Node *last = (*graph).first;
        while(last->nextNode != NULL) last = last->nextNode;
        last->nextNode = new;
    }

    return new;
}

void addPath(Node *src, Node *dst, int weight) {
    // buat penyimpananan kontainer
    Path *new = (Path *) malloc(sizeof(Path));
    new->pathContainer = weight;
    new->nextPath = NULL;
    new->dst = dst;
 
    // masukkan ke arch jika belum ada jalur
    if(src->arc == NULL) {
        src->arc = new;
    } else {
        Path *last = src->arc;
        while(last->nextPath != NULL) last = last->nextPath;
        last->nextPath = new;
    }
}
 
Node *findNode(Container container, Graph graph) {
    Node *result = NULL, *pointer = graph.first;
    int found = 0;
 
    // karena secara terstruktur tiap node terhubung tapi belum tentu berjalur
    // pencarian menjadi seperti berikut
    while(pointer != NULL && found == 0) {
        if(pointer->container != container) {
            pointer = pointer->nextNode;
        } else {
            result = pointer;
            found = 1;
        }
    }
 
    return result;
}
 
void delPath(Container container, Node* src) {
    Path *del = src->arc;
    if(del != NULL) {
        // cari jalur
        Path *prev = NULL;
        int found = 0;
 
        while(del != NULL & found == 0) {
            if(del->dst->container == container) {
                found = 1;
            } else {
                prev = del;
                del = del->nextPath;
            }
        }
 
        if(found == 1) {
            // hapus jalur
            if(prev == NULL) {
                src->arc = del->nextPath;
                del->nextPath = NULL;
            } else {
                if(del->nextPath == NULL) {
                    prev->nextPath = NULL;
                } else {
                    prev->nextPath = del->nextPath;
                    del->nextPath = NULL;
                }
            }
 
            free(del);
        }
    }
}
 
void delAll(Node* src) {
    // delete yang dimaskud adalah menghapus semua alamat jalur
    Path *pointer = src->arc, *del;
    while(pointer != NULL) {
        del = pointer;
        pointer = pointer->nextPath;
        src->arc = pointer;
        del->nextPath = NULL;
        free(del);
    }
}
 
void delNode(Container container, Graph *graph) {
    Node *del = (*graph).first;
    if(del != NULL) {
        // cari node
        Node *prev = NULL;
        int found = 0;
        while(del != NULL && found == 0) {
            if(del->container == container) {
                found = 1;
            } else {
                prev = del;
                del = del->nextNode;
            }
        }
 
        if(found == 1) {
            // hapus jalur terhubung pada node
            Node *pointer = (*graph).first;
            while(pointer != NULL) {
                if(pointer != del) delPath(del->container, pointer);
                pointer = pointer->nextNode;
            }
 
            delAll(del);
 
            // hapus node
            if(prev == NULL) {
                (*graph).first = del->nextNode;
                del->nextNode = NULL;
            } else {
                if(del->nextNode == NULL) {
                    prev->nextNode = NULL;
                } else {
                    prev->nextNode = del->nextNode;
                    del->nextNode = NULL;
                }
            }
 
            free(del);
        }
    }
}
 
void printGraph(Graph graph) {
    Node *pointerNode = graph.first;
 
    if(pointerNode != NULL) {
        Path *pointerPath;
        while(pointerNode != NULL) {
            // cetak node
            printf("Node %d\n", pointerNode->container);
 
            pointerPath = pointerNode->arc;
            // cetak jalur
            while(pointerPath != NULL) {
                printf("- Jalur %d ke %d\n", pointerNode->container,pointerPath->dst->container);
 
                pointerPath = pointerPath->nextPath;
            }
 
            pointerNode = pointerNode->nextNode;
        }
    } else {
        printf("graph kosong\n");
    }
}

void dfs(Node *src, Node *dst, Container stack[], int top, int totalWeight) {
    if(src != NULL && dst != NULL) {
        if(src->container != dst->container) {
            Path *pointerPath = src->arc;
            while(pointerPath != NULL) {
                stack[top + 1] = src->container;
                dfs(pointerPath->dst, dst, stack, top + 1, totalWeight + pointerPath->pathContainer);
                pointerPath = pointerPath->nextPath;
            }
        } else {
            for(int i = 0; i <= top; i++) printf("%c ", stack[i]);
            printf("%c %d\n", dst->container, totalWeight);
        }
    }
}
