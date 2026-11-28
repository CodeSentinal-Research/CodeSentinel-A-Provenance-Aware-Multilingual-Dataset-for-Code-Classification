#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 131071
typedef struct Node { long long key; int count; struct Node* next; } Node;
Node* table[HASH_SIZE];
int hash(long long key) {
    int h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}
int get_count(long long key) {
    int h = hash(key);
    for (Node* cur = table[h]; cur; cur = cur->next) {
        if (cur->key == key) return cur->count;
    }
    return 0;
}
void add_key(long long key) {
    int h = hash(key);
    for (Node* cur = table[h]; cur; cur = cur->next) {
        if (cur->key == key) { cur->count++; return; }
    }
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key; n->count = 1; n->next = table[h];
    table[h] = n;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int k; scanf("%d", &k);
        add_key(0);
        long long cur = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            ans += get_count(cur - k);
            add_key(cur);
        }
        printf("%lld\n", ans);
    }
    return 0;
}