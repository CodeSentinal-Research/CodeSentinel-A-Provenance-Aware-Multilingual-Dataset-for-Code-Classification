#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int cmpTickets(const void* a, const void* b) {
    char** t1 = *(char***)a;
    char** t2 = *(char***)b;
    int c = strcmp(t1[0], t2[0]);
    if (c != 0) return c;
    return strcmp(t1[1], t2[1]);
}

bool dfs(char* curr, int count, int total, bool* used, char*** tickets, char** res) {
    res[count] = curr;
    if (count == total) return true;

    for (int i = 0; i < total; i++) {
        if (!used[i] && strcmp(tickets[i][0], curr) == 0) {
            used[i] = true;
            if (dfs(tickets[i][1], count + 1, total, used, tickets, res)) return true;
            used[i] = false;
        }
    }
    return false;
}

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize) {
    qsort(tickets, ticketsSize, sizeof(char**), cmpTickets);
    char** res = (char**)malloc((ticketsSize + 1) * sizeof(char*));
    bool* used = (bool*)calloc(ticketsSize, sizeof(bool));
    *returnSize = ticketsSize + 1;

    dfs("JFK", 0, ticketsSize, used, tickets, res);
    free(used);
    return res;
}