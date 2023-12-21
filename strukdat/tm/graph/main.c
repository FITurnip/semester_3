/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include "header.h"
 
int main() {
    Graph graph;
    createEmpty(&graph);
    Node *pos[9];
    // masukkan node
    for(int i = 1; i <= 8; i++) {
        addNode(i, &graph);
        pos[i] = findNode(i, graph);
    }
 
    // masukkan jalur
    addPath(pos[1], pos[2], 0);
    addPath(pos[1], pos[7], 0);
    addPath(pos[1], pos[5], 0);
    addPath(pos[1], pos[4], 0);
 
    addPath(pos[4], pos[7], 0);
 
    addPath(pos[2], pos[3], 0);
    addPath(pos[2], pos[6], 0);
 
    addPath(pos[3], pos[8], 0);
 
    addPath(pos[6], pos[8], 0);
 
 
    // input yang akan dihapus
    int tempToDel;
    scanf("%d", &tempToDel);
 
    // print before after
    printGraph(graph);
    delNode(tempToDel, &graph);
    printf("==============\n");
    printGraph(graph);
    return 0;
}

