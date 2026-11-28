#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minHeapify(int arr[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int t = arr[i]; arr[i] = arr[smallest]; arr[smallest] = t;
        minHeapify(arr, n, smallest);
    }
}

int popMin(int arr[], int* n) {
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
    return root;
}

void pushMin(int arr[], int* n, int val) {
    arr[*n] = val;
    int i = *n;
    (*n)++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (arr[i] < arr[p]) {
            int t = arr[i]; arr[i] = arr[p]; arr[p] = t;
            i = p;
        } else {
            break;
        }
    }
}

int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        int* heap = (int*)malloc(q * sizeof(int));
        int heapSize = 0;
        char op[32];
        while (q--) {
            scanf("%s", op);
            if (strcmp(op, "INSERT") == 0) {
                int val;
                scanf("%d", &val);
                pushMin(heap, &heapSize, val);
            } else if (strcmp(op, "EXTRACT_MIN") == 0) {
                if (heapSize == 0) printf("EMPTY\n");
                else printf("%d\n", popMin(heap, &heapSize));
            } else if (strcmp(op, "PEEK") == 0) {
                if (heapSize == 0) printf("EMPTY\n");
                else printf("%d\n", heap[0]);
            }
        }
        free(heap);
    }
    return 0;
}