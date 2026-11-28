#include <stdio.h>
#include <stdlib.h>

typedef struct TrieNode {
    struct TrieNode* next[2];
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)calloc(1, sizeof(TrieNode));
    return node;
}

void insert(TrieNode* root, int num) {
    TrieNode* curr = root;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!curr->next[bit]) curr->next[bit] = createNode();
        curr = curr->next[bit];
    }
}

int query(TrieNode* root, int num) {
    TrieNode* curr = root;
    int res = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int opp = 1 - bit;
        if (curr->next[opp]) {
            res |= (1 << i);
            curr = curr->next[opp];
        } else {
            curr = curr->next[bit];
        }
    }
    return res;
}

int findMaximumXOR(int* nums, int numsSize) {
    TrieNode* root = createNode();
    for (int i = 0; i < numsSize; i++) insert(root, nums[i]);
    int maxXor = 0;
    for (int i = 0; i < numsSize; i++) {
        int cur = query(root, nums[i]);
        if (cur > maxXor) maxXor = cur;
    }
    return maxXor;
}