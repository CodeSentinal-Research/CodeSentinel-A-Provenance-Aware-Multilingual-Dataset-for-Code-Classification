#include <stdlib.h>

int cmpTask(const void* a, const void* b) {
    int* t1 = *(int**)a;
    int* t2 = *(int**)b;
    return (t2[1] - t2[0]) - (t1[1] - t1[0]);
}

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    qsort(tasks, tasksSize, sizeof(int*), cmpTask);
    int curEnergy = 0, reqEnergy = 0;

    for (int i = 0; i < tasksSize; i++) {
        int actual = tasks[i][0];
        int min = tasks[i][1];
        if (curEnergy < min) {
            reqEnergy += min - curEnergy;
            curEnergy = min;
        }
        curEnergy -= actual;
    }
    return reqEnergy;
}