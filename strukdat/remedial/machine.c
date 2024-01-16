/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan remedial dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Penggunaan Library
#include "header.h"

// Makro untuk mempermudah pengenalan nama struct
#define _row_container Person
#define _col_container Goodness

// Membuat list
void createList(List *list) {
    (*list).first = NULL;
}

// Menghitung elemen
int countRowElements(List list) {
    int sum = 0;
    if (list.first != NULL) {
        RowElement *curPointer = list.first;
        while (curPointer != NULL) {
            sum++;
            curPointer = curPointer->nextRow;
        }
    }

    return sum;
}

int countColElements(RowElement list) {
    int sum = 0;

    if (list.colList != NULL) {
        ColElement *curPointer = list.colList;
        while (curPointer != NULL) {
            sum++;
            curPointer = curPointer->nextCol;
        }
    }
    return sum;
}

// Menyimpan elemen baru
RowElement *setNewRowElement(_row_container dataContainer) {
    RowElement *new = (RowElement *)malloc(sizeof(RowElement));
    new->rowContainer = dataContainer;
    new->colList = NULL;
    return new;
}

ColElement *setNewColElement(_col_container dataContainer) {
    ColElement *new = (ColElement *)malloc(sizeof(ColElement));
    new->colContainer = dataContainer;
    return new;
}

// Memasukkan elemen baru ke list
void addFirstRow(_row_container dataContainer, List *list) {
    RowElement *new = setNewRowElement(dataContainer);
    if ((*list).first == NULL)
        new->nextRow = NULL;
    else
        new->nextRow = (*list).first;
    (*list).first = new;
    new = NULL;
}

void addFirstCol(_col_container dataContainer, RowElement *list) {
    ColElement *new = setNewColElement(dataContainer);
    if ((*list).colList == NULL)
        new->nextCol = NULL;
    else
        new->nextCol = (*list).colList;
    (*list).colList = new;
    new = NULL;
}

void addAfterRow(RowElement *prev, _row_container dataContainer) {
    RowElement *new = setNewRowElement(dataContainer);
    if (prev->nextRow == NULL)
        new->nextRow = NULL;
    else
        new->nextRow = prev->nextRow;
    prev->nextRow = new;
    new = NULL;
}

void addAfterCol(ColElement *prev, _col_container dataContainer) {
    ColElement *new = setNewColElement(dataContainer);
    if (prev->nextCol == NULL)
        new->nextCol = NULL;
    else
        new->nextCol = prev->nextCol;
    prev->nextCol = new;
    new = NULL;
}

void addLastRow(_row_container dataContainer, List *list) {
    if ((*list).first == NULL) {
        addFirstRow(dataContainer, list);
    }
    else {
        RowElement *last = (*list).first;
        while (last->nextRow != NULL)
            last = last->nextRow;
        addAfterRow(last, dataContainer);
    }
}

void addLastCol(_col_container dataContainer, RowElement *list) {
    if ((*list).colList == NULL) {
        addFirstCol(dataContainer, list);
    }
    else {
        ColElement *last = (*list).colList;
        while (last->nextCol != NULL)
            last = last->nextCol;
        addAfterCol(last, dataContainer);
    }
}

// Menghapus elemen dari list
void delFirstCol(RowElement *list) {
    if ((*list).colList != NULL) {
        ColElement *del = (*list).colList;
        if (countColElements(*list) == 1) {
            (*list).colList = NULL;
        }
        else {
            (*list).colList = (*list).colList->nextCol;
            del->nextCol = NULL;
        }

        free(del);
    }
}

void delAfterCol(ColElement *prev) {
    ColElement *del = prev->nextCol;
    if (del != NULL) {
        if (del->nextCol == NULL) {
            prev->nextCol = NULL;
        }
        else {
            prev->nextCol = del->nextCol;
            del->nextCol = NULL;
        }

        free(del);
    }
}

void delLastCol(RowElement *list) {
    if ((*list).colList != NULL) {
        if (countColElements(*list) == 1) {
            delFirstCol(list);
        }
        else {
            ColElement *last = (*list).colList;
            ColElement *prev_last;
            while (last->nextCol != NULL) {
                prev_last = last;
                last = last->nextCol;
            }
            delAfterCol(prev_last);
        }
    }
}

void delAllCols(RowElement *list) {
    int elementCounter = countColElements(*list);
    if (elementCounter != 0) {
        for (int i = elementCounter; i >= 1; i--)
            delLastCol(list);
    }
}

void delFirstRow(List *list) {
    if ((*list).first != NULL) {
        RowElement *del = (*list).first;

        if (del->colList != NULL)
            delAllCols(del);

        if (countRowElements(*list) == 1) {
            (*list).first = NULL;
        }
        else {
            (*list).first = (*list).first->nextRow;
            del->nextRow = NULL;
        }

        free(del);
    }
}

void delAfterRow(RowElement *prev) {
    if (prev != NULL) {
        RowElement *del = prev->nextRow;
        if (del != NULL) {
            if (del->colList != NULL)
                delAllCols(del);

            if (del->nextRow == NULL) {
                prev->nextRow = NULL;
            }
            else {
                prev->nextRow = del->nextRow;
            }
            del->nextRow = NULL;
            free(del);
        }
    }
}

void delLastRow(List *list) {
    if ((*list).first != NULL) {
        if (countRowElements(*list) == 1) {
            delFirstRow(list);
        }
        else {
            RowElement *last = (*list).first;
            RowElement *prev_last;
            while (last->nextRow != NULL) {
                prev_last = last;
                last = last->nextRow;
            }
            delAfterRow(prev_last);
        }
    }
}

void delAllRows(List *list) {
    int elementCounter = countRowElements(*list);
    if (elementCounter != 0) {
        for (int i = elementCounter; i >= 1; i--)
            delLastRow(list);
    }
}

// Menampilkan element dari list
void printElement(List list) {
    if (list.first != NULL) {
        RowElement *curRowPointer = list.first;
        ColElement *curColPointer;
        while (curRowPointer != NULL) {
            printf("%s\n", curRowPointer->rowContainer.name);

            curColPointer = curRowPointer->colList;
            while (curColPointer != NULL) {
                printf("- %s %d\n", curColPointer->colContainer.name, curColPointer->colContainer.year);

                curColPointer = curColPointer->nextCol;
            }

            curRowPointer = curRowPointer->nextRow;
            if(curRowPointer != NULL) printf("\n");
        }
    }
    else {
        printf("List Kosong.\n-------------------------\n");
    }
}

// cari row berdasarkan nama
RowElement *findRowElement(_row_container dataContainer, List *list) {
    RowElement *curPointer = (*list).first;
    int stop = 0;

    while (stop == 0) {
        if (curPointer != NULL) {
            if (strcmp(curPointer->rowContainer.name, dataContainer.name) == 0)
                stop = 1;
            else
                curPointer = curPointer->nextRow;
        }
        else {
            stop = 1;
        }
    }

    return curPointer;
}

// cari col berdasarkan posisi
ColElement *findColElement(int pos, RowElement *rowElement) {
    ColElement *curPointer = rowElement->colList;
    int stop = 0;
    int curPos = 1;

    while (stop == 0) {
        if(curPointer != NULL) {
            if(curPos != pos) {
                curPos++;
                curPointer = curPointer->nextCol;
            }
            else stop = 1;
        } else {
            stop = 1;
        }
    }

    return curPointer;
}

// Undefine karena hanya dipakai sebatas pada file ini
#undef _row_container
#undef _col_container