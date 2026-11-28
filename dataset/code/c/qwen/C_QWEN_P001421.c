#include <stdio.h>
#include <string.h>

int main() {
    int n1, n2;
    scanf("%d", &n1);
    char list1[n1][101];
    for (int i = 0; i < n1; i++) scanf("%s", list1[i]);
    
    scanf("%d", &n2);
    char list2[n2][101];
    for (int i = 0; i < n2; i++) scanf("%s", list2[i]);
    
    int min_sum = 200000;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                if (i + j < min_sum) min_sum = i + j;
            }
        }
    }
    
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (strcmp(list1[i], list2[j]) == 0 && i + j == min_sum) {
                printf("%s\n", list1[i]);
            }
        }
    }
    return 0;
}
