/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan uas dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
 
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
        if(strcmp(pointer->container.contain, container.contain) != 0) {
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
 
        while(del != NULL && found == 0) {
            if(strcmp(del->dst->container.contain, container.contain) == 0) {
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
            if(strcmp(del->container.contain, container.contain) == 0) {
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
            printf("Node %s\n", pointerNode->container.contain);
 
            pointerPath = pointerNode->arc;
            // cetak jalur
            while(pointerPath != NULL) {
                printf("- Jalur %s ke %s\n", pointerNode->container.contain,pointerPath->dst->container.contain);
 
                pointerPath = pointerPath->nextPath;
            }
 
            pointerNode = pointerNode->nextNode;
        }
    } else {
        printf("graph kosong\n");
    }
}

void dfs(Node *src, Node *dst, Route *temp, Route result[], int *resultCounter) {
    if(src != NULL && dst != NULL) {
        // bandingkan apakah dst ditemukan
        if(strcmp(src->container.contain, dst->container.contain) != 0) { // jika tidak, catat rute
            Path *pointerPath = src->arc;
            while(pointerPath != NULL) {
                temp->top++;
                temp->stack[temp->top] = src->container;
                temp->totalWeight += pointerPath->pathContainer;

                dfs(pointerPath->dst, dst, temp, result, resultCounter);
                temp->totalWeight -= pointerPath->pathContainer;
                temp->top--;
                
                pointerPath = pointerPath->nextPath;
            }
        } else { // jika ya, masukkan rute tidak langsung secara asc
            if(temp->top > 0) {
                temp->top++;
                temp->stack[temp->top] = dst->container;
                (*resultCounter)++;
                result[(*resultCounter)] = (*temp);
                temp->top--;

                int isSorted = 0;
                int i = (*resultCounter);
                Route tempSort;
                while(i > 0 && isSorted == 0) {
                    if(result[i].totalWeight < result[i - 1].totalWeight) {
                        tempSort = result[i];
                        result[i] = result[i - 1];
                        result[i - 1] = tempSort;
                        i--;
                    } else {
                        isSorted = 1;
                    }
                }
            }
        }
    }
}
