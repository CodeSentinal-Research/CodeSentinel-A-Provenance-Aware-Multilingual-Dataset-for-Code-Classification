#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char from[n][101], to[n][101];
    int is_dest[n];
    for (int i = 0; i < n; i++) is_dest[i] = 1;
    
    for (int i = 0; i < n; i++) {
        scanf("%s %s", from[i], to[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(from[i], to[j]) == 0) {
                is_dest[j] = 0;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (is_dest[i]) {
            printf("%s\n", to[i]);
            break;
        }
    }
    return 0;
}
