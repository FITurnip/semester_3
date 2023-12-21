/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
// Struktur data binner tree
#define Container char
typedef struct nodeStruct* nodeAddress;
typedef struct nodeStruct {
    Container container;
    nodeAddress right, left;
} Node;
 
typedef struct {
    Node* root;
} Tree;
 
// Memmbuat node & tree
Node *makeNode(Container container);
void makeTree(Container container, Tree *tree);
void addRight(Container container, Node *root);
void addLeft(Container container, Node *root);
 
// Menghapus tree
void delAll(Node *root);
void delRight(Node *root);
void delLeft(Node *root);
 
// Print element
extern int isFirstPrintedNode;
void __printTreePreOrder(Node *root);       // hidden function
void __printTreeInOrder(Node *root);        // hidden function
void __printTreePostOrder(Node *root);      // hidden function
void printTreePreOrder(Node *root);
void printTreeInOrder(Node *root);
void printTreePostOrder(Node *root);
 
// Menyalin tree
void copyTree(Node *src, Node **dst);
 
// Membandingkan tree
int isEqual(Node *a, Node *b);
