#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char curr[10001] = "1";
    for(int i=1; i<n; i++) {
        char next[10001] = ""; int j=0, k=0;
        while(curr[j]) {
            char c = curr[j]; int count=0;
            while(curr[j]==c) { count++; j++; }
            k += sprintf(next+k, "%d%c", count, c);
        }
        strcpy(curr, next);
    }
    printf("%s\n", curr);
    return 0;
}
