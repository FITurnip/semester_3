/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Penggunaan library
#include <stdio.h>
#include "header.h"

int main()
{
    List L;
    Kontak kontak[9];
    for (int i = 0; i < 9; i++)
        scanf(" %s %s %s", kontak[i].nama, kontak[i].notel, kontak[i].email);

    printf("Data Kontak\n()()()()()()()()()()()()()()()()\n");

    // CreateList.
    createList(&L);
    // AddLast.
    addLast(kontak[0], &L);
    // AddFirst.
    addFirst(kontak[1], &L);
    // AddBefore L.First->next.
    addBefore(L.first->next, kontak[2], &L);
    // // PrintElement.
    printElement(L, 0);
    printf("()()()()()()()()()()()()()()()()\n");

    // AddAfter L.First->next.
    addAfter(L.first->next, kontak[3], &L);
    // DelAfter L.First.
    delAfter(L.first, &L);
    // AddAfter L.First.
    addAfter(L.first, kontak[4], &L);
    // AddBefore L.Tail.
    addBefore(L.tail, kontak[5], &L);
    // DelFirst.
    delFirst(&L);
    // AddAfter L.Tail.
    addAfter(L.tail, kontak[6], &L);
    // PrintElement.
    printElement(L, 0);
    printf(")()()()()()()()()()()()()()()()(\n");

    // DelLast.
    delLast(&L);
    // AddBefore L.first.
    addBefore(L.first, kontak[7], &L);
    // DelAfter L.first.
    delAfter(L.first, &L);
    // AddLast.
    addLast(kontak[8], &L);
    // PrintReverse.
    printElement(L, 1);
    printf("()()()()()()()()()()()()()()()()\n");

    // DelAll.
    delAll(&L);
    // PrintElement.
    printElement(L, 0);
    return 0;
}
/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Penggunaan struct
typedef struct
{ // data
    char nama[51], notel[51], email[51];
} Kontak;

typedef struct elmt *ElementAddress; // pointer ke element selanjutnya

#define ElementContainer Kontak

typedef struct elmt
{ // menyimpan next data
    ElementContainer container;
    ElementAddress prev, next;
} Element;

typedef struct
{ // menyimpan pointer ke element pertama
    Element *first, *tail;
} List;

// Membuat list dan menghitung element
void createList(List *list);
int countElement(List list);

// Menambahkan element ke list
void addFirst(ElementContainer element, List *list);
void addAfter(Element *prev, ElementContainer element, List *list);
void addBefore(Element *next, ElementContainer element, List *list);
void addLast(ElementContainer element, List *list);

// Menghapus element dari list
void delFirst(List *list);
void delAfter(Element *prev, List *list);
void delLast(List *list);
void delAll(List *list);

// Menampilkan list
void printContainer(ElementContainer container);
void printElement(List list, int reverse);

#undef ElementContainer
/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Penggunaan library
#include "header.h"
#include <stdio.h>
#include <malloc.h>

#define ElementContainer Kontak

// Set up list
void createList(List *list)
{
    (*list).first = NULL; // menandakan list belum terkait ke element manapun
    (*list).tail = NULL;
}

// Menghitung banyaknya element pada list
int countElement(List list)
{
    int counter = 0; // inisiasi banyak element yang telah dihitung
    if (list.first != NULL)
    {
        Element *pointer = list.first; // tunjuk element pertama
        while (pointer != NULL)
        { // selama belum mencapai ujung list, hitung
            counter++;
            pointer = pointer->next; // tunjuk element selanjutnya
        }
    }

    return counter;
}

// Menambahkan element pada list
void addFirst(ElementContainer element, List *list)
{
    //  set element
    Element *new = (Element *)malloc(sizeof(Element));
    new->container = element;

    // kaitkan element pertama ke element selanjutnya
    if ((*list).first == NULL)
    {
        new->prev = NULL;
        new->next = NULL;
        (*list).tail = new;
    }
    else
    {
        new->next = (*list).first;
        new->prev = NULL;
        (*list).first->prev = new;
    }
    (*list).first = new; // tunjuk ke element baru
    new = NULL;          // hilangkan kaitan new
}

void addAfter(Element *prev, ElementContainer element, List *list)
{
    if (prev != NULL)
    { // pastikan elemen exist
        // set element
        Element *new = (Element *)malloc(sizeof(Element));
        new->container = element;

        // kaitkan element sebelumnya ke element selanjutnya
        if (prev->next == NULL)
        {
            new->next = NULL;
            (*list).tail = new;
        }
        else
        {
            new->next = prev->next;
            new->next->prev = new;
        }

        // tunjuk ke element baru
        new->prev = prev;
        prev->next = new;
        new = NULL; // hilangkan kaitan new
    }
}

void addBefore(Element *next, ElementContainer element, List *list)
{
    if (next != NULL)
    { // pastikan elemen exist
        // set element
        Element *new = (Element *)malloc(sizeof(Element));
        new->container = element;

        // kaitkan element selanjutnya ke element sebelumnya
        if (next->prev == NULL)
        {
            new->prev = NULL;
            (*list).first = new;
        }
        else
        {
            new->prev = next->prev;
            new->prev->next = new;
        }

        // tunjuk ke element baru
        new->next = next;
        next->prev = new;
        new = NULL; // hilangkan kaitan new
    }
}

void addLast(ElementContainer element, List *list)
{
    if ((*list).first == NULL)
    {
        addFirst(element, list); // kondisi kosong, masukan ke element pertama
    }
    else
    {
        // cari element paling terakhir
        Element *prev = (*list).first;
        while (prev->next != NULL)
            prev = prev->next;

        addAfter(prev, element, list); // tambahkan ke element paling terakhir
    }
}

// Menghapus element pada list
void delFirst(List *list)
{
    if ((*list).first != NULL)
    { // pastikan element bisa dihapus
        Element *del = (*list).first;
        if (countElement(*list) == 1)
        {
            (*list).first = NULL; // jika hanya satu element, langsung null
            (*list).tail = NULL;
        }
        else
        {
            (*list).first = (*list).first->next;
            (*list).first->prev = NULL;
            del->next = NULL;
        }          // jika tidak, tunjuk element selanjutnya
        free(del); // hapus data
    }
}

void delAfter(Element *prev, List *list)
{
    if (prev != NULL)
    {                              // pastikan tidak null
        Element *del = prev->next; // tunjuk element
        if (del->next == NULL)
        {
            prev->next = NULL; // langsung null
        }
        else
        {
            prev->next = del->next; // tunjuk element selanjutnya
            del->next->prev = prev;
            del->next = NULL; // langsung null
        }
        del->prev = NULL;
        free(del); // hapus data
    }
}

void delLast(List *list)
{
    if ((*list).first != NULL)
    { // pastikan tidak kosong
        if (countElement(*list) == 1)
        { // jika hanya satu, hapus element pertama
            delFirst(list);
        }
        else
        { // jika tidak, cari element paling ujung dan hapus
            Element *last = (*list).first;
            Element *prev;
            while (last->next != NULL)
            {
                prev = last;
                last = last->next;
            }

            delAfter(prev, list);
        }
    }
}

void delAll(List *list)
{
    // pastikan tidak kosong
    int elementCounter = countElement(*list);
    if (elementCounter != 0)
    {
        // hapus dari paling terakhir
        for (int i = elementCounter; i >= 1; i--)
            delLast(list);
    }
}

// menampilkan data
void printContainer(ElementContainer container)
{
    printf("%s ", container.nama);
    printf("%s ", container.notel);
    printf("%s\n", container.email);
}

void printElement(List list, int reverse)
{
    if (list.first != NULL)
    { // kondisi list tidak kosong
        Element *pointer;

        if (reverse == 0)
            pointer = list.first;
        else
            pointer = list.tail;

        while (pointer != NULL)
        {
            printContainer(pointer->container);
            if (reverse == 0)
                pointer = pointer->next;
            else
                pointer = pointer->prev;
        }
    }
    else
    {
        printf("List Kosong.\n");
    }
}

#undef ElementContainer
