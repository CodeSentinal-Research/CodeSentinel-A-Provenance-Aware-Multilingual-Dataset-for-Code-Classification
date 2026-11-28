#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int cur;
    bool present[1005];
} SmallestInfiniteSet;

SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet* obj = (SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));
    obj->cur = 1;
    for (int i = 0; i <= 1000; i++) obj->present[i] = false;
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    for (int i = 1; i < obj->cur; i++) {
        if (obj->present[i]) {
            obj->present[i] = false;
            return i;
        }
    }
    return obj->cur++;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    if (num < obj->cur) {
        obj->present[num] = true;
    }
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj);
}