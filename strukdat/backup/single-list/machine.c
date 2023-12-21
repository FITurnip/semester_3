#include "header.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Set up list
void createList(List *list)
{
    (*list).first = NULL; // menandakan list belum terkait ke element manapun
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
void addFirst(Idol datas, List *list)
{
    //  set element
    Element *new = (Element *)malloc(sizeof(Element));
    new->container = datas;

    // kaitkan element pertama ke element selanjutnya
    if ((*list).first == NULL)
        new->next = NULL;
    else
        new->next = (*list).first;
    (*list).first = new; // tunjuk ke element baru
    new = NULL;          // hilangkan kaitan new
}

void addAfter(Element *prev, Idol datas)
{
    // set element
    Element *new = (Element *)malloc(sizeof(Element));
    new->container = datas;

    // kaitkan element sebelumnya ke element selanjutnya
    if (prev != NULL)
    {
        if (prev->next == NULL)
            new->next = NULL;
        else
            new->next = prev->next;
        prev->next = new; // tunjuk ke element baru
        new = NULL;       // hilangkan kaitan new
    }
}

void addLast(Idol datas, List *list)
{
    if ((*list).first == NULL)
    {
        addFirst(datas, list); // kondisi kosong, masukan ke element pertama
    }
    else
    {
        // cari element paling terakhir
        Element *prev = (*list).first;
        while (prev->next != NULL)
            prev = prev->next;

        addAfter(prev, datas); // tambahkan ke element paling terakhir
    }
}

// Menghapus element pada list
void delFirst(List *list)
{
    if ((*list).first != NULL)
    { // pastikan element bisa dihapus
        Element *del = (*list).first;
        if (countElement(*list) == 1)
            (*list).first = NULL; // jika hanya satu element, langsung null
        else
            (*list).first = (*list).first->next; // jika tidak, tunjuk element selanjutnya
        free(del);                               // hapus data
    }
}

void delAfter(Element *prev, List *list)
{
    Element *del = prev->next; // tunjuk element
    if (del != NULL)
    { // pastikan tidak null
        if (del->next == NULL)
        {
            prev->next = NULL; // langsung null
        }
        else
        {
            prev->next = del->next; // tunjuk element selanjutnya
            del->next = NULL;       // langsung null
        }
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
void printContainer(Idol container)
{
    printf("%s %s - %d tahun\n", container.nama, container.grup, 2023 - container.tahun_lahir);
}

void printElement(List list)
{
    if (list.first != NULL)
    { // kondisi list tidak kosong
        Element *pointer = list.first;
        int itr = 1; // inisiasi element pertama
        printf(":) :) :) :) :) :) :) :) :) :)\n");
        while (pointer != NULL)
        {
            printContainer(pointer->container);
            pointer = pointer->next;
            itr++;
        }
    }
    else
    {
        printf(":( :( :( :( :( :( :( :( :( :(\n\n");
    }
}