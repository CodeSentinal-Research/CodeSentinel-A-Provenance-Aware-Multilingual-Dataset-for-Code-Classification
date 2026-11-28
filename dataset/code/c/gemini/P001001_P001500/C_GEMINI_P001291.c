#include <stdbool.h>
#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool isNStraightHand(int* hand, int handSize, int groupSize) {
    if (handSize % groupSize != 0) return false;
    qsort(hand, handSize, sizeof(int), cmpInt);

    bool* visited = (bool*)calloc(handSize, sizeof(bool));
    for (int i = 0; i < handSize; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        int nextVal = hand[i] + 1;
        int found = 1;

        for (int j = i + 1; j < handSize && found < groupSize; j++) {
            if (!visited[j] && hand[j] == nextVal) {
                visited[j] = true;
                nextVal++;
                found++;
            }
        }
        if (found < groupSize) {
            free(visited);
            return false;
        }
    }
    free(visited);
    return true;
}