
/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan tes mesin dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
typedef struct nodeStruct* nodeAddress;
typedef struct pathStruct* pathAddress;
#define Container int
 
typedef struct nodeStruct {
    Container container;
    nodeAddress nextNode;
    pathAddress arc;
} Node;
 
typedef struct pathStruct {
    int pathContainer;
    pathAddress nextPath;
    Node* dst;
} Path;
 
typedef struct {
    Node* first;
} Graph;
 
void createEmpty(Graph *graph);
void addNode(Container container, Graph *graph);
void addPath(Node *src, Node *dst, int weight);
Node *findNode(Container container, Graph graph);
void delPath(Container container, Node* src);
void delAll(Node* src);
void delNode(Container container, Graph *graph);
void printGraph(Graph graph);
