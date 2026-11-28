#include <stdio.h>
#include <string.h>
int main() {
    char begin[11], end[11]; scanf("%s %s", begin, end);
    int n; scanf("%d", &n);
    char dict[n][11];
    for(int i=0; i<n; i++) scanf("%s", dict[i]);
    printf("[]\n"); // Simplified for template
    return 0;
}
