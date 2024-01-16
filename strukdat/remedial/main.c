/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan remedial dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Penggunaan Library
#include <stdio.h>
#include "header.h"

int main() {
    // Inisiasi variable
    // List of list
    List list;
    createList(&list);

    // Container
    Person person[2];
    int goodnessCounter, columnPos;
    Goodness goodness;

    // Pointer
    RowElement *rowPointer;
    ColElement *colPointer;

    // Counter
    int n;

    // Meminta masukan jumlah row
    scanf(" %d", &n);

    // Masukkan n row ke list
    for (int i = 0; i < n; i++) {
        scanf(" %s %d", person[0].name, &goodnessCounter);

        addLastRow(person[0], &list);
        rowPointer = findRowElement(person[0], &list);

        // masukkan goodnessCounter col ke row yang baru saja dimasukkan
        for(int j = 0; j < goodnessCounter; j++) {
            scanf(" %s %d", goodness.name, &goodness.year);
            addLastCol(goodness, rowPointer);
        }
    }

    // Meminta masukkan jumlah penularan kebaikan
    scanf(" %d", &n);

    // Tularkan n kebaikan
    for(int i = 0; i < n; i++) {
        // meminta src, dst, dan posisi dari col goodness dari src
        scanf(" %s %s %d", person[0].name, person[1].name, &columnPos);

        // cari yang dimaksud di atas
        rowPointer = findRowElement(person[0], &list);
        colPointer = findColElement(columnPos, rowPointer);

        rowPointer = findRowElement(person[1], &list);

        // masukkan ke dst
        addLastCol(colPointer->colContainer, rowPointer);
    }

    // tampilkan hasilnya
    printElement(list);

    return 0;
}