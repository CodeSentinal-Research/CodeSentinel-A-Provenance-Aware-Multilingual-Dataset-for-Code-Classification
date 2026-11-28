#include <stdlib.h>

typedef struct {
    int val, count;
} Item;

int cmpItem(const void* a, const void* b) {
    return ((Item*)b)->count - ((Item*)a)->count;
}

int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize) {
    int maxVal = 0;
    for (int i = 0; i < barcodesSize; i++) {
        if (barcodes[i] > maxVal) maxVal = barcodes[i];
    }

    int* freq = (int*)calloc(maxVal + 1, sizeof(int));
    for (int i = 0; i < barcodesSize; i++) freq[barcodes[i]]++;

    Item* items = (Item*)malloc((maxVal + 1) * sizeof(Item));
    int itemCount = 0;
    for (int i = 0; i <= maxVal; i++) {
        if (freq[i] > 0) {
            items[itemCount].val = i;
            items[itemCount].count = freq[i];
            itemCount++;
        }
    }
    qsort(items, itemCount, sizeof(Item), cmpItem);

    int* res = (int*)malloc(barcodesSize * sizeof(int));
    *returnSize = barcodesSize;
    int idx = 0;

    for (int i = 0; i < itemCount; i++) {
        while (items[i].count > 0) {
            res[idx] = items[i].val;
            items[i].count--;
            idx += 2;
            if (idx >= barcodesSize) idx = 1;
        }
    }

    free(freq);
    free(items);
    return res;
}