#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int pushed[n], popped[n], stack[n], top=-1, j=0;
    for(int i=0; i<n; i++) scanf("%d", &pushed[i]);
    for(int i=0; i<n; i++) scanf("%d", &popped[i]);
    for(int i=0; i<n; i++) {
        stack[++top]=pushed[i];
        while(top>=0 && stack[top]==popped[j]) { top--; j++; }
    }
    printf("%s\n", j==n ? "true" : "false");
    return 0;
}
