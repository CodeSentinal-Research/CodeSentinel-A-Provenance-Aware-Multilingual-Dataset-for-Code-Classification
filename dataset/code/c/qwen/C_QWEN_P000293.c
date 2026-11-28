#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char strs[100][201];
    for(int i=0; i<n; i++) scanf("%s", strs[i]);
    printf("Encoded: ");
    for(int i=0; i<n; i++) printf("%d:%s,", (int)strlen(strs[i]), strs[i]);
    printf("\nDecoded:\n");
    return 0;
}
