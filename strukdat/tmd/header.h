/**
 * Saya Franklin mengerjakan evaluasi TMD dalam mata kuliah
 * Strukdat untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
 * yang telah dispesifikasikan. Aamiin.
*/
// Struktur data n-er tree
#define Container Proffesion
typedef struct {
    char unique_name[201];
    int salary, salary_digit, exp, total_skill;
    char **skills;
    int columnWidth;
    int dreamDestination; // flag
} Proffesion;
 
typedef struct nodeStruct* nodeAddress;
typedef struct nodeStruct {
    Container container;
    nodeAddress sibling, child;
    int level;
} Node;
 
typedef struct {
    Node* root;
    int maxLevelOfTree;
    int *maxSpace;
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
void printContainer(Container container, int total_space);
void printTreePreOrder(Tree *tree, Node *root, int isFirstPrintedNode, int total_space, int minCond);
void printTreePostOrder(Node *root, int isFirstPrintedNode);
 
// Menyalin tree
void copyTree(Node *src, Node **dst);
 
// Membandingkan tree
int isEqual(Node *a, Node *b);
int getSalaryDigit(int salary);
char *parse(char *input_str, Proffesion *proffesion);

// mendapatkan nilai min max
int max(int a, int b);
int min(int a, int b);
int getMaxColumnWidth(Node *root, Tree *tree);

// buat dream path dan print
int makeDreamPath(Node *root, Container container);
void printDreamPath(Tree *tree, Node *root);
void printDreamTree(Tree *tree, Node *root);