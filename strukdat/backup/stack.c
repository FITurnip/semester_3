/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Penggunaan library
#include <stdio.h>
#include "header.h"

int main()
{
    Stack s[2];
    Book temp;
    createEmpty(&s[0]);
    createEmpty(&s[1]);
    // printStack S1
    // printStack S2
    printBook(s);
    // push S1
    pushBook(&s[0]);
    // push S2
    pushBook(&s[1]);
    // push S2
    pushBook(&s[1]);
    // printStack S1
    // printStack S2
    printBook(s);
    // pop S1
    pop(&s[0]);
    // pop S2 ke S1
    transferBook(&s[1], &s[0]);
    // push S1
    pushBook(&s[0]);
    // push S2
    pushBook(&s[1]);
    // push S1
    pushBook(&s[0]);
    // pop S2
    pop(&s[1]);
    // pop S1 ke S2
    transferBook(&s[0], &s[1]);
    // printStack S1
    // printStack S2
    printBook(s);
    printf("==========================\n");
    return 0;
}
/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Penggunaan struct
// Kontainer yang akan dipakai
typedef struct
{
    char title[51];
    int price;
} Book;

// Struktur stack
#define Container Book
typedef struct elmt *elmtAddress;
typedef struct elmt
{
    Container container;
    elmtAddress lowerElmt;
} Element;

typedef struct
{
    Element *top;
} Stack;

// Fungsi dan prosedur dasar stack
void createEmpty(Stack *s);
int isEmpty(Stack s);
int countElement(Stack s);
void push(Container container, Stack *s);
void pop(Stack *s);
void printStack(Stack s);

#undef Container

// Extended
void printBook(Stack S[]);
void pushBook(Stack *target);
void transferBook(Stack *src, Stack *dst);

/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Penggunaan library
#include "header.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define Container Book

void createEmpty(Stack *s)
{
    (*s).top = NULL; // kaitkan dengan kosong
}

int isEmpty(Stack s)
{
    int emptyCond = 0; // inisiasi state condition
    if (s.top != NULL)
        emptyCond = 1; // true apabila top tidak mengait pada kosong
    return emptyCond;
}

int countElement(Stack s)
{
    int counter = 0; // inisiasi jumlah sebelum dihitung
    if (s.top != NULL)
    { // pastikan perhitungan dimulai saat top tidak mengait pada kosong
        Element *pointer = s.top;
        while (pointer != NULL)
        { // point hingga paling bawah sembari menghitung element
            counter++;
            pointer = pointer->lowerElmt;
        }
    }
    return counter;
}

void push(Container container, Stack *s)
{
    Element *new = (Element *)malloc(sizeof(Element)); // alokasi memori baru
    new->container = container;                        // isikan element
    if ((*s).top == NULL)
        new->lowerElmt = NULL; // kaitkan dengan element di bawahnya
    else
        new->lowerElmt = (*s).top;
    (*s).top = new; // set ulang top menjadi element baru
    new = NULL;     // hilangkan kaitan pada new
}

void pop(Stack *s)
{
    if ((*s).top != NULL)
    {
        Element *del = (*s).top;
        if (countElement((*s)) == 1)
            (*s).top = NULL; // kaitkan top saat ini dengan lower
        else
            (*s).top = (*s).top->lowerElmt;
        del->lowerElmt = NULL; // hapus kaitan element
        free(del);             // bebaskan memori
    }
}

void printStack(Stack s)
{
    if (s.top != NULL)
    {
        Element *pointer = s.top;
        int i = 1;
        while (pointer != NULL)
        { // tunjuk hingga paling bawah
            printf("%d. %s Rp.%d\n", i, pointer->container.title, pointer->container.price);
            pointer = pointer->lowerElmt;
            i++;
        }
    }
    else
    {
        printf("- Kosong\n");
    }
}

#undef Container

// Extended
void printBook(Stack S[])
{
    printf("==========================\n");
    printf("Buku di S1:\n");
    printStack(S[0]);
    printf("\nBuku di S2:\n");
    printStack(S[1]);
}

void pushBook(Stack *target)
{
    Book temp;
    scanf("%s %d", temp.title, &temp.price);
    push(temp, target);
}

void transferBook(Stack *src, Stack *dst)
{
    Book temp = src->top->container;
    pop(src);
    push(temp, dst);
}
