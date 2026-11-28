#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 131071
typedef struct Node { long long key; int idx; struct Node* next; } Node;
Node* table[HASH_SIZE];
int hash(long long key) {
    int h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}
int find_idx(long long key) {
    int h = hash(key);
    for (Node* cur = table[h]; cur; cur = cur->next) {
        if (cur->key == key) return cur->idx;
    }
    return -999999;
}
void put_idx(long long key, int idx) {
    int h = hash(key);
    for (Node* cur = table[h]; cur; cur = cur->next) {
        if (cur->key == key) return;
    }
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key; n->idx = idx; n->next = table[h];
    table[h] = n;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int k; scanf("%d", &k);
        put_idx(0, -1);
        long long cur = 0; int max_len = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            int prev = find_idx(cur - k);
            if (prev != -999999) {
                if (i - prev > max_len) max_len = i - prev;
            }
            put_idx(cur, i);
        }
        printf("%d\n", max_len);
    }
    return 0;
}