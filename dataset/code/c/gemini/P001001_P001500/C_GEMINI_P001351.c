#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char** items;
    int size;
    int idx;
} CombinationIterator;

CombinationIterator* combinationIteratorCreate(char* characters, int combinationLength) {
    CombinationIterator* it = (CombinationIterator*)malloc(sizeof(CombinationIterator));
    it->items = NULL;
    it->size = 0;
    it->idx = 0;
    return it;
}

char* combinationIteratorNext(CombinationIterator* obj) {
    return obj->items[obj->idx++];
}

bool combinationIteratorHasNext(CombinationIterator* obj) {
    return obj->idx < obj->size;
}

void combinationIteratorFree(CombinationIterator* obj) {
    free(obj);
}