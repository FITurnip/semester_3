/**
 * Single List
*/
#define ListContainer Skill
typedef struct {
    char name[201];
} Skill;

typedef struct elmt *ElementAddress; // pointer ke element selanjutnya

typedef struct elmt { // menyimpan next data
    ListContainer container;
    ElementAddress next;
} Element;

typedef struct { // menyimpan pointer ke element pertama
    Element *first;
} List;

// Membuat list dan menghitung element
void createList(List *list);
int countListElement(List list);

// Menambahkan element ke list
void addListElementFirst(ListContainer datas, List *list);
void addListElementAfter(Element *prev, ListContainer datas);
void addListElementLast(ListContainer datas, List *list);

// Menghapus element dari list
void delListElementFirst(List *list);
void delListElementAfter(Element *prev, List *list);
void delListElementLast(List *list);
void delListElementAll(List *list);

// Menampilkan list
void printListElement(ListContainer container);
void printList(List list);

/**
 * N-er Tree
*/
// Struktur data n-er tree
#define Container Profession
typedef struct {
    char name_key[201];
    int salary, exp, totalSkill;
    List skill;
} Profession;
 
typedef struct nodeStruct* nodeAddress;
typedef struct nodeStruct {
    Container container;
    nodeAddress sibling, child;
} Node;
 
typedef struct {
    Node* root;
} Tree;
 
// Memmbuat node & tree
Node *makeNode(Container container);
void makeTree(Container container, Tree *tree);
void addChild(Container container, Node *root);
 
// Menghapus tree
void delAll(Node *root);
void delChild(Container container, Node *root);
 
// Mencari node
Node *findNode(Container container, Node *root);
 
// Print element
void printTreePreOrder(Node *root, int isFirstPrintedNode);
void printTreePostOrder(Node *root, int isFirstPrintedNode);
 
// Menyalin tree
void copyTree(Node *src, Node **dst);
 
// Membandingkan tree
int isEqual(Node *a, Node *b);
