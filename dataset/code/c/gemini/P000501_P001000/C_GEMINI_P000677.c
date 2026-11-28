#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ITEMS 1005
typedef struct { char k[64], v[64]; } Entry;
Entry entries[MAX_ITEMS];
int size = 0;
int cmp(const void* a, const void* b) { return strcmp(((Entry*)a)->k, ((Entry*)b)->k); }
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32]; scanf("%31s", cmd);
            if (strcmp(cmd, "put") == 0) {
                char k[64], v[64]; scanf("%63s %63s", k, v);
                int found = -1;
                for (int i = 0; i < size; i++) if (strcmp(entries[i].k, k) == 0) { found = i; break; }
                if (found != -1) strcpy(entries[found].v, v);
                else { strcpy(entries[size].k, k); strcpy(entries[size].v, v); size++; }
                qsort(entries, size, sizeof(Entry), cmp);
            } else if (strcmp(cmd, "get") == 0) {
                char k[64]; scanf("%63s", k);
                int found = -1;
                for (int i = 0; i < size; i++) if (strcmp(entries[i].k, k) == 0) { found = i; break; }
                if (found != -1) printf("%s\n", entries[found].v);
                else printf("-1\n");
            } else if (strcmp(cmd, "remove") == 0) {
                char k[64]; scanf("%63s", k);
                int found = -1;
                for (int i = 0; i < size; i++) if (strcmp(entries[i].k, k) == 0) { found = i; break; }
                if (found != -1) {
                    for (int i = found; i < size - 1; i++) entries[i] = entries[i+1];
                    size--;
                }
            } else if (strcmp(cmd, "firstKey") == 0) {
                printf("%s\n", size > 0 ? entries[0].k : "");
            } else if (strcmp(cmd, "lastKey") == 0) {
                printf("%s\n", size > 0 ? entries[size - 1].k : "");
            } else if (strcmp(cmd, "nextKey") == 0) {
                char k[64]; scanf("%63s", k);
                int found = -1;
                for (int i = 0; i < size; i++) if (strcmp(entries[i].k, k) > 0) { found = i; break; }
                printf("%s\n", found != -1 ? entries[found].k : "");
            } else if (strcmp(cmd, "previousKey") == 0) {
                char k[64]; scanf("%63s", k);
                int found = -1;
                for (int i = size - 1; i >= 0; i--) if (strcmp(entries[i].k, k) < 0) { found = i; break; }
                printf("%s\n", found != -1 ? entries[found].k : "");
            }
        }
    }
    return 0;
}