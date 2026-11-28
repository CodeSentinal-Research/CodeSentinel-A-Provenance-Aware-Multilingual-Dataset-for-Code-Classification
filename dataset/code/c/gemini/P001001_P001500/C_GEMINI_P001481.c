#include <stdlib.h>

int cmpIntBoats(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(int), cmpIntBoats);
    int l = 0, r = peopleSize - 1;
    int boats = 0;

    // Binary search loop to narrow down range
    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            l++;
        }
        r--;
        boats++;
    }
    return boats;
}