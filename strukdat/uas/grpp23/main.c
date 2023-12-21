/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan uas dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include "header.h"

int main() {
    Graph graph;
    createEmpty(&graph);
    Container containerA, containerB;
    int weight;

    Node *tempA, *tempB;
    int totalPath, totalNode = 0;

    scanf(" %d", &totalPath);
    for(int i = 0; i < totalPath; i++) {
        scanf(" %s %s %d", containerA.contain, containerB.contain, &weight);
        tempA = findNode(containerA, graph);
        if(tempA == NULL) {
            totalNode++;
            tempA = addNode(containerA, &graph);
        }

        tempB = findNode(containerB, graph);
        if(tempB == NULL) {
            totalNode++;
            tempB = addNode(containerB, &graph);
        }

        addPath(tempA, tempB, weight);
    }

    Route tempRoute, resRoute[totalPath];
    tempRoute.top = -1;
    tempRoute.totalWeight = 0;
    int resultCounter = -1;
    scanf(" %s %s", containerA.contain, containerB.contain);
    tempA = findNode(containerA, graph);
    tempB = findNode(containerB, graph);
    dfs(tempA, tempB, &tempRoute, resRoute, &resultCounter);
    for(int i = 0; i <= resultCounter; i++) {
        for(int j = 0; j <= resRoute[i].top; j++) {
            printf("%s ", resRoute[i].stack[j].contain);
        }
        printf("%d\n", resRoute[i].totalWeight);
    }
    return 0;
}

