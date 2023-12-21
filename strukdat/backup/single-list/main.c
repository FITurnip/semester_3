#include <stdio.h>
#include "header.h"

int main()
{
    List list;
    Idol idol[6];
    for (int i = 0; i < 6; i++)
        scanf(" %s %s %d", idol[i].nama, idol[i].grup, &idol[i].tahun_lahir);

    createList(&list);

    addFirst(idol[0], &list);
    addLast(idol[1], &list);
    addAfter(list.first->next, idol[2]);
    printElement(list);

    delAfter(list.first->next, &list);
    delLast(&list);
    printElement(list);

    delAll(&list);
    printElement(list);

    addLast(idol[3], &list);
    addFirst(idol[4], &list);
    delFirst(&list);
    printElement(list);

    addFirst(idol[5], &list);
    printElement(list);
    return 0;
}