#include <stdlib.h>

int cmpPotions(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    qsort(potions, potionsSize, sizeof(int), cmpPotions);
    int* res = (int*)malloc(spellsSize * sizeof(int));

    for (int i = 0; i < spellsSize; i++) {
        long long minPotion = (success + spells[i] - 1) / spells[i];
        int l = 0, r = potionsSize;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            int mid = (l + r) / 2;
            if (potions[mid] >= minPotion) r = mid;
            else l = mid + 1;
        }
        res[i] = potionsSize - l;
    }

    *returnSize = spellsSize;
    return res;
}