#include <stdio.h>
int main() {
    int n1, n2; scanf("%d", &n1);
    int a[n1]; for(int i=0; i<n1; i++) scanf("%d", &a[i]);
    scanf("%d", &n2);
    int b[n2]; for(int i=0; i<n2; i++) scanf("%d", &b[i]);
    if(n1 != n2) printf("NO\n");
    else {
        int same = 1;
        for(int i=0; i<n1; i++) if(a[i] != b[i]) { same = 0; break; }
        printf("%s\n", same ? "YES" : "NO");
    }
    return 0;
}
