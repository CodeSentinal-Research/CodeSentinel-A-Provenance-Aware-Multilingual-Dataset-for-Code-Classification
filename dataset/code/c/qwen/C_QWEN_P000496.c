#include <stdio.h>
#define MOD 1000000007
int main() {
    int n; scanf("%d", &n);
    int arr[30001], left[30001], right[30001], stack[30001], top=-1;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++) {
        while(top>=0 && arr[stack[top]]>=arr[i]) top--;
        left[i] = (top==-1) ? -1 : stack[top];
        stack[++top]=i;
    }
    top=-1;
    for(int i=n-1; i>=0; i--) {
        while(top>=0 && arr[stack[top]]>arr[i]) top--;
        right[i] = (top==-1) ? n : stack[top];
        stack[++top]=i;
    }
    long long total=0;
    for(int i=0; i<n; i++) {
        long long count = (long long)(i-left[i])*(right[i]-i);
        total = (total + (long long)arr[i]*count) % MOD;
    }
    printf("%lld\n", total);
    return 0;
}
