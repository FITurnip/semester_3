/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan remedial dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

// Penggunaan Library
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Penggunaan data
typedef struct
{
    char name[51];
} Person;

typedef struct
{
    char name[101];
    int year;
} Goodness;

/**
 * List
 */
// Struktur

// Makro untuk mempermudah pengenalan nama struct
#define _row_container Person
#define _col_container Goodness

typedef struct _col_element *ColElementAddress;
typedef struct _col_element
{
    _col_container colContainer;
    ColElementAddress nextCol;
} ColElement;

typedef struct _row_element *RowElementAddress;
typedef struct _row_element
{
    _row_container rowContainer;
    ColElement *colList;
    RowElementAddress nextRow;
} RowElement;

typedef struct
{
    RowElement *first;
} List;

// Membuat list dan menghitung elemen
void createList(List *list);
int countRowElements(List list);
int countColElements(RowElement list);

// Membuat elemen baru
RowElement *setNewRowElement(_row_container dataContainer);
ColElement *setNewColElement(_col_container dataContainer);
void addFirstRow(_row_container dataContainer, List *list);
void addFirstCol(_col_container dataContainer, RowElement *list);
void addAfterRow(RowElement *prev, _row_container dataContainer);
void addAfterCol(ColElement *prev, _col_container dataContainer);
void addLastRow(_row_container dataContainer, List *list);
void addLastCol(_col_container dataContainer, RowElement *list);

// Menghapus elemen
void delFirstCol(RowElement *list);
void delAfterCol(ColElement *prev);
void delLastCol(RowElement *list);
void delAllCols(RowElement *list);
void delFirstRow(List *list);
void delAfterRow(RowElement *prev);
void delLastRow(List *list);
void delAllRows(List *list);

// Menampilkan elemen
void printElement(List list);

// Mencari elemen
RowElement *findRowElement(_row_container dataContainer, List *list);
ColElement *findColElement(int pos, RowElement *rowElement);

// Undefine karena hanya dipakai sebatas pada file ini
#undef _row_container
#undef _col_container