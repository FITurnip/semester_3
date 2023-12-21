#pragma once

typedef struct
{
    char nama[31], grup[31];
    int tahun_lahir;
} Idol;

typedef struct elmt *ElementAddress; // pointer ke element selanjutnya

typedef struct elmt
{ // menyimpan next data
    Idol container;
    ElementAddress next;
} Element;

typedef struct
{ // menyimpan pointer ke element pertama
    Element *first;
} List;

// Membuat list dan menghitung element
void createList(List *list);
int countElement(List list);

// Menambahkan element ke list
void addFirst(Idol datas, List *list);
void addAfter(Element *prev, Idol datas);
void addLast(Idol datas, List *list);

// Menghapus element dari list
void delFirst(List *list);
void delAfter(Element *prev, List *list);
void delLast(List *list);
void delAll(List *list);

// Menampilkan list
void printContainer(Idol container);
void printElement(List list);