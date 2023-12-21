
/*
    Saya Franklin Impianro Turnip(2203211) mengerjakan uas dalam mata kuliah Strukdat untuk keberkahanNya
    maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
typedef struct nodeStruct* nodeAddress;
typedef struct pathStruct* pathAddress;
#define Container String
typedef struct {
    char contain[3];
} String;
 
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

typedef struct {
    Container stack[48];
    int totalWeight;
    int top;
} Route;

void createEmpty(Graph *graph);
Node *addNode(Container container, Graph *graph);
void addPath(Node *src, Node *dst, int weight);
Node *findNode(Container container, Graph graph);
void delPath(Container container, Node* src);
void delAll(Node* src);
void delNode(Container container, Graph *graph);
void printGraph(Graph graph);
void dfs(Node *src, Node *dst, Route *temp, Route result[], int *resultCounter);
