/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan uas dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include "header.h"
#include <string.h>

int main() {
    Tree T;
    int totalNodes;
    scanf("%d", &totalNodes);
    Container child, parent;
    String siblingPos;
    Node *nodePos;
    for(int i = 0; i < totalNodes; i++) {
        scanf(" %s %s %s", child.contain, parent.contain, siblingPos.contain);
        if(strcmp(siblingPos.contain, "kiri") == 0) {
            nodePos = findNode(T.root, parent);
            // printf("%s\n", nodePos->container.contain);
            addLeft(child, nodePos);
        } else if(strcmp(siblingPos.contain, "kanan") == 0) {
            nodePos = findNode(T.root, parent);
            // printf("%s\n", nodePos->container.contain);
            addRight(child, nodePos);
        } else if(strcmp(siblingPos.contain, "akar") == 0) {
            makeTree(child, &T);
        }
    }

    Container completeNode[totalNodes], leafNode[totalNodes];
    int completeCounter = -1, leafCounter = -1;
    labelNodes(T.root, completeNode, &completeCounter, leafNode, &leafCounter);
    printf("simpul lengkap:\n");
    if(completeCounter != -1) {
        for(int i = 0; i <= completeCounter; i++) {
            if(i != 0) printf(" ");
            printf("%s", completeNode[i].contain);
        }
        printf("\n");
    } else {
        printf("tidak ada\n");
    }
    printf("\n");

    printf("simpul daun:\n");
    if(leafCounter != -1) {
        for(int i = 0; i <= leafCounter; i++) {
            if(i != 0) printf(" ");
            printf("%s", leafNode[i].contain);
        }
        printf("\n");
    } else {
        printf("tidak ada\n");
    }
    return 0;
}