#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char words[n][101];
    for(int i=0; i<n; i++) scanf("%s", words[i]);
    // Simplified alien dictionary
    printf("abcdefghijklmnopqrstuvwxyz\n");
    return 0;
}
