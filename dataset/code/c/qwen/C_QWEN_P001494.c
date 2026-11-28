#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    scanf("%s", s);
    int n = strlen(s);
    
    int l = 0, r = n, idx = 0;
    int res[n + 1];
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') res[idx++] = l++;
        else res[idx++] = r--;
    }
    res[idx] = l;
    for (int i = 0; i <= n; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
