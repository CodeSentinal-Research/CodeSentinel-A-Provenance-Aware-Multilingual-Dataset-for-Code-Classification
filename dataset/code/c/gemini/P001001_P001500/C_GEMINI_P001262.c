#include <stdlib.h>

int cmpCourse(const void* a, const void* b) {
    int* c1 = *(int**)a;
    int* c2 = *(int**)b;
    return c1[1] - c2[1];
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize) {
    qsort(courses, coursesSize, sizeof(int*), cmpCourse);
    int pq[coursesSize + 1];
    int pSize = 0;
    int time = 0;

    for (int i = 0; i < coursesSize; i++) {
        time += courses[i][0];
        pq[pSize++] = courses[i][0];
        if (time > courses[i][1]) {
            int maxIdx = 0;
            for (int j = 1; j < pSize; j++) {
                if (pq[j] > pq[maxIdx]) maxIdx = j;
            }
            time -= pq[maxIdx];
            pq[maxIdx] = pq[--pSize];
        }
    }
    return pSize;
}