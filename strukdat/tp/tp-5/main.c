/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tp dalam mata kuliah Strukdat untuk keberkahanNya
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
        scanf(" %c %c %d", &containerA, &containerB, &weight);
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

    Container stack[totalNode];
    scanf(" %c %c", &containerA, &containerB);
    tempA = findNode(containerA, graph);
    tempB = findNode(containerB, graph);
    dfs(tempA, tempB, stack, -1, 0);
    return 0;
}

