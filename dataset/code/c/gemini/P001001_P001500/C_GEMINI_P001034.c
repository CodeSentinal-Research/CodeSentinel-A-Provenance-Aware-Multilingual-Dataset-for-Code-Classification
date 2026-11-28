#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int cap = 1000, size = 0;
    int* vals = (int*)malloc(cap * sizeof(int));
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* cur = lists[i];
        while (cur) {
            if (size == cap) {
                cap *= 2;
                vals = (int*)realloc(vals, cap * sizeof(int));
            }
            vals[size++] = cur->val;
            cur = cur->next;
        }
    }
    if (size == 0) {
        free(vals);
        return NULL;
    }
    qsort(vals, size, sizeof(int), cmp);
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    for (int i = 0; i < size; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = vals[i];
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
    free(vals);
    return dummy.next;
}