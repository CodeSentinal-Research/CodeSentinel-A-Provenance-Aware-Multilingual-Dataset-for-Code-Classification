#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int val;
    struct Node* next;
} Node;
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        Node* head = NULL;
        Node* tail = NULL;
        int size = 0;
        while (q--) {
            char cmd[16];
            scanf("%15s", cmd);
            if (strcmp(cmd, "enqueue") == 0) {
                int x; scanf("%d", &x);
                Node* n = (Node*)malloc(sizeof(Node));
                n->val = x; n->next = NULL;
                if (!tail) head = tail = n;
                else { tail->next = n; tail = n; }
                size++;
            } else if (strcmp(cmd, "dequeue") == 0) {
                if (head) {
                    printf("%d\n", head->val);
                    Node* temp = head;
                    head = head->next;
                    if (!head) tail = NULL;
                    free(temp);
                    size--;
                }
            } else if (strcmp(cmd, "front") == 0) {
                if (head) printf("%d\n", head->val);
            } else if (strcmp(cmd, "size") == 0) {
                printf("%d\n", size);
            } else if (strcmp(cmd, "isEmpty") == 0) {
                printf("%s\n", size == 0 ? "true" : "false");
            }
        }
    }
    return 0;
}