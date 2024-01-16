/**
 * Saya Franklin mengerjakan evaluasi [nama evaluasi] dalam mata kuliah
 * Strukdat untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
 * yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main() {
    // Inisiasi variabel yang akan digunakan
    Tree dreamTree;
    int totalNode;
    char inputTemp[201];
    Proffesion professionTemp, parentProfession;
    Node *nodeTemp;

    // Meminta input dari user untuk mendapatkan jumlah node
    scanf("%d", &totalNode);

    for(int i = 0; i < totalNode; i++) {
        // input node information without skills
        scanf(" %s", inputTemp);

        // parsing
        strcpy(parentProfession.unique_name, parse(inputTemp, &professionTemp));
        professionTemp.skills = (char **) malloc(professionTemp.total_skill * sizeof(char *));
        for(int j = 0; j < professionTemp.total_skill; j++) {
            professionTemp.skills[j] = (char *) malloc(201 * sizeof(char));
            scanf(" %s", professionTemp.skills[j]);

            professionTemp.columnWidth = max(professionTemp.columnWidth, strlen(professionTemp.skills[j]) + 4);
        }
        
        // masukkan ke dalam tree
        if(strcmp(parentProfession.unique_name, "null") != 0) {
            nodeTemp = findNode(parentProfession, dreamTree.root);
            addChild(professionTemp, nodeTemp);

            // cari kedalaman max
            dreamTree.maxLevelOfTree = max(dreamTree.maxLevelOfTree, nodeTemp->level + 1);
        } else {
            makeTree(professionTemp, &dreamTree);
        }

        // hilangkan address untuk diisikan ulang pada iterasi selanjutnya
        professionTemp.skills = NULL;
    }

    // alokasi untuk keperluan space saat print nanti
    dreamTree.maxSpace = (int *) malloc (sizeof (int) * (dreamTree.maxLevelOfTree + 1));
    for(int i = 0; i <= dreamTree.maxLevelOfTree; i++) dreamTree.maxSpace[i] = 0;

    // print sebelum dipangkas
    printDreamTree(&dreamTree, dreamTree.root);
    
    // pangkas
    scanf(" %s", professionTemp.unique_name);
    makeDreamPath(dreamTree.root, professionTemp);

    for(int i = 0; i <= dreamTree.maxLevelOfTree; i++) dreamTree.maxSpace[i] = 0;

    // print setelah dipangkas
    printf("\n");
    printDreamPath(&dreamTree, dreamTree.root);
    return 0;
}