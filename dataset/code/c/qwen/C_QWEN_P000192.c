#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], left=0, right=n-1;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    while(left < right) {
        while(left < right && arr[left] < 0) left++;
        while(left < right && arr[right] >= 0) right--;
        if(left < right) { int t=arr[left]; arr[left]=arr[right]; arr[right]=t; }
    }
    for(int i=0; i<n; i++) printf("%d%c", arr[i], i==n-1?'\n':' ');
    return 0;
}
