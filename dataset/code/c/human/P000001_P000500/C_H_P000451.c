#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



typedef struct Node {
    int key;
    int degree;
    struct Node* parent;
    struct Node* child;
    struct Node* next;
    struct Node* prev;
    int childFlag;
} Node;

typedef struct FHeap {
    Node* minPtr;
    int n; // total number of Nodes
} FHeap;

void printNodeInfo(Node* node) {
    if (node == NULL) {
        printf("Node is NULL.\n");
        return;
    }

    printf("Node Info:\n");
    printf("  Key: %d\n", node->key);
    printf("  Degree: %d\n", node->degree);
    printf("  ChildFlag: %d\n", node->childFlag);
    printf("  Parent Key: %d\n", node->parent ? node->parent->key : -1);
    printf("  Child Key: %d\n", node->child ? node->child->key : -1);
    printf("  Next Key: %d\n", node->next ? node->next->key : -1);
    printf("  Prev Key: %d\n", node->prev ? node->prev->key : -1);
}


Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->childFlag = 0;
    node->degree = 0;
    node->parent = NULL;
    node->child = NULL;
    node->next = node;
    node->prev = node;
    return node;
}

FHeap* createFHeap() {
    FHeap* heap = (FHeap*)malloc(sizeof(FHeap));
    heap->minPtr = NULL;
    heap->n = 0;
    return heap;
}

void AddNodeIntoList(Node* nodeToBeAdded, Node* list) {
    // if(nodeToBeAdded == NULL || list == NULL) return;
    if(list->next == list) {
        list->next = nodeToBeAdded;
        list->prev = nodeToBeAdded;
        nodeToBeAdded->next = list;
        nodeToBeAdded->prev = list;
        return;
    }
    Node* temp = list->prev;
    list->prev->next = nodeToBeAdded;
    list->prev = nodeToBeAdded;
    nodeToBeAdded->next = list;
    nodeToBeAdded->prev = temp;
    return;
}



void PrintTreeDegree(Node* treeDegree[], int maxDegree) {
    printf("TreeDegree array:\n");
    for (int i = 0; i < maxDegree; i++) {
        if (treeDegree[i] != NULL) {
            printf("Degree %d: Node with key %d\n", i, treeDegree[i]->key);
        } else {
            printf("Degree %d: NULL\n", i);
        }
    }
    printf("\n");
}

void PrintNodesArray(Node* nodes[], int numberOfNodes) {
    printf("Nodes array:\n");
    for (int i = 0; i < numberOfNodes; i++) {
        if (nodes[i] != NULL) {
            printf("Node %d: key = %d, degree = %d\n", i, nodes[i]->key, nodes[i]->degree);
        } else {
            printf("Node %d: NULL\n", i);
        }
    }
    printf("\n");
}


void Consolidation(FHeap* heap) {
    // initialize the array that keep track of the degree of the trees
    int maxDegree = 7;
    Node* treeDegree[maxDegree];
    for(int i=0;i<maxDegree;i++) {
        treeDegree[i] = NULL;
    }
    
    // put all the root nodes into another array
    Node* curr = heap->minPtr;
    Node* nodes[heap->n+10];
    int numberOfNodes = 0;

    if (curr != NULL) {
        // Collect nodes into the array
        while (1) {
            nodes[numberOfNodes++] = curr;
            curr = curr->next;
            if (curr == heap->minPtr) {
                break;
            }
        }
        // Sort nodes by their keys using a simple bubble sort
        for (int i = 0; i < numberOfNodes - 1; i++) {
            for (int j = 0; j < numberOfNodes - i - 1; j++) {
                if (nodes[j]->key > nodes[j + 1]->key) {
                    Node* temp = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = temp;
                }
            }
        }
    }
    // PrintNodesArray(nodes, numberOfNodes);
    // deal with the nodes in the nodes[], put them into the treeDegree array,
    // if encounter the same degree node, link them together.
    for(int i=0;i<numberOfNodes;i++) {
        Node *x = nodes[i];
        int degree = x->degree;
        // meld the trees that has same degree
        while(treeDegree[degree] != NULL) { // exist another same degree node
        // printf("linked");
            Node* y = treeDegree[degree];
            if(x->key > y->key) {// make sure x is smaller
                Node* temp = x;
                x = y;
                y = temp;
            }
            // before meld x&y, we are going the remove y from the linked list(roots list) first
            if(y->next != y) {
                y->prev->next = y->next;
                y->next->prev = y->prev;
            }
            // make y the child of x
            y->parent = x;
            y->next = y;
            y->prev = y;
            
            if(x->child == NULL) { // build linked list by only y
                x->child = y;
            }else{
                AddNodeIntoList(y, x->child);

                // Sort the child list by the key
                Node* child = x->child;
                Node* childNodes[x->degree+1];
                int childCount =0;
                // put children into a array
                while(child != NULL) {
                    childNodes[childCount++] = child;
                    child = child->next;
                    if(child == x->child) {
                        break;
                    }
                }
                // Use bubble sort to sort them by key
                for(int j=0;j<childCount-1;j++) {
                    for(int k=0;k<childCount-j-1;k++) {
                        if(childNodes[k]->key > childNodes[k+1]->key) {
                            Node* temp = childNodes[k];
                            childNodes[k] = childNodes[k+1];
                            childNodes[k+1] = temp;
                        }
                    }
                }
                // Build back the doubly linked list
                for(int j=0;j<childCount;j++) {
                    childNodes[j]->next = childNodes[(j+1) % childCount];
                    childNodes[j]->prev = childNodes[(j-1+childCount) % childCount];
                }

                x->child = childNodes[0];
            }
            x->degree++;
            y->childFlag = 0;

            treeDegree[degree] = NULL;
            degree++;
        }
        treeDegree[degree] = x;

    }
    // rebuild the linkedlist of roots
    heap->minPtr = NULL;
    for(int i=0;i<maxDegree;i++) {
        if(treeDegree[i] != NULL) {
            if(heap->minPtr == NULL) {
                heap->minPtr = treeDegree[i];
                heap->minPtr->next = heap->minPtr;
                heap->minPtr->prev = heap->minPtr;
                // printNodeInfo(heap->minPtr);
            }else {
                AddNodeIntoList(treeDegree[i], heap->minPtr);
                // printNodeInfo(heap->minPtr);
                if(heap->minPtr->key > treeDegree[i]->key) {
                    heap->minPtr = treeDegree[i];
                }
            }
        }
    }
    // pointer needs to be cared in case of infinite loop
    


}

void insert(FHeap* heap, int key) {
    Node* node = createNode(key);
    // add the newNode into the root list.
    if(heap->minPtr == NULL) {
        heap->minPtr = node;
    }else {
        AddNodeIntoList(node, heap->minPtr);
        if(heap->minPtr->key > node->key) {
            heap->minPtr = node;
        }
    }
    // insert doesn't need to consolidation
    heap->n++;
}

Node* search(FHeap* heap, int key) {
    Node* root = heap->minPtr;
    Node* stack[100];
    int top = -1;
    // put the root list into the stack
    Node* curr = root;
    while(1) {
        stack[++top] = curr;
        curr = curr->next;
        if(curr == root){
            break;
        }
    }
    // Use stack to search
    while(top != -1) {
        Node* node = stack[top--];
        if(node->key == key) {
            return node;
        }
        // if the node has child, put all the child into the stack
        if(node->child != NULL) {
            Node* child = node->child;
            while(1) {
                stack[++top] = child;
                if(child->next == node->child) {
                    break;
                }
                child = child->next;
            }
        }
    }
    return NULL;
}

void CutRelationWithParent(Node* targetNode) {
    if(targetNode->parent != NULL) {
        targetNode->parent->degree--;
        if(targetNode->next == targetNode && targetNode->parent->child == targetNode) {
            targetNode->parent->child = NULL;
        }else if(targetNode->parent->child == targetNode){
            targetNode->parent->child = targetNode->next;
        }
        targetNode->parent = NULL;
    }
}

void printFHeap(FHeap* heap) {
    if (heap == NULL || heap->minPtr == NULL) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Fibonacci Heap Structure:\n");

    // Create a stack for nodes to process
    Node* stack[heap->n];
    int levels[heap->n]; // Level corresponding to each node
    int top = -1; // Stack pointer

    // Push all root nodes to the stack with level 0
    Node* start = heap->minPtr;
    do {
        stack[++top] = start;
        levels[top] = 0; // Level 0 for root nodes
        start = start->next;
    } while (start != heap->minPtr);

    // Process nodes
    while (top >= 0) {
        Node* curr = stack[top];
        int level = levels[top--]; // Pop node and its level from stack

        // Print current node information with level
        for (int i = 0; i < level; i++) {
            printf("  "); // Indent to indicate level
        }
        printf("Node Key: %d, Degree: %d, ChildFlag: %d, Parent: %d\n",
               curr->key, curr->degree, curr->childFlag,
               curr->parent ? curr->parent->key : -1);

        // If the node has children, push them onto the stack with incremented level
        if (curr->child != NULL) {
            Node* child = curr->child;
            do {
                stack[++top] = child;
                levels[top] = level + 1; // Child level is parent level + 1
                child = child->next;
            } while (child != curr->child);
        }
    }
}

void extractMin(FHeap* heap) {
    Node* currMin = heap->minPtr;
    if(currMin != NULL) {
        // put the child of the min into the root list
        if(currMin->child != NULL) {
            Node* curr = currMin->child;
            while(1) {
                Node* next = curr->next;
                // printNodeInfo(curr);
                AddNodeIntoList(curr, heap->minPtr);
                curr->parent = NULL;
                curr->childFlag = 0;
                curr = next;
                if(curr == currMin->child) {
                    break;
                }
            }
        }
        // remove the node from the list, and then do consolidation
        if(currMin->next == currMin) {
            heap->minPtr = NULL;
        }else {
            currMin->next->prev = currMin->prev;
            currMin->prev->next = currMin->next;
            heap->minPtr = currMin->next;
            // printFHeap(heap);
            // printNodeInfo(heap->minPtr->next->next);
            Consolidation(heap);
            //壞掉
            // printNodeInfo(heap->minPtr->next);
        }
        heap->n--;
        return;
    }
    return;
}

void decreaseKey (FHeap* heap, int key, int value){
    Node* target = search(heap, key);
    if((target->key - value) <= 0) {
        target->key = 0;
    }else {
        target->key = target->key - value;
    }
    
    if(target == heap->minPtr) return;
    // if it's in the root list -> return
    int isInRootList = 0;
    Node* curr = heap->minPtr;
    while(1) {
        if(curr == target) {
            isInRootList = 1;
            break;
        }
        curr = curr->next;
        if(curr == heap->minPtr) break;
    }
    // "In the root list and smaller than the minPtr" 
    
    if(isInRootList) {
        if(target->key < heap->minPtr->key) {
        heap->minPtr = target;
        }
        return;
    }
    // new key smaller than parent -> cut and add in root list
    if(target->key < target->parent->key) {
        CutRelationWithParent(target);
        if(target->next == target) {
        }else if(target->next->next == target) {
            target->next->next = target->next;
            target->next->prev = target->next;
        }else{
            target->next->prev = target->prev;
            target->prev->next = target->next;
        }
        AddNodeIntoList(target, heap->minPtr);
    }
    if(target->key < heap->minPtr->key) {
    heap->minPtr = target;
    }
    return;
}

void delete(FHeap* heap, int key) {
    decreaseKey(heap, key, 100000);
    extractMin(heap);
    return;
}

void printLevelOrder(FHeap* heap) {
    if (heap == NULL || heap->minPtr == NULL) {
        printf("Heap is empty.\n");
        return;
    }

    Node* root = heap->minPtr;
    Node* roots[heap->n]; // Array to store root nodes
    int rootCount = 0;

    // Collect all root nodes
    Node* curr = root;
    do {
        roots[rootCount++] = curr;
        curr = curr->next;
    } while (curr != root);

    // Sort roots by degree
    for (int i = 0; i < rootCount - 1; i++) {
        for (int j = 0; j < rootCount - i - 1; j++) {
            if (roots[j]->degree > roots[j + 1]->degree) {
                Node* temp = roots[j];
                roots[j] = roots[j + 1];
                roots[j + 1] = temp;
            }
        }
    }

    // Perform level-order traversal for each root
    for (int i = 0; i < rootCount; i++) {
        Node* currRoot = roots[i];
        // printf("Degree %d: ", currRoot->degree);

        // Use a queue for level-order traversal
        Node* queue[heap->n];
        int front = 0, rear = 0;

        queue[rear++] = currRoot;
        while (front < rear) {
            Node* node = queue[front++];
            printf("%d ", node->key);

            // Enqueue children
            if (node->child != NULL) {
                Node* child = node->child;
                do {
                    queue[rear++] = child;
                    child = child->next;
                } while (child != node->child);
            }
        }
        printf("\n");
    }
}

int main () {
    int param1, param2;
    char command[20];

    FHeap* heap = createFHeap();

    // while(1) {
    //     scanf("%s", command);
    //     if (strcmp(command, "insert") == 0) {   
    //         scanf("%d", &param1);
    //         insert(heap, param1);
    //     } else if (strcmp(command, "delete") == 0) {
    //         scanf("%d", &param1);
    //         delete(heap, param1);
    //     } else if (strcmp(command, "decrease") == 0) {
    //         scanf("%d", &param1);
    //         scanf("%d", &param2);
    //         decreaseKey(heap, param1, param2);
    //     } else if (strcmp(command, "extract-min") == 0) {
    //         extractMin(heap);
    //     } else if (strcmp(command, "exit") == 0) {
    //         break;
    //     }
    //     fflush(stdin);
    // }
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 5);
    insert(heap, 3);
    insert(heap, 7);
    insert(heap, 15);
    insert(heap, 18);
    insert(heap, 22);
    insert(heap, 1);
    insert(heap, 12);
    extractMin(heap);
    decreaseKey(heap, 20, 1);
    insert(heap, 25);
    insert(heap, 30);
    extractMin(heap);
    decreaseKey(heap, 30, 10);
    extractMin(heap);
    decreaseKey(heap, 25, 4);
    insert(heap, 8);
    insert(heap, 9);
    extractMin(heap);
    insert(heap, 1);
    extractMin(heap);
    extractMin(heap);
    insert(heap, 1);
    insert(heap, 4);
    insert(heap, 3);
    insert(heap, 2);
    Consolidation(heap);
    printLevelOrder(heap);
    // printFHeap(heap);
    return 0;
}
// cascading
// watch the notice in pdf
// During consolidation, when multiple roots have the same degree, the two roots
// with the smallest key values are merged first and the children of the root of the
// new tree should be sorted in ascending order(from left to right).
