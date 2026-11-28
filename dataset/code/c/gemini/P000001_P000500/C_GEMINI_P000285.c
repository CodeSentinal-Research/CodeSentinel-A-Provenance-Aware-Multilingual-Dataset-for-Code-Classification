#include <stdbool.h>

bool isSubsequence(char* A, char* B) {
    int i = 0, j = 0;
    while (A[i] != '\0' && B[j] != '\0') {
        if (A[i] == B[j]) i++;
        j++;
    }
    return A[i] == '\0';
}