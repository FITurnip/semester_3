/**
 * Saya Franklin mengerjakan evaluasi TMD dalam mata kuliah
 * Strukdat untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
 * yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
 
Node *makeNode(Container container) {
    // mengalokasikan memori sebesar Node untuk dipakai
    Node *node = (Node *) malloc (sizeof (Node));
    node->container = container;
    node->sibling = NULL;
    node->child = NULL;
 
    return node;
}
 
void makeTree(Container container, Tree *tree) {
    // memberikan alokasi bagi root untuk menyimpan container
    Node *node = makeNode(container);
    node->level = 0;
    tree->root = node;
    node = NULL;
}
 
void addChild(Container container, Node *root) {
    if(root != NULL) {
        // membuat alokasi bagi node baru untuk menyimpan child dari root
        Node *new = makeNode(container);
        new->level = root->level + 1;
 
        if(root->child == NULL) {
            root->child = new;
        } else {
            if(root->child->sibling == NULL) {
                new->sibling = root->child;
                root->child->sibling = new;
            } else {
                Node *last = root->child;
                while(last->sibling != root->child) last = last->sibling;
                new->sibling = root->child;
                last->sibling = new;
            }
        }
 
        new = NULL;
    }
}
 
void delAll(Node *root) {
    if(root != NULL) {
        if(root->child != NULL) {
            // hapus semua anak terlebih dahulu
            if(root->child->sibling == NULL) {
                delAll(root->child);
            } else {
                Node *pointer = root->child;
                Node *delNode;
                while(pointer->sibling != root->child) {
                    delNode = pointer;
                    pointer = pointer->sibling;
                    delAll(delNode);
                }
            }
        }
        // hapus parent
        free(root);
    }
}
 
int isContainerEqual(Container container1, Container container2) {
    // membandingkan kesamaan dua container berdasarkan nama, karena namanya bersifat unik
    int isEqual = 0;
    if(strcmp(container1.unique_name, container2.unique_name) == 0) isEqual = 1;
 
    return isEqual;
}
 
void delChild(Container container, Node *root) {
    if(root != NULL) {
        Node *delNode = root->child;
        // hanya akan menghapus pada node yang mengadung container
        if(delNode != NULL) {
            if(delNode->sibling == NULL) {  // kondisi parent hanya memiliki satu anak
                if(isContainerEqual(root->child->container, container) == 1) {
                    delAll(root->child);    // hapus seluruh pohon dari node
                    root->child = NULL;
                } else {
                    printf("Node tidak ditemukan\n");
                }
            } else {                        // kondisi parent hanya memiliki lebih dari satu anak
                // temukan terlebih dahulu posisi node
                Node *prev = NULL;
                int found = 0;
 
                while(delNode->sibling != root->child && found == 0) {
                    if(isContainerEqual(delNode->container, container) == 1) {
                        found = 1;
                    } else {
                        prev = delNode;
                        delNode = delNode->sibling;
                    }
                }
                if(found == 0 && isContainerEqual(delNode->container, container) == 1) found = 1;
 
                if(found == 1) {
                    Node *last = root->child;
                    while(last->sibling != root->child) last = last->sibling;
 
                    // perbaiki posisi sibling antara prev dan next dari node yang dihapus
                    if(prev == NULL) {
                        if(delNode->sibling == last && last->sibling == root->child) {
                            root->child = last;
                            last->sibling = NULL;
                        } else {
                            root->child = delNode->sibling;
                            last->sibling = root->child;
                        }
                    } else {
                        if(prev == root->child && last->sibling == root->child) {
                            root->child->sibling = NULL;
                        } else {
                            prev->sibling = delNode->sibling;
                            delNode->sibling = NULL;
                        }
                    }
                    delAll(delNode);    // hapus seluruh pohon dari node
                } else {
                    printf("Node tidak ditemukan\n");
                }
            }
        }
    }
}

Node *findNode(Container container, Node *root) {
    // pengecekan dilakukan secara preOrder
    Node *result = NULL;
    if(root != NULL) {
        if(isContainerEqual(root->container, container) == 1) {
            result = root;
        } else {
            Node *pointer = root->child;
            if(pointer != NULL) {
                if(pointer->sibling == NULL) {
                    if(isContainerEqual(pointer->container, container) == 1) {
                        result = pointer;
                    } else result = findNode(container, pointer);
                } else {
                    while(pointer->sibling != root->child && result == NULL) {
                        if(isContainerEqual(pointer->container, container) == 1) {
                            result = pointer;
                        } else {
                            result = findNode(container, pointer);
                            pointer = pointer->sibling;
                        }
                    }
 
                    if(result == NULL) {
                        if(isContainerEqual(pointer->container, container) == 1) {
                            result = pointer;
                        }
 
                        else result = findNode(container, pointer);
                    }
                }
            }
        }
    }
 
    return result; // akan mengembalikan NULL jika tidak temukan
}

void printContainer(Container container, int total_space) {
    // sebelum melakukan print container, print space terlebih dahulu
    for(int space = 0; space < total_space; space++) printf(" ");
    printf("|%s - %d digit\n", container.unique_name, container.salary_digit);
    for(int space = 0; space < total_space; space++) printf(" ");
    printf(" - %d\n", container.salary);
    for(int space = 0; space < total_space; space++) printf(" ");
    printf(" - %d tahun\n", container.exp);
    
    for(int i = 0; i < container.total_skill; i++) {
        for(int space = 0; space < total_space; space++) printf(" ");
        printf(" - %s\n", container.skills[i]);
    }
}
 
void printTreePreOrder(Tree *tree, Node *root, int isFirstPrintedNode, int total_space, int minCond) {
    if(root != NULL) {
        // preOrder mencetak terlebih dahulu kemudian mengunjungi node kiri hingga habis, dilanjut kanan
        if(root->container.dreamDestination >= minCond) {
            if(isFirstPrintedNode == 1) printf("\n");
            printContainer(root->container, total_space);

            tree->maxSpace[root->level] = max(tree->maxSpace[root->level], root->container.columnWidth);
        }
        int cur_total_space = total_space + tree->maxSpace[root->level] + 1;
        Node *pointer = root->child;

        if(pointer != NULL) {
            if(pointer->sibling != NULL) {
                while(pointer->sibling != root->child) {
                    if(pointer->container.dreamDestination >= minCond) printTreePreOrder(tree, pointer, 1, cur_total_space, minCond);
                    pointer = pointer->sibling;
                }
            }
            if(pointer->container.dreamDestination >= minCond) printTreePreOrder(tree, pointer, 1, cur_total_space, minCond);
        } else {
        }
    }
}

void printTreePostOrder(Node *root, int isFirstPrintedNode) {
    if(root != NULL) {
        // postOrder mengunjungi terlebih dahulu dari kiri hingga habis, dilanjut kanan, baru dicetak
        Node *pointer = root->child;
        if(pointer != NULL) {
            if(pointer->sibling == NULL) {
                printTreePostOrder(pointer, 0);
            } else {
                while(pointer->sibling != root->child) {
                    printTreePostOrder(pointer, 0);
                    pointer = pointer->sibling;
                }
 
                printTreePostOrder(pointer, 0);
            }
        }
        printContainer(root->container, isFirstPrintedNode);
        if(isFirstPrintedNode == 0) printf("-");
        else isFirstPrintedNode = 0;
    }
}
 
void copyTree(Node *src, Node **dst) {
    if(src != NULL) {
        // meng-copy tree src node per node
        (*dst) = makeNode(src->container);
 
        if(src->child != NULL) {
            if(src->child->sibling == NULL) {
                copyTree(src->child, &(*dst)->child);
            } else {
                Node *srcPointer = src->child, *dstPointer = (*dst)->child;
                while(srcPointer->sibling != src->child) {
                    copyTree(srcPointer, &dstPointer);
                    srcPointer = srcPointer->sibling;
                    dstPointer = dstPointer->sibling;
                }
 
                copyTree(srcPointer, &dstPointer);
            }
        }
    }
}
 
int isEqual(Node *a, Node *b) {
    // pengecekan dilakukan secara preOrder
    int equalCond = 1;
    if(a != NULL && b != NULL) {
        if(isContainerEqual(a->container, b->container) == 0) {
            equalCond = 0;
        } else {
            if(a->child != NULL && b->child != NULL) {
                if(a->child->sibling == NULL) {
                    equalCond = isEqual(a->child, b->child);
                } else {
                    Node *aPointer = a->child, *bPointer = b->child;
                    while(aPointer->sibling != a->child && equalCond == 1) {
                        if(aPointer != NULL && bPointer != NULL) {
                            equalCond = isEqual(aPointer, bPointer);
                            aPointer = aPointer->sibling;
                            bPointer = bPointer->sibling;
                        } else {
                            equalCond = 0;
                        }
                    }
 
                    equalCond = isEqual(aPointer, bPointer);
                }
            }
        }
    } else {
        if(a != NULL || b != NULL) {
            equalCond = 0;
        }
    }
 
    return equalCond;
}


int getTotalDigit(int num) {
    int totalDigit = 0;
    if(num != 0) {
        while(num != 0) {
            num /= 10;
            totalDigit++;
        }
    } else {
        totalDigit = 0;
    }

    return totalDigit;
}

const int one_million = 1000000;
int getSalaryDigit(int salary) {
    salary /= one_million;
    return getTotalDigit(salary);
}

char *parse(char *input_str, Proffesion *proffesion) {
    int idx_input_str = 0, i = 0;
    int salaryWidth = 3, expWidth = 9;
    (*proffesion).columnWidth = 0;
    
    // name
    while(input_str[idx_input_str] != '#') {
        proffesion->unique_name[i] = input_str[idx_input_str];

        idx_input_str++;
        i++;
        (*proffesion).columnWidth++;
    }
    idx_input_str++;
    proffesion->unique_name[i] = '\0';
    (*proffesion).columnWidth += 11;

    // parent node
    char *parentNode = (char *) malloc(201 * sizeof(char));
    i = 0;
    while(input_str[idx_input_str] != '#') {
        parentNode[i] = input_str[idx_input_str];

        idx_input_str++;
        i++;
    }
    idx_input_str++;
    parentNode[i] = '\0';

    // salary
    proffesion->salary = 0;
    while(input_str[idx_input_str] != '#') {
        proffesion->salary = (proffesion->salary * 10) + (input_str[idx_input_str] - '0');

        idx_input_str++;
        i++;
        salaryWidth++;
    }
    idx_input_str++;

    // exp
    proffesion->exp = 0;
    while(input_str[idx_input_str] != '#') {
        proffesion->exp = (proffesion->exp * 10) + (input_str[idx_input_str] - '0');

        idx_input_str++;
        expWidth++;
    }
    idx_input_str++;

    // total_skill
    proffesion->total_skill = 0;
    while(input_str[idx_input_str] != '\0') {
        proffesion->total_skill = (proffesion->total_skill * 10) + (input_str[idx_input_str] - '0');

        idx_input_str++;
        i++;
    }

    // tentukan max dari columnWidth berdasarkan yang sudah dihitung saat parsing, panjang salary, dan exp
    proffesion->salary_digit = (getSalaryDigit(proffesion->salary));
    proffesion->columnWidth += (getTotalDigit(proffesion->salary_digit));
    proffesion->columnWidth = max(proffesion->columnWidth, salaryWidth);
    proffesion->columnWidth = max(proffesion->columnWidth, expWidth);

    proffesion->dreamDestination = 1;

    return parentNode;
}


// mencari min max
int max(int a, int b) {
    int res = a;
    if(res < b) res = b;
    return res;
}

int min(int a, int b) {
    int res = a;
    if(res > b) res = b;
    return res;
}

int getMaxColumnWidth(Node *root, Tree *tree) {
    Node *sibling = root->sibling;

    if(sibling != NULL) {
        while(sibling != root) {
            tree->maxSpace[root->level] = max(tree->maxSpace[root->level], sibling->container.columnWidth);
            printf("%s %d\n", sibling->container.unique_name, tree->maxSpace[root->level]);
            sibling = sibling->sibling;
        }
        tree->maxSpace[root->level] = max(tree->maxSpace[root->level], sibling->container.columnWidth);
        printf("%s %d\n", sibling->container.unique_name, tree->maxSpace[root->level]);
        sibling = sibling->sibling;
    } else {
        printf("%s %d\n", root->container.unique_name, tree->maxSpace[root->level]);
        tree->maxSpace[root->level] = max(tree->maxSpace[root->level], root->container.columnWidth);
    }

    printf("max of %d is %d", root->level, tree->maxSpace[root->level]);
    return tree->maxSpace[root->level];
}

// buat dream path
int makeDreamPath(Node *root, Container container) {
    int found = 0;
    if(root != NULL) {
        // mencari dream yang dicari secara preorder
        if(isContainerEqual(root->container, container) == 0) {
            Node *pointer = root->child;
            if(pointer != NULL) {
                if(pointer->sibling != NULL) {
                    Node *last = pointer;

                    while(last->sibling != pointer) last = last->sibling;

                    while(pointer != last && found == 0) {
                        found = makeDreamPath(pointer, container);
                        pointer = pointer->sibling;
                    }

                    if(found == 0) {
                        found = makeDreamPath(pointer, container);
                    }
                } else {
                    found = makeDreamPath(pointer, container);
                }
            }
        } else {
            // apabila sudah ditemukan, extend dreampath
            found = 1;
            Node *pointer = root->sibling;
            if(pointer != NULL) {
                while(pointer != root) {
                    pointer->container.dreamDestination = 0;
                    pointer = pointer->sibling;
                }
            }
        }

    }

    return found;
}
 

// print dream path dan dream tree
void printDreamPath(Tree *tree, Node *root) {
    printTreePreOrder(tree, root, 0, 0, 1);
}

void printDreamTree(Tree *tree, Node *root) {
    printTreePreOrder(tree, root, 0, 0, 0);
}