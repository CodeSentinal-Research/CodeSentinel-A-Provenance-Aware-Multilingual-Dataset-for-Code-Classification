#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int input[n], output[n], stack[n], top=-1;
    for(int i=0; i<n; i++) scanf("%d", &input[i]);
    for(int i=0; i<n; i++) scanf("%d", &output[i]);
    int j=0;
    for(int i=0; i<n; i++) {
        stack[++top]=input[i];
        while(top>=0 && stack[top]==output[j]) { top--; j++; }
    }
    printf("%s\n", j==n ? "true" : "false");
    return 0;
}
