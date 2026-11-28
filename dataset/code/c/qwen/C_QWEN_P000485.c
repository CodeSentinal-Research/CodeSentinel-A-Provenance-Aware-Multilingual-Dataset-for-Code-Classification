#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[100000], stack[100000], top=-1, res[100000], res_idx=0;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++) {
        if(arr[i]>0) { stack[++top]=arr[i]; }
        else {
            while(top>=0 && stack[top]>0 && stack[top]<-arr[i]) top--;
            if(top>=0 && stack[top]==-arr[i]) top--;
            else if(top<0 || stack[top]<0) stack[++top]=arr[i];
        }
    }
    for(int i=0; i<=top; i++) printf("%d%c", stack[i], i==top?'\n':' ');
    return 0;
}
