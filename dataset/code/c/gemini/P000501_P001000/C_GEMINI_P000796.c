#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 131071
typedef struct Node { int key; int idx; struct Node* next; } Node;
Node* table[HASH_SIZE];
int hash(int key) {
    int h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}
int find_idx(int key) {
    int h = hash(key);
    for (Node* cur = table[h]; cur; cur = cur->next) {
        if (cur->key == key) return cur->idx;
    }
    return -999999;
}
void put_idx(int key, int idx) {
    int h = hash(key);
    for (Node* cur = table[h]; cur; cur = cur->next) {
        if (cur->key == key) { cur->idx = idx; return; }
    }
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key; n->idx = idx; n->next = table[h];
    table[h] = n;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        long long total = 0;
        for (int i = 0; i < n; i++) { scanf("%d", &nums[i]); total += nums[i]; }
        int p; scanf("%d", &p);
        int target = total % p;
        if (target == 0) { printf("0\n"); return 0; }
        put_idx(0, -1);
        int cur = 0, min_len = n;
        for (int i = 0; i < n; i++) {
            cur = (cur + nums[i]) % p;
            int needed = (cur - target + p) % p;
            int prev = find_idx(needed);
            if (prev != -999999) {
                if (i - prev < min_len) min_len = i - prev;
            }
            put_idx(cur, i);
        }
        printf("%d\n", min_len < n ? min_len : -1);
    }
    return 0;
}