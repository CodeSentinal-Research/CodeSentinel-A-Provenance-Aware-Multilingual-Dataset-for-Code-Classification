#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[32];
} NodeStr;

int getNodeIdx(char* name, NodeStr* nodes, int* nSize) {
    for (int i = 0; i < *nSize; i++) {
        if (strcmp(nodes[i].name, name) == 0) return i;
    }
    strcpy(nodes[*nSize].name, name);
    return (*nSize)++;
}

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char*** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    NodeStr nodes[100];
    int nSize = 0;
    double dist[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) dist[i][j] = (i == j) ? 1.0 : -1.0;
    }

    for (int i = 0; i < equationsSize; i++) {
        int u = getNodeIdx(equations[i][0], nodes, &nSize);
        int v = getNodeIdx(equations[i][1], nodes, &nSize);
        dist[u][v] = values[i];
        dist[v][u] = 1.0 / values[i];
    }

    for (int k = 0; k < nSize; k++) {
        for (int i = 0; i < nSize; i++) {
            for (int j = 0; j < nSize; j++) {
                if (dist[i][k] > 0 && dist[k][j] > 0) {
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
    }

    double* res = (double*)malloc(queriesSize * sizeof(double));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int u = -1, v = -1;
        for (int j = 0; j < nSize; j++) {
            if (strcmp(nodes[j].name, queries[i][0]) == 0) u = j;
            if (strcmp(nodes[j].name, queries[i][1]) == 0) v = j;
        }
        if (u == -1 || v == -1) res[i] = -1.0;
        else res[i] = dist[u][v];
    }
    return res;
}