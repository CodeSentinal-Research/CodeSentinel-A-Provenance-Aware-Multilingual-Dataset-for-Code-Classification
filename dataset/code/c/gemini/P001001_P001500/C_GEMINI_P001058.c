#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    int key;
    int count;
} FreqEntry;

typedef struct {
    FreqEntry entries[10000];
    int entryCount;
    Node* stacks[10005];
    int maxFreq;
} FreqStack;

FreqStack* freqStackCreate() {
    FreqStack* obj = (FreqStack*)malloc(sizeof(FreqStack));
    obj->entryCount = 0;
    obj->maxFreq = 0;
    for (int i = 0; i <= 10000; i++) obj->stacks[i] = NULL;
    return obj;
}

int getFreq(FreqStack* obj, int val) {
    for (int i = 0; i < obj->entryCount; i++) {
        if (obj->entries[i].key == val) return obj->entries[i].count;
    }
    return 0;
}

void incFreq(FreqStack* obj, int val) {
    for (int i = 0; i < obj->entryCount; i++) {
        if (obj->entries[i].key == val) {
            obj->entries[i].count++;
            return;
        }
    }
    obj->entries[obj->entryCount].key = val;
    obj->entries[obj->entryCount].count = 1;
    obj->entryCount++;
}

void decFreq(FreqStack* obj, int val) {
    for (int i = 0; i < obj->entryCount; i++) {
        if (obj->entries[i].key == val) {
            obj->entries[i].count--;
            return;
        }
    }
}

void freqStackPush(FreqStack* obj, int val) {
    int f = getFreq(obj, val) + 1;
    incFreq(obj, val);
    if (f > obj->maxFreq) obj->maxFreq = f;
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->stacks[f];
    obj->stacks[f] = node;
}

int freqStackPop(FreqStack* obj) {
    Node* top = obj->stacks[obj->maxFreq];
    int val = top->val;
    obj->stacks[obj->maxFreq] = top->next;
    free(top);
    decFreq(obj, val);
    if (obj->stacks[obj->maxFreq] == NULL) obj->maxFreq--;
    return val;
}

void freqStackFree(FreqStack* obj) {
    free(obj);
}