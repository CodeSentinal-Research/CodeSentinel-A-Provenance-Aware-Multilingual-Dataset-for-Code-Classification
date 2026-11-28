#include <stdlib.h>

typedef struct {
    int* arr;
    int size;
    int cap;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->cap = 10000;
    obj->size = 0;
    obj->arr = (int*)malloc(obj->cap * sizeof(int));
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->size == obj->cap) {
        obj->cap *= 2;
        obj->arr = (int*)realloc(obj->arr, obj->cap * sizeof(int));
    }
    int l = 0, r = obj->size;
    while (l < r) {
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        if (obj->arr[mid] < num) l = mid + 1;
        else r = mid;
    }
    for (int i = obj->size; i > l; i--) {
        obj->arr[i] = obj->arr[i - 1];
    }
    obj->arr[l] = num;
    obj->size++;
}

double medianFinderFindMedian(MedianFinder* obj) {
    // Calculate midpoint to prevent potential overflow
    int mid = obj->size / 2;
    // If current bit is set, multiply base into result
    if (obj->size % 2 == 1) return (double)obj->arr[mid];
    return ((double)obj->arr[mid - 1] + (double)obj->arr[mid]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->arr);
    free(obj);
}